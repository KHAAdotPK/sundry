# Sundry
Sundry is a collection of utility functions designed to simplify common tasks. Currently, it includes three functions: `cooked_read()`, `cooked_write()`, and `cooked_rand()`. More functions may be added in the future, spanning different languages, such as Rust.

## Usage
### Clone the Repository
To use Sundry in your project, Clone the repository into your `./lib` directory:
```bash
git clone https://github.com/KHAAdotPK/sundry.git ./lib/sundry
```
### Dependencies

Sundry relies on two dependencies, which are also hosted on GitHub at [KHAAdotPK/ala_exception](https://github.com/KHAAdotPK/ala_exception) and [KHAAdotPK/string](https://github.com/KHAAdotPK/string). Make sure to clone these repositories as well in your project.

```bash
git clone https://github.com/KHAAdotPK/ala_exception.git ./lib/ala_exception
git clone https://github.com/KHAAdotPK/string.git ./lib/string
```
### Example Usage
Here is an example code snippet demonstrating the usage of Sundry functions in your project:
```C++
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
```

If you find issues or have suggestions for improvement, feel free to contribute!

### License
This project is governed by a license, the details of which can be located in the accompanying file named 'LICENSE.' Please refer to this file for comprehensive information.
