/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA6
 * Created: March 20th, 2011
 * Last Revised: March 21st, 2012
 *
 * File Description: "commandFuntions.c" contains the functions for individual commands
 *********************************************************************************************/
#include "PA6.h"

void read (int program[], int operand)
{
	char buffer[81];
	bool validEntry = false;
	cin.clear();
	cin.ignore(500, '\n');
	cin.clear();

	while (!validEntry)
	{
		cout << endl << "Enter number at memory location: " << operand << " ? ";
		cin.getline(buffer,80);

		if ((buffer[0] == '+') || (buffer[0] == '-'))
		{
			int number = atoi (buffer);

			if ((number > -9999) && (number < 9999))
			{
				program[operand] = number;
				validEntry = true;
			}
			else
			{
				cout << "Entered number out of memory range (-9999 to +9999)." << endl;
				system ("pause");
			}
		}
		else
		{
			cout << "First character must be a + or a - operator." << endl;
			system ("pause");
		}

		system ("cls");
	}
}

void write (int program[], int operand)
{
	cout << endl << "Number at memory location: "<< operand << " is "<< showpos << program[operand] << endl;
}

bool add (int program[], int *accumulator, int operand)
{
	bool isGood = true;

	if ((*accumulator + program[operand]) > 9999)
		isGood = false;
	else
		*accumulator += program[operand];

	return isGood;
}

bool subtract (int program[], int *accumulator, int operand)
{
	bool isGood = true;

	if ((*accumulator - program[operand]) < -9999)
		isGood = false;
	else
		*accumulator -= program[operand];

	return isGood;
}

bool multiply (int program[], int *accumulator, int operand)
{
	bool isGood = true;

	if (((*accumulator * program[operand]) > 9999) || ((*accumulator * program[operand]) < -9999))
		isGood = false;
	else
		*accumulator *= program[operand];

	return isGood;
}

bool divide (int program[], int *accumulator, int operand)
{
	bool isGood = true;

	if (program[operand] == 0)
		isGood = false;
	else if (((*accumulator / program[operand]) > 9999) || ((*accumulator / program[operand]) < -9999))
		isGood = false;
	else
		*accumulator /= program[operand];

	return isGood;
}

bool modulus (int program[], int *accumulator, int operand)
{
	bool isGood = true;

	if (program[operand] == 0)
		isGood = false;
	else if (((*accumulator % program[operand]) > 9999) || ((*accumulator % program[operand]) < -9999))
		isGood = false;
	else
		*accumulator %= program[operand];

	return isGood;
}

bool exponentiation (int program[], int *accumulator, int operand)
{
	bool isGood = true;

	if (program[operand] == 0)
		isGood = false;
	else if ((pow ((double)*accumulator, (double)program[operand]) > 9999) || (pow ((double)*accumulator, (double)program[operand]) < -9999))
		isGood = false;
	else
		*accumulator = (int)pow ((double)*accumulator, (double)program[operand]);

	return isGood;
}

void dump (int program[], int accumulator, int commandRegister, int commandCode, int operand, int i, string outputFile, int maxProgramSize)
{
	ofstream output;
	system("pause");
	system ("cls");
	cout<<"REGISTERS" << endl <<
		"Accumulator: " << showpos << setfill('0') << left << setw(5) << accumulator << endl <<
		"Counter: "<< noshowpos << i << endl <<
		"Command Register: " << showpos << commandRegister << endl <<
		"Command Code: " << commandCode << endl <<
		"Operand: " << noshowpos << operand << endl << endl;
	cout << "MEMORY" << endl;
	cout << "     0     1     2     3     4     5     6     7     8     9";

	for (int j = 0; j < maxProgramSize; j++)
	{
		if (j % 10 == 0)
		{
			cout << noshowpos << endl << j;
		}
		cout << " " << setw(5) << showpos << program[j];
	}

	output.open (outputFile.c_str (), std::ios::app);
	output<<"REGISTERS" << endl <<
		"Accumulator: " << showpos << setfill('0') << left << setw(5) << accumulator << endl <<
		"Counter: "<< noshowpos << i << endl <<
		"Command Register: " << showpos << commandRegister << endl <<
		"Command Code: " << commandCode << endl <<
		"Operand: " << noshowpos << operand << endl << endl;
	output << "MEMORY" << endl;
	output << "     0     1     2     3     4     5     6     7     8     9";

	for (int j = 0; j < maxProgramSize; j++)
	{
		if (j % 10 == 0)
		{
			output << noshowpos << endl << j;
		}
		output << " " << setw(5) << showpos << program[j];
	}
	output.close ();

	cout << endl;
	cout << "Program Executed." << endl;
	output.open (outputFile.c_str (), std::ios::app);
	output << endl << "Program Executed." << endl << endl;
	output.close ();
	system("pause");
}