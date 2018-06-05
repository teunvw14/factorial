#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <gmpxx.h>

int main(int argc, char * argv[])
{

    // First check if the user has specified two or three arguments.
    // If not, print out an error message and quit.
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
        inNum = std::stol(argv[1]); // Cast second argument to long, to use for further calculations.
    }
    catch(const std::exception& e) // Will throw an error if the input can't be cast to a long.
    {
        // Print out an error letting the user know the input was invalid and quit.
        std::cout << std::endl << "Please enter a valid number, it has to be a whole positive integer. \nLike this: factorial 6    [returns 720]" << std::endl
                  << "You can also specify an output file like this: \nfactorial 6 sixfactorial.txt    [writes 720 in sixfactorial.txt]"
                  << std::endl;
        return 2;
    }
    

    if (inNum > 100000)
    {
        // Some weird things happen when you take the factorial of large numbers.
        if (argc != 3)
        {
            // If the output is really large and there is no output file specified, warn the user.
            std::cout << std::endl
                     << "The result is unlikely to fit in the console, specifying an output file is stronly recommended."
                     << "Try specifying an output file like this: \nfactorial 6 sixfactorial.txt    [writes 720 in sixfactorial.txt]"
                     << std::endl;
        }

        // If the output is really large, warn the user it will take a while.
        std::cout << std::endl << "This will take a while.\nYou can quit at any moment by pressing Ctrl+C.";
    }

    // Initialize the factorial variable and set it to 1.
    mpz_t numFact;
    mpz_init(numFact);
    mpz_set_ui(numFact, 1);

    // Calculate the factorial; it's stored in the numFact variable.
    for (long i = 1; i <= inNum; i++)
    {
        mpz_mul_ui(numFact, numFact, i);
    }

    if (argc == 3) // Output file specified
    {
        // Try opening the file.
        std::ofstream outFile(argv[2]);
        if (!outFile)
        {
            // Warn the user if the program is unable to open the output file and quit.
            std::cout << std::endl << "Unable to open file " << argv[2] << ". "<< std::endl
                      << "Try using it like this:\n factorial 6 sixfactorial.txt    [writes 720 in sixfactorial.txt]"
                      << std::endl;
            return 3;
        }
        else
        {
            // Store the result of the factorial in the output file.
            outFile << std::endl << "Factorial of " << inNum << " is: " << std::endl << numFact << std::endl;
            std::cout << std::endl << "Factorial of " << inNum << " can be found in " << argv[2] << "." << std::endl;
        }
        outFile.close();
    }
    else
    {
        // Display the factorial in the console.
        std::cout << std::endl << "Factorial of " << inNum << ": " << std::endl;
        mpz_out_str(stdout, 10, numFact);
        std::cout << std::endl;
    }
    // Clear the memory allocated for numFact variable.
    mpz_clear(numFact);

    return 0;
}   