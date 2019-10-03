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

int main(void)
{
    auto i1 = 42;
    auto i2{42};
    auto i3 = {42};
    auto i4 = {4, 8, 15, 16, 23, 42};

    show_type(i1);
    show_type(i2);
    show_type(i3);
    show_type(i4);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

int main(void)
{
    auto i1 = 42;
    const auto i2 = 42;
    volatile auto i3 = 42;
    const volatile auto i4 = 42;

    show_type(i1);
    show_type(i2);
    show_type(i3);
    show_type(i4);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

int main(void)
{
    int i = 42;

    auto i1 = i;
    auto &i2 = i;
    auto &&i3 = i;

    show_type(i1);
    show_type(i2);
    show_type(i3);

    const auto ic1 = i;
    // const auto &ic2 = i;         // compile error
    volatile auto iv1 = i;
    // volatile auto &iv2 = i;      // compile error

    show_type(ic1);
    // show_type(ic2);
    show_type(iv1);
    // show_type(iv2);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

int main(void)
{
    const int i = 42;

    auto i1 = i;
    auto &i2 = i;
    auto &&i3 = i;

    show_type(i1);
    show_type(i2);
    show_type(i3);

    const auto ic1 = i;
    const auto &ic2 = i;
    volatile auto iv1 = i;
    // volatile auto &iv2 = i;      // compile error

    show_type(ic1);
    show_type(ic2);
    show_type(iv1);
    // show_type(iv2);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

int main(void)
{
    volatile int i = 42;

    auto i1 = i;
    auto &i2 = i;
    auto &&i3 = i;

    show_type(i1);
    show_type(i2);
    show_type(i3);

    const auto ic1 = i;
    // const auto &ic2 = i;         // compile error
    volatile auto iv1 = i;
    volatile auto &iv2 = i;

    show_type(ic1);
    // show_type(ic2);
    show_type(iv1);
    show_type(iv2);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE06

#define valueness(a)                                    \
    if (std::is_rvalue_reference<decltype(a)>{}) {      \
        std::cout << #a << " is an r-value\n";          \
    }                                                   \
    else {                                              \
        std::cout << #a << " is an l-value\n";          \
    }

int main(void)
{
    int i = 42;

    auto i1 = i;
    auto &i2 = i;
    auto &&i3 = i;
    auto &&i4 = 42;

    valueness(i);
    valueness(i1);
    valueness(i2);
    valueness(i3);
    valueness(i4);
}

#endif
