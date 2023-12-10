/* 
   lib/sundry/cooked_read.cc
   Q@khaa.pk
 */

#include "cooked_read.hh"

namespace cc_tokenizer
{
template<>
cc_tokenizer::String<char> cooked_read(cc_tokenizer::String<char> file_name) throw(ala_exception) 
{
   std::fstream file;
   //std::ifstream file;
   std::streampos length, i = 0;
   char* file_text = NULL;
   
   cc_tokenizer::allocator<char> alloc_obj;

   file.open(file_name.c_str(), std::fstream::in); 
   
   if (file.fail()) {
         
      throw ala_exception(cc_tokenizer::String<char>("cooked_read() - failed to open \"") + cc_tokenizer::String<char>(file_name) + cc_tokenizer::String<char>("\""));
   }
  
   file.seekg(0, std::fstream::end);

   if (file.fail()) {
      file.close();
      throw ala_exception("cooked_read() - seek() failed");
   }
   
   length = file.tellg();
   
   if (length <= 0) {
   
      file.close();
      throw ala_exception("cooked_read() - tellg() failed");
   }

   file.seekg(0, std::fstream::beg);
   
   if (file.fail()) {
   
      file.close();
      throw ala_exception("cooked_read() - seekg() failed");
   }	   

   try {

      /* Already made certain that length is more than zero, now the following call will not return a NULL value */
      file_text = alloc_obj.allocate(length);
   }
   catch(std::bad_alloc& e) {
	 
      file.close();
      throw ala_exception("cooked_read() - Caught std::bad_alloc");
   }
   catch(std::length_error& e) {
   
      file.close();
      throw ala_exception("cooked_read() - Caught std::length_error");
   }
   
   file.read(file_text, length);
      
   if (file.bad()) {

      alloc_obj.deallocate(file_text);
      
      file.close();
      throw ala_exception("cooked_read() - read() failed");
   } 

   // Go for Camel casing!  
   cc_tokenizer::String<char> fileTextAsStr(file_text, length);

   file.close();
 
   alloc_obj.deallocate(file_text);
    	    
   return fileTextAsStr;
}

}