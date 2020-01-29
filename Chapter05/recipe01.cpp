//
// Copyright (C) 2019 Rian Quinn <user@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// -----------------------------------------------------------------------------
#ifdef EXAMPLE01

#include <thread>
#include <string>
#include <iostream>

void foo()
{
    static std::string msg{"The answer is: 42\n"};
    while(true) {
        for (const auto &c : msg) {
            std::clog << c;
        }
    }
}

int main(void)
{
    std::thread t1{foo};
    std::thread t2{foo};

    t1.join();
    t2.join();

    // Never reached
    return 0;
}

// The answer is:he 42
// The answer is: 42
// The answer is answer is::  42
// The answer is:42
//  42
// ThThe answer is: 42
// The answer is: 42
// ...

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <mutex>
#include <thread>
#include <string>
#include <iostream>

std::mutex m{};

void foo()
{
    static std::string msg{"The answer is: 42\n"};
    while(true) {
        m.lock();
        for (const auto &c : msg) {
            std::clog << c;
        }
        m.unlock();
    }
}

int main(void)
{
    std::thread t1{foo};
    std::thread t2{foo};

    t1.join();
    t2.join();

    // Never reached
    return 0;
}

// The answer is: 42
// The answer is: 42
// The answer is: 42
// The answer is: 42
// The answer is: 42
// ...

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <mutex>
#include <thread>

std::mutex m{};

void foo()
{
    m.lock();
}

int main(void)
{
    std::thread t1{foo};
    std::thread t2{foo};

    t1.join();
    t2.join();

    // Never reached
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <array>
#include <mutex>
#include <thread>
#include <string>
#include <iostream>

std::mutex m{};
std::array<int,6> numbers{4,8,15,16,23,42};

int foo(int index)
{
    m.lock();
    auto element = numbers.at(index);
    m.unlock();

    return element;
}

int main(void)
{
    std::cout << "The answer is: " << foo(5) << '\n';
    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <mutex>
#include <thread>
#include <iostream>

std::mutex m{};

void foo()
{
    static std::string msg{"The answer is: 42\n"};

    while(true) {
        std::lock_guard lock(m);
        for (const auto &c : msg) {
            std::clog << c;
        }
    }
}

int main(void)
{
    std::thread t1{foo};
    std::thread t2{foo};

    t1.join();
    t2.join();

    // Never reached
    return 0;
}

// The answer is: 42
// The answer is: 42
// The answer is: 42
// The answer is: 42
// The answer is: 42
// ...

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE06

#include <mutex>
#include <thread>
#include <string>
#include <iostream>

std::recursive_mutex m{};

void foo()
{
    m.lock();
    m.lock();

    std::cout << "The answer is: 42\n";

    m.unlock();
    m.unlock();
}

int main(void)
{
    std::thread t1{foo};
    std::thread t2{foo};

    t1.join();
    t2.join();

    return 0;
}

// The answer is: 42
// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE07

#include <mutex>
#include <shared_mutex>
#include <thread>
#include <iostream>

int count_rw{};
const auto &count_ro = count_rw;

std::shared_mutex m{};

void reader()
{
    while(true) {
        std::shared_lock lock(m);
        if (count_ro >= 42) {
            return;
        }
    }
}

void writer()
{
    while(true) {
        std::unique_lock lock(m);
        if (++count_rw == 100) {
            return;
        }
    }
}

int main(void)
{
    std::thread t1{reader};
    std::thread t2{reader};
    std::thread t3{reader};
    std::thread t4{reader};
    std::thread t5{writer};

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE08

#include <mutex>
#include <thread>
#include <iostream>

std::timed_mutex m{};

void foo()
{
    using namespace std::chrono;

    if (m.try_lock_for(seconds(1))) {
        std::cout << "lock acquired\n";
    }
    else {
        std::cout << "lock failed\n";
    }
}

int main(void)
{
    std::thread t1{foo};
    std::thread t2{foo};

    t1.join();
    t2.join();

    return 0;
}

// lock acquired
// lock failed

#endif
