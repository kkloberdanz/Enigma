Programmer    : Kyle Kloberdanz
Date Created  : 19 Feb 2015
Description   : A simplified implementation of the enigma cipher.
               Uses 1 rotor instead of 3

File          : README.txt

Usage:
   To encrypt:
              : To encipher:
                  ./enigma INPUTFILE OUTPUTFILE

              Encipher without spaces:
                  ./enigma INPUTFILE OUTPUTFILE --no-spaces

              To decipher:
                  ./enigma INPUTFILE OUTPUTFILE -d

              Decipher withoug spaces:
                  ./enigma INPUTFILE OUTPUTFILE -d --no-spaces

Notes        : Compiled with g++ (Debian 5.3.1-8) (stretch-sid)
              and GNU Make 4.1
              Complier MUST be compatable with c++11 standard

              For best results, compile and run with a linux system
              (Not tested for Windows, OSX, or any other OS)

              To compile, ensure you are in the same directory as the
              Makefile, then type 'make'

              To compile without make: 
              'g++ main.cpp enigma.cpp Rotor.cpp -o Enigma -Wall -Wextra -O2 -std=c++11'
            



