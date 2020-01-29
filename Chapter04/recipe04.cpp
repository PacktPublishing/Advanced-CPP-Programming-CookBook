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
    foo("The answer is: ", 42);
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <tuple>
#include <iostream>

int main(void)
{
    std::tuple t("the answer is: ", 42);
    std::cout << std::get<0>(t) << std::get<1>(t) << '\n';
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <tuple>
#include <iostream>

template<typename... Args>
void foo(Args &&...args)
{
    std::tuple t(std::forward<Args>(args)...);
    std::cout << std::get<0>(t) << std::get<1>(t) << '\n';
}

int main(void)
{
    foo("The answer is: ", 42);
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

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
    foo("The answer is", 42);
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <tuple>
#include <iostream>

template<
    std::size_t I = 0,
    typename ... Args,
    typename FUNCTION
    >
constexpr void
for_each(const std::tuple<Args...> &t, FUNCTION &&func)
{
    if constexpr (I < sizeof...(Args)) {
        func(std::get<I>(t));
        for_each<I + 1>(t, std::forward<FUNCTION>(func));
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
