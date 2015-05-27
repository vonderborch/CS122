/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA6
 * Created: March 20th, 2011
 * Last Revised: March 21st, 2012
 *
 * File Description: "functions.c" contains the code for general functions.
 *********************************************************************************************/
#include "PA6.h"

void commandCycle (int stepthroughCommand, string fileName, int commandNum, string command, int operand)
{
	ofstream outputFile;

	cout << "Command " <<commandNum << ": " << command << ", Operand: " << operand << endl;
	outputFile.open (fileName.c_str (), std::ios::app);
	outputFile << "Command " << commandNum << ": " << command << ", Operand: " << operand << endl;
	outputFile.close ();
	if (stepthroughCommand == 1)
	{
		system ("pause");
		cout << endl;
	}
}