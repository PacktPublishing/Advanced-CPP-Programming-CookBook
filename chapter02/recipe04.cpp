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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wterminate"

// -----------------------------------------------------------------------------
#ifdef EXAMPLE01

#include <iostream>
#include <stdexcept>

class the_answer
{
public:
    ~the_answer()
    {
        throw std::runtime_error("42");
    }
};

int main(void)
{
    try {
        the_answer is;
    }
    catch (const std::exception &e) {
        std::cout << "The answer is: " << e.what() << '\n';
    }
}

// terminate called after throwing an instance of 'std::runtime_error'
//   what():  42
// Aborted (core dumped)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>
#include <stdexcept>

class the_answer
{
public:
    ~the_answer() noexcept(false)
    {
        throw std::runtime_error("42");
    }
};

int main(void)
{
    try {
        the_answer is;
    }
    catch (const std::exception &e) {
        std::cout << "The answer is: " << e.what() << '\n';
    }
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <iostream>
#include <stdexcept>

class the_answer
{
public:
    ~the_answer() noexcept(false)
    {
        throw std::runtime_error("42");
    }
};

int main(void)
{
    try {
        the_answer is;
        throw std::runtime_error("first exception");
    }
    catch (const std::exception &e) {
        std::cout << "The answer is: " << e.what() << '\n';
    }
}

// terminate called after throwing an instance of 'std::runtime_error'
//   what():  42
// Aborted (core dumped)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <iostream>
#include <stdexcept>

class the_answer
{
public:
    ~the_answer() noexcept(false)
    {
        if (std::uncaught_exceptions() > 0) {
            std::cout << "unable to throw 42\n";
            return;
        }

        throw std::runtime_error("42");
    }
};

int main(void)
{
    try {
        the_answer is;
        throw std::runtime_error("first exception");
    }
    catch (const std::exception &e) {
        std::cout << "The answer is: " << e.what() << '\n';
    }
}

// unable to throw 42
// The answer is: first exception

#endif

#pragma GCC diagnostic pop
