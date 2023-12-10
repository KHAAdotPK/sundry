/* 
   lib/sundry/cooked_rand.cc
   Q@khaa.pk
 */

#include "cooked_rand.hh"

namespace cc_tokenizer {

// Returns a random number, bounded by 'low' and 'high'(inclusive bounds)
cc_tokenizer::string_character_traits<char>::int_type cooked_rand_worker1(cc_tokenizer::string_character_traits<char>::int_type low, cc_tokenizer::string_character_traits<char>::int_type high)
{
    cc_tokenizer::string_character_traits<char>::int_type n;

    do 
    {
        srand(time(NULL));

        n = rand()%10 + 1;
    }
    while (n < low || n > high);

    return n;
}

// Checks if a random number 'n' is already in array 'ptr' at 'i'th location. If 'n' is there(at i'th location), then false is returned
bool cooked_rand_worker2(const cc_tokenizer::string_character_traits<char>::int_type* ptr, cc_tokenizer::string_character_traits<char>::int_type n, cc_tokenizer::string_character_traits<char>::int_type i)
{
    bool ret = true; 

    if (!(i < 0))
    {
        if (ptr[i] == n)
	{
	    ret = false;
	}
	else
	{
	    ret = cooked_rand_worker2(ptr, n, i - 1);
	}
    }
        
    return ret;
}

// TODO, This function now returns '0'(always). Make it return something meaningful otherwise, make it return 'void'
// Gnerates a random number, bounded by 'low' and 'high'(inclusive bounds). Stores it in an array 'ptr' of unique(mutually exclusive) 'n' random numbers at location 'i'. This function always returns 0    
cc_tokenizer::string_character_traits<char>::int_type cooked_rand(cc_tokenizer::string_character_traits<char>::int_type* ptr, cc_tokenizer::string_character_traits<char>::int_type n, cc_tokenizer::string_character_traits<char>::int_type low, cc_tokenizer::string_character_traits<char>::int_type high, cc_tokenizer::string_character_traits<char>::int_type i)
{
    cc_tokenizer::string_character_traits<char>::int_type j = 0;
    
    /* Generate randon number, check it against all i - 1 locations */
    /* If num not in any of i - 1 locations put it at i'th location */
    do 
    {
        // Get a random number  
        j = cooked_rand_worker1(low, high);

        // Check, if it is a relatvely unique random number?  
    } 
    while (cooked_rand_worker2(ptr, j, i) != true);

    // Finally a unique number. Store it at i'th location
    ptr[i] = j;

    i = i + 1;

    if (!(i > n))
    {
        cooked_rand(ptr, n, low, high, i);
    }

    return 0; 
}
}
