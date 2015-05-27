// This example shows how to handle file processing in C++

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

int main (void)
{
	ifstream input;
	ofstream output ("output.txt", std::ios::out);
	string filename;

	cout << "Enter filename: ";
	cin >> filename;

	input.open (filename.c_str (), std::ios::in);

	while (!input.eof ())
	{
		int number; // Can't be used outside the loop...Should we always redeclare number? Probably not...

		input >> number;
		output << number << endl;
	}

	input.close ();
	output.close ();


	return 0;
}