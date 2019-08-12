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

// ==16917== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==16917== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==16917== Command: ./recipe03_example01
// ==16917==
// ==16917==
// ==16917== HEAP SUMMARY:
// ==16917==     in use at exit: 4 bytes in 1 blocks
// ==16917==   total heap usage: 2 allocs, 1 frees, 72,708 bytes allocated
// ==16917==
// ==16917== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
// ==16917==    at 0x4838E86: operator new(unsigned long) (vg_replace_malloc.c:344)
// ==16917==    by 0x401133: main (in /home/rianquinn/book/chapter06/build/recipe03_example01)
// ==16917==
// ==16917== LEAK SUMMARY:
// ==16917==    definitely lost: 4 bytes in 1 blocks
// ==16917==    indirectly lost: 0 bytes in 0 blocks
// ==16917==      possibly lost: 0 bytes in 0 blocks
// ==16917==    still reachable: 0 bytes in 0 blocks
// ==16917==         suppressed: 0 bytes in 0 blocks
// ==16917==
// ==16917== For lists of detected and suppressed errors, rerun with: -s
// ==16917== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

int main(void)
{
    auto ptr = new int;
    delete ptr;
}

// ==17319== Memcheck, a memory error detector
// ==17319== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==17319== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==17319== Command: ./recipe03_example02
// ==17319==
// ==17319==
// ==17319== HEAP SUMMARY:
// ==17319==     in use at exit: 0 bytes in 0 blocks
// ==17319==   total heap usage: 2 allocs, 2 frees, 72,708 bytes allocated
// ==17319==
// ==17319== All heap blocks were freed -- no leaks are possible
// ==17319==
// ==17319== For lists of detected and suppressed errors, rerun with: -s
// ==17319== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <list>
std::list<int> data;

int main(void)
{
    for (auto i = 0; i < 10000; i++) {
        data.push_back(i);
    }
}

// ==17627== Memcheck, a memory error detector
// ==17627== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==17627== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==17627== Command: ./recipe03_example03
// ==17627==
// ==17627==
// ==17627== HEAP SUMMARY:
// ==17627==     in use at exit: 0 bytes in 0 blocks
// ==17627==   total heap usage: 10,001 allocs, 10,001 frees, 312,704 bytes allocated
// ==17627==
// ==17627== All heap blocks were freed -- no leaks are possible
// ==17627==
// ==17627== For lists of detected and suppressed errors, rerun with: -s
// ==17627== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <vector>
std::vector<int> data;

int main(void)
{
    for (auto i = 0; i < 10000; i++) {
        data.push_back(i);
    }
}

// ==18258== Memcheck, a memory error detector
// ==18258== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==18258== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==18258== Command: ./recipe03_example04
// ==18258==
// ==18258==
// ==18258== HEAP SUMMARY:
// ==18258==     in use at exit: 0 bytes in 0 blocks
// ==18258==   total heap usage: 16 allocs, 16 frees, 203,772 bytes allocated
// ==18258==
// ==18258== All heap blocks were freed -- no leaks are possible
// ==18258==
// ==18258== For lists of detected and suppressed errors, rerun with: -s
// ==18258== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <deque>
std::deque<int> data;

int main(void)
{
    for (auto i = 0; i < 10000; i++) {
        data.push_back(i);
    }
}

// ==18281== Memcheck, a memory error detector
// ==18281== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==18281== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==18281== Command: ./recipe03_example05
// ==18281==
// ==18281==
// ==18281== HEAP SUMMARY:
// ==18281==     in use at exit: 0 bytes in 0 blocks
// ==18281==   total heap usage: 85 allocs, 85 frees, 115,552 bytes allocated
// ==18281==
// ==18281== All heap blocks were freed -- no leaks are possible
// ==18281==
// ==18281== For lists of detected and suppressed errors, rerun with: -s
// ==18281== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

#endif
