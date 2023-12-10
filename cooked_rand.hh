/* 
   lib/sundry/cooked_rand.hh 
   Q@khaa.pk
 */

#include <iostream>
//#include <cstdlib>
#include <ctime>

#include "../string/src/string_character_traits.hh"

namespace cc_tokenizer 
{

// Returns a random number, bounded by 'low' and 'high'(inclusive bounds)
cc_tokenizer::string_character_traits<char>::int_type cooked_rand_worker1(cc_tokenizer::string_character_traits<char>::int_type, cc_tokenizer::string_character_traits<char>::int_type);

// Checks if a random number 'n' is already in array 'ptr' at 'i'th location. if'n' is there(at i'th location), then false is returned
bool cooked_rand_worker2(const cc_tokenizer::string_character_traits<char>::int_type*, cc_tokenizer::string_character_traits<char>::int_type, cc_tokenizer::string_character_traits<char>::int_type = 0); 

// TODO, This function now returns '0'(always). Make it return something meaningful, otherwise make it return void
// Generates a random number, bounded by 'low' and 'high'(inclusive bounds). Store it in an array 'ptr' of unique(mutually exclusive) 'n' random numbers at location 'i'. This function always returns '0' 
cc_tokenizer::string_character_traits<char>::int_type cooked_rand(cc_tokenizer::string_character_traits<char>::int_type*, cc_tokenizer::string_character_traits<char>::int_type, cc_tokenizer::string_character_traits<char>::int_type, cc_tokenizer::string_character_traits<char>::int_type, cc_tokenizer::string_character_traits<char>::int_type = 0);
}

