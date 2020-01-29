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

// -----------------------------------------------------------------------------
#ifdef EXAMPLE01

#include <iostream>

void foo(const int *array, size_t size)
{
    for (auto i = 0; i < size; i++) {
        std::cout << array[i] << ' ';
    }

    std::cout << '\n';
}

int main(void)
{
    int array[] = {4, 8, 15, 16, 23, 42};
    foo(array, sizeof(array)/sizeof(array[0]));
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>

template<size_t N>
void foo(const int (&array)[N])
{
    for (auto i = 0; i < N; i++) {
        std::cout << array[i] << ' ';
    }

    std::cout << '\n';
}

int main(void)
{
    int array[] = {4, 8, 15, 16, 23, 42};
    foo(array);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <iostream>
#include "span.hpp"

namespace std
{
template<typename T>
using span = tcb::span<T>;
}

void foo(const std::span<int> &s)
{
    for (auto i = 0; i < s.size(); i++) {
        std::cout << s[i] << ' ';
    }

    std::cout << '\n';
}

int main(void)
{
    int array[] = {4, 8, 15, 16, 23, 42};
    foo(array);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <iostream>
#include "span.hpp"

namespace std
{
template<typename T>
using span = tcb::span<T>;
}

void foo(const std::span<int> &s)
{
    for (const auto &elem : s) {
        std::cout << elem << ' ';
    }

    std::cout << '\n';
}

int main(void)
{
    int array[] = {4, 8, 15, 16, 23, 42};
    foo(array);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <memory>
#include <vector>
#include <iostream>
#include "span.hpp"

namespace std
{
template<typename T>
using span = tcb::span<T>;
}

void foo(const std::span<int> &s)
{
    std::cout << "size: " << s.size() << '\n';
    std::cout << "size (in bytes): " << s.size_bytes() << '\n';
}

int main(void)
{
    auto ptr1 = new int[6]();
    foo({ptr1, 6});
    delete [] ptr1;

    std::vector<int> v(6);
    foo({v.data(), v.size()});

    auto ptr2 = std::make_unique<int>(6);
    foo({ptr2.get(), 6});
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE06

#include <iostream>
#include "span.hpp"

namespace std
{
template<typename T>
using span = tcb::span<T>;
}

void foo2(const std::span<int> &s)
{
    for (const auto &elem : s) {
        std::cout << elem << ' ';
    }

    std::cout << '\n';
}

void foo1(const std::span<int> &s)
{
    foo2(s.subspan(5, 1));
}

int main(void)
{
    int array[] = {4, 8, 15, 16, 23, 42};
    foo1(array);
}

#endif
