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

uint8_t memory[0x1000] = {};

class mm
{
    uint8_t *cursor{memory};

public:
    mm() = default;

    template<typename T>
    T *allocate()
    {
        if (cursor + sizeof(T) > memory + 0x1000) {
            throw std::bad_alloc();
        }

        auto ptr = new (cursor) T;
        cursor += sizeof(T);

        return ptr;
    }
};

mm g_mm;

int main(void)
{
    auto i1 = g_mm.allocate<int>();
    auto i2 = g_mm.allocate<int>();
    auto i3 = g_mm.allocate<int>();
    auto i4 = g_mm.allocate<int>();

    std::cout << "memory: " << (void *)memory << '\n';
    std::cout << "i1: " << (void *)i1 << '\n';
    std::cout << "i2: " << (void *)i2 << '\n';
    std::cout << "i3: " << (void *)i3 << '\n';
    std::cout << "i4: " << (void *)i4 << '\n';
}

// memory: 0x4041a0
// i1: 0x4041a0
// i2: 0x4041a4
// i3: 0x4041a8
// i4: 0x4041ac

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>

uint8_t memory[0x1000] = {};

class mm
{
    uint8_t *cursor{memory};

public:
    mm() = default;

    template<typename T>
    T *allocate()
    {
        if (cursor + sizeof(T) > memory + 0x1000) {
            throw std::bad_alloc();
        }

        auto ptr = new (cursor) T;
        cursor += sizeof(T);

        return ptr;
    }
};

mm g_mm1;
mm g_mm2;

int main(void)
{
    auto i1 = g_mm1.allocate<int>();
    auto i2 = g_mm1.allocate<int>();
    auto i3 = g_mm2.allocate<int>();
    auto i4 = g_mm2.allocate<int>();

    std::cout << "memory: " << (void *)memory << '\n';
    std::cout << "i1: " << (void *)i1 << '\n';
    std::cout << "i2: " << (void *)i2 << '\n';
    std::cout << "i3: " << (void *)i3 << '\n';
    std::cout << "i4: " << (void *)i4 << '\n';
}

// memory: 0x4041a0
// i1: 0x4041a0
// i2: 0x4041a4
// i3: 0x4041a8
// i4: 0x4041ac

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <iostream>

uint8_t memory[0x1000] = {};

class mm
{
    uint8_t *cursor{memory};
    mm() = default;

public:

    template<typename T>
    T *allocate()
    {
        if (cursor + sizeof(T) > memory + 0x1000) {
            throw std::bad_alloc();
        }

        auto ptr = new (cursor) T;
        cursor += sizeof(T);

        return ptr;
    }

    mm(const mm &) = delete;
    mm &operator=(const mm &) = delete;
    mm(mm &&) = delete;
    mm &operator=(mm &&) = delete;

    static auto &instance()
    {
        static mm s_mm;
        return s_mm;
    }
};

int main(void)
{
    auto i1 = mm::instance().allocate<int>();
    auto i2 = mm::instance().allocate<int>();
    auto i3 = mm::instance().allocate<int>();
    auto i4 = mm::instance().allocate<int>();

    std::cout << "memory: " << (void *)memory << '\n';
    std::cout << "i1: " << (void *)i1 << '\n';
    std::cout << "i2: " << (void *)i2 << '\n';
    std::cout << "i3: " << (void *)i3 << '\n';
    std::cout << "i4: " << (void *)i4 << '\n';
}

// memory: 0x4041a0
// i1: 0x4041a0
// i2: 0x4041a4
// i3: 0x4041a8
// i4: 0x4041ac

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <iostream>

uint8_t memory[0x1000] = {};

class mm
{
    uint8_t *cursor{memory};
    mm() = default;

public:

    template<typename T>
    T *allocate()
    {
        if (cursor + sizeof(T) > memory + 0x1000) {
            throw std::bad_alloc();
        }

        auto ptr = new (cursor) T;
        cursor += sizeof(T);

        return ptr;
    }

    mm(const mm &) = delete;
    mm &operator=(const mm &) = delete;
    mm(mm &&) = delete;
    mm &operator=(mm &&) = delete;

    static auto &instance()
    {
        static mm s_mm;
        return s_mm;
    }
};

template<typename T>
constexpr T *allocate()
{
    return mm::instance().allocate<T>();
}

int main(void)
{
    auto i1 = allocate<int>();
    auto i2 = allocate<int>();
    auto i3 = allocate<int>();
    auto i4 = allocate<int>();

    std::cout << "memory: " << (void *)memory << '\n';
    std::cout << "i1: " << (void *)i1 << '\n';
    std::cout << "i2: " << (void *)i2 << '\n';
    std::cout << "i3: " << (void *)i3 << '\n';
    std::cout << "i4: " << (void *)i4 << '\n';
}

// memory: 0x4041a0
// i1: 0x4041a0
// i2: 0x4041a4
// i3: 0x4041a8
// i4: 0x4041ac

#endif
