#!/bin/sh

g++ -c -o User.o User.cpp
g++ -c -o database.o database.cpp

g++ database.o User.o -o program
