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

#include <memory>
#include <iostream>

class car;
class engine;

class car
{
    friend void build_car();
    std::shared_ptr<engine> m_engine;

public:
    car() = default;
};

class engine
{
    friend void build_car();
    std::shared_ptr<car> m_car;

public:
    engine() = default;
};

void build_car()
{
    auto c = std::make_shared<car>();
    auto e = std::make_shared<engine>();

    c->m_engine = e;
    e->m_car = c;
}

int main(void)
{
    build_car();
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <memory>
#include <iostream>

class car;
class engine;

class car
{
    friend void build_car();
    std::shared_ptr<engine> m_engine;

public:
    car() = default;
};

class engine
{
    friend void build_car();
    std::shared_ptr<car> m_car;

public:
    engine() = default;
};

void build_car()
{
    auto c = std::make_shared<car>();
    auto e = std::make_shared<engine>();

    c->m_engine = e;
    e->m_car = c;

    std::cout << c.use_count() << '\n';
    std::cout << e.use_count() << '\n';
}

int main(void)
{
    build_car();
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <memory>
#include <iostream>

class car;
class engine;

class car
{
    friend void build_car();
    std::shared_ptr<engine> m_engine;

public:
    car() = default;
};

class engine
{
    friend void build_car();
    std::weak_ptr<car> m_car;

public:
    engine() = default;
};

void build_car()
{
    auto c = std::make_shared<car>();
    auto e = std::make_shared<engine>();

    c->m_engine = e;
    e->m_car = c;

    std::cout << c.use_count() << '\n';
    std::cout << e.use_count() << '\n';
}

int main(void)
{
    build_car();
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <memory>
#include <iostream>

class car;
class engine;

class car
{
    friend void build_car();
    std::shared_ptr<engine> m_engine;

public:
    car() = default;
};

class engine
{
    friend void build_car();
    std::weak_ptr<car> m_car;

public:
    engine() = default;

    void test()
    {
        if (m_car.expired()) {
            std::cout << "car deleted\n";
        }
    }
};

void build_car()
{
    auto e = std::make_shared<engine>();

    {
        auto c = std::make_shared<car>();

        c->m_engine = e;
        e->m_car = c;
    }

    e->test();
}

int main(void)
{
    build_car();
    return 0;
}

#endif
