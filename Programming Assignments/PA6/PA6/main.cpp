/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA6
 * Created: March 20th, 2011
 * Last Revised: March 21st, 2012
 *
 * File Description: "main.c" contains the main function for the program.
 *********************************************************************************************/
#include "PA6.h"

int main(void)
{
	string compName = "Simpletron 9000", inputFile = "", outputFile = "", program = "";
	int comp_state = 0, option = 0, stepthroughCommands = 2, maxProgramSize = 100;

	while (comp_state >= 0)
	{
		// Settings loading
		if (comp_state == 0)
		{
			inputFile = "";
			outputFile = "output.txt";
			stepthroughCommands = 2;
			maxProgramSize = 1000;

			comp_state = 1;
		}
		// Main Menu
		else if (comp_state == 1)
		{
			option = display_menu (1, 0, ':', 1, 3, ";", compName, "Main Menu", "Run Program;Settings;Quit");

			if (option == 1)
			{
				if (inputFile == "")
				{
					while (inputFile == "")
					{
						system ("cls");
						cout << "Enter Input Program Filename (without file extension): ";
						cin >> inputFile;
					}
					program = inputFile;
					inputFile += ".txt";
				}
				if (outputFile != "" && outputFile != ".txt")
				{
					simpletron (program, inputFile, outputFile, stepthroughCommands, maxProgramSize);
				}
				else
				{
					cout << "Output filename syntax invalid, please reenter under the options menu" << endl;
				}
			}
			else if (option == 2)
			{
				comp_state = 2;
			}
			else
			{
				comp_state = -1;
			}
		}
		// Options Menu
		else if (comp_state == 2)
		{
			option = display_menu (1, 0, ':', 1, 4, ";", compName, "Options Menu", "(Main Menu);Change Output File;Command Stepthrough Options;Max Program Size");

			if (option == 1)
			{
				comp_state = 1;
			}
			else if (option == 2)
			{
				while (outputFile == "")
				{
					system ("cls");
					cout << "Enter Output Filename (without file extension): ";
					cin >> outputFile;
				}
				outputFile += ".txt";
			}
			else if (option == 3)
			{
				stepthroughCommands = display_menu (1, 0, ':', 1, 2, ";", compName, "Stepthrough Commands at Runtime?", "Yes;No");
			}
			else if (option == 4)
			{
				while (maxProgramSize < 0)
				{
					system ("cls");
					cout << "Enter Maximum Program Size ( > 0): ";
					cin >> maxProgramSize;
				}
			}
		}
	}
	cin.clear();
	cin.ignore(500, '\n');
	cin.clear();

	system ("cls");

	return 0;
}