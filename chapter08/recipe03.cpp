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

template <
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

private:

    void push_back(const T &value)
    {
        m_v.push_back(value);
        std::sort(m_v.begin(), m_v.end(), compare_type());
    }

    void push_back(T &&value)
    {
        m_v.push_back(std::move(value));
        std::sort(m_v.begin(), m_v.end(), compare_type());
    }

    template<typename... Args>
    void emplace_back(Args&&... args)
    {
        m_v.emplace_back(std::forward<Args>(args)...);
        std::sort(m_v.begin(), m_v.end(), compare_type());
    }

public:

    void insert(const T &value)
    {
        return push_back(value);
    }

    void insert(T &&value)
    {
        return push_back(std::move(value));
    }

    template <typename... Args>
    reference emplace(Args&&... args)
    {
        return emplace_back(std::forward<Args>(args)...);
    }

public:

    template <typename Iter>
    container(
        Iter first,
        Iter last,
        const Allocator &alloc = Allocator()
    ) :
        m_v(first, last, alloc)
    {
        std::sort(m_v.begin(), m_v.end(), compare_type());
        dump();
    }
};

int main(void)
{
    std::vector<int> v{4, 42, 15, 8, 23, 16};
    container<int> c{v.cbegin(), v.cend()};

    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <vector>
#include <algorithm>
#include <iostream>

template <
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

private:

    void push_back(const T &value)
    {
        m_v.push_back(value);
        std::sort(m_v.begin(), m_v.end(), compare_type());
    }

    void push_back(T &&value)
    {
        m_v.push_back(std::move(value));
        std::sort(m_v.begin(), m_v.end(), compare_type());
    }

    template<typename... Args>
    void emplace_back(Args&&... args)
    {
        m_v.emplace_back(std::forward<Args>(args)...);
        std::sort(m_v.begin(), m_v.end(), compare_type());
    }

public:

    void insert(const T &value)
    {
        push_back(value);
    }

    void insert(T &&value)
    {
        push_back(std::move(value));
    }

    template <typename... Args>
    void emplace(Args&&... args)
    {
        emplace_back(std::forward<Args>(args)...);
    }

public:

    template <typename Iter>
    container(
        Iter first,
        Iter last,
        const Allocator &alloc = Allocator()
    ) :
        m_v(first, last, alloc)
    {
        std::sort(m_v.begin(), m_v.end(), compare_type());
    }

public:

    using const_iterator = typename vector_type::const_iterator;
    using const_reverse_iterator = typename vector_type::const_reverse_iterator;

    const_iterator begin() const noexcept
    {
        return m_v.begin();
    }

    const_iterator cbegin() const noexcept
    {
        return m_v.cbegin();
    }

    const_iterator end() const noexcept
    {
        return m_v.end();
    }

    const_iterator cend() const noexcept
    {
        return m_v.cend();
    }

    const_reverse_iterator rbegin() const noexcept
    {
        return m_v.crbegin();
    }

    const_reverse_iterator crbegin() const noexcept
    {
        return m_v.crbegin();
    }

    const_reverse_iterator rend() const noexcept
    {
        return m_v.crend();
    }

    const_reverse_iterator crend() const noexcept
    {
        return m_v.crend();
    }

    template <typename... Args>
    void emplace(const_iterator pos, Args&&... args)
    {
        m_v.emplace(pos, std::forward<Args>(args)...);
        std::sort(m_v.begin(), m_v.end(), compare_type());
    }

    const_iterator erase(const_iterator pos)
    {
        return m_v.erase(pos);
    }

    const_iterator erase(const_iterator first, const_iterator last)
    {
        return m_v.erase(first, last);
    }
};

int main(void)
{
    container<int> c{4, 42, 15, 8, 23, 16};

    // -------------------------------------------------------------------------

    std::cout << "elements: ";
    for (const auto &elem : c) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    // -------------------------------------------------------------------------

    std::cout << "elements: ";
    for (auto iter = c.cbegin(); iter != c.cend(); iter++) {
        std::cout << *iter << ' ';
    }
    std::cout << '\n';

    // -------------------------------------------------------------------------

    std::cout << "elements: ";
    for (auto iter = c.crbegin(); iter != c.crend(); iter++) {
        std::cout << *iter << ' ';
    }
    std::cout << '\n';

    // -------------------------------------------------------------------------

    c.emplace(c.cend(), 1);

    std::cout << "elements: ";
    for (const auto &elem : c) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    c.erase(c.cbegin());

    std::cout << "elements: ";
    for (const auto &elem : c) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    // -------------------------------------------------------------------------

    c.erase(c.cbegin(), c.cend());

    std::cout << "elements: ";
    for (const auto &elem : c) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    // -------------------------------------------------------------------------

    return 0;
}

#endif
