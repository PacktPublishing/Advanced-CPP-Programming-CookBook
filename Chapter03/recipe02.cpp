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

class the_answer
{
    int m_answer{42};

public:

    the_answer() = default;

public:

    ~the_answer()
    {
        std::cout << "The answer is: " << m_answer << '\n';
    }
};

int main(void)
{
    the_answer is;
    return 0;
}

// The answer is: 42

#endif

// the_answer(the_answer &&other) noexcept;
// the_answer &operator=(the_answer &&other) noexcept;

// instance2 = std::move(instance1);

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>

class the_answer
{
    int m_answer{};

public:

    the_answer() = default;

    explicit the_answer(int answer) :
        m_answer{answer}
    { }

public:

    ~the_answer()
    {
        if (m_answer != 0) {
            std::cout << "The answer is: " << m_answer << '\n';
        }
    }

    the_answer(the_answer &&other) noexcept
    {
        *this = std::move(other);
    }

    the_answer &operator=(the_answer &&other) noexcept
    {
        if (&other == this) {
            return *this;
        }

        m_answer = std::move(other.m_answer);
        other.m_answer = 0;

        return *this;
    }

    the_answer(const the_answer &) = default;
    the_answer &operator=(const the_answer &) = default;
};

int main(void)
{
    {
        the_answer is;
        the_answer is_42{42};
        is = is_42;
    }

    std::cout << '\n';

    {
        the_answer is;
        the_answer is_42{42};
        is = std::move(is_42);
    }

    return 0;
}

// The answer is: 42
// The answer is: 42

// The answer is: 42

#endif
