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

#include "my_library.h"
#include <iostream>

int main(void)
{
    using namespace library_name;

    std::cout << "The answer is: " << my_api() << '\n';
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>
#include "my_library.h"

int main(void)
{
    library_name::my_api();
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include "my_library.h"
#include <iostream>

int main(void)
{
    library_name::my_api();
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include "my_library.h"
#include <iostream>

int main(void)
{
    library_name::my_api();
    library_name::config::show_hex = true;
    library_name::my_api();

    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include "my_library.h"

int main(void)
{
    library_name::my_api(42);
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE06

#include "apis.h"

int main(void)
{
    library_name::my_api();
    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE07

#include "my_library_single.h"

int main(void)
{
    library_name::my_api();
    return 0;
}

#endif
