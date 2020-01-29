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
    the_answer()
    {
        std::cout << "The answer is: ";
    }

    ~the_answer()
    {
        std::cout << "42\n";
    }
};

int main(void)
{
    the_answer is;
    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>
#include <stdexcept>

class the_answer
{
public:

    int *answer{};

    the_answer() :
        answer{new int}
    {
        *answer = 42;
    }

    ~the_answer()
    {
        std::cout << "The answer is: " << *answer << '\n';
        delete answer;
    }
};

int main(void)
{
    the_answer is;

    if (*is.answer == 42) {
        return 0;
    }

    return 1;
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

    int *answer{};

    the_answer() :
        answer{new int}
    {
        *answer = 43;
    }

    ~the_answer()
    {
        std::cout << "The answer is not: " << *answer << '\n';
        delete answer;
    }
};

void foo()
{
    the_answer is;

    if (*is.answer == 42) {
        return;
    }

    throw std::runtime_error("");
}

int main(void)
{
    try {
        foo();
    }
    catch(...)
    { }

    return 0;
}

// The answer is not: 43

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <iostream>
#include <stdexcept>

template<typename FUNC>
class finally
{
    FUNC m_func;

public:
    finally(FUNC func) :
        m_func{func}
    { }

    ~finally()
    {
        m_func();
    }
};

int main(void)
{
    auto execute_on_exit = finally{[]{
        std::cout << "The answer is: 42\n";
    }};
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <iostream>
#include <stdexcept>

template<typename FUNC>
class finally
{
    FUNC m_func;

public:
    finally(FUNC func) :
        m_func{func}
    { }

    ~finally()
    {
        m_func();
    }
};

int main(void)
{
    try {
        auto execute_on_exit = finally{[]{
            std::cout << "The answer is: 42\n";
        }};

        std::cout << "step 1: Collect answers\n";
        throw std::runtime_error("???");
        std::cout << "step 3: Profit\n";
    }
    catch (...)
    { }
}

// step 1: Collect answers
// The answer is: 42

#endif

#pragma GCC diagnostic pop
