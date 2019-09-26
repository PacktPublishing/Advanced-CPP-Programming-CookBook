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
#include <functional>

template<
    typename RET,
    typename... ARGS
    >
class base
{
public:
    virtual ~base() = default;
    virtual RET func(ARGS... args) = 0;
};

template<
    typename T,
    typename RET,
    typename... ARGS
    >
class wrapper :
    public base<RET, ARGS...>
{
    T m_t{};
    RET (T::*m_func)(ARGS...);

public:

    wrapper(RET (T::*func)(ARGS...)) :
        m_func{func}
    { }

    RET func(ARGS... args) override
    {
        return std::invoke(m_func, &m_t, args...);
    }
};

template<
    typename RET,
    typename... ARGS
    >
class delegate
{
    std::unique_ptr<base<RET, ARGS...>> m_wrapper;

public:

    template<typename T>
    delegate(RET (T::*func)(ARGS...)) :
        m_wrapper{
            std::make_unique<wrapper<T, RET, ARGS...>>(func)
        }
    { }

    RET operator()(ARGS... args)
    {
        return m_wrapper->func(args...);
    }
};

class spiderman
{
public:
    bool attack(int x, int)
    {
        return x == 0 ? true : false;
    }
};

class captain_america
{
public:
    bool attack(int, int y)
    {
        return y == 0 ? true : false;
    }
};

int main(void)
{
    std::array<delegate<bool, int, int>, 2> heros {
        delegate(&spiderman::attack),
        delegate(&captain_america::attack)
    };

    for (auto &h : heros) {
        std::cout << h(0, 42) << '\n';
    }

    return 0;
}

// 1
// 0

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <array>
#include <memory>
#include <iostream>
#include <functional>

template<
    typename RET,
    typename... ARGS
    >
class base
{
public:
    virtual ~base() = default;
    virtual RET func(ARGS... args) = 0;
};

template<
    typename T,
    typename RET,
    typename... ARGS
    >
class wrapper :
    public base<RET, ARGS...>
{
    T m_t{};
    RET (T::*m_func)(ARGS...);

public:

    wrapper(RET (T::*func)(ARGS...)) :
        m_func{func}
    { }

    RET func(ARGS... args) override
    {
        return std::invoke(m_func, &m_t, args...);
    }
};

template<typename>
class delegate;

template<
    typename RET,
    typename... ARGS
    >
class delegate<RET(ARGS...)>
{
    std::unique_ptr<base<RET, ARGS...>> m_wrapper;

public:

    template<typename T>
    delegate(RET (T::*func)(ARGS...)) :
        m_wrapper{
            std::make_unique<wrapper<T, RET, ARGS...>>(func)
        }
    { }

    RET operator()(ARGS... args)
    {
        return m_wrapper->func(args...);
    }
};

template<
    typename T,
    typename RET,
    typename... ARGS
    >
delegate(RET(T::*)(ARGS...)) -> delegate<RET(ARGS...)>;

class spiderman
{
public:
    bool attack(int x, int)
    {
        return x == 0 ? true : false;
    }
};

class captain_america
{
public:
    bool attack(int, int y)
    {
        return y == 0 ? true : false;
    }
};

int main(void)
{
    std::array<delegate<bool(int, int)>, 2> heros {
        delegate(&spiderman::attack),
        delegate(&captain_america::attack)
    };

    for (auto &h : heros) {
        std::cout << h(0, 42) << '\n';
    }

    return 0;
}

// 1
// 0

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <array>
#include <memory>
#include <iostream>
#include <functional>

template<
    typename RET,
    typename... ARGS
    >
class base
{
public:
    virtual ~base() = default;
    virtual RET func(ARGS... args) = 0;
};

template<
    typename T,
    typename RET,
    typename... ARGS
    >
class wrapper :
    public base<RET, ARGS...>
{
    T m_t{};
    RET (T::*m_func)(ARGS...);

public:

    wrapper(RET (T::*func)(ARGS...)) :
        m_func{func}
    { }

    RET func(ARGS... args) override
    {
        return std::invoke(m_func, &m_t, args...);
    }
};

template<
    typename T,
    typename RET,
    typename... ARGS
    >
class wrapper_const :
    public base<RET, ARGS...>
{
    T m_t{};
    RET (T::*m_func)(ARGS...) const;

public:

    wrapper_const(RET (T::*func)(ARGS...) const) :
        m_func{func}
    { }

    RET func(ARGS... args) override
    {
        return std::invoke(m_func, &m_t, args...);
    }
};

template<typename>
class delegate;

template<
    typename RET,
    typename... ARGS
    >
class delegate<RET(ARGS...)>
{
    std::unique_ptr<base<RET, ARGS...>> m_wrapper;

public:

    template<typename T>
    delegate(RET (T::*func)(ARGS...)) :
        m_wrapper{
            std::make_unique<wrapper<T, RET, ARGS...>>(func)
        }
    { }

