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

// talk about the reorder buffer and super scaling CPUs and why example 1 is
// not 2x the time for example 2

// -----------------------------------------------------------------------------
#ifdef EXAMPLE01

#include <vector>
#include <iostream>
#include <algorithm>

constexpr auto size = 1000000;

int main(void)
{
    std::vector<int> numbers1(size);
    std::vector<int> numbers2(size);
    std::vector<int> numbers3(size);
    std::vector<int> numbers4(size);

    std::generate(numbers1.begin(), numbers1.end(), []() {
	    return rand() % size;
    });
    std::generate(numbers2.begin(), numbers2.end(), []() {
	    return rand() % size;
    });
    std::generate(numbers3.begin(), numbers3.end(), []() {
	    return rand() % size;
    });
    std::generate(numbers4.begin(), numbers4.end(), []() {
	    return rand() % size;
    });

    std::sort(numbers1.begin(), numbers1.end());
    std::sort(numbers2.begin(), numbers2.end());
    std::sort(numbers3.begin(), numbers3.end());
    std::sort(numbers4.begin(), numbers4.end());

    std::cout << numbers1.back() << '\n';
    std::cout << numbers2.back() << '\n';
    std::cout << numbers3.back() << '\n';
    std::cout << numbers4.back() << '\n';

    return 0;
}

// 999998
// 999998
// 999999
// 999999

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <future>
#include <thread>
#include <vector>
#include <iostream>
#include <algorithm>

constexpr auto size = 1000000;

int foo()
{
    std::vector<int> numbers(size);
    std::generate(numbers.begin(), numbers.end(), []() {
	    return rand() % size;
    });

    std::sort(numbers.begin(), numbers.end());
    return numbers.back();
}

int main(void)
{
    auto a1 = std::async(std::launch::async, foo);
    auto a2 = std::async(std::launch::async, foo);
    auto a3 = std::async(std::launch::async, foo);
    auto a4 = std::async(std::launch::async, foo);

    std::cout << a1.get() << '\n';
    std::cout << a2.get() << '\n';
    std::cout << a3.get() << '\n';
    std::cout << a4.get() << '\n';

    return 0;
}

// 999999
// 999998
// 999999
// 999999

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <future>
#include <thread>
#include <vector>
#include <iostream>
#include <algorithm>

constexpr auto size = 1000000;

int foo()
{
    std::vector<int> numbers(size);
    std::generate(numbers.begin(), numbers.end(), []() {
	    return rand() % size;
    });

    std::sort(numbers.begin(), numbers.end());
    return numbers.back();
}

int main(void)
{
    auto a1 = std::async(std::launch::deferred, foo);
    auto a2 = std::async(std::launch::deferred, foo);
    auto a3 = std::async(std::launch::deferred, foo);
    auto a4 = std::async(std::launch::deferred, foo);

    std::cout << a1.get() << '\n';
    std::cout << a2.get() << '\n';
    std::cout << a3.get() << '\n';
    std::cout << a4.get() << '\n';

    return 0;
}

// 999999
// 999998
// 999999
// 999999

#endif
