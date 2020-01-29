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

#include <mutex>
#include <thread>
#include <iostream>

std::mutex m{};

class the_answer
{
public:
    void print() const
    {
        std::lock_guard lock(m);
        std::cout << "The answer is: 42\n";
    }
};

int main(void)
{
    the_answer is;
    is.print();

    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <mutex>
#include <thread>
#include <iostream>

class the_answer
{
    std::mutex m{};

public:
    void print() const
    {
        std::lock_guard lock(m);
        std::cout << "The answer is: 42\n";
    }
};

int main(void)
{
    the_answer is;
    is.print();

    return 0;
}

// ...
// /home/user/book/chapter05/recipe03.cpp:67:31:   required from here
// /usr/include/c++/9/bits/std_mutex.h:159:9: error: passing ‘std::lock_guard<const std::mutex>::mutex_type’ {aka ‘const std::mutex’} as ‘this’ argument discards qualifiers [-fpermissive]
//   159 |       { _M_device.lock(); }
//       |         ^~~~~~~~~
// ...

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <mutex>
#include <thread>
#include <iostream>

class the_answer
{
    mutable std::mutex m{};

public:
    void print() const
    {
        std::lock_guard lock(m);
        std::cout << "The answer is: 42\n";
    }
};

int main(void)
{
    the_answer is;
    is.print();

    return 0;
}

// The answer is: 42

#endif
