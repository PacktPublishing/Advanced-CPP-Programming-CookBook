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

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <iostream>

TEST_CASE("the answer")
{
    std::cout << "The answer is: 42\n";
}

// test cases: 1 | 1 passed
// assertions: - none -

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <vector>
#include <iostream>
#include <algorithm>

TEST_CASE("sort a vector")
{
    std::vector<int> v{4, 8, 15, 16, 23, 42};
    REQUIRE(v.size() == 6);

    SECTION("sort descending order") {
        std::sort(v.begin(), v.end(), std::greater<int>());

        CHECK(v.front() == 42);
        CHECK(v.back() == 4);
    }

    SECTION("sort ascending order") {
        std::sort(v.begin(), v.end(), std::less<int>());

        CHECK(v.front() == 4);
        CHECK(v.back() == 42);
    }
 }

// ===============================================================================
// All tests passed (6 assertions in 1 test case)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <vector>
#include <iostream>
#include <algorithm>

void foo(int val)
{
    if (val != 42) {
        throw std::runtime_error("The answer is: 42");
    }
}

TEST_CASE("the answer")
{
    CHECK_NOTHROW(foo(42));
    REQUIRE_NOTHROW(foo(42));

    CHECK_THROWS(foo(0));
    CHECK_THROWS_AS(foo(0), std::runtime_error);
    CHECK_THROWS_WITH(foo(0), "The answer is: 42");

    REQUIRE_THROWS(foo(0));
    REQUIRE_THROWS_AS(foo(0), std::runtime_error);
    REQUIRE_THROWS_WITH(foo(0), "The answer is: 42");
}

// ===============================================================================
// All tests passed (8 assertions in 1 test case)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <vector>
#include <iostream>
#include <algorithm>

void foo(int val)
{
    if (val != 42) {
        throw std::runtime_error("The answer is: 42");
    }
}

TEST_CASE("the answer")
{
    CHECK_NOTHROW(foo(42));
    REQUIRE_NOTHROW(foo(42));

    CHECK_THROWS(foo(0));
    CHECK_THROWS_AS(foo(0), std::runtime_error);
    CHECK_THROWS_WITH(foo(0), "The answer is: 42");

    REQUIRE_THROWS(foo(0));
    REQUIRE_THROWS_AS(foo(0), std::runtime_error);
    REQUIRE_THROWS_WITH(foo(0), "The answer is: 42");
}

// ===============================================================================
// All tests passed (8 assertions in 1 test case)

#endif
