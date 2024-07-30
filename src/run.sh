#!/bin/bash

clear; neofetch;

# *Link
echo "Linking..."
echo ""
g++ -c main.cpp -I /home/sopmod/Downloads/SFML-2.6.1-linux-gcc-64-bit/SFML-2.6.1/include;


# *Compile
echo "Compiling..."
echo ""
g++ main.o -o MineBlocks -L /home/sopmod/Downloads/SFML-2.6.1-linux-gcc-64-bit/SFML-2.6.1/lib -lsfml-system -lsfml-window -lsfml-graphics;


# *Run
echo "Running..."
echo ""
# clear;
./MineBlocks