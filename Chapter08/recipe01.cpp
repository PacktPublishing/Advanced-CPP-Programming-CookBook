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

#include <vector>
#include <algorithm>
#include <iostream>

template<
    typename T,
    typename Compare = std::less<T>,
    typename Allocator = std::allocator<T>
    >
class container
{
    using vector_type = std::vector<T, Allocator>;
    vector_type m_v;

public:

    using value_type = typename vector_type::value_type;
    using allocator_type = typename vector_type::allocator_type;
    using size_type = typename vector_type::size_type;
    using difference_type = typename vector_type::difference_type;
    using reference = typename vector_type::reference;
    using const_reference = typename vector_type::const_reference;
    using pointer = typename vector_type::pointer;
    using const_pointer = typename vector_type::const_pointer;
    using compare_type = Compare;

public:

    container() noexcept(noexcept(Allocator()))
    {
        std::cout << "1\n";
    }

    explicit container(
        const Allocator &alloc
    ) noexcept :
        m_v(alloc)
    {
        std::cout << "2\n";
    }

    container(
        size_type count,
        const T &value,
        const Allocator &alloc = Allocator()
    ) :
        m_v(count, value, alloc)
    {
        std::cout << "3\n";
    }

    explicit container(
        size_type count,
        const Allocator &alloc = Allocator()
    ) :
        m_v(count, alloc)
    {
        std::cout << "4\n";
    }

    container(
        const container &other,
        const Allocator &alloc
    ) :
        m_v(other.m_v, alloc)
    {
        std::cout << "5\n";
    }

    container(
        container &&other
    ) noexcept :
        m_v(std::move(other.m_v))
    {
        std::cout << "6\n";
    }

    container(
        container &&other,
        const Allocator &alloc
    ) :
        m_v(std::move(other.m_v), alloc)
    {
        std::cout << "7\n";
    }

    container(
        std::initializer_list<T> init,
        const Allocator &alloc = Allocator()
    ) :
        m_v(init, alloc)
    {
        std::sort(m_v.begin(), m_v.end(), compare_type());
        std::cout << "8\n";
    }
};

int main(void)
{
    auto alloc = std::allocator<int>();

    container<int> c1;
    container<int> c2(alloc);
    container<int> c3(42, 42);
    container<int> c4(42);
    container<int> c5(c1, alloc);
    container<int> c6(std::move(c1));
    container<int> c7(std::move(c2), alloc);
    container<int> c8{4, 42, 15, 8, 23, 16};

    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <vector>
#include <algorithm>
#include <iostream>

template<
    typename T,
    typename Compare = std::less<T>,
    typename Allocator = std::allocator<T>
    >
class container
{
    using vector_type = std::vector<T, Allocator>;
    vector_type m_v;

public:

    using value_type = typename vector_type::value_type;
    using allocator_type = typename vector_type::allocator_type;
    using size_type = typename vector_type::size_type;
    using difference_type = typename vector_type::difference_type;
    using reference = typename vector_type::reference;
    using const_reference = typename vector_type::const_reference;
    using pointer = typename vector_type::pointer;
    using const_pointer = typename vector_type::const_pointer;
    using compare_type = Compare;

public:

    container() noexcept(noexcept(Allocator())) = default;

    explicit container(
        const Allocator &alloc
    ) noexcept :
        m_v(alloc)
    { }

    container(
        size_type count,
        const T &value,
        const Allocator &alloc = Allocator()
    ) :
        m_v(count, value, alloc)
    { }

    explicit container(
        size_type count,
        const Allocator &alloc = Allocator()
    ) :
        m_v(count, alloc)
    { }

    container(
        const container &other,
        const Allocator &alloc
    ) :
        m_v(other.m_v, alloc)
    { }

    container(
        container &&other
    ) noexcept :
        m_v(std::move(other.m_v))
    { }

    container(
        container &&other,
        const Allocator &alloc
    ) :
        m_v(std::move(other.m_v), alloc)
    { }

    container(
        std::initializer_list<T> init,
        const Allocator &alloc = Allocator()
    ) :
        m_v(init, alloc)
    {
        std::sort(m_v.begin(), m_v.end(), compare_type());
    }

public:

    void push_back(const T &value)
    {
        m_v.push_back(value);
        std::sort(m_v.begin(), m_v.end(), compare_type());

        std::cout << "1\n";
    }

    void push_back(T &&value)
    {
        m_v.push_back(std::move(value));
        std::sort(m_v.begin(), m_v.end(), compare_type());

        std::cout << "2\n";
    }

    template<typename... Args>
    void emplace_back(Args&&... args)
    {
        m_v.emplace_back(std::forward<Args>(args)...);
        std::sort(m_v.begin(), m_v.end(), compare_type());

        std::cout << "3\n";
    }
};

int main(void)
{
    int i = 42;
    container<int> c;

    c.push_back(i);
    c.push_back(std::move(i));
    c.emplace_back(42);

    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <vector>
#include <algorithm>
#include <iostream>

template<
    typename T,
    typename Compare = std::less<T>,
    typename Allocator = std::allocator<T>
    >
class container
{
    using vector_type = std::vector<T, Allocator>;
    vector_type m_v;

    void dump()
    {
        std::cout << "elements: ";
        for (const auto &elem : m_v) {
            std::cout << elem << ' ';
        }

        std::cout << '\n';
    }

public:

    using value_type = typename vector_type::value_type;
    using allocator_type = typename vector_type::allocator_type;
    using size_type = typename vector_type::size_type;
    using difference_type = typename vector_type::difference_type;
    using reference = typename vector_type::reference;
    using const_reference = typename vector_type::const_reference;
    using pointer = typename vector_type::pointer;
    using const_pointer = typename vector_type::const_pointer;
    using compare_type = Compare;

public:

    container() noexcept(noexcept(Allocator())) = default;

    explicit container(
        const Allocator &alloc
    ) noexcept :
        m_v(alloc)
    { }

    container(
        size_type count,
        const T &value,
        const Allocator &alloc = Allocator()
    ) :
        m_v(count, value, alloc)
    { }

    explicit container(
        size_type count,
        const Allocator &alloc = Allocator()
    ) :
        m_v(count, alloc)
    { }

    container(
        const container &other,
        const Allocator &alloc
    ) :
        m_v(other.m_v, alloc)
    { }

    container(
        container &&other
    ) noexcept :
        m_v(std::move(other.m_v))
    { }

    container(
        container &&other,
        const Allocator &alloc
    ) :
        m_v(std::move(other.m_v), alloc)
    { }

    container(
        std::initializer_list<T> init,
        const Allocator &alloc = Allocator()
    ) :
        m_v(init, alloc)
    {
        std::sort(m_v.begin(), m_v.end(), compare_type());
    }

public:

    void push_back(const T &value)
    {
        m_v.push_back(value);
        std::sort(m_v.begin(), m_v.end(), compare_type());

        dump();
    }

    void push_back(T &&value)
    {
        m_v.push_back(std::move(value));
        std::sort(m_v.begin(), m_v.end(), compare_type());

        dump();
    }

    template<typename... Args>
    void emplace_back(Args&&... args)
    {
        m_v.emplace_back(std::forward<Args>(args)...);
        std::sort(m_v.begin(), m_v.end(), compare_type());

        std::cout << "3\n";
    }
};

int main(void)
{
    int i = 42;
    container<int> c;

    c.emplace_back(4);
    c.push_back(i);
    c.emplace_back(15);
    c.push_back(8);
    c.emplace_back(23);
    c.push_back(std::move(16));

    return 0;
}

#endif
