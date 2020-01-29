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

#include <iostream>

template <typename T>
constexpr auto type_info()
{
    std::string_view name{__PRETTY_FUNCTION__};
    name.remove_prefix(37);
    name.remove_suffix(1);
    return name;
}

#define show_type(a)                            \
    std::cout << #a                             \
              << " = "                          \
              << type_info<decltype(a)>()       \
              << '\n';                          \

// -----------------------------------------------------------------------------
#ifdef EXAMPLE01

template<typename FUNC>
auto question(FUNC &&func)
{
    auto x = func() + 10;
    return x;
}

short the_answer()
{
    return 32;
}

int main(void)
{
    auto i = question(the_answer);
    show_type(i);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

template<typename FUNC>
auto question(FUNC &&func)
{
    decltype(func()) x = func() + 10;
    return x;
}

short the_answer()
{
    return 32;
}

int main(void)
{
    auto i = question(the_answer);
    show_type(i);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

template<typename FUNC>
constexpr auto question(FUNC &&func) -> decltype(func())
{
    return func() + 10;
}

short the_answer()
{
    return 32;
}

int main(void)
{
    auto i = question(the_answer);
    show_type(i);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

int main(void)
{
    decltype(auto) i1 = 42;
    decltype(auto) i2{42};

    show_type(i1);
    show_type(i2);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

int main(void)
{
    decltype(auto) i1 = 42;
    const decltype(auto) i2 = 42;
    volatile decltype(auto) i3 = 42;
    const volatile decltype(auto) i4 = 42;

    show_type(i1);
    show_type(i2);
    show_type(i3);
    show_type(i4);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE06

int main(void)
{
    int i = 42;

    int i1 = i;
    int &i2 = i;
    int &&i3 = std::move(i);

    show_type(i1);
    show_type(i2);
    show_type(i3);

    auto a1 = i1;
    auto a2 = i2;
    auto a3 = std::move(i3);

    show_type(a1);
    show_type(a2);
    show_type(a3);

    auto a4 = i1;
    auto &a5 = i2;
    auto &&a6 = std::move(i3);

    show_type(a4);
    show_type(a5);
    show_type(a6);

    decltype(auto) d1 = i1;
    decltype(auto) d2 = i2;
    decltype(auto) d3 = std::move(i3);

    show_type(d1);
    show_type(d2);
    show_type(d3);
}

#endif
