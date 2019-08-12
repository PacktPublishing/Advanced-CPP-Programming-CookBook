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

struct the_answer_noexcept
{
    the_answer_noexcept() = default;

    the_answer_noexcept(const the_answer_noexcept &is) noexcept
    {
        std::cout << "l-value\n";
    }

    the_answer_noexcept(the_answer_noexcept &&is) noexcept
    {
        std::cout << "r-value\n";
    }
};

struct the_answer_can_throw
{
    the_answer_can_throw() = default;

    the_answer_can_throw(const the_answer_can_throw &is)
    {
        std::cout << "l-value\n";
    }

    the_answer_can_throw(the_answer_can_throw &&is)
    {
        std::cout << "r-value\n";
    }
};

int main(void)
{
    the_answer_noexcept is1;
    the_answer_can_throw is2;

    std::cout << "noexcept: ";
    auto is3 = std::move_if_noexcept(is1);

    std::cout << "can throw: ";
    auto is4  = std::move_if_noexcept(is2);

    return 0;
}

// noexcept: r-value
// can throw: l-value

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <memory>
#include <iostream>
#include <stdexcept>

template<typename T>
class mock_vector
{
public:
    using size_type = std::size_t;

    mock_vector(size_type s) :
        m_size{s},
        m_buffer{std::make_unique<T[]>(m_size)}
    { }

    void resize(size_type size)
        noexcept(std::is_nothrow_move_constructible_v<T>)
    {
        auto tmp = std::make_unique<T[]>(size);

        for (size_type i = 0; i < m_size; i++) {
            tmp[i] = std::move_if_noexcept(m_buffer[i]);
        }

        m_size = size;
        m_buffer = std::move(tmp);
    }

private:
    size_type m_size{};
    std::unique_ptr<T[]> m_buffer{};
};

struct suboptimal
{
    suboptimal() = default;

    suboptimal(suboptimal &&other)
    {
        *this = std::move(other);
    }

    suboptimal &operator=(suboptimal &&)
    {
        std::cout << "move\n";
        return *this;
    }

    suboptimal(const suboptimal &other)
    {
        *this = other;
    }

    suboptimal &operator=(const suboptimal &)
    {
        std::cout << "copy\n";
        return *this;
    }
};

struct optimal
{
    optimal() = default;

    optimal(optimal &&other) noexcept
    {
        *this = std::move(other);
    }

    optimal &operator=(optimal &&) noexcept
    {
        std::cout << "move\n";
        return *this;
    }

    optimal(const optimal &other)
    {
        *this = other;
    }

    optimal &operator=(const optimal &)
    {
        std::cout << "copy\n";
        return *this;
    }
};

int main(void)
{
    mock_vector<optimal> d1(5);
    mock_vector<suboptimal> d2(5);

    d1.resize(10);
    std::cout << "--------------\n";
    d2.resize(10);

    return 0;
}

// move
// move
// move
// move
// move
// --------------
// copy
// copy
// copy
// copy
// copy

#endif
