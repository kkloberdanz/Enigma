/*
 * Programmer    : Kyle Kloberdanz
 * Date Created  : 19 Feb 2015
 * Description   : A simplified implementation of the enigma cipher.
 *                 Uses 1 rotor instead of 3
 *
 * File          : enigma.cpp
 */
#include <iostream>
#include "enigma.h"
bool isLetter(char ch){
    return (((ch >= 'a')&&(ch <= 'z')) || ((ch >= 'A')&&(ch <= 'Z')));
}

std::string preproscess(std::string line, bool noSpaces){
    // Preproscessing, remove all non alpha characters, 
    // and lowercase all letters
    std::string outputline = "";
    unsigned int i;
    for( i = 0; i < line.length(); i++ ){
        if (noSpaces){
            if( (isLetter(line[i])) ){
                if( (line[i] >= 'A') && (line[i] <= 'Z') ){
                    // 32, the distance from a to A
                    line[i] = line[i] + 32;
                }
                outputline += line[i];
            }
        } else {
            if( (isLetter(line[i])) || (line[i] == ' ') ){
                if( (line[i] >= 'A') && (line[i] <= 'Z') ){
                    // 32, the distance from a to A
                    line[i] = line[i] + 32;
                }
                outputline += line[i];
            }
        }
    }
    return outputline;
}

void printHelp(){
    std::cout << "Usage: To encipher:\n"
            "        ./enigma INPUTFILE OUTPUTFILE\n\n"
 
            "Encipher without spaces:\n"
            "        ./enigma INPUTFILE OUTPUTFILE --no-spaces\n\n"

            "   To decipher:\n"
            "       ./enigma INPUTFILE OUTPUTFILE -d\n\n"

            "   Decipher withoug spaces:\n\n"
            "       ./enigma INPUTFILE OUTPUTFILE -d --no-spaces\n"
 << std::endl;
}

