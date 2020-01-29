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

class copy_or_move
{
public:

    copy_or_move() = default;

public:

    copy_or_move(copy_or_move &&other) noexcept
    {
        *this = std::move(other);
    }

    copy_or_move &operator=(copy_or_move &&other) noexcept
    {
        std::cout << "move\n";
        return *this;
    }

    copy_or_move(const copy_or_move &other)
    {
        *this = other;
    }

    copy_or_move &operator=(const copy_or_move &other)
    {
        std::cout << "copy\n";
        return *this;
    }
};

int main(void)
{
    const copy_or_move test1;
    copy_or_move test2;

    test2 = std::move(test1);
    return 0;
}

// copy

#endif
