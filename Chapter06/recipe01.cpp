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

#include <string>
#include <vector>
#include <hayai.hpp>

std::vector<std::string> data;

BENCHMARK(vector, push_back, 10, 100)
{
    data.push_back("The answer is: 42");
}

BENCHMARK(vector, emplace_back, 10, 100)
{
    data.emplace_back("The answer is: 42");
}

// [==========] Running 2 benchmarks.
// [ RUN      ] vector.push_back (10 runs, 100 iterations per run)
// [     DONE ] vector.push_back (0.200741 ms)
// ...
// [ RUN      ] vector.emplace_back (10 runs, 100 iterations per run)
// [     DONE ] vector.emplace_back (0.166699 ms)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

volatile int data = 0;

void foo()
{
    data++;
}

int main(void)
{
    for (auto i = 0; i < 100000; i++) {
        foo();
    }
}

// Ir       file:function
// ------------------------------------------------------------
// 938,046  ???:_dl_lookup_symbol_x [/usr/lib64/ld-2.29.so]
// 800,000  ???:foo() [/home/user/book/chapter06/build/recipe01_example02]
// 761,954  ???:do_lookup_x [/usr/lib64/ld-2.29.so]
// 500,009  ???:main [/home/user/book/chapter06/build/recipe01_example02]
// 366,967  ???:_dl_relocate_object [/usr/lib64/ld-2.29.so]
// 132,922  ???:strcmp [/usr/lib64/libc-2.29.so]
// 118,879  ???:check_match [/usr/lib64/ld-2.29.so]
// ...

#endif
