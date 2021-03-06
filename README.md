TypeSection
===========

This is the beginning of an LLVM pass that add stores type information of
symboltable entries in a separate object file section.

The goal of this is to allow easier interoperation with compiled languages.
Another advantage might be a simplified C build process.

Setup for development
--------------------

Get llvm, run `./configure` and `make`, wait 10 minutes. Then clone this project inside it's `lib/Transforms`
directory. Go there, and run `make`. It should compile without errors.

Run `./run-example.sh` to run the pass over the example file.

University of Illinois/NCSA Open Source License
===============================================
Copyright (c) 2012 Tinco Andringa 
All rights reserved.

Developed by:       Tinco Andringa
                    http://www.tinco.nl     

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal with the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimers.
Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimers in the documentation and/or other materials provided with the distribution.
Neither the names of Tinco Andringa, nor the names of its contributors may be used to endorse or promote products derived from this Software without specific prior written permission.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE SOFTWARE.
