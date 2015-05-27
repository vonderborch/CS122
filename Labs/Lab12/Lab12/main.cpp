#include "lab12.h"

int main (void)
{
	ifstream input;
	ofstream output;
	string fileName;
	int key;
	FileFilter *file;
	cout << "Enter Filename: ";
	cin >> fileName;
	input.open (fileName.c_str (), ios::in);
	input.clear ();
	input.seekg (0, ios::beg);
	cout << "Enter File to Output To: ";
	cin >> fileName;
	output.open (fileName.c_str (), ios::out);
	cout << "Select Mode (1 = Copy, 2 = To Upper, 3 = Encrypt, 4 = Double Space): ";
	cin >> key;
	if (key == 1)
	{
		file = new cpyFl;
		file->doFilter (input, output, key);
	}
	else if (key == 2)
	{
		file = new tupFl;
		file->doFilter (input, output, key);
	}
	else if (key == 3)
	{
		cout << "Key? ";
		cin >> key;
		file = new encFl;
		file->doFilter (input, output, key);
	}
	else
	{
		file = new dblFl;
		file->doFilter (input, output, key);
	}
	delete file;
	output.close ();

	return 0;
}