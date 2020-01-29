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

#include <vector>
#include <iostream>

class the_answer
{
    std::vector<int> m_answer;

public:

    the_answer() = default;

    explicit the_answer(int answer) :
        m_answer{{answer}}
    { }

    ~the_answer()
    {
        if (!m_answer.empty()) {
            std::cout << "The answer is: " << m_answer.at(0) << '\n';
        }
    }

public:

    the_answer(the_answer &&other) noexcept
    {
        *this = std::move(other);
    }

    the_answer &operator=(the_answer &&other) noexcept
    {
        try {
            m_answer.emplace(m_answer.begin(), other.m_answer.at(0));
            other.m_answer.erase(other.m_answer.begin());
        }
        catch(...) {
            std::cout << "failed to move\n";
        }

        return *this;
    }
};

int main(void)
{
    {
        the_answer is_42{};
        the_answer is_what{};

        is_what = std::move(is_42);
    }

    std::cout << '\n';

    {
        the_answer is_42{42};
        the_answer is_what{};

        is_what = std::move(is_42);
    }

    return 0;
}

// failed to move
// The answer is not: 0
// The answer is not: 0

// The answer is: 42
// The answer is not: 0

#endif
