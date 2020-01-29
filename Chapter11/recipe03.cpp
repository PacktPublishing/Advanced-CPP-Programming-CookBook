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

class margin
{
public:
    int width()
    {
        return 32;
    }
};

class button : public margin
{
public:
    int width()
    {
        return margin::width() + 10;
    }
};

int main()
{
    auto b = new button();
    std::cout << "button width: " << b->width() << '\n';
}


#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <memory>
#include <iostream>

class base
{
public:
    virtual int width() = 0;
};

class button : public base
{
public:
    int width()
    {
        return 10;
    }
};

class decorator : public base
{
    std::unique_ptr<base> m_base;

public:
    decorator(std::unique_ptr<base> b) :
        m_base{std::move(b)}
    { }

    int width()
    {
        return m_base->width();
    }
};

class margin : public decorator
{
public:
    margin(std::unique_ptr<base> b) :
        decorator{std::move(b)}
    { }

    int width()
    {
        return decorator::width() + 32;
    }
};

int main()
{
    auto button1 = std::make_unique<button>();
    auto button2 = std::make_unique<margin>(std::make_unique<button>());

    std::cout << "button1 width: " << button1->width() << '\n';
    std::cout << "button2 width: " << button2->width() << '\n';
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <memory>
#include <iostream>

class base
{
public:
    virtual int width() = 0;
};

class button : public base
{
public:
    int width()
    {
        return 10;
    }
};

class decorator : public base
{
    std::unique_ptr<base> m_base;

public:
    decorator(std::unique_ptr<base> b) :
        m_base{std::move(b)}
    { }

    int width()
    {
        return m_base->width();
    }
};

class margin : public decorator
{
public:
    margin(std::unique_ptr<base> b) :
        decorator{std::move(b)}
    { }

    int width()
    {
        return decorator::width() + 32;
    }
};

int main()
{
    auto b =
        std::make_unique<margin>(
            std::make_unique<margin>(
                std::make_unique<button>()
            )
        );

    std::cout << "button width: " << b->width() << '\n';
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <memory>
#include <iostream>

class base
{
public:
    virtual int width() = 0;
    virtual int content_width() = 0;
};

class button : public base
{
public:
    int width()
    {
        return 10;
    }

    int content_width()
    {
        return width() - 1;
    }
};

class decorator : public base
{
    std::unique_ptr<base> m_base;

public:
    decorator(std::unique_ptr<base> b) :
        m_base{std::move(b)}
    { }

    int width()
    {
        return m_base->width();
    }

    int content_width()
    {
        return m_base->content_width();
    }
};

class margin : public decorator
{
public:
    margin(std::unique_ptr<base> b) :
        decorator{std::move(b)}
    { }

    int width()
    {
        return decorator::width() + 32;
    }

    int content_width()
    {
        return decorator::content_width();
    }
};

class padding : public decorator
{
public:
    padding(std::unique_ptr<base> b) :
        decorator{std::move(b)}
    { }

    int width()
    {
        return decorator::width();
    }

    int content_width()
    {
        return decorator::content_width() - 5;
    }
};

int main()
{
    auto b =
        std::make_unique<margin>(
            std::make_unique<padding>(
                std::make_unique<button>()
            )
        );

    std::cout << "button width: " << b->width() << '\n';
    std::cout << "button content width: " << b->content_width() << '\n';
}

#endif
