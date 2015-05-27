/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA6
 * Created: March 20th, 2011
 * Last Revised: March 21st, 2012
 *
 * File Description: "main.c" contains the main function for the program.
 *********************************************************************************************/
#ifndef PA6_H
#define PA6_H

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <math.h>
#include "menu_system.h"

using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

// Command Codes
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define MODULUS 34
#define EXPONENTIATION 35
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43
#define CLEARSCREEN 99

// primary functions
void simpletron (string programString, string inputFile, string outputFile, int stepthroughCommands, int maxProgramSize);

// main functions
bool getProgram (int program[], string inputFile, int maxProgramSize);
bool runProgram (int program[], string outputFile, int stepthroughCommands, int maxProgramSize);

// command functions
void read (int program[], int operand);
void write (int program[], int operand);
void dump (int program[], int accumulator, int commandRegister, int commandCode, int operand, int i, string outputFile, int maxProgramSize);
bool add (int program[], int *accumulator, int operand);
bool subtract (int program[], int *accumulator, int operand);
bool multiply (int program[], int *accumulator, int operand);
bool divide (int program[], int *accumulator, int operand);
bool modulus (int program[], int *accumulator, int operand);
bool exponentiation (int program[], int *accumulator, int operand);

// other functions
void commandCycle (int stepthroughCommand, string fileName, int commandNum, string command, int operand);

#endif