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

class interface
{
public:
    virtual ~interface() = default;
    virtual void foo() = 0;
};

class A :
    public interface
{
public:
    void foo() override
    {
        std::cout << "The answer is: 42\n";
    }
};

class B :
    public interface
{
public:
    void foo() override
    {
        std::cout << "The answer is not: 43\n";
    }
};

class client
{
    interface &m_i;

public:
    client(interface &i) :
        m_i{i}
    { }

    void bar()
    {
        m_i.foo();
    }
};

int main(void)
{
    A a;
    B b;

    client c1(a);
    client c2(b);

    c1.bar();
    c2.bar();
}

#endif

// The answer is: 42
// The answer is not: 43

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>

template<typename DERIVED>
class interface
{
public:
    constexpr void foo()
    {
        static_cast<DERIVED *>(this)->foo_override();
    }
};

class A :
    public interface<A>
{
public:
    void foo_override()
    {
        std::cout << "The answer is: 42\n";
    }
};

class B :
    public interface<B>
{
public:
    void foo_override()
    {
        std::cout << "The answer is not: 43\n";
    }
};

template<typename T>
class client
{
    interface<T> &m_i;

public:
    client(interface<T> &i) :
        m_i{i}
    { }

    void bar()
    {
        m_i.foo();
    }
};

int main(void)
{
    A a;
    B b;

    client c1(a);
    client c2(b);

    c1.bar();
    c2.bar();
}

#endif

// The answer is: 42
// The answer is not: 43

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <iostream>

template<typename DERIVED>
class interface
{
public:
    constexpr void foo()
    {
        static_cast<DERIVED *>(this)->foo_override();
    }
};

template<typename T>
class client
{
    interface<T> &m_i;

public:
    client(interface<T> &i) :
        m_i{i}
    { }

    void bar()
    {
        m_i.foo();
    }
};

int main(void)
{
    client c(std::cout);
}

#endif

// home/user/book/chapter13/recipe01.cpp: In function ‘int main()’:
// /home/user/book/chapter13/recipe01.cpp:187:23: error: class template argument deduction failed:
//   187 |     client c(std::cout);
//       |                       ^
// /home/user/book/chapter13/recipe01.cpp:187:23: error: no matching function for call to ‘client(std::ostream&)’
// /home/user/book/chapter13/recipe01.cpp:175:5: note: candidate: ‘template<class T> client(interface<T>&)-> client<T>’
//   175 |     client(interface<T> &i) :
//       |     ^~~~~~
// /home/user/book/chapter13/recipe01.cpp:175:5: note:   template argument deduction/substitution failed:
// /home/user/book/chapter13/recipe01.cpp:187:23: note:   ‘std::ostream’ {aka ‘std::basic_ostream<char>’} is not derived from ‘interface<T>’
//   187 |     client c(std::cout);
//       |                       ^
// /home/user/book/chapter13/recipe01.cpp:170:7: note: candidate: ‘template<class T> client(client<T>)-> client<T>’
//   170 | class client
//       |       ^~~~~~
// /home/user/book/chapter13/recipe01.cpp:170:7: note:   template argument deduction/substitution failed:
// /home/user/book/chapter13/recipe01.cpp:187:23: note:   ‘std::basic_ostream<char>’ is not derived from ‘client<T>’
//   187 |     client c(std::cout);
//       |                       ^
// make[2]: *** [CMakeFiles/recipe01_example03.dir/build.make:63: CMakeFiles/recipe01_example03.dir/recipe01.cpp.o] Error 1
// make[1]: *** [CMakeFiles/Makefile2:184: CMakeFiles/recipe01_example03.dir/all] Error 2
// make: *** [Makefile:84: all] Error 2

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <iostream>

template <typename T>
concept interface = requires(T t)
{
    { t.foo() } -> void;
};

class A
{
public:
    void foo()
    {
        std::cout << "The answer is: 42\n";
    }
};

class B
{
public:
    void foo()
    {
        std::cout << "The answer is not: 43\n";
    }
};

template<interface T>
class client
{
    T &m_i;

public:
    client(T &i) :
        m_i{i}
    { }

    void bar()
    {
        m_i.foo();
    }
};

int main(void)
{
    A a;
    B b;

    client c1(a);
    client c2(b);

    c1.bar();
    c2.bar();
}

#endif

// The answer is: 42
// The answer is not: 43

