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

// objdump -d recipe02_example01

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
//   401106:	55                   	push   %rbp
//   401107:	48 89 e5             	mov    %rsp,%rbp
//   40110a:	b8 00 00 00 00       	mov    $0x0,%eax
//   40110f:	5d                   	pop    %rbp
//   401110:	c3                   	retq
//   401111:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
//   401118:	00 00 00
//   40111b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

volatile int data[10];

int main(void)
{
    for (auto i = 0; i < 10; i++) {
        data[i] = 42;
    }
}

// 0000000000401106 <main>:
//   401106:	55                   	push   %rbp
//   401107:	48 89 e5             	mov    %rsp,%rbp
//   40110a:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
//   401111:	83 7d fc 09          	cmpl   $0x9,-0x4(%rbp)
//   401115:	7f 16                	jg     40112d <main+0x27>
//   401117:	8b 45 fc             	mov    -0x4(%rbp),%eax
//   40111a:	48 98                	cltq
//   40111c:	c7 04 85 40 40 40 00 	movl   $0x2a,0x404040(,%rax,4)
//   401123:	2a 00 00 00
//   401127:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
//   40112b:	eb e4                	jmp    401111 <main+0xb>
//   40112d:	b8 00 00 00 00       	mov    $0x0,%eax
//   401132:	5d                   	pop    %rbp
//   401133:	c3                   	retq
//   401134:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
//   40113b:	00 00 00
//   40113e:	66 90                	xchg   %ax,%ax

// 0000000000401020 <main>:
//   401020:	31 c0                	xor    %eax,%eax
//   401022:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
//   401028:	48 63 d0             	movslq %eax,%rdx
//   40102b:	83 c0 01             	add    $0x1,%eax
//   40102e:	c7 04 95 40 40 40 00 	movl   $0x2a,0x404040(,%rdx,4)
//   401035:	2a 00 00 00
//   401039:	83 f8 0a             	cmp    $0xa,%eax
//   40103c:	75 ea                	jne    401028 <main+0x8>
//   40103e:	31 c0                	xor    %eax,%eax
//   401040:	c3                   	retq

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

volatile int data[4];

int main(void)
{
    for (auto i = 0; i < 4; i++) {
        data[i] = 42;
    }
}

// 0000000000401020 <main>:
//   401020:	c7 05 06 30 00 00 2a 	movl   $0x2a,0x3006(%rip)        # 404030 <data>
//   401027:	00 00 00
//   40102a:	31 c0                	xor    %eax,%eax
//   40102c:	c7 05 fe 2f 00 00 2a 	movl   $0x2a,0x2ffe(%rip)        # 404034 <data+0x4>
//   401033:	00 00 00
//   401036:	c7 05 f8 2f 00 00 2a 	movl   $0x2a,0x2ff8(%rip)        # 404038 <data+0x8>
//   40103d:	00 00 00
//   401040:	c7 05 f2 2f 00 00 2a 	movl   $0x2a,0x2ff2(%rip)        # 40403c <data+0xc>
//   401047:	00 00 00
//   40104a:	c3                   	retq

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

// 000000000040110d <main>:
//   40110d:	55                   	push   %rbp
//   40110e:	48 89 e5             	mov    %rsp,%rbp
//   401111:	48 81 ec 90 01 00 00 	sub    $0x190,%rsp
//   401118:	48 81 ec 90 01 00 00 	sub    $0x190,%rsp
//   40111f:	48 89 e0             	mov    %rsp,%rax
//   401122:	48 89 c7             	mov    %rax,%rdi
//   401125:	48 8d 85 70 fe ff ff 	lea    -0x190(%rbp),%rax
//   40112c:	ba 32 00 00 00       	mov    $0x32,%edx
//   401131:	48 89 c6             	mov    %rax,%rsi
//   401134:	48 89 d1             	mov    %rdx,%rcx
//   401137:	f3 48 a5             	rep movsq %ds:(%rsi),%es:(%rdi)
//   40113a:	e8 c7 ff ff ff       	callq  401106 <_Z3foo6mydata>
//   40113f:	48 81 c4 90 01 00 00 	add    $0x190,%rsp
//   401146:	b8 00 00 00 00       	mov    $0x0,%eax
//   40114b:	c9                   	leaveq
//   40114c:	c3                   	retq
//   40114d:	0f 1f 00             	nopl   (%rax)

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

// 0000000000401111 <main>:
//   401111:	55                   	push   %rbp
//   401112:	48 89 e5             	mov    %rsp,%rbp
//   401115:	48 81 ec 90 01 00 00 	sub    $0x190,%rsp
//   40111c:	48 8d 85 70 fe ff ff 	lea    -0x190(%rbp),%rax
//   401123:	48 89 c7             	mov    %rax,%rdi
//   401126:	e8 db ff ff ff       	callq  401106 <_Z3fooR6mydata>
//   40112b:	b8 00 00 00 00       	mov    $0x0,%eax
//   401130:	c9                   	leaveq
//   401131:	c3                   	retq
//   401132:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
//   401139:	00 00 00
//   40113c:	0f 1f 40 00          	nopl   0x0(%rax)

#endif
