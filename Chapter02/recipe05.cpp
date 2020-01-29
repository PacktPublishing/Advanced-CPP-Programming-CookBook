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

class the_answer : public std::exception
{
public:
    the_answer() = default;
    const char *what() const noexcept
    {
        return "The answer is: 42";
    }
};

int main(void)
{
    try {
        throw the_answer{};
    }
    catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>
#include <stdexcept>

class the_answer : public std::exception
{
    const char *m_str;
public:

    the_answer(const char *str) :
        m_str{str}
    { }

    const char *what() const noexcept
    {
        return m_str;
    }
};

int main(void)
{
    try {
        throw the_answer("42");
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
#include <string.h>

class the_answer : public std::runtime_error
{
public:
    explicit the_answer(const char *str) :
        std::runtime_error{str}
    { }
};

int main(void)
{
    try {
        throw the_answer("42");
    }
    catch (const the_answer &e) {
        std::cout << "The answer is: " << e.what() << '\n';
    }
    catch (const std::exception &e) {
        std::cout << "unknown exception: " << e.what() << '\n';
    }
}

// The answer is: 42

#endif

#pragma GCC diagnostic pop
