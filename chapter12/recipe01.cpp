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

    char c = 0;
    auto r = c + 42;

    show_type(c);
    show_type(r);
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

    int i1 = i;
    int &i2 = i;

    show_type(i1);
    show_type(i2);

    auto a1 = i1;
    auto a2 = i2;

    show_type(a1);
    show_type(a2);

    auto a3 = i1;
    auto &a4 = i2;

    show_type(a3);
    show_type(a4);

    int &&i3 = std::move(i);
    show_type(i3);

    auto &&a5 = i3;
    show_type(a5);

    auto &&a6 = i1;
    show_type(a6);

    auto &&a7 = i2;
    show_type(a7);

    auto &&a8 = i3;
    show_type(a8);

    auto &&a9 = std::move(i3);
    show_type(a9);

    auto &&a10 = 42;
    show_type(a10);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

int main(void)
{
    const int i = 42;

    auto i1 = i;
    auto &i2 = i;
    auto &&i3 = std::move(i);

    show_type(i1);
    show_type(i2);
    show_type(i3);
}

#endif
