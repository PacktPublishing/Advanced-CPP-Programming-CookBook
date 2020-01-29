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

#ifndef MY_LIBRARY
#define MY_LIBRARY

namespace library_name
{
    int my_api() { return 42; }
}

#endif

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#ifndef MY_LIBRARY
#define MY_LIBRARY

namespace library_name
{
    void my_api()
    {
        std::cout << "The answer is: 42" << '\n';
    }
}

#endif

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#ifndef MY_LIBRARY
#define MY_LIBRARY

#include <iostream>
#include <iomanip>

namespace library_name
{
    void my_api(bool show_hex = false)
    {
        if (show_hex) {
            std::cout << std::hex << "The answer is: " << 42 << '\n';
        }
        else {
            std::cout << std::dec << "The answer is: " << 42 << '\n';
        }
    }
}

#endif

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#ifndef MY_LIBRARY
#define MY_LIBRARY

#include <iostream>
#include <iomanip>

namespace library_name
{
    namespace config
    {
        inline bool show_hex = false;
    }

    void my_api()
    {
        if (config::show_hex) {
            std::cout << std::hex << "The answer is: " << 42 << '\n';
        }
        else {
            std::cout << std::dec << "The answer is: " << 42 << '\n';
        }
    }
}

#endif

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#ifndef MY_LIBRARY
#define MY_LIBRARY

#include <cassert>

namespace library_name
{
    #define CHECK(a) assert(a == 42)

    void my_api(int val)
    {
        CHECK(val);
    }
}

#endif

#endif
