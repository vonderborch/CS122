#include "lab12.h"

void FileFilter::doFilter (ifstream &in, ofstream &out, int key)
{
	while (in.peek () != EOF)
		out << trnsform (in.get(), key);
}

char FileFilter::trnsform (char ch, int key)
{
	return ch;
}

char cpyFl::trnsform (char ch, int key)
{
	return ch;
}

char tupFl::trnsform (char ch, int key)
{
	return toupper(ch);
}

char encFl::trnsform (char ch, int key)
{
	if (isalpha (ch))
	{
		if (isupper (ch))
		{
			return (((ch + key - 65) % 26) + 65);
		}
		else
		{
			return (((ch + key - 97) % 26) + 97);
		}
	}
	return ch;
	//return (((ch + this->mKey - 65) % 26) + 65)
}

void dblFl::doFilter (ifstream &in, ofstream &out, int key)
{
	int i = 0;
	while (in.peek () != EOF)
	{
		char ch = (char)in.get ();
		if (ch == '\n')
		{
			out << "\n\n";
		}
		else
		{
			out << trnsform (ch, key);
		}
	}
}

char dblFl::trnsform (char ch, int key)
{
	return ch;
}