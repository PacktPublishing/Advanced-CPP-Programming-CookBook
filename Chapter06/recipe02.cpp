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

int main(void)
{ }

// > objdump -d recipe02_example01

// 0000000000401000 <_init>:
// 0000000000401020 <_start>:
// 000000000040104f <.annobin_init.c>:
// 0000000000401050 <_dl_relocate_static_pie>:
// 0000000000401055 <.annobin__dl_relocate_static_pie.end>:
// 0000000000401060 <deregister_tm_clones>:
// 0000000000401090 <register_tm_clones>:
// 00000000004010d0 <__do_global_dtors_aux>:
// 0000000000401100 <frame_dummy>:
// 0000000000401106 <main>:
// 0000000000401120 <__libc_csu_init>:
// 0000000000401190 <__libc_csu_fini>:
// 0000000000401198 <_fini>:

// 0000000000401106 <main>:
//   401106:	push   %rbp
//   401107:	mov    %rsp,%rbp
//   40110a:	mov    $0x0,%eax
//   40110f:	pop    %rbp
//   401110:	retq

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

volatile int data[1000];

int main(void)
{
    for (auto i = 0U; i < 1000; i++) {
        data[i] = 42;
    }
}

// > objdump -d ./recipe02_example02 | awk '/main>:/,/ret/'
// 0000000000401020 <main>:
//   401020:	xor    %eax,%eax
//   401022:	nopw   0x0(%rax,%rax,1)
//   401028:	mov    %eax,%edx
//   40102a:	add    $0x1,%eax
//   40102d:	movl   $0x2a,0x404040(,%rdx,4)
//   401038:	cmp    $0x3e8,%eax
//   40103d:	jne    401028 <main+0x8>
//   40103f:	xor    %eax,%eax
//   401041:	retq

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

volatile int data[4];

int main(void)
{
    for (auto i = 0U; i < 4; i++) {
        data[i] = 42;
    }
}

// > objdump -d ./recipe02_example03 | awk '/main>:/,/ret/'
// 0000000000401020 <main>:
//   401020: movl   $0x2a,0x3006(%rip)
//   40102a: xor    %eax,%eax
//   40102c: movl   $0x2a,0x2ffe(%rip)
//   401036: movl   $0x2a,0x2ff8(%rip)
//   401040: movl   $0x2a,0x2ff2(%rip)
//   40104a: retq

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

struct mydata {
    int data[100];
};

void foo(mydata d)
{
    (void) d;
}

int main(void)
{
    mydata d;
    foo(d);
}

// > objdump -d ./recipe02_example04 | awk '/main>:/,/ret/'
// 000000000040110d <main>:
//   40110d: push   %rbp
//   40110e: mov    %rsp,%rbp
//   401111: sub    $0x190,%rsp
//   401118: sub    $0x190,%rsp
//   40111f: mov    %rsp,%rax
//   401122: mov    %rax,%rdi
//   401125: lea    -0x190(%rbp),%rax
//   40112c: mov    $0x32,%edx
//   401131: mov    %rax,%rsi
//   401134: mov    %rdx,%rcx
//   401137: rep movsq %ds:(%rsi),%es:(%rdi)
//   40113a: callq  401106 <_Z3foo6mydata>
//   40113f: add    $0x190,%rsp
//   401146: mov    $0x0,%eax
//   40114b: leaveq
//   40114c: retq

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

struct mydata {
    int data[100];
};

void foo(mydata &d)
{
    (void) d;
}

int main(void)
{
    mydata d;
    foo(d);
}

// > objdump -d ./recipe02_example05 | awk '/main>:/,/ret/'
// 0000000000401111 <main>:
//   401111: push   %rbp
//   401112: mov    %rsp,%rbp
//   401115: sub    $0x190,%rsp
//   40111c: lea    -0x190(%rbp),%rax
//   401123: mov    %rax,%rdi
//   401126: callq  401106 <_Z3fooR6mydata>
//   40112b: mov    $0x0,%eax
//   401130: leaveq
//   401131: retq

#endif
