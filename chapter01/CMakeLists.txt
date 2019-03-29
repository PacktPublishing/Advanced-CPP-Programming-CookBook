#
# Copyright (C) 2019 Rian Quinn <rianquinn@gmail.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# ------------------------------------------------------------------------------
# Header
# ------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.6)
project(chapter01)

include(ExternalProject)
find_package(Git REQUIRED)

set(CMAKE_CXX_STANDARD 17)

function(example recipe number)
    add_executable(${recipe}_example${number} ${recipe}.cpp)
    target_compile_definitions(${recipe}_example${number} PRIVATE EXAMPLE${number} BOOST_LOG_DYN_LINK)

    target_link_libraries(${recipe}_example${number} follybenchmark folly glog gflags double-conversion boost_chrono boost_log boost_regex boost_system pthread)
endfunction(example)

# ------------------------------------------------------------------------------
# Examples
# ------------------------------------------------------------------------------

example(recipe01 01)
example(recipe01 02)
example(recipe01 03)
example(recipe01 04)
example(recipe01 05)
example(recipe01 06)
example(recipe01 07)
example(recipe01 08)
example(recipe01 09)
example(recipe01 10)

example(recipe02 01)
example(recipe02 02)

example(recipe03 01)
example(recipe03 02)

example(recipe04 01)
example(recipe04 02)
