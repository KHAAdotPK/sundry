/*
    lib/sundry/cooked_write_new.hh
    Q@khaa.pk
 */

#include <iostream>
#include <fstream>

#include "../ala_exception/ala_exception.hh"
#include "../string/src/String.hh"

#ifndef SUNDRY_COOKED_WRITE_HH
#define SUNDRY_COOKED_WRITE_HH

namespace cc_tokenizer
{
    template<typename E>
    void cooked_write(cc_tokenizer::String<E> file_name, cc_tokenizer::String<E> data) throw(ala_exception) 
    {
        std::fstream file;

        file.open(file_name.c_str(), std::fstream::out | std::fstream::app);

        if (file.fail())
        {
            throw ala_exception(cc_tokenizer::String<char>("cooked_write() Error: failed to open \"") + cc_tokenizer::String<char>(file_name) + cc_tokenizer::String<char>("\""));
        }

        file.seekg(0, std::fstream::end);

        if (file.fail())
        {
            file.close();
            throw ala_exception("cooked_write() Error: seek() failed");
        }

        file.write(data.c_str(), data.size());

        if (file.bad())
        {
            file.close();
            throw ala_exception("cooked_write() Error: write() failed");
        }

        file.close();   
    }
}

#endif
