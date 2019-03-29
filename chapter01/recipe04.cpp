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
#include <folly/Benchmark.h>

BENCHMARK(insert_front) {
    std::vector<int> v;
    for (auto i = 0; i < 1000; i++) {
        v.insert(v.begin(), i);
    }
}

BENCHMARK(insert_back) {
    std::vector<int> v;
    for (auto i = 0; i < 1000; i++) {
        v.insert(v.end(), i);
    }
}

int main(void)
{
    folly::runBenchmarks();
    return 0;
}

// ============================================================================
// /home/user/book/chapter01/recipe04.cpp          relative  time/iter  iters/s
// ============================================================================
// insert_front                                               143.72us    6.96K
// insert_back                                                 42.11us   23.75K
// ============================================================================

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>
#include <folly/dynamic.h>

int main(void)
{
    folly::dynamic answer;

    answer = 42;
    std::cout << "The answer is: " << answer << '\n';

    answer = "42";
    std::cout << "The answer is: " << answer << '\n';

    return 0;
}

// The answer is: 42
// The answer is: 42

#endif

