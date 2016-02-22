/*
 * Programmer    : Kyle Kloberdanz
 * Date Created  : 19 Feb 2015
 * Description   : A simplified implementation of the enigma cipher.
 *                 Uses 1 rotor instead of 3
 *
 * File          : Rotor.cpp
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iterator>
#include <random>
#include "Rotor.h"
#include "enigma.h"

Rotor::Rotor(){
}

void Rotor::printShiftRotor(){
    for( std::vector<char>::iterator it = shiftRotor.begin(); 
                                it != shiftRotor.end(); it++ ){
        //std::cout << *it << ' ';
        std::cout << *it;
    }
    std::cout << std::endl;
}

void Rotor::initialize(){
    /*
    shiftRotor = {'b','z','e','p','l','w','m','s','y','o','k','n','c','t','g','d','h','x','i','u','j','q','v','r','f','a'};
    int i;
    for( i = 0; i < shiftAmounts; i++ ){
        this->shiftLeft();
    }
    */

    // fills the std::vector, shiftRotor with the letters a -> z,
    // then randomizes their order
    srand(time(0));
    int i;
    for( i = 'a'; i <= 'z'; i++ ){
        shiftRotor.push_back(i);
    }
    std::random_shuffle( shiftRotor.begin(), shiftRotor.end() );
    this->printShiftRotor();
}

void Rotor::initialize(std::string startingPosition){
    // fills the std::vector, shiftRotor with the letters from startingPosition
    unsigned int i;
    startingPosition = preproscess(startingPosition, true);
    for( i = 0; i < startingPosition.length(); i++ ){
        shiftRotor.push_back(startingPosition[i]);
    }
}

void Rotor::shiftRight(){
    char tmp = shiftRotor.back();
    shiftRotor.pop_back();
    shiftRotor.insert(shiftRotor.begin(), tmp);
}

void Rotor::shiftLeft(){
    char tmp = shiftRotor.front();
    shiftRotor.erase(shiftRotor.begin());
    shiftRotor.push_back(tmp);
}

std::string Rotor::encryptString(std::string str){
    std::string output = "";
    unsigned int i;
    for( i = 0; i < str.length(); i++ ){
        if( str[i] != ' ' ){
            output += shiftRotor[str[i] - 'a'];
        } else {
            output += ' ';
        }
        this->shiftLeft();
    }
    return output;
}

std::string Rotor::decipherString(std::string str){
    std::string output = "";
    unsigned int i;
    unsigned int j;
    // linear search through shiftRotor for the letter
    // at str[i]. Append the position + 'a' to output
    
    for( i = 0; i < str.length(); i++ ){
        if( str[i] == ' ' ){
            output += ' ';
        } else {
            for( j = 0; j < shiftRotor.size(); j++ ){
                if(shiftRotor[j] == str[i]){
                    output += (j + 'a');
                    break;
                }
            }
        }
        this->shiftLeft();
    }
    return output;
}

