/*
 * Programmer    : Kyle Kloberdanz
 * Date Created  : 19 Feb 2015
 * Description   : A simplified implementation of the enigma cipher.
 *                 Uses 1 rotor instead of 3
 *
 * File          : Rotor.h
 */

#ifndef ROTOR_H
#define ROTOR_H

#include <vector>

class Rotor{
    private:
        std::vector<char> shiftRotor;
    public:
        Rotor();
        void printShiftRotor();
        void initialize();
        void initialize(std::string);
        void shiftRight();
        void shiftLeft();
        std::string encryptString(std::string);
        std::string decipherString(std::string);
};
#endif
