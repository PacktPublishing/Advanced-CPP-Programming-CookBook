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

int main(void)
{
    auto ptr = new int;
    *ptr = 42;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

int main(void)
{
    auto p = new int;
    delete p;

    delete p;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

int main(void)
{
    auto p = new int;
    delete p;

    *p = 42;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <memory>

int main(void)
{
    auto ptr = std::make_unique<int>();
    *ptr = 42;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <memory>
#include <iostream>

int main(void)
{
    auto ptr = std::make_unique<int[]>(100);
    ptr[0] = 42;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE06

#include <array>
#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> count;

void inc(int *val)
{
    count += *val;
}

int main(void)
{
    auto ptr = std::make_unique<int>(1);
    std::array<std::thread, 42> threads;

    for (auto &thread : threads) {
        thread = std::thread{inc, ptr.get()};
    }

    for (auto &thread : threads) {
        thread.join();
    }

    std::cout << "count: " << count << '\n';

    return 0;
}

// count: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE07

#include <array>
#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> count;

void inc(int *val)
{
    count += *val;
}

int main(void)
{
    std::array<std::thread, 42> threads;

    {
        auto ptr = std::make_unique<int>(1);

        for (auto &thread : threads) {
            thread = std::thread{inc, ptr.get()};
        }
    }

    for (auto &thread : threads) {
        thread.join();
    }

    std::cout << "count: " << count << '\n';

    return 0;
}

// count: 32579929

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE08

#include <array>
#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> count;

void inc(std::shared_ptr<int> val)
{
    count += *val;
}

int main(void)
{
    std::array<std::thread, 42> threads;

    {
        auto ptr = std::make_shared<int>(1);

        for (auto &thread : threads) {
            thread = std::thread{inc, ptr};
        }
    }

    for (auto &thread : threads) {
        thread.join();
    }

    std::cout << "count: " << count << '\n';

    return 0;
}

// count: 42

#endif
