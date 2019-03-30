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
#ifndef EXAMPLE02

#include <iostream>
#include "abseil-cpp-20181200/absl/strings/numbers.h"

int main(void)
{
    int answer;
    (void) absl::SimpleAtoi("42", &answer);

    std::cout << "The answer is: " << answer << '\n';
    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>
#include "abseil-cpp-20181200/absl/time/clock.h"

int main(void)
{
    std::cout << "Time: " << absl::Now() << '\n';
    return 0;
}

// Time: 2019-03-30T14:12:27.423875045-06:00

#endif

