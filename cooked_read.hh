/* 
   lib/sundry/cooked_read.hh
   Q@khaa.pk
 */

#include <iostream>
#include <fstream>

#include "../ala_exception/ala_exception.hh"
#include "../string/src/String.hh"

namespace cc_tokenizer 
{
template<typename E>
cc_tokenizer::String<E> cooked_read(cc_tokenizer::String<E>) throw(ala_exception);

//cc_tokenizer::String<char> cooked_read(cc_tokenizer::String<char>) throw(ala_exception);
}

