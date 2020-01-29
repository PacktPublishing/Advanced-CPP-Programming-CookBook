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

#include <iostream>

int sub(int a, int b)
{ return a + b; }

int main(void)
{
    std::cout << "The answer is: " << sub(41, 1) << '\n';
    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>

void add(int a, int &b)
{ b += a; }

int main(void)
{
    int a = 41, b = 1;
    add(a, b);

    std::cout << "The answer is: " << b << '\n';
    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <iostream>

int add(int a, int b)
{ return a + b; }

int main(void)
{
    std::cout << "The answer is: " << add(41, 1) << '\n';
    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <stdio.h>
#include <iostream>

int main(void)
{
    printf("The answer is: %d\n", 42);
    std::cout << "The answer is: " << 42 << '\n';
    return 0;
}

// The answer is: 42
// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <iostream>

int main(void)
{
    auto answer = 41;

    std::cout << "The answer is: " << ++answer << '\n';
    std::cout << "The answer is: " << answer++ << '\n';

    return 0;
}

// The answer is: 42
// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE06

#include <iostream>

int add(int a, int b)
{ return a + b; }

int Sub(int a, int b)
{ return a - b; }

int main(void)
{
    std::cout << "The answer is: " << add(41, 1) << '\n';
    std::cout << "The answer is: " << Sub(43, 1) << '\n';

    return 0;
}

// The answer is: 42
// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE07

#include <queue>
#include <iostream>

int main(void)
{
    std::queue<int> my_queue;

    my_queue.emplace(42);
    std::cout << "The answer is: " << my_queue.front() << '\n';
    my_queue.pop();

    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE08

#include <iostream>

auto add(int a, int b)
{ return a + b; }

int main(void)
{
    std::cout << "The answer is: " << add(41, 1) << '\n';
    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE09

#include <iostream>

template <typename T>
T add(T a, T b)
{ return a + b; }

int main(void)
{
    std::cout << "The answer is: " << add(41, 1) << '\n';
    return 0;
}

// The answer is: 42

#endif
