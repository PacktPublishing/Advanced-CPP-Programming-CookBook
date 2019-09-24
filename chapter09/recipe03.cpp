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

int main(void)
{
    return 0;
}

#endif


// // -----------------------------------------------------------------------------
// #ifdef EXAMPLE01

// #include <array>
// #include <memory>
// #include <iostream>

// template<typename R, typename... ARGS>
// class hero
// {
// public:
//     virtual ~hero() = default;
//     virtual R operator()(ARGS...) const = 0;
// };

// template<
//     typename T,
//     typename R, typename... ARGS
//     >
// class attack_wrapper : public hero<R, ARGS...>
// {
//     std::unique_ptr<T> m_t{std::make_unique<T>()};

// public:
//     R operator()(ARGS... args) const
//     {
//         return m_t->attack(std::forward<ARGS>(args)...);
//     }
// };

// class spiderman
// {
// public:
//     bool attack(int x, int) const
//     {
//         if (x == 0) {
//             return true;
//         }

//         return false;
//     }
// };

// class captain_america
// {
// public:
//     bool attack(int, int y) const
//     {
//         if (y == 0) {
//             return true;
//         }

//         return false;
//     }
// };

// int main(void)
// {
//     using attack_t = bool(int, int);

//     std::array<std::unique_ptr<hero<attack_t>>, 2> heros {
//         std::make_unique<attack_wrapper<spiderman, attack_t>>(),
//         std::make_unique<attack_wrapper<captain_america, attack_t>>()
//     };

//     for (const auto &h : heros) {
//         std::cout << h->operator()(1, 0) << '\n';
//     }

//     return 0;
// }

// // 0
// // 1

// #endif
