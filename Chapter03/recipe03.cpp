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

#include <memory>
#include <iostream>

class the_answer
{
    std::unique_ptr<int> m_answer;

public:

    explicit the_answer(int answer) :
        m_answer{std::make_unique<int>(answer)}
    { }

    ~the_answer()
    {
        if (m_answer) {
            std::cout << "The answer is: " << *m_answer << '\n';
        }
    }

public:

    the_answer(the_answer &&other) noexcept
    {
        *this = std::move(other);
    }

    the_answer &operator=(the_answer &&other) noexcept
    {
        m_answer = std::move(other.m_answer);
        return *this;
    }
};

int main(void)
{
    the_answer is_42{42};
    the_answer is = std::move(is_42);

    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <memory>
#include <iostream>

class the_answer
{
    std::unique_ptr<int> m_answer;

public:

    the_answer() = default;

    explicit the_answer(int answer) :
        m_answer{std::make_unique<int>(answer)}
    { }

    ~the_answer()
    {
        if (m_answer) {
            std::cout << "The answer is: " << *m_answer << '\n';
        }
    }

public:

    the_answer(the_answer &&other) noexcept
    {
        *this = std::move(other);
    }

    the_answer &operator=(the_answer &&other) noexcept
    {
        m_answer = std::move(other.m_answer);
        return *this;
    }

public:

    the_answer(const the_answer &) = default;
    the_answer &operator=(const the_answer &) = default;
};

int main(void)
{
    the_answer is_42{42};
    the_answer is = is_42;

    return 0;
}

// /home/rianquinn/book/chapter03/recipe03.cpp:111:5: note: ‘the_answer::the_answer(const the_answer&)’ is implicitly deleted because the default definition would be ill-formed:
//   111 |     the_answer(const the_answer &) = default;
//       |     ^~~~~~~~~~

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <memory>
#include <iostream>

class the_answer
{
    std::shared_ptr<int> m_answer;

public:

    the_answer() = default;

    explicit the_answer(int answer) :
        m_answer{std::make_shared<int>(answer)}
    { }

    ~the_answer()
    {
        if (m_answer) {
            std::cout << "The answer is: " << *m_answer << '\n';
        }
    }

    auto use_count()
    { return m_answer.use_count(); }

public:

    the_answer(the_answer &&other) noexcept
    {
        *this = std::move(other);
    }

    the_answer &operator=(the_answer &&other) noexcept
    {
        m_answer = std::move(other.m_answer);
        return *this;
    }

    the_answer(const the_answer &other)
    {
        *this = other;
    }

    the_answer &operator=(const the_answer &other)
    {
        m_answer = other.m_answer;
        return *this;
    }
};

int main(void)
{
    {
        the_answer is_42{42};
        the_answer is = is_42;
        std::cout << "count: " << is.use_count() << '\n';
    }

    std::cout << '\n';

    {
        the_answer is_42{42};
        the_answer is = std::move(is_42);
        std::cout << "count: " << is.use_count() << '\n';
    }

    return 0;
}

// count: 2
// The answer is: 42
// The answer is: 42

// count: 1
// The answer is: 42

#endif

