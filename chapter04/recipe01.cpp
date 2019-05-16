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

template<typename T>
void the_answer(T is)
{
    std::cout << "The answer is: " << is << '\n';
}

int main(void)
{
    the_answer(42);
    the_answer(42U);
    the_answer(42.0);

    return 0;
}

// The answer is: 42
// The answer is: 42
// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>
#include <type_traits>

template<
    typename T,
    std::enable_if_t<std::is_integral_v<T>, int> = 0
    >
void the_answer(T is)
{
    std::cout << "The answer is: " << is << '\n';
}

int main(void)
{
    the_answer(42);
    return 0;
}

// The answer is: 42

#endif

// template<bool B, class T = void>
// struct enable_if {};

// template<class T>
// struct enable_if<true, T> { typedef T type; };

// template<
//     typename T,
//     typename = std::enable_if_t<std::is_integral_v<T>>
//     >

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <iostream>
#include <type_traits>

template<
    typename T,
    std::enable_if_t<std::is_integral_v<T>>* = nullptr
    >
void the_answer(T is)
{
    std::cout << "The answer is: " << is << '\n';
}

int main(void)
{
    the_answer(42);
    return 0;
}

// The answer is: 42

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <iostream>
#include <type_traits>

template<
    typename T,
    std::enable_if_t<std::is_integral_v<T>>* = nullptr
    >
void the_answer(T is)
{
    std::cout << "The answer is: " << is << '\n';
}

int main(void)
{
    the_answer(42.0);

    return 0;
}

// /home/user/book/chapter04/recipe01.cpp: In function ‘int main()’:
// /home/user/book/chapter04/recipe01.cpp:126:20: error: no matching function for call to ‘the_answer(double)’
//   126 |     the_answer(42.0);
//       |                    ^
// /home/user/book/chapter04/recipe01.cpp:119:6: note: candidate: ‘template<class T, std::enable_if_t<is_integral_v<T> >* <anonymous> > void the_answer(T)’
//   119 | void the_answer(T is)
//       |      ^~~~~~~~~~
// /home/user/book/chapter04/recipe01.cpp:119:6: note:   template argument deduction/substitution failed:
// In file included from /usr/include/c++/9/bits/move.h:55,
//                  from /usr/include/c++/9/bits/nested_exception.h:40,
//                  from /usr/include/c++/9/exception:144,
//                  from /usr/include/c++/9/ios:39,
//                  from /usr/include/c++/9/ostream:38,
//                  from /usr/include/c++/9/iostream:39,
//                  from /home/user/book/chapter04/recipe01.cpp:112:
// /usr/include/c++/9/type_traits: In substitution of ‘template<bool _Cond, class _Tp> using enable_if_t = typename std::enable_if::type [with bool _Cond = std::is_integral_v<double>; _Tp = void]’:
// /home/user/book/chapter04/recipe01.cpp:117:48:   required from here
// /usr/include/c++/9/type_traits:2426:11: error: no type named ‘type’ in ‘struct std::enable_if<false, void>’
//  2426 |     using enable_if_t = typename enable_if<_Cond, _Tp>::type;
//       |           ^~~~~~~~~~~
// make[2]: *** [CMakeFiles/recipe01_example04.dir/build.make:63: CMakeFiles/recipe01_example04.dir/recipe01.cpp.o] Error 1
// make[1]: *** [CMakeFiles/Makefile2:147: CMakeFiles/recipe01_example04.dir/all] Error 2
// make: *** [Makefile:84: all] Error 2

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <iostream>
#include <type_traits>
#include <iomanip>

template<
    typename T,
    std::enable_if_t<std::is_integral_v<T>>* = nullptr
    >
void the_answer(T is)
{
    std::cout << "The answer is: " << is << '\n';
}

template<
    typename T,
    std::enable_if_t<std::is_floating_point_v<T>>* = nullptr
    >
void the_answer(T is)
{
    std::cout << std::setprecision(10);
    std::cout << "The answer is: " << is << '\n';
}

int main(void)
{
    the_answer(42);
    the_answer(42U);
    the_answer(42.12345678);

    return 0;
}

// The answer is: 42
// The answer is: 42
// The answer is: 42.12345678

#endif
