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

#include <iostream>

struct the_answer
{
    using type = unsigned;
};

template<typename T>
void foo(typename T::type t)
{
    std::cout << "The answer is not: " << t << '\n';
}

template<typename T>
void foo(T t)
{
    std::cout << "The answer is: " << t << '\n';
}

int main(void)
{
    foo<the_answer>(23);
    foo<int>(42);

    return 0;
}

// The answer is: 23
// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>
#include <type_traits>

template<typename T>
constexpr auto is_int()
{ return false; }

template<>
constexpr auto is_int<int>()
{ return true; }

template<
    typename T,
    std::enable_if_t<is_int<T>(), int> = 0
    >
void the_answer(T is)
{
    std::cout << "The answer is: " << is << '\n';
}

int main(void)
{
    the_answer(42);
    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <iostream>
#include <type_traits>

template<
    typename T,
    std::enable_if_t<std::is_integral_v<T>>* = nullptr
    >
void the_answer(T is)
{
    std::cout << "The answer is: " << is << '\n';
}

int main(void)
{
    the_answer(42);
    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <iostream>
#include <type_traits>

template<typename T>
std::enable_if_t<std::is_integral_v<T>>
the_answer(T is)
{
    std::cout << "The answer is: " << is << '\n';
}

int main(void)
{
    the_answer(42);
    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <iostream>
#include <type_traits>
#include <iomanip>

template<
    typename T,
    std::enable_if_t<std::is_integral_v<T>>* = nullptr
    >
void the_answer(T is)
{
    std::cout << "The answer is: " << is << '\n';
}

template<
    typename T,
    std::enable_if_t<std::is_floating_point_v<T>>* = nullptr
    >
void the_answer(T is)
{
    std::cout << std::setprecision(10);
    std::cout << "The answer is: " << is << '\n';
}

int main(void)
{
    the_answer(42);
    the_answer(42U);
    the_answer(42.12345678);

    return 0;
}

// The answer is: 42
// The answer is: 42
// The answer is: 42.12345678

#endif
