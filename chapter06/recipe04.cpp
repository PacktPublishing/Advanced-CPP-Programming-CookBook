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

void foo1()
{
    throw 42;
}

void foo2()
{
    throw 42;
}

void foo42()
{
    foo1();
    foo2();
}

int main(void)
{
    try {
        foo42();
    }
    catch (...) {
    }
}

// > readelf -SW ./recipe04_example01 | grep .gcc_except_table
//   [18] .gcc_except_table PROGBITS        00000000004021d0 0021d0 000014 00   A  0   0  4

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

void foo1()
{
    throw 42;
}

void foo2()
{
    throw 42;
}

void foo42() noexcept
{
    foo1();
    foo2();
}

int main(void)
{
    try {
        foo42();
    }
    catch (...) {
    }
}

// > readelf -SW ./recipe04_example02 | grep .gcc_except_table
//   [18] .gcc_except_table PROGBITS        00000000004021d0 0021d0 000004 00   A  0   0  1

#endif
