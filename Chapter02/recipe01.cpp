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
    throw std::runtime_error("The answer is: 42");
}

int main(void)
{
    try {
        foo();
    }
    catch(const std::exception &e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>
#include <stdexcept>

void foo() noexcept
{
    throw std::runtime_error("The answer is: 42");
}

int main(void)
{
    try {
        foo();
    }
    catch(const std::exception &e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}

// terminate called after throwing an instance of 'std::runtime_error'
//   what():  The answer is: 42
// Aborted (core dumped)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <iostream>
#include <stdexcept>

void foo() noexcept
{
    try {
        throw std::runtime_error("The answer is: 42");
    }
    catch(const std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

int main(void)
{
    foo();
    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <iostream>
#include <stdexcept>

void foo() noexcept(true)
{
    throw std::runtime_error("The answer is: 42");
}

int main(void)
{
    try {
        foo();
    }
    catch(const std::exception &e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}

// terminate called after throwing an instance of 'std::runtime_error'
//   what():  The answer is: 42
// Aborted (core dumped)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <limits>
#include <iostream>
#include <stdexcept>

template<typename T>
uint64_t foo(T val) noexcept(sizeof(T) <= 4)
{
    if constexpr(sizeof(T) <= 4) {
        return static_cast<uint64_t>(val) << 32;
    }

    throw std::runtime_error("T is too large");
}

int main(void)
{
    try {
        uint32_t val1 = std::numeric_limits<uint32_t>::max();
        std::cout << "foo: " << foo(val1) << '\n';

        uint64_t val2 = std::numeric_limits<uint64_t>::max();
        std::cout << "foo: " << foo(val2) << '\n';
    }
    catch(const std::exception &e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}

// foo: 18446744069414584320
// foo: T is too large

#endif

#pragma GCC diagnostic pop
