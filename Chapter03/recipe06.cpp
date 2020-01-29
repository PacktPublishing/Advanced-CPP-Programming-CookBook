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

class the_answer
{
public:

    the_answer() = default;

    void foo() &
    {
        std::cout << "the answer is: 42\n";
    }

    void foo() &&
    {
        std::cout << "the answer is not: 0\n";
    }

public:

    the_answer(the_answer &&other) noexcept = default;
    the_answer &operator=(the_answer &&other) noexcept = default;

    the_answer(const the_answer &other) = default;
    the_answer &operator=(const the_answer &other) = default;
};

int main(void)
{
    the_answer is;

    is.foo();
    std::move(is).foo();
    the_answer{}.foo();
}

// the answer is: 42
// the answer is not: 0
// the answer is not: 0

#endif
