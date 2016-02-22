all:
	g++ main.cpp enigma.cpp Rotor.cpp -o enigma -Wall -Wextra -Wpedantic -O2 -std=gnu++11
