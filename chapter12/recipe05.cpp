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

#include <iostream>

template <typename T>
constexpr auto type_info()
{
    std::string_view name{__PRETTY_FUNCTION__};
    name.remove_prefix(37);
    name.remove_suffix(1);
    return name;
}

#define show_type(a)                            \
    std::cout << #a                             \
              << " = "                          \
              << type_info<decltype(a)>()       \
              << '\n';                          \

// -----------------------------------------------------------------------------
#ifdef EXAMPLE01

template<typename T>
class the_answer
{

public:
    the_answer(T t)
    {
        show_type(t);
    }
};

int main(void)
{
    the_answer<unsigned> is_1(42);
    the_answer is_2(42);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

template<typename T>
class the_answer
{

public:
    the_answer(T t)
    {
        show_type(t);
    }
};

the_answer(int) -> the_answer<unsigned>;

int main(void)
{
    the_answer is(42);
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

template<typename T>
class the_answer
{

public:
    the_answer(T t)
    {
        show_type(t);
    }
};

the_answer(const char *) -> the_answer<std::string>;

int main(void)
{
    the_answer is("The answer is: 42");
}

#endif
