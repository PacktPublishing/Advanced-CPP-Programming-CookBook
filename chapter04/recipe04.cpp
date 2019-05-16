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

template<typename... Args>
void foo(Args &&...args)
{ }

int main(void)
{
    foo("The answer");
    foo("The answer is", 42);
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>

template<typename... Args>
void foo2(Args &&...args)
{ }

template<typename... Args>
void foo1(Args &&...args)
{
    foo2(args...);
}

int main(void)
{
    foo1("The answer");
    foo1("The answer is", 42);
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <iostream>

template<typename... Args>
void foo2(Args &&...args)
{ }

template<typename... Args>
void foo1(Args &&...args)
{
    foo2(std::forward<Args>(args)...);
}

int main(void)
{
    foo1("The answer");
    foo1("The answer is", 42);
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <iostream>

template<typename... Args>
void foo2(const char *str, Args &&...args)
{ }

template<typename... Args>
void foo1(Args &&...args)
{
    foo2("the cow is blue", std::forward<Args>(args)...);
}

int main(void)
{
    foo1("The answer");
    foo1("The answer is", 42);
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <iostream>

template<typename... Args>
struct the_answer
{ };

template<typename... Args>
void foo(Args &&...args)
{
    the_answer<Args...> is;
}

int main(void)
{
    foo("The answer");
    foo("The answer is", 42);
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE06

#include <tuple>
#include <iostream>

template<typename... Args>
void foo(Args &&...args)
{
    std::tuple t(std::forward<Args>(args)...);
    std::cout << std::get<0>(t) << '\n';
}

int main(void)
{
    foo("The answer");
    foo("The answer is", 42);
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE07

#include <tuple>
#include <iostream>

template<typename... Args>
void foo(Args &&...args)
{
    std::cout << sizeof...(Args) << '\n';
    std::cout << std::tuple_size_v<std::tuple<Args...>> << '\n';
}

int main(void)
{
    foo("The answer");
    foo("The answer is", 42);
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE08

#include <tuple>
#include <iostream>

template<
    std::size_t I = 0,
    typename TUPLE,
    typename FUNCTION
    >
constexpr void
for_each(TUPLE &&tuple, FUNCTION &&func)
{
    if constexpr (I < std::tuple_size_v<std::remove_reference_t<TUPLE>>) {
        func(std::get<I>(tuple));
        for_each<I + 1>(
            std::forward<TUPLE>(tuple),
            std::forward<FUNCTION>(func)
        );
    }
}

template<typename... Args>
void foo(Args &&...args)
{
    std::tuple t(std::forward<Args>(args)...);
    for_each(t, [](const auto &arg) {
        std::cout << arg;
    });
}

int main(void)
{
    foo("The answer is: ", 42);
    std::cout << '\n';

    return 0;
}

// The answer is: 42

#endif
