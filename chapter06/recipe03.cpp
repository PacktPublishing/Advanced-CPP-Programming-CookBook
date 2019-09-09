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
}

// > valgrind ./recipe03_example01
// ==8260== Memcheck, a memory error detector
// ==8260== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==8260== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==8260== Command: ./recipe03_example01
// ==8260==
// ==8260==
// ==8260== HEAP SUMMARY:
// ==8260==     in use at exit: 0 bytes in 0 blocks
// ==8260==   total heap usage: 1 allocs, 1 frees, 72,704 bytes allocated
// ==8260==
// ==8260== All heap blocks were freed -- no leaks are possible
// ==8260==
// ==8260== For lists of detected and suppressed errors, rerun with: -s
// ==8260== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

// > valgrind --tool=massif ./recipe03_example01
// ==8462== Massif, a heap profiler
// ==8462== Copyright (C) 2003-2017, and GNU GPL'd, by Nicholas Nethercote
// ==8462== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==8462== Command: ./recipe03_example01
// ==8462==
// ==8462==

// > cat massif.out.8462
// desc: (none)
// cmd: ./recipe03_example01
// time_unit: i
// ...
// #-----------
// snapshot=2
// #-----------
// time=2570959
// mem_heap_B=72704
// mem_heap_extra_B=8
// mem_stacks_B=0
// heap_tree=peak
// n1: 72704 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
//  n1: 72704 0x4922E89: ??? (in /usr/lib64/libstdc++.so.6.0.26)
//   n1: 72704 0x400FF59: call_init.part.0 (in /usr/lib64/ld-2.29.so)
//    n1: 72704 0x4010060: _dl_init (in /usr/lib64/ld-2.29.so)
//     n0: 72704 0x4001149: ??? (in /usr/lib64/ld-2.29.so)
// ...

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

int main(void)
{
    auto ptr = new int;
    delete ptr;
}

// > valgrind ./recipe03_example02
// ==8857== Memcheck, a memory error detector
// ==8857== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==8857== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==8857== Command: ./recipe03_example02
// ==8857==
// ==8857==
// ==8857== HEAP SUMMARY:
// ==8857==     in use at exit: 0 bytes in 0 blocks
// ==8857==   total heap usage: 2 allocs, 2 frees, 72,708 bytes allocated
// ==8857==
// ==8857== All heap blocks were freed -- no leaks are possible
// ==8857==
// ==8857== For lists of detected and suppressed errors, rerun with: -s
// ==8857== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

// > valgrind --tool=massif --threshold=0.1 ./recipe03_example02
// ==10257== Massif, a heap profiler
// ==10257== Copyright (C) 2003-2017, and GNU GPL'd, by Nicholas Nethercote
// ==10257== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==10257== Command: ./recipe03_example02
// ==10257==
// ==10257==

// desc: --threshold=0.1
// cmd: ./recipe03_example02
// time_unit: i
// ...
// #-----------
// snapshot=3
// #-----------
// time=2561576
// mem_heap_B=472704
// mem_heap_extra_B=16
// mem_stacks_B=0
// heap_tree=peak
// n2: 472704 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
//  n0: 400000 0x401147: main (in /home/user/book/chapter06/build/recipe03_example02)
//  n1: 72704 0x4922E89: ??? (in /usr/lib64/libstdc++.so.6.0.26)
//   n1: 72704 0x400FF59: call_init.part.0 (in /usr/lib64/ld-2.29.so)
//    n1: 72704 0x4010060: _dl_init (in /usr/lib64/ld-2.29.so)
//     n0: 72704 0x4001149: ??? (in /usr/lib64/ld-2.29.so)
// ...

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <vector>
std::vector<int> data;

int main(void)
{
    for (auto i = 0; i < 10000; i++) {
        data.push_back(i);
    }
}

// > valgrind ./recipe03_example03
// ==11063== Memcheck, a memory error detector
// ==11063== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==11063== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==11063== Command: ./recipe03_example03
// ==11063==
// ==11063==
// ==11063== HEAP SUMMARY:
// ==11063==     in use at exit: 0 bytes in 0 blocks
// ==11063==   total heap usage: 16 allocs, 16 frees, 203,772 bytes allocated
// ==11063==
// ==11063== All heap blocks were freed -- no leaks are possible
// ==11063==
// ==11063== For lists of detected and suppressed errors, rerun with: -s
// ==11063== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <vector>
std::vector<int> data;

int main(void)
{
    data.reserve(10000);

    for (auto i = 0; i < 10000; i++) {
        data.push_back(i);
    }
}

// > valgrind ./recipe03_example04
// ==11859== Memcheck, a memory error detector
// ==11859== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==11859== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==11859== Command: ./recipe03_example04
// ==11859==
// ==11859==
// ==11859== HEAP SUMMARY:
// ==11859==     in use at exit: 0 bytes in 0 blocks
// ==11859==   total heap usage: 2 allocs, 2 frees, 112,704 bytes allocated
// ==11859==
// ==11859== All heap blocks were freed -- no leaks are possible
// ==11859==
// ==11859== For lists of detected and suppressed errors, rerun with: -s
// ==11859== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <any>
#include <string>

std::any data;

int main(void)
{
    data = 42;
    data = std::string{"The answer is: 42"};
}

// > valgrind ./recipe03_example05
// ==14224== Memcheck, a memory error detector
// ==14224== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==14224== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==14224== Command: ./recipe03_example05
// ==14224==
// ==14224==
// ==14224== HEAP SUMMARY:
// ==14224==     in use at exit: 0 bytes in 0 blocks
// ==14224==   total heap usage: 3 allocs, 3 frees, 72,754 bytes allocated
// ==14224==
// ==14224== All heap blocks were freed -- no leaks are possible
// ==14224==
// ==14224== For lists of detected and suppressed errors, rerun with: -s
// ==14224== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE06

#include <any>
#include <string>

std::any data;

int main(void)
{
    data = 42;
    data = std::string{"The answer is: 42"};
    data = 42;
    data = std::string{"The answer is: 42"};
    data = 42;
    data = std::string{"The answer is: 42"};
    data = 42;
    data = std::string{"The answer is: 42"};
}

// > valgrind ./recipe03_example06
// ==15074== Memcheck, a memory error detector
// ==15074== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==15074== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==15074== Command: ./recipe03_example06
// ==15074==
// ==15074==
// ==15074== HEAP SUMMARY:
// ==15074==     in use at exit: 0 bytes in 0 blocks
// ==15074==   total heap usage: 9 allocs, 9 frees, 72,904 bytes allocated
// ==15074==
// ==15074== All heap blocks were freed -- no leaks are possible
// ==15074==
// ==15074== For lists of detected and suppressed errors, rerun with: -s
// ==15074== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE07

#include <variant>
#include <string>

std::variant<int, std::string> data;

int main(void)
{
    data = 42;
    data = std::string{"The answer is: 42"};
}

// > valgrind ./recipe03_example07
// ==15411== Memcheck, a memory error detector
// ==15411== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==15411== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==15411== Command: ./recipe03_example07
// ==15411==
// ==15411==
// ==15411== HEAP SUMMARY:
// ==15411==     in use at exit: 0 bytes in 0 blocks
// ==15411==   total heap usage: 2 allocs, 2 frees, 72,722 bytes allocated
// ==15411==
// ==15411== All heap blocks were freed -- no leaks are possible
// ==15411==
// ==15411== For lists of detected and suppressed errors, rerun with: -s
// ==15411== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

#endif
