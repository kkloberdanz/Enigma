/*
 * Programmer    : Kyle Kloberdanz
 * Date Created  : 19 Feb 2015
 * Description   : A simplified implementation of the enigma cipher.
 *                 Uses 1 rotor instead of 3
 *
 * File          : enigma.h
 */

#ifndef ENIGMA_H
#define ENIGMA_H

std::string preproscess(std::string line, bool noSpaces);
bool isLetter(char);
std::string preproscess(std::string, bool );
void printHelp();
#endif
