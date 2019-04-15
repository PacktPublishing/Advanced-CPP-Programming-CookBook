//
// Copyright (C) 2019 Rian Quinn <rianquinn@gmail.com>
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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wterminate"

// -----------------------------------------------------------------------------
#ifdef EXAMPLE01

#include <iostream>
#include <stdexcept>

void foo()
{
    try {
        throw std::runtime_error("The answer is: 42");
    }
    catch (const std::exception &e) {
        std::cout << e.what() << '\n';
        throw;
    }
}

int main(void)
{
    try {
        foo();
    }
    catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

// The answer is: 42
// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>
#include <stdexcept>

int main(void)
{
    std::exception_ptr eptr;

    try {
        try {
            throw std::runtime_error("The answer is: 42");
        }
        catch (...) {
            throw;
        }
    }
    catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <iostream>
#include <stdexcept>

int main(void)
{
    std::exception_ptr eptr;

    try {
        throw std::runtime_error("The answer is: 42");
    }
    catch (...) {
        eptr = std::current_exception();
    }

    try {
        std::rethrow_exception(eptr);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <thread>
#include <iostream>
#include <stdexcept>

std::exception_ptr eptr{};

void thread1()
{
    while (eptr == nullptr)
    { }

    try {
        std::rethrow_exception(eptr);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void thread2()
{
    try {
        throw std::runtime_error("The answer is: 42");
    }
    catch (const std::runtime_error &e) {
        eptr = std::make_exception_ptr(e);
    }
}

int main(void)
{
    std::thread t1(thread1);
    std::thread t2(thread2);

    t2.join();
    t1.join();
}

// The answer is: 42

#endif

#pragma GCC diagnostic pop
