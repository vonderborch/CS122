/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA6
 * Created: March 20th, 2011
 * Last Revised: March 21st, 2012
 *
 * File Description: "mainFunctions.c" contains the main functions for the Simpletron.
 *********************************************************************************************/
#include "PA6.h"

bool getProgram (int program[], string inputFile, int maxProgramSize)
{
	// variables
	ifstream input;
	char commandBuffer[10];
	bool isValid = true;
	int i = 0;

	// open program file
	input.open (inputFile.c_str (), std::ios::in);

	// while the program is valid, does not go over the number of possible commands, and the program is not over, do this cycle
	while ((!input.eof ()) && (isValid) && (i < maxProgramSize))
	{
		// get the next input line into the commandBuffer
		input >> commandBuffer;
		// check if the first character is correct or not
		if ((commandBuffer[0] == '+') || (commandBuffer[0] == '-'))
		{
			// get the length of the command...
			int commandLength = strlen (commandBuffer);

			// if the length is correct...
			if (commandLength == 5)
			{
				// for each letter in the commandBuffer
				for (int j = 1; j < 5; j++)
				{
					// if it isn't a digit, the program is invalid
					if (!isdigit (commandBuffer[j]))
					{
						isValid = false;
					}
					// assign the command (if it is valid) into the program memory
					signed int command = atoi (commandBuffer);
					program[i] = command;
				}
			}
			// otherwise the program is not valid
			else
			{
				isValid = false;
			}
		}
		// otherwise the program is not valid
		else
		{
			isValid = false;
		}
		// move to next line...
		i++;
	}

	// close file and return program validity
	input.close ();
	return isValid;
}

bool runProgram (int program[], string outputFile, int stepthroughCommands, int maxProgramSize)
{
	signed int accumulator = 0, commandRegister = 0, commandCode = 0;
	int i = 0, operand = 0;
	bool isRunning = true, isValid = true;
	string commandString = "";

	while(isRunning)
	{
		commandRegister = program[i];
		commandCode = commandRegister / 100;
		operand = commandRegister % 100;
		i++;

		if (commandCode == READ)
		{
			commandString = "READ";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			read (program, operand);
		}
		else if (commandCode == WRITE)
		{
			commandString = "WRITE";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			write (program, operand);
		}
		else if (commandCode == LOAD)
		{
			commandString = "LOAD";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			accumulator = program[operand];
		}
		else if (commandCode == STORE)
		{
			commandString = "STORE";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			program[operand] = accumulator;
		}
		else if (commandCode == ADD)
		{
			commandString = "ADD";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			add (program, &accumulator, operand);
		}
		else if (commandCode == SUBTRACT)
		{
			commandString = "SUBTRACT";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			subtract (program, &accumulator, operand);
		}
		else if (commandCode == DIVIDE)
		{
			commandString = "DIVIDE";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			divide (program, &accumulator, operand);
		}
		else if (commandCode == MULTIPLY)
		{
			commandString = "MULTIPLY";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			multiply (program, &accumulator, operand);
		}
		else if (commandCode == MODULUS)
		{
			commandString = "MODULUS";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			modulus (program, &accumulator, operand);
		}
		else if (commandCode == EXPONENTIATION)
		{
			commandString = "EXPONENTIATION";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			exponentiation (program, &accumulator, operand);
		}
		else if (commandCode == BRANCH)
		{
			commandString = "BRANCH";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			i = operand;
		}
		else if (commandCode == BRANCHNEG)
		{
			commandString = "BRANCHNEG";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			if (accumulator < 0)
				i = operand;
		}
		else if (commandCode == BRANCHZERO)
		{
			commandString = "BRANCHZERO";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			if (accumulator == 0)
				i = operand;
		}
		else if (commandCode == HALT)
		{
			commandString = "HALT";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			cout << "Program Finished." << endl;
			dump (program, accumulator, commandRegister, commandCode, operand, (i - 1), outputFile, maxProgramSize);
			isRunning = false;
		}
		else if (commandCode == CLEARSCREEN)
		{
			commandString = "CLEARSCREEN";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			system ("cls");
		}
		else
		{
			commandString = "Fatal Error, Undefined Code";
			commandCycle (stepthroughCommands, outputFile, i - 1, commandString, operand);
			dump (program, accumulator, commandRegister, commandCode, operand, (i - 1), outputFile, maxProgramSize);
			isValid = false;
			isRunning = false;
		}
	}
	return isValid;
}