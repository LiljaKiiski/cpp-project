#!/bin/sh

g++ -c -o User.o User.cpp
g++ -c -o Database.o Database.cpp
g++ -c -o run_database.o run_database.cpp

g++ Database.o User.o run_database.o -o program
