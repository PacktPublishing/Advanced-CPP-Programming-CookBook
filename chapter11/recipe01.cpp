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

#include <string>

class answer
{
    std::string m_answer;

public:
    answer(std::string str) :
        m_answer{std::move(str)}
    { }
};

class know_it_all
{
public:
    auto ask_question(const char *question)
    {
        (void) question;
        return answer("The answer is: 42");
    }
};

int main(void)
{
    know_it_all universe;
    auto ___ = universe.ask_question("What is the meaning of life?");
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <string>

class answer
{
    std::string m_answer;

public:
    answer(std::string str) :
        m_answer{std::move(str)}
    { }

    static inline auto make_answer(std::string str)
    { return answer(str); }
};

using factory_t = answer(*)(std::string str);

template<factory_t factory = answer::make_answer>
class know_it_all
{
public:
    auto ask_question(const char *question)
    {
        (void) question;
        return factory("The answer is: 42");
    }
};

int main(void)
{
    know_it_all universe;
    auto ___ = universe.ask_question("What is the meaning of life?");
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <string>
#include <iostream>

class answer
{
    std::string m_answer;

public:
    answer(std::string str) :
        m_answer{std::move(str)}
    { }

    static inline auto make_answer(std::string str)
    { return answer(str); }
};

using factory_t = answer(*)(std::string str);

class expected_answer : public answer
{
public:
    expected_answer(std::string str) :
        answer{str}
    {
        if (str != "The answer is: 42") {
            std::cerr << "wrong answer: " << str << '\n';
            exit(1);
        }

        std::cout << "correct answer: " << str << '\n';
    }

    static inline answer make_answer(std::string str)
    { return expected_answer(str); }
};

template<factory_t factory = answer::make_answer>
class know_it_all
{
public:
    auto ask_question(const char *question)
    {
        (void) question;
        return factory("The answer is: 42");
    }
};

int main(void)
{
    know_it_all<expected_answer::make_answer> universe;
    auto ___ = universe.ask_question("What is the meaning of life?");
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <string>
#include <iostream>

class answer
{
    std::string m_answer;

public:
    answer(std::string str) :
        m_answer{std::move(str)}
    { }

    static inline auto make_answer(std::string str)
    { return answer(str); }
};

using factory_t = answer(*)(std::string str);

class expected_answer : public answer
{
public:
    expected_answer(std::string str) :
        answer{str}
    {
        if (str != "The answer is: 42") {
            std::cerr << "wrong answer: " << str << '\n';
            exit(1);
        }

        std::cout << "correct answer: " << str << '\n';
    }

    static inline answer make_answer(std::string str)
    { return expected_answer(str); }
};

template<factory_t factory = answer::make_answer>
class know_it_all
{
public:
    auto ask_question(const char *question)
    {
        (void) question;
        return factory("Not sure");
    }
};

int main(void)
{
    know_it_all<expected_answer::make_answer> universe;
    auto ___ = universe.ask_question("What is the meaning of life?");
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <string>
#include <iostream>
#include <functional>

class answer
{
    std::string m_answer;

public:
    answer(std::string str) :
        m_answer{std::move(str)}
    { }

    static inline auto make_answer(std::string str)
    { return answer(str); }
};

class expected_answer : public answer
{
public:
    expected_answer(std::string str) :
        answer{str}
    {
        if (str != "The answer is: 42") {
            std::cerr << "wrong answer: " << str << '\n';
            exit(1);
        }

        std::cout << "correct answer: " << str << '\n';
    }

    static inline answer make_answer(std::string str)
    { return expected_answer(str); }
};

class know_it_all
{
    std::function<answer(std::string str)> m_factory;

public:
    know_it_all(answer(*f)(std::string str) = answer::make_answer) :
        m_factory{f}
    { }

    auto ask_question(const char *question)
    {
        (void) question;
        return m_factory("The answer is: 42");
    }
};

int main(void)
{
    know_it_all universe(expected_answer::make_answer);
    auto ___ = universe.ask_question("What is the meaning of life?");
}

#endif
