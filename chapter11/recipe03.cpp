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

#include <iostream>

class html_div
{
public:
    virtual int width() = 0;
};

class button : public html_div
{
public:
    int width()
    {
        return 10;
    }
};

class decorator : public html_div
{
    html_div *m_div;

public:
    decorator(html_div *d) :
        m_div{d}
    { }

    int width()
    {
        return m_div->width();
    }
};

class margin : public decorator
{
public:
    margin(html_div *d) :
        decorator{d}
    { }

    int width()
    {
        return decorator::width() + 32;
    }
};

int main()
{
    auto button1 = new button();
    auto button2 = new margin(new button());

    std::cout << "button1 width: " << button1->width() << '\n';
    std::cout << "button2 width: " << button2->width() << '\n';
}


#endif
