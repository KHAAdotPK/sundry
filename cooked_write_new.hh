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

        E* ptr = NULL;
        try 
        {            
            ptr = cc_tokenizer::allocator<E>().allocate(data.getShape().getN());

            for (cc_tokenizer::string_character_traits<char>::size_type i = 0; i < data.getShape().getN(); i++)
            {
                ptr[i] = data[i];
            }           
        }
        catch (std::bad_alloc& e)
        {
            throw ala_exception(cc_tokenizer::String<char>("cooked_write() Error: ") + e.what());
        }
        catch (std::length_error& e)
        {
            throw ala_exception(cc_tokenizer::String<char>("cooked_write() Error: ") + e.what());
        }
        catch (ala_exception& e)
        {
            throw ala_exception(cc_tokenizer::String<char>("cooked_write() -> ") + e.what());
        }

        file.write((char*)ptr, data.getShape().getN()*sizeof(E));            

        // Check for any write errors, make sure that your program stops here
        if (!file.good()) 
        {
            throw ala_exception("cooked_write() Error: Failed during file write operation.");
        }
        
        cc_tokenizer::allocator<E>().deallocate(ptr, data.getShape().getN());

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
