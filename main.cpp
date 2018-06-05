#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <gmpxx.h>

int main(int argc, char * argv[])
{
    if (argc != 2 && argc != 3)
    {
        std::cout << std::endl << "Please enter a number to calculate the factorial of. \nLike this: factorial 6    [returns 720]" << std::endl
                  << "You can also specify an output file like this: \nfactorial 6 sixfactorial.txt    [writes 720 in sixfactorial.txt]"
                  << std::endl;
        return 1;
    }

    long inNum;

    try
    {
        inNum = std::stol(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl << "Please enter a valid number, it has to be a whole positive integer. \nLike this: factorial 6    [returns 720]" << std::endl
                  << "You can also specify an output file like this: \nfactorial 6 sixfactorial.txt    [writes 720 in sixfactorial.txt]"
                  << std::endl;
        return 2;
    }
    

    if (inNum > 100000)
    {

        if (argc != 3)
        {
            std::cout << std::endl
                     << "The result will not fit in the console, output file is required."
                     << "Try specifying an output file like this: \nfactorial 6 sixfactorial.txt    [writes 720 in sixfactorial.txt]"
                     << std::endl;
        }

        std::cout << std::endl << "This will take a while.\nYou can quit at any moment by pressing Ctrl+C.";
    }
    mpz_t numFact;
    mpz_init(numFact);
    mpz_set_ui(numFact, 1);

    for (long i = 1; i <= inNum; i++)
    {
        mpz_mul_ui(numFact, numFact, i);
    }

    if (argc == 3)
    {
        std::ofstream outFile(argv[2]);
        if (!outFile)
        {
            std::cout << std::endl << "Unable to open file" << argv[2] << std::endl
                      << "Try using it like this:\n factorial 6 sixfactorial.txt    [writes 720 in sixfactorial.txt]"
                      << std::endl;
            return 3;
        }
        else
        {
            outFile << std::endl << "Factorial of " << inNum << " is: " << std::endl << numFact << std::endl;
            std::cout << std::endl << "Factorial of " << inNum << " can be found in " << argv[2] << "." << std::endl;
        }
        outFile.close();
    }
    else
    {
        std::cout << std::endl << "Factorial of " << inNum << ": " << std::endl;
        mpz_out_str(stdout, 10, numFact);
        std::cout << std::endl;
    }


    mpz_clear(numFact);

    return 0;

}   