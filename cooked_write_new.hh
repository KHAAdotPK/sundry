/*
    lib/sundry/cooked_write_new.hh
    Q@khaa.pk
 */

#include <iostream>
#include <fstream>

//#include "../ala_exception/ala_exception.hh"
//#include "../string/src/String.hh"
#include "../Numcy/header.hh"

#ifndef SUNDRY_COOKED_WRITE_HH
#define SUNDRY_COOKED_WRITE_HH

namespace cc_tokenizer
{
    /*template<typename E>
    void cooked_write(cc_tokenizer::String<char>, E*) throw(ala_exception);*/
    
    template<typename E>
    void cooked_write(cc_tokenizer::String<char> file_name, Collective<E>& data) throw(ala_exception)
    {
        if (data.getShape().getN() == 0)
        {
            throw ala_exception("cooked_write() Error: Data object has an empty shape or uninitialized dimensions.");
        }

        /*
            No checking of file if it already exits
         */
        

        // Proceed with writing data in binary format 

        std::ofstream file(file_name.c_str(), std::ios::binary);
        if (!file) 
        {
            throw ala_exception(cc_tokenizer::String<char>("cooked_write() Error: Failed to open file ") + file_name + cc_tokenizer::String<char>(" for writing."));
        }

        char* ptr = NULL;
        try 
        {
            ptr = reinterpret_cast<char*>(data.slice(0, data.getShape().getN()));            
        }
        catch (ala_exception& e)
        {
            throw ala_exception(cc_tokenizer::String<char>("cooked_write() -> ") + e.what());
        }

        file.write(ptr, data.getShape().getN()*sizeof(E));            

        // Check for any write errors, make sure that your program stops here
        if (!file.good()) 
        {
            throw ala_exception("cooked_write() Error: Failed during file write operation.");
        }
        
        cc_tokenizer::allocator<char>().deallocate(ptr, data.getShape().getN()*sizeof(E));

        file.close();
    }    

    template<typename E>
    void cooked_write(cc_tokenizer::String<char> file_name, cc_tokenizer::String<E> data) throw(ala_exception) 
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
