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

int main(void)
{
    int n = 42;
    int d = 0;

    auto f = n/d;
}

// /home/user/book/chapter07/recipe03.cpp:30:15: runtime error: division by zero
// Floating point exception (core dumped)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

int main(void)
{
    int *p = 0;
    *p = 42;
}

// /home/user/book/chapter07/recipe03.cpp:44:8: runtime error: store to null pointer of type 'int'
// Segmentation fault (core dumped)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

int main(void)
{
    int numbers[] = {4, 8, 15, 16, 23, 42};
    numbers[10] = 0;
}

// /home/user/book/chapter07/recipe03.cpp:58:15: runtime error: index 10 out of bounds for type 'int [6]'
// /home/user/book/chapter07/recipe03.cpp:58:17: runtime error: store to address 0x7ffe75e7a0c8 with insufficient space for an object of type 'int'
// 0x7ffe75e7a0c8: note: pointer points here
// 00 00 00 00 33 df e9 73 49 7f 00 00 68 ff ff ff ff ff ff ff a8 a1 e7 75 fe 7f 00 00 60 0b cf 74

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <climits>

int main(void)
{
    int i = INT_MAX;
    i++;
}

// /home/user/book/chapter07/recipe03.cpp:76:6: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int'

#endif
