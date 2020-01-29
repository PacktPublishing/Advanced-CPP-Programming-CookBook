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

class myclass
{
    int answer;

public:
    ~myclass()
    {
        answer = 42;
    }
};

void foo()
{
    throw 42;
}

int main(void)
{
    myclass c;

    try {
        foo();
    }
    catch (...) {
    }
}

// > objdump -d ./recipe04_example01 | awk '/main>:/,/ret/'
// 000000000040119c <main>:
//   ...
//   4011e1: callq  401080 <_Unwind_Resume@plt>
//   ...

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

class myclass
{
    int answer;

public:
    ~myclass()
    {
        answer = 42;
    }
};

void foo()
{
    throw 42;
}

int main(void) noexcept
{
    myclass c;

    try {
        foo();
    }
    catch (...) {
    }
}

// > objdump -d ./recipe04_example02 | awk '/main>:/,/ret/'
// 000000000040118c <main>:
//   40118c: push   %rbp
//   40118d: mov    %rsp,%rbp
//   401190: sub    $0x10,%rsp
//   401194: callq  401166 <_Z3foov>
//   401199: lea    -0x4(%rbp),%rax
//   40119d: mov    %rax,%rdi
//   4011a0: callq  4011be <_ZN7myclassD1Ev>
//   4011a5: mov    $0x0,%eax
//   4011aa: jmp    4011bb <main+0x2f>
//   4011ac: mov    %rax,%rdi
//   4011af: callq  401030 <__cxa_begin_catch@plt>
//   4011b4: callq  401050 <__cxa_end_catch@plt>
//   4011b9: jmp    401199 <main+0xd>
//   4011bb: leaveq
//   4011bc: retq

#endif
