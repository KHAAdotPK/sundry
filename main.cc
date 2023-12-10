/* 
    main.cc
    Q@khaa.pk 
*/

#include "./lib/sundry/cooked_rand.hh"
#include "./lib/sundry/cooked_read.hh"
#include "./lib/sundry/cooked_write.hh"

using namespace cc_tokenizer;

int main(int argc, char* argv[]) 
{
    int *n = NULL;
    String<char> data;

    try 
    {
        n = cc_tokenizer::allocator<int>().allocate(4);
    }
    catch (std::length_error &e)
    {
        std::cout<< e.what() << std::endl;
        return -1;
    }
    catch (std::bad_alloc &e)
    {
        std::cout<< e.what() << std::endl;
        return -1;
    }

    try 
    {
        cooked_rand(n, 4, 1, 5); 
        data = cooked_read<char>(String<char>("project.xml"));
        cooked_write(String<char>("data.xml"), data);  
    }
    catch (ala_exception &e)
    {
        cc_tokenizer::allocator<int>().deallocate(n);

        std::cout<< e.what() << std::endl;

        return -1;
    }

    for (int i = 0; i < 4; i++)
    {
        std::cout<<"-> "<<n[i]<<std::endl;
    }

    std::cout<< data.c_str() << std::endl;
    
    cc_tokenizer::allocator<int>().deallocate(n);

    return 0;
}
