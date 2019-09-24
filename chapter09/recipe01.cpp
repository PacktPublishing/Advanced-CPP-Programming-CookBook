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

#include <array>
#include <memory>
#include <iostream>

class hero
{
public:
    virtual ~hero() = default;
    virtual const char *name() const = 0;
};

class spiderman : public hero
{
public:
    const char *name() const
    {
        return "Spiderman";
    }
};

class captain_america : public hero
{
public:
    const char *name() const
    {
        return "Captin America";
    }
};

int main(void)
{
    std::array<std::unique_ptr<hero>, 2> heros {
        std::make_unique<spiderman>(),
        std::make_unique<captain_america>()
    };

    for (const auto &h : heros) {
        std::cout << h->name() << '\n';
    }

    return 0;
}

// Spiderman
// Captin America

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>

class spiderman
{
public:
    const char *name() const
    {
        return "Spiderman";
    }
};

class captain_america
{
public:
    const char *name() const
    {
        return "Captin America";
    }
};

template<typename T>
auto name(const T &t)
{
    return t.name();
}

int main(void)
{
    std::cout << name(spiderman{}) << '\n';
    std::cout << name(captain_america{}) << '\n';

    return 0;
}

// Spiderman
// Captin America

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <array>
#include <memory>
#include <iostream>

class hero
{
public:
    virtual ~hero() = default;
    virtual const char *name() const = 0;
};

template<typename T>
class delegate : public hero
{
    std::unique_ptr<T> m_t{std::make_unique<T>()};

public:
    const char *name() const
    {
        return m_t->name();
    }
};

class spiderman
{
public:
    const char *name() const
    {
        return "Spiderman";
    }
};

class captain_america
{
public:
    const char *name() const
    {
        return "Captin America";
    }
};

int main(void)
{
    std::array<std::unique_ptr<hero>, 2> heros {
        std::make_unique<delegate<spiderman>>(),
        std::make_unique<delegate<captain_america>>()
    };

    for (const auto &h : heros) {
        std::cout << h->name() << '\n';
    }

    return 0;
}

// Spiderman
// Captin America

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <array>
#include <memory>
#include <iostream>

template<typename T>
class delegate_helper
{
    T m_t;

public:
    const char *name() const
    {
        return m_t.name();
    }
};

class delegate
{
    void *m_t{};

    template<typename T>
    T *t()
    {
        return static_cast<T *>(m_t);
    }

public:

    template<typename T>
    delegate()
    {
        m_t = new T;
    }

    ~delegate()
    {
        delete t<T>();
    }

    const char *name() const
    {
        return t()->name();
    }
};

class spiderman
{
public:
    const char *name() const
    {
        return "Spiderman";
    }
};

class captain_america
{
public:
    const char *name() const
    {
        return "Captin America";
    }
};

int main(void)
{
    std::array<delegate, 2> heros {
        delegate<spiderman>(),
        delegate<captain_america>()
    };

    for (const auto &h : heros) {
        std::cout << h.name() << '\n';
    }

    return 0;
}

// Spiderman
// Captin America

#endif
