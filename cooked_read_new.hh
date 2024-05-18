/*
    sundry/cooked_read_new.hh
    Q@khaa.pk
 */

#include <iostream>
#include <fstream>

#include "../ala_exception/ala_exception.hh"
#include "../string/src/String.hh"

#ifndef SUNDRY_COOKED_READ_NEW_HH
#define SUNDRY_COOKED_READ_NEW_HH

namespace cc_tokenizer
{
    template<typename E>
    cc_tokenizer::String<E> cooked_read(cc_tokenizer::String<E>) throw(ala_exception);

    template<>
    cc_tokenizer::String<char> cooked_read(cc_tokenizer::String<char> file_name) throw(ala_exception) 
    {
        std::fstream file;        
        std::streampos length, i = 0;
        char* file_text = NULL;
   
        cc_tokenizer::allocator<char> alloc_obj;

        file.open(file_name.c_str(), std::fstream::in); 
   
        if (file.fail())
        {         
            throw ala_exception(cc_tokenizer::String<char>("cooked_read() Error: Failed to open \"") + cc_tokenizer::String<char>(file_name) + cc_tokenizer::String<char>("\"."));
        }
  
        file.seekg(0, std::fstream::end);

        if (file.fail())
        {
            file.close();
            throw ala_exception("cooked_read() Error: seek() failed.");
        }
   
        length = file.tellg();
   
        if (length <= 0)
        {   
            file.close();
            throw ala_exception("cooked_read() Error: tellg() failed.");
        }

        file.seekg(0, std::fstream::beg);
   
        if (file.fail())
        {   
            file.close();
            throw ala_exception("cooked_read() Error: seekg() failed.");
        }	   

        try
        {
            /* Already made certain that length is more than zero, now the following call will not return a NULL value */
            file_text = alloc_obj.allocate(length);
        }
        catch(std::bad_alloc& e)
        {	 
            file.close();
            throw ala_exception(cc_tokenizer::String<char>("cooked_read() Error: ") + cc_tokenizer::String<char>(e.what()));
        }
        catch(std::length_error& e)
        {   
            file.close();
            throw ala_exception(cc_tokenizer::String<char>("cooked_read() Error: ") + cc_tokenizer::String<char>(e.what()));
        }    
   
        file.read(file_text, length);
      
        if (file.bad())
        {
            alloc_obj.deallocate(file_text);
      
            file.close();
            throw ala_exception("cooked_read() Error: read() failed.");
        } 

        // Go for Camel casing!  
        cc_tokenizer::String<char> fileTextAsStr(file_text, length);

        file.close();
 
        alloc_obj.deallocate(file_text);
    	    
       return fileTextAsStr;
    }
}
#endif