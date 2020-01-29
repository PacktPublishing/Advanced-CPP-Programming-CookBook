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

#include <array>
#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> count;

void
inc(std::shared_ptr<int> val)
{
    count += *val;
}

void
execute_threads(std::unique_ptr<int> ptr)
{
    std::array<std::thread, 42> threads;
    auto shared = std::shared_ptr<int>(std::move(ptr));

    for (auto &thread : threads) {
        thread = std::thread{inc, shared};
    }

    for (auto &thread : threads) {
        thread.join();
    }
}

int main(void)
{
    execute_threads(std::make_unique<int>(1));
    std::cout << "count: " << count << '\n';

    return 0;
}

// count: 42

#endif
