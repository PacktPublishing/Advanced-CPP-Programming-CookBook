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

int main(void)
{
    std::cout << "Hello World\n";
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

import std.core;

int main(void)
{
    std::cout << "Hello World\n";
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <string>

template<size_t number>
class the_answer
{
public:
    auto operator()() const
    {
        return "The answer is: " + std::to_string(number);
    }
};

#define CHECK(a) (a() == "The answer is: 42")

#include <iostream>
// #include "header.h"

int main(void)
{
    the_answer<42> is;
    std::cout << is() << '\n';
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

import std.string;
export module answers;

export
template<size_t number>
class the_answer
{
public:
    auto operator()() const
    {
        return "The answer is: " + std::to_string(number);
    }
};

#define CHECK(a) (a() == "The answer is: 42")

import answers;
import std.core;

int main(void)
{
    the_answer<42> is;
    std::cout << is() << '\n';
}

#endif
