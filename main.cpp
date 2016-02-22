/*
 * Programmer    : Kyle Kloberdanz
 * Date Created  : 19 Feb 2015
 * Description   : A simplified implementation of the enigma cipher.
 *                 Uses 1 rotor instead of 3
 * 
 * File          : main.cpp
 *
 * Usage:
 *     To encrypt:
 *                : To encipher:
 *                    ./enigma INPUTFILE OUTPUTFILE
 *
 *                Encipher without spaces:
 *                    ./enigma INPUTFILE OUTPUTFILE --no-spaces
 *
 *                To decipher:
 *                    ./enigma INPUTFILE OUTPUTFILE -d
 *
 *                Decipher withoug spaces:
 *                    ./enigma INPUTFILE OUTPUTFILE -d --no-spaces
 *
 * Notes        : Compiled with g++ (Debian 5.3.1-8) (stretch-sid)
 *                and GNU Make 4.1
 *                Complier MUST be compatable with c++11 standard
 *
 *                For best results, compile and run with a linux system
 *                (Not tested for Windows, OSX, or any other OS)
 *
 *                To compile, ensure you are in the same directory as the
 *                Makefile, then type 'make'
 *
 *                To compile without make: 
 *                'g++ main.cpp enigma.cpp Rotor.cpp -o enigma -Wall -Wextra -O2 -std=c++11'
 *              
 *
 */
#include <iostream>
#include <cstdlib>
#include <fstream>

#include "enigma.h"
#include "Rotor.h"

int main(int argc, char* argv[]){

    /*
     * input handling
     */
    Rotor rotor1;
    //std::string startingPosition = "pnvqtaeuxclkwgiohmbjfdrszy";

    bool setDecrypt = false;
    bool noSpaces   = false;
    if( (argc > 1) && ((std::string)argv[1] == "--help" ) ){
        printHelp();
        std::exit(EXIT_FAILURE);

    } else if( (argc == 4) && ((std::string)argv[3] == "-d") ){
        setDecrypt = true;

    } else if ( (argc == 4) && ((std::string)argv[3] == "--no-spaces") ) {
        noSpaces = true;

    } else if ( (argc == 5) && ((std::string)argv[3] == "-d") 
                            && ((std::string)argv[4] == "--no-spaces")){
        setDecrypt = true;
        noSpaces = true;

    } else if( argc < 3 ){
        std::cout << "enigma: not enough input arguments" << std::endl;
        std::cout << "(Type enigma --help for usage)" << std::endl;
        std::exit(EXIT_FAILURE);

    } else if( argc > 3 ){
        std::cout << "enigma: too many input arguments" << std::endl;
        std::cout << "(Type enigma --help for usage)" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    char* inputFilename = argv[1]; 

    std::ifstream inputFile;

    inputFile.open(inputFilename);

    if( !inputFile.is_open() ){
        std::cout << "enigma: Could not open file: " << inputFilename << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::ofstream outputFile;
    char* outputFilename = argv[2];

    outputFile.open(outputFilename);

    std::string line;
    std::string plainText = "";
    std::string keyString = "";
    std::string cipherText = "";
    std::string decipheredText = "";

    /*
    std::cout << (setDecrypt? "Enter key to decrypt: " :
                         "Enter key to encrypt: ");
    std::cin >> key;
    */
    std::string key;
    if( setDecrypt ){
        std::cout << "Enter key to decrypt: ";
        getline(std::cin, key);

        if(key.length() != 26){
            std::cout << "Key is not the correct length!" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }

    if( setDecrypt ){
        rotor1.initialize(key);
        while( getline(inputFile, line) ){
            // remove non-alpha characters and lowercase all letters
            cipherText = preproscess(line, noSpaces); 
            decipheredText = rotor1.decipherString(cipherText);
            outputFile << decipheredText << std::endl;
        }

    } else {
        rotor1.initialize();
        while( getline(inputFile, line) ){
            // remove non-alpha characters and lowercase all letters
            plainText  = preproscess(line, noSpaces);
            cipherText = rotor1.encryptString(plainText); 
            outputFile << cipherText << std::endl;
        }
    }

    outputFile.close();
    inputFile.close();
    return 0;
}