    template<typename T>
    delegate(RET (T::*func)(ARGS...) const) :
        m_wrapper{
            std::make_unique<wrapper_const<T, RET, ARGS...>>(func)
        }
    { }

    RET operator()(ARGS... args)
    {
        return m_wrapper->func(args...);
    }
};

template<
    typename T,
    typename RET,
    typename... ARGS
    >
delegate(RET(T::*)(ARGS...)) -> delegate<RET(ARGS...)>;

template<
    typename T,
    typename RET,
    typename... ARGS
    >
delegate(RET(T::*)(ARGS...) const) -> delegate<RET(ARGS...)>;

class spiderman
{
public:
    bool attack(int x, int) const
    {
        return x == 0 ? true : false;
    }
};

class captain_america
{
public:
    bool attack(int, int y) const
    {
        return y == 0 ? true : false;
    }
};

int main(void)
{
    std::array<delegate<bool(int, int)>, 2> heros {
        delegate(&spiderman::attack),
        delegate(&captain_america::attack)
    };

    for (auto &h : heros) {
        std::cout << h(0, 42) << '\n';
    }

    return 0;
}

// 1
// 0

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <array>
#include <memory>
#include <iostream>
#include <functional>

template<
    typename RET,
    typename... ARGS
    >
class base
{
public:
    virtual ~base() = default;
    virtual RET func(ARGS... args) = 0;
};

template<
    typename RET,
    typename... ARGS
    >
class fun_wrapper :
    public base<RET, ARGS...>
{
    RET (*m_func)(ARGS...);

public:

    fun_wrapper(RET (*func)(ARGS...)) :
        m_func{func}
    { }

    RET func(ARGS... args) override
    {
        return m_func(args...);
    }
};

template<
    typename T,
    typename RET,
    typename... ARGS
    >
class memfun_wrapper :
    public base<RET, ARGS...>
{
    const T *m_t{};
    RET (T::*m_func)(ARGS...);

public:

    memfun_wrapper(const T *t, RET (T::*func)(ARGS...)) :
        m_t{t},
        m_func{func}
    { }

    RET func(ARGS... args) override
    {
        return std::invoke(m_func, m_t, args...);
    }
};

template<
    typename T,
    typename RET,
    typename... ARGS
    >
class memfun_wrapper_const :
    public base<RET, ARGS...>
{
    const T *m_t{};
    RET (T::*m_func)(ARGS...) const;

public:

    memfun_wrapper_const(const T *t, RET (T::*func)(ARGS...) const) :
        m_t{t},
        m_func{func}
    { }

    RET func(ARGS... args) override
    {
        return std::invoke(m_func, m_t, args...);
    }
};

template<typename>
class delegate;

template<
    typename RET,
    typename... ARGS
    >
class delegate<RET(ARGS...)>
{
    std::unique_ptr<base<RET, ARGS...>> m_wrapper;

public:

    delegate(RET (func)(ARGS...)) :
        m_wrapper{
            std::make_unique<fun_wrapper<RET, ARGS...>>(func)
        }
    { }

    template<typename T>
    delegate(const T *t, RET (T::*func)(ARGS...)) :
        m_wrapper{
            std::make_unique<memfun_wrapper<T, RET, ARGS...>>(t, func)
        }
    { }

    template<typename T>
    delegate(const T *t, RET (T::*func)(ARGS...) const) :
        m_wrapper{
            std::make_unique<memfun_wrapper_const<T, RET, ARGS...>>(t, func)
        }
    { }

    RET operator()(ARGS... args)
    {
        return m_wrapper->func(args...);
    }
};

template<
    typename RET,
    typename... ARGS
    >
delegate(RET(*)(ARGS...)) -> delegate<RET(ARGS...)>;

template<
    typename T,
    typename RET,
    typename... ARGS
    >
delegate(const T *, RET(T::*)(ARGS...)) -> delegate<RET(ARGS...)>;

template<
    typename T,
    typename RET,
    typename... ARGS
    >
delegate(const T *, RET(T::*)(ARGS...) const) -> delegate<RET(ARGS...)>;

bool attack(int x, int y)
{
    return x == 42 && y == 42 ? true : false;
}

class spiderman
{
public:
    bool attack(int x, int) const
    {
        return x == 0 ? true : false;
    }
};

class captain_america
{
public:
    bool attack(int, int y) const
    {
        return y == 0 ? true : false;
    }
};

int main(void)
{
    spiderman s;
    captain_america c;

    std::array<delegate<bool(int, int)>, 3> heros {
        delegate(attack),
        delegate(&s, &spiderman::attack),
        delegate(&c, &captain_america::attack)
    };

    for (auto &h : heros) {
        std::cout << h(0, 42) << '\n';
    }

    return 0;
}

// 0
// 1
// 0

#endif
