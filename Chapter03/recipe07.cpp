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
        std::cout << "The answer is: " << *m_answer << '\n';
    }

public:

    the_answer(the_answer &&other) noexcept = default;
    the_answer &operator=(the_answer &&other) noexcept = default;
};

int main(void)
{
    the_answer is_42{42};
    the_answer is_what{42};

    is_what = std::move(is_42);
    return 0;
}

// The answer is: 42
// Segmentation fault (core dumped)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

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
        std::cout << "The answer is: " << *m_answer << '\n';
    }

public:

    the_answer(the_answer &&other) noexcept = delete;
    the_answer &operator=(the_answer &&other) noexcept = delete;

    the_answer(const the_answer &other) = delete;
    the_answer &operator=(const the_answer &other) = delete;
};

int main(void)
{
    the_answer is_42{42};
    the_answer is_what{42};

    is_what = std::move(is_42);
    return 0;
}

// /home/user/book/chapter03/recipe07.cpp: In function ‘int main()’:
// /home/user/book/chapter03/recipe07.cpp:106:30: error: use of deleted function ‘the_answer& the_answer::operator=(the_answer&&)’
//      is_what = std::move(is_42);
//                               ^
// /home/user/book/chapter03/recipe07.cpp:95:17: note: declared here
//      the_answer &operator=(the_answer &&other) noexcept = delete;
//                  ^~~~~~~~

#endif
