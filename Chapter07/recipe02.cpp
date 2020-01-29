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
{
    new int;
}

// =================================================================
// ==24111==ERROR: LeakSanitizer: detected memory leaks

// Direct leak of 4 byte(s) in 1 object(s) allocated from:
// #0 0x7f5e7329aa27 in operator new(unsigned long) (/lib64/libasan.so.5+0x10fa27)
// #1 0x401153 in main /home/user/book/chapter07/recipe02.cpp:27
// #2 0x7f5e72c8ff32 in __libc_start_main (/lib64/libc.so.6+0x23f32)
//
// ...

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

int main(void)
{
    auto p = new int;
    delete p;

    delete p;
}

// =================================================================
// ==24328==ERROR: AddressSanitizer: attempting double-free on 0x602000000010 in thread T0:
// #0 0x7f967d155105 in operator delete(void*, unsigned long) (/lib64/libasan.so.5+0x111105)
// #1 0x401185 in main /home/user/book/chapter07/recipe02.cpp:50
// #2 0x7f967cb48f32 in __libc_start_main (/lib64/libc.so.6+0x23f32)
// #3 0x40109d in _start (/home/user/book/chapter07/build/recipe02_example02+0x40109d)
//
// ...

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

int main(void)
{
    int *p = (int *)42;
    *p = 0;
}

// AddressSanitizer:DEADLYSIGNAL
// =================================================================
// ==24694==ERROR: AddressSanitizer: SEGV on unknown address 0x00000000002a (pc 0x00000040116a bp 0x0000004011a0 sp 0x7fffe43eb398 T0)
// ==24694==The signal is caused by a WRITE memory access.
// ==24694==Hint: address points to the zero page.
// #0 0x401169 in main /home/user/book/chapter07/recipe02.cpp:82
// #1 0x7f5c4eb06f32 in __libc_start_main (/lib64/libc.so.6+0x23f32)
// #2 0x40108d in _start (/home/user/book/chapter07/build/recipe02_example03+0x40108d)
//
// ...

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

int main(void)
{
    auto p = new int;
    delete p;

    *p = 0;
}

// =================================================================
// ==24957==ERROR: AddressSanitizer: heap-use-after-free on address 0x602000000010 at pc 0x0000004011c2 bp 0x7ffd87177460 sp 0x7ffd87177450
// WRITE of size 4 at 0x602000000010 thread T0
// #0 0x4011c1 in main /home/user/book/chapter07/recipe02.cpp:108
// #1 0x7fab4d427f32 in __libc_start_main (/lib64/libc.so.6+0x23f32)
// #2 0x4010ad in _start (/home/user/book/chapter07/build/recipe02_example04+0x4010ad)
//
// ...

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

int main(void)
{
    int *p = (int *)42;
    delete p;
}

// =================================================================
// ==25263==ERROR: AddressSanitizer: SEGV on unknown address 0x00000000001a (pc 0x7f9212dbac7f bp 0x000000000004 sp 0x7fff4e63b100 T0)
// ==25263==The signal is caused by a WRITE memory access.
// ==25263==Hint: address points to the zero page.
// #0 0x7f9212dbac7e (/lib64/libasan.so.5+0x28c7e)
// #1 0x7f9212ea30cc in operator delete(void*, unsigned long) (/lib64/libasan.so.5+0x1110cc)
// #2 0x401158 in main /home/user/book/chapter07/recipe02.cpp:172
// #3 0x7f9212896f32 in __libc_start_main (/lib64/libc.so.6+0x23f32)
// #4 0x40108d in _start (/home/user/book/chapter07/build/recipe02_example05+0x40108d)
//
// ...

#endif
