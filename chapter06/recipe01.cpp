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

#include <vector>
#include <iostream>
#include <hayai.hpp>

std::vector<int> data;

BENCHMARK(vector, push_back, 10, 100)
{
    data.push_back(42);
}

// [==========] Running 1 benchmark..
// [ RUN      ] vector.push_back (10 runs, 100 iterations per run)
// [     DONE ] vector.push_back (0.044323 ms)
// [   RUNS   ]        Average time: 4.432 us (~1.692 us)
//                     Fastest time: 3.222 us (-1.210 us / -27.306 %)
//                     Slowest time: 7.511 us (+3.079 us / +69.461 %)
//                      Median time: 3.582 us (1st quartile: 3.330 us ...

//              Average performance: 225616.49708 runs/s
//                 Best performance: 310366.23215 runs/s ...
//                Worst performance: 133138.06417 runs/s ...
//               Median performance: 279173.64601 runs/s ...

// [ITERATIONS]        Average time: 0.044 us (~0.017 us)
//                     Fastest time: 0.032 us (-0.012 us / -27.306 %)
//                     Slowest time: 0.075 us (+0.031 us / +69.461 %)
//                      Median time: 0.036 us (1st quartile: 0.033 us ...

//              Average performance: 22561649.70783 iterations/s
//                 Best performance: 31036623.21539 iterations/s ...
//                Worst performance: 13313806.41725 iterations/s ...
//               Median performance: 27917364.60078 iterations/s ...
// [==========] Ran 1 benchmark..

#endif
