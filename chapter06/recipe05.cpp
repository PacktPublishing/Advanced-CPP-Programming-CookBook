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

class animal
{
public:
    animal() = default;
    virtual ~animal() = default;

    virtual const char *name() = 0;

    void type()
    {
        std::cout << "this animal is a: " << name() << '\n';
    }
};

class dog : public animal
{
public:
    dog() = default;
    ~dog() override = default;

    const char *name()
    {
        return "dog";
    }
};

class cat : public animal
{
public:
    cat() = default;
    ~cat() override = default;

    const char *name()
    {
        return "cat";
    }
};

int main(void)
{
    dog d;
    cat c;

    d.type();
    c.type();

    return 0;
}

// this animal is a: dog
// this animal is a: cat

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>

template<typename T>
class animal
{
public:
    animal() = default;
    ~animal() = default;

    void type()
    {
        std::cout << "this animal is a: " <<
            static_cast<T *>(this)->name() << '\n';
    }
};

class dog : public animal<dog>
{
public:
    dog() = default;
    ~dog() = default;

    const char *name()
    {
        return "dog";
    }
};

class cat : public animal<cat>
{
public:
    cat() = default;
    ~cat() = default;

    const char *name()
    {
        return "cat";
    }
};

int main(void)
{
    dog d;
    cat c;

    d.type();
    c.type();

    return 0;
}

// this animal is a: dog
// this animal is a: cat

#endif
