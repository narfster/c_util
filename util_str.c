//! \file util_str.c
//!
//! \author Dan Yerushalmi https://github.com/narfster
//!
//! \date 11/09/2019
//!
//! \brief string utilites
//!
//! \copyright MIT License 2019 Dan Yerushalmi (c)
//! 
//! Permission is hereby granted, free of charge, to any person obtaining a copy
//! of this software and associated documentation files (the "Software"), to deal
//! in the Software without restriction, including without limitation the rights
//! to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//! copies of the Software, and to permit persons to whom the Software is
//! furnished to do so, subject to the following conditions:
//!
//! The above copyright notice and this permission notice shall be included in all
//! copies or substantial portions of the Software.
//! 
//! THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//! IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//! FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//! AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//! LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//! OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//! SOFTWARE.


#include "string.h"


//! Split string by delimiter
//!
//! \arg str -  String to split must be mutable
//! \arg argv[] - point to tokens stored in str 
//! \arg argv_len - length of given argv array
//! \arg split_count - number of tokens found
//! \arg delim - the characters to use as delimiter
//! 
//! fucntion will add null characters between tokens into orginal string
//! if you don't want function to touch original string, send in a copy.
//! argv An array of char pointers, each char pointer will point to
//! first character of token in char* str
void util_str_split(char* str ,
                    char* argv[],
                    int argv_len, 
                    int* split_count, 
                    const char* delim){

    char* token; 
    char* rest = str; 
    int count_elem = 0;
  
    while ((token = strtok_r(rest, delim, &rest)) && count_elem < argv_len) 
    {
        argv[count_elem] = token;
        count_elem++;
    }
    
    if(count_elem > 1){
        *split_count = count_elem - 1;
    }
        
}




