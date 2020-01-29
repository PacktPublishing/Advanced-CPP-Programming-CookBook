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
    std::cout << "The answer is: 42\n";
}

int main(void)
{
    std::cout << std::boolalpha;
    std::cout << "could foo throw: " << !noexcept(foo()) << '\n';
    return 0;
}

// could foo throw: true

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>
#include <stdexcept>

void foo1()
{
    std::cout << "The answer is: 42\n";
}

void foo2()
{
    throw std::runtime_error("The answer is: 42");
}

void foo3() noexcept
{
    std::cout << "The answer is: 42\n";
}

void foo4() noexcept
{
    throw std::runtime_error("The answer is: 42");
}

int main(void)
{
    std::cout << std::boolalpha;
    std::cout << "could foo throw: " << !noexcept(foo1()) << '\n';
    std::cout << "could foo throw: " << !noexcept(foo2()) << '\n';
    std::cout << "could foo throw: " << !noexcept(foo3()) << '\n';
    std::cout << "could foo throw: " << !noexcept(foo4()) << '\n';
    return 0;
}

// could foo throw: true
// could foo throw: true
// could foo throw: false
// could foo throw: false

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <iostream>
#include <stdexcept>

void foo()
{
    throw std::runtime_error("The answer is: 42");
}

int main(void)
{
    foo();
}

// terminate called after throwing an instance of 'std::runtime_error'
//   what():  The answer is: 42
// Aborted (core dumped)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <iostream>
#include <stdexcept>

void foo()
{
    throw std::runtime_error("The answer is: 42");
}

int main(void)
{
    if constexpr(noexcept(foo())) {
        foo();
    }
    else {
        try {
            foo();
        }
        catch (...)
        { }
    }
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <iostream>
#include <stdexcept>

void foo() noexcept
{
    throw std::runtime_error("The answer is: 42");
}

int main(void)
{
    if constexpr(noexcept(foo())) {
        foo();
    }
    else {
        try {
            foo();
        }
        catch (...)
        { }
    }
}

// terminate called after throwing an instance of 'std::runtime_error'
//   what():  The answer is: 42
// Aborted (core dumped)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE06

#include <iostream>
#include <stdexcept>

void foo1()
{
    std::cout << "The answer is: 42\n";
}

void foo2() noexcept(noexcept(foo1()))
{
    foo1();
}

int main(void)
{
    std::cout << std::boolalpha;
    std::cout << "could foo throw: " << !noexcept(foo1()) << '\n';
    std::cout << "could foo throw: " << !noexcept(foo2()) << '\n';
}

// could foo throw: true
// could foo throw: true

#endif

#pragma GCC diagnostic pop

