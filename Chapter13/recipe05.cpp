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

#include <vector>
#include <iostream>

auto
even_numbers(size_t s, size_t e)
{
    std::vector<int> nums;

    if (s % 2 != 0 || e % 2 != 0) {
        std::terminate();
    }

    for (auto i = s; i <= e; i += 2) {
        nums.push_back(i);
    }

    return nums;
}

int main(void)
{
    for (const auto &num : even_numbers(0, 10)) {
        std::cout << num << ' ';
    }

    std::cout << '\n';
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>

generator<int>
even_numbers(size_t s, size_t e)
{
    if (s % 2 != 0 || e % 2 != 0) {
        std::terminate();
    }

    for (auto i = s; i < e; i += 2) {
        co_yield i;
    }

    co_return e;
}

int main(void)
{
    for (const auto &num : even_numbers(0, 10)) {
        std::cout << num << ' ';
    }

    std::cout << '\n';
}

#endif
