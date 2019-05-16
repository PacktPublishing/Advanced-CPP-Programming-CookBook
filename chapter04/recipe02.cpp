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

#include <iostream>

struct the_answer
{ };

void foo2(const the_answer &is)
{
    std::cout << "l-value\n";
}

void foo2(the_answer &&is)
{
    std::cout << "r-value\n";
}

template<typename T>
void foo1(T &&t)
{
    foo2(t);
}

int main(void)
{
    the_answer is;
    foo1(is);
    foo1(the_answer());

    return 0;
}

// l-value
// l-value

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>

struct the_answer
{ };

void foo2(const the_answer &is)
{
    std::cout << "l-value\n";
}

void foo2(the_answer &&is)
{
    std::cout << "r-value\n";
}

template<typename T>
void foo1(T &&t)
{
    foo2(std::forward<T>(t));
}

int main(void)
{
    the_answer is;
    foo1(is);
    foo1(the_answer());

    return 0;
}

// l-value
// r-value

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <iostream>

struct the_answer
{ };

void foo2(const the_answer &is, int i)
{
    std::cout << "l-value: " << i << '\n';
}

void foo2(the_answer &&is, int i)
{
    std::cout << "r-value: " << i << '\n';
}

template<typename... Args>
void foo1(Args &&...args)
{
    foo2(std::forward<Args>(args)...);
}

int main(void)
{
    the_answer is;
    foo1(is, 42);
    foo1(the_answer(), 42);

    return 0;
}

// l-value
// r-value

#endif
