/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA6
 * Created: March 20th, 2011
 * Last Revised: March 21st, 2012
 *
 * File Description: "Simpletron.c" contains the Simpletron controller function.
 *********************************************************************************************/
#include "PA6.h"

void simpletron (string programString, string inputFile, string outputFile, int stepthroughCommands, int maxProgramSize)
{
	ofstream output;
	int program [1000] = { 0 };
	bool nextStep = false;

	cout << "PROGRAM: " << programString << endl << endl;
	output.open (outputFile.c_str (), std::ios::app);
	output << "PROGRAM: " << programString << endl << endl;
	output.close ();

	cout << "Loading/Reading program from input file...";
	output.open (outputFile.c_str (), std::ios::app);
	output << "Loading/Reading program from input file..." << endl;
	output.close ();
	nextStep = getProgram (program, inputFile, maxProgramSize);
	if (nextStep)
	{
		cout << "Program loaded/read. ";
		system ("pause");
		cout << "Program Execution beginning." << endl;
		output.open (outputFile.c_str (), std::ios::app);
		output << "Program read." << endl << "Program Execution beginning." << endl;
		output.close ();
		runProgram (program, outputFile, stepthroughCommands, maxProgramSize);
	}
	else
	{
		cout << "Problem loading/reading program. Please debug and run again!" << endl;
		output.open (outputFile.c_str (), std::ios::app);
		output << "Problem loading/reading program. Please debug and run again!" << endl;
		output.close ();
	}
}