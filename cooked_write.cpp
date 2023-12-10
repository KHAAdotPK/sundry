/*
    lib/sundry/cooked_write.cpp
    Q@khaa.pk
 */

#include "cooked_write.hh"

namespace cc_tokenizer 
{
template<>
void cooked_write(cc_tokenizer::String<char> file_name, cc_tokenizer::String<char> data) throw(ala_exception) 
{
    std::fstream file;

    file.open(file_name.c_str(), std::fstream::out | std::fstream::app);

    if (file.fail())
    {
        throw ala_exception(cc_tokenizer::String<char>("cooked_write() - failed to open \"") + cc_tokenizer::String<char>(file_name) + cc_tokenizer::String<char>("\""));
    }

    file.seekg(0, std::fstream::end);

    if (file.fail())
    {
        file.close();
        throw ala_exception("cooked_write() - seek() failed");
    }

    file.write(data.c_str(), data.size());

    if (file.bad())
    {
        file.close();
        throw ala_exception("cooked_write() - write() failed");
    }

    file.close();    
}
}