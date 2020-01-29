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

public:

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

    template<typename... Args>
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

public:

    container &operator=(const container &other)
    {
        m_v = other.m_v;
        return *this;
    }

    container &operator=(container &&other) noexcept
    {
        m_v = std::move(other.m_v);
        return *this;
    }

    container &operator=(std::initializer_list<T> list)
    {
        m_v = list;
        std::sort(m_v.begin(), m_v.end(), compare_type());

        return *this;
    }

    void assign(size_type count, const T &value)
    {
        m_v.assign(count, value);
    }

    template <typename Iter>
    void assign(Iter first, Iter last)
    {
        m_v.assign(first, last);
        std::sort(m_v.begin(), m_v.end(), compare_type());
    }

    void assign(std::initializer_list<T> list)
    {
        m_v.assign(list);
        std::sort(m_v.begin(), m_v.end(), compare_type());
    }

    allocator_type get_allocator() const
    {
        return m_v.get_allocator();
    }

    const_reference at(size_type pos) const
    {
        return m_v.at(pos);
    }

	const_reference front() const
    {
        return m_v.front();
    }

	const_reference back() const
    {
        return m_v.back();
    }

    const T* data() const noexcept
    {
        return m_v.data();
    }

    bool empty() const noexcept
    {
        return m_v.empty();
    }

    size_type size() const noexcept
    {
        return m_v.size();
    }

    size_type max_size() const noexcept
    {
        return m_v.max_size();
    }

    void reserve(size_type new_cap)
    {
        m_v.reserve(new_cap);
    }

	size_type capacity() const noexcept
    {
        return m_v.capacity();
    }

    void shrink_to_fit()
    {
        m_v.shrink_to_fit();
    }

    void clear() noexcept
    {
        m_v.clear();
    }

    void pop_back()
    {
        m_v.pop_back();
    }

    void resize(size_type count)
    {
        m_v.resize(count);
    }

    void resize(size_type count, const value_type &value)
    {
        m_v.resize(count, value);
    }

    void swap(container &other) noexcept
    {
        m_v.swap(other.m_v);
    }

public:

    template <typename O, typename Alloc>
    friend bool operator==(const container<O, Alloc> &lhs,
                           const container<O, Alloc> &rhs);

    template <typename O, typename Alloc>
    friend bool operator!=(const container<O, Alloc> &lhs,
                           const container<O, Alloc> &rhs);

    template <typename O, typename Alloc>
    friend bool operator<(const container<O, Alloc> &lhs,
                          const container<O, Alloc> &rhs);

    template <typename O, typename Alloc>
    friend bool operator<=(const container<O, Alloc> &lhs,
                           const container<O, Alloc> &rhs);

    template <typename O, typename Alloc>
    friend bool operator>(const container<O, Alloc> &lhs,
                          const container<O, Alloc> &rhs);

    template <typename O, typename Alloc>
    friend bool operator>=(const container<O, Alloc> &lhs,
                           const container<O, Alloc> &rhs);
};

template <typename O, typename Alloc>
bool operator==(const container<O, Alloc> &lhs,
                const container<O, Alloc> &rhs)
{
    return lhs.m_v == rhs.m_v;
}

template <typename O, typename Alloc>
bool operator!=(const container<O, Alloc> &lhs,
                const container<O, Alloc> &rhs)
{
    return lhs.m_v != rhs.m_v;
}

template <typename O, typename Alloc>
bool operator<(const container<O, Alloc> &lhs,
               const container<O, Alloc> &rhs)
{
    return lhs.m_v < rhs.m_v;
}

template <typename O, typename Alloc>
bool operator<=(const container<O, Alloc> &lhs,
                const container<O, Alloc> &rhs)
{
    return lhs.m_v <= rhs.m_v;
}

template <typename O, typename Alloc>
bool operator>(const container<O, Alloc> &lhs,
               const container<O, Alloc> &rhs)
{
    return lhs.m_v > rhs.m_v;
}

template <typename O, typename Alloc>
bool operator>=(const container<O, Alloc> &lhs,
                const container<O, Alloc> &rhs)
{
    return lhs.m_v >= rhs.m_v;
}

int main(void)
{
    container<int> c1{4, 42, 15, 8, 23, 16};

    // -------------------------------------------------------------------------

    container<int> c2;
    c2 = c1;
    c2.dump();

    container<int> c3;
    c3 = std::move(c2);
    c3.dump();

    container<int> c4;
    c4 = {4, 42, 15, 8, 23, 16};
    c4.dump();

    // -------------------------------------------------------------------------

    container<int> c5;
    c5.assign(1, 42);
    c5.dump();

    container<int> c6;
    c6.assign(c1.cbegin(), c1.cend());
    c6.dump();

    container<int> c7;
    c7.assign({4, 42, 15, 8, 23, 16});
    c7.dump();

    // -------------------------------------------------------------------------

    std::cout << "c1.at(0): " << c1.at(0) << '\n';
    std::cout << "c1.front(): " << c1.front() << '\n';
    std::cout << "c1.back(): " << c1.back() << '\n';
    std::cout << "c1.data(): " << c1.data() << '\n';

    // -------------------------------------------------------------------------

    std::cout << "c1.empty(): " << c1.empty() << '\n';
    std::cout << "c1.size(): " << c1.size() << '\n';
    std::cout << "c1.max_size(): " << c1.max_size() << '\n';

    // -------------------------------------------------------------------------

    c1.reserve(42);
    std::cout << "c1.capacity(): " << c1.capacity() << '\n';
    c1.shrink_to_fit();
    std::cout << "c1.capacity(): " << c1.capacity() << '\n';

    // -------------------------------------------------------------------------

    c1.clear();
    std::cout << "c1.size(): " << c1.size() << '\n';
    c1.resize(42);
    std::cout << "c1.size(): " << c1.size() << '\n';

    c1.clear();
    std::cout << "c1.size(): " << c1.size() << '\n';
    c1.resize(42, 42);
    std::cout << "c1.size(): " << c1.size() << '\n';

    // -------------------------------------------------------------------------

    c1.swap(c4);
    c1.pop_back();
    c1.dump();

    // -------------------------------------------------------------------------

    std::cout << "==: " << (c1 == c4) << '\n';
    std::cout << "!=: " << (c1 != c4) << '\n';
    std::cout << " <: " << (c1 < c4) << '\n';
    std::cout << "<=: " << (c1 <= c4) << '\n';
    std::cout << " >: " << (c1 > c4) << '\n';
    std::cout << ">=: " << (c1 >= c4) << '\n';

    // -------------------------------------------------------------------------

    return 0;
}

#endif
