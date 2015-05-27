#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

class FileFilter
{
	public:
		virtual void doFilter (ifstream &in, ofstream &out, int key);
		virtual char trnsform (char ch, int key);
};
class cpyFl : public FileFilter
{
	public:
		//void doFilter (ifstream &in, ofstream &out);
		char trnsform (char ch, int key);
};
class tupFl : public FileFilter
{
	public:
		//void doFilter (ifstream &in, ofstream &out);
		char trnsform (char ch, int key);
};
class encFl : public FileFilter
{
	public:
		//void doFilter (ifstream &in, ofstream &out);
		char trnsform (char ch, int key);
};
class dblFl : public FileFilter
{
	public:
		void doFilter (ifstream &in, ofstream &out, int key);
		char trnsform (char ch, int key);
};