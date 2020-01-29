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

TEST_CASE("the answer")
{
    CHECK(true);
}

// =========================================================
// All tests passed (1 assertion in 1 test case)

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

        CHECK(v[0] == 42);
        CHECK(v[5] == 4);
    }

    SECTION("sort ascending order") {
        std::sort(v.begin(), v.end(), std::less<int>());

        CHECK(v[0] == 4);
        CHECK(v[5] == 42);
    }
}

// =========================================================
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

// =========================================================
// All tests passed (8 assertions in 1 test case)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

TEST_CASE("the answer")
{
    CHECK(true);
}

// -r xml

// <?xml version="1.0" encoding="UTF-8"?>
// <Catch name="recipe01_example01">
//   <Group name="recipe01_example01">
//     <TestCase name="the answer" filename="/home/user/book/chapter07/recipe01.cpp" line="28">
//       <OverallResult success="true"/>
//     </TestCase>
//     <OverallResults successes="1" failures="0" expectedFailures="0"/>
//   </Group>
//   <OverallResults successes="1" failures="0" expectedFailures="0"/>
// </Catch>

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch.hpp>

#include <vector>
#include <iostream>

TEST_CASE("the answer")
{
    std::vector<int> v{4, 8, 15, 16, 23, 42};

    BENCHMARK("sort vector") {
        std::sort(v.begin(), v.end());
    };
}

// ---------------------------------------------------------
// the answer
// ---------------------------------------------------------
// /home/user/book/chapter07/recipe01.cpp:145
// .........................................................
//
// benchmark name     samples       iterations    estimated
//                    mean          low mean      high mean
//                    std dev       low std dev   high std dev
// ---------------------------------------------------------
// sort vector                100          322     6.279 ms
//                         197 ns       197 ns       198 ns
//                           2 ns         2 ns         3 ns
//
//
// =========================================================
// test cases: 1 | 1 passed
// assertions: - none -

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE06

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <cmath>
#include <climits>

class vector
{
    int m_x{};
    int m_y{};

public:

    vector() = default;

    vector(int x, int y) :
        m_x{x},
        m_y{y}
    { }

    auto x() const
    { return m_x; }

    auto y() const
    { return m_y; }

    void translate(const vector &p)
    {
        m_x += p.m_x;
        m_y += p.m_y;
    }

    auto magnitude()
    {
        auto a2 = m_x * m_x;
        auto b2 = m_y * m_y;

        return sqrt(a2 + b2);
    }
};

bool operator== (const vector &p1, const vector &p2)
{ return p1.x() == p2.x() && p1.y() == p2.y(); }

bool operator!= (const vector &p1, const vector &p2)
{ return p1.x() != p2.x() || p1.y() != p2.y(); }

vector origin;

TEST_CASE("default constructor")
{
    vector p;

    REQUIRE(p.x() == 0);
    REQUIRE(p.y() == 0);
}

TEST_CASE("origin")
{
    vector v1{0, 0};
    vector v2{0, 0};

    REQUIRE(v1 == origin);
    REQUIRE(v2 != origin);

    REQUIRE(v1.x() == 0);
    REQUIRE(v1.y() == 0);

    REQUIRE(v2.x() == 1);
    REQUIRE(v2.y() == 1);
}

TEST_CASE("translate")
{
    vector p{-4, -8};
    p.translate({46, 50});

    CHECK(p.x() == 42);
    CHECK(p.y() == 42);
}

TEST_CASE("magnitude")
{
    vector p(1, 1);
    CHECK(Approx(p.magnitude()).epsilon(0.1) == 1.4);
}

TEST_CASE("magnitude overflow")
{
    vector p(INT_MAX, INT_MAX);
    CHECK(p.magnitude() == 65536);
}

// magnitude overflow
// ---------------------------------------------------------
// /home/user/book/chapter07/recipe01.cpp:257
// .........................................................
//
// /home/user/book/chapter07/recipe01.cpp:260: FAILED:
//   CHECK( p.magnitude() == 65536 )
// with expansion:
//   1.4142135624 == 65536 (0x10000)
//
// =========================================================
// test cases: 5 | 4 passed | 1 failed
// assertions: 8 | 7 passed | 1 failed

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE07

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <string>
#include <fstream>

class file
{
    std::fstream m_file{"test.txt", std::fstream::out};

public:

    void write(const std::string &str)
    {
        m_file.write(str.c_str(), str.length());
    }
};

class the_answer
{
public:

    the_answer(file &f)
    {
        f.write("The answer is: 42\n");
    }
};

TEST_CASE("the answer")
{
    file f;
    the_answer{f};
}

// =========================================================
// test cases: 1 | 1 passed
// assertions: - none -

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE08

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <string>
#include <fstream>

class file
{
    std::fstream m_file{"test.txt", std::fstream::out};

public:
    VIRTUAL ~file() = default;

    VIRTUAL void write(const std::string &str)
    {
        m_file.write(str.c_str(), str.length());
    }
};

class the_answer
{
public:
    the_answer(file &f)
    {
        f.write("The answer is: 42\n");
    }
};

class mock_file : public file
{
public:
    void write(const std::string &str)
    {
        if (str == "The answer is: 42\n") {
            passed = true;
        }
        else {
            passed = false;
        }
    }

    bool passed{};
};

TEST_CASE("the answer")
{
    mock_file f;
    REQUIRE(f.passed == false);

    f.write("The answer is not: 43\n");
    REQUIRE(f.passed == false);

    the_answer{f};
    CHECK(f.passed);
}

// =========================================================
// test cases: 1 | 1 passed
// assertions: - none -

#endif
