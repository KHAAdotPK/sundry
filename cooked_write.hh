/*
    lib/sundry/cooked_write.hh
    Q@khaa.pk
 */

#include <iostream>
#include <fstream>

#include "../ala_exception/ala_exception.hh"
#include "../string/src/String.hh"

namespace cc_tokenizer
{
template<typename E>
void cooked_write(cc_tokenizer::String<E>, cc_tokenizer::String<char>) throw(ala_exception);

//cc_tokenizer::String<char> cooked_read(cc_tokenizer::String<char>) throw(ala_exception);
}