#include <iostream>
#include <cstring>
#include <windows.h>
#include <cctype>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define CSI const signed int

//simpletron codes

CSI READ=10; // read a word from kboard to spec. location in memory
CSI WRITE=11; // write a word from memory to the screen
CSI LOAD=20; // load a word from spec. location in memory into accumulator
CSI STORE=21; // store a word from acc. into spec. location in memory
CSI ADD=30; // add a word from spec. location in memory to word in accumulator.leaves result in acc.
CSI SUBTRACT=31; // subtract as for add
CSI DIVIDE=32; // divide as for add
CSI MULTIPLY=33; // multiply as for add
CSI MODULUS=34; // modulus as for add
CSI BRANCH=40; // unconditional branch (goto)
CSI BRANCHNEG=41; // branch if acc is negative
CSI BRANCHZERO=42; // branch if acc is zero
CSI HALT=43; // end program
CSI CLEARSCREEN=99; // clear the screen

//function prototypes

void begin();
void clrscr();
void entercode(signed int[]);
void execute(signed int[]);
void read(signed int[],int);
void write(signed int[],int);
void dump(signed int[],signed int,signed int,signed int,int,int);
void add (signed int[],signed int*,int);
void subtract(signed int[],signed int*,int);
void multiply(signed int[],signed int*,int);
void divide(signed int[],signed int*,int);
void modulus(signed int[],signed int*,int);

int main()

{
	signed int Memory [100]={0}; //simpletron memory
	begin();
	entercode(Memory);
	system("PAUSE");
	clrscr();
	execute(Memory);

	return 0;
}

void begin()
{
	clrscr();
	cout<<"*** Welcome to Simpletron. ***"<<endl<<endl<<
		"*** Please enter your program one instruction ***"<<endl
		<<"*** (or data word) at a time. I will type the ***"<<endl<<
		"*** location number and a question mark (?). ***"<<endl<<
		"*** You then type the word for that location. ***"<<endl<<
		"*** Type the sentinel -99999 to stop entering ***"<<endl<<
		"*** your program. v.1.0 (c) Russ 2001 ***"<<endl;
}

void clrscr()
{
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen,
		&cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen,
		&cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
}

void entercode(signed int array[])

{
	char buffer[81];// for input

	for(int i=0;i<100;i++)
	{
entry: cout<<endl<<(i<10 ? "0":"")<<i<<" ? ";// print 1 as 01 etc.
		cin.getline(buffer,80);
		if (buffer[0] != '+' && buffer[0] != '-')// expect + or - as first char
		{
			cout<<endl<<"Not a valid simpletron code"<<endl;
			goto entry;
		}
		int bufflen=strlen(buffer);
		if(bufflen !=5 && (strcmp(buffer,"-99999")))// simpletron codes are SDDDD or -99999
		{
			cout<<endl<<"Not a valid simpletron code"<<endl;
			goto entry;
		}
		for(int j=1;j<bufflen;j++)
		{
			if (!isdigit(buffer[j]))
			{
				cout<<endl<<"Not a valid simpletron code"<<endl;
				goto entry;
			}
		}
		if (!strcmp(buffer,"-99999"))// find sentinel
		{
			cout<<endl<<"*** Program loading finished. ***"<<endl<<
				"*** Program execution begins. ***"<<endl;
			return;
		}
		signed int a=atoi(buffer);
		array[i]=a;// fill memory with program code
	}
}

void execute(signed int array[])
{
	signed int Accumulator=0,InstructionRegister=0,OpCode=0;
	int Counter=0,Operand=0;
	bool Flag=TRUE;

	while(Flag)
	{
		InstructionRegister=array[Counter];
		OpCode=InstructionRegister /100;
		Operand=InstructionRegister %100;
		Counter++;

		switch(OpCode)
		{
		case READ: {
			read(array,Operand);
			break;
				   }
		case WRITE:{
			write(array,Operand);
			break;
				   }
		case CLEARSCREEN :{
			clrscr();
			break;
						  }
		case HALT: {
			cout<<endl<<"*** Program execution terminated. ***"<<endl;
			Flag=FALSE;
			dump(array,Accumulator,InstructionRegister,OpCode,Operand,(Counter-1));
			break;
				   }
		case BRANCH: {
			Counter=Operand;
			break;
					 }
		case BRANCHZERO:{
			if (Accumulator==0) Counter=Operand;
			break;
						}
		case BRANCHNEG: {
			if (Accumulator <0) Counter=Operand;
			break;
						}
		case LOAD: {
			Accumulator=array[Operand];
			break;
				   }
		case STORE: {
			array[Operand]=Accumulator;
			break;
					}
		case ADD: {
			add(array,&Accumulator,Operand);
			break;
				  }
		case SUBTRACT: {
			subtract(array,&Accumulator,Operand);
			break;
					   }
		case MULTIPLY: {
			multiply(array,&Accumulator,Operand);
			break;
					   }
		case DIVIDE: {
			divide(array,&Accumulator,Operand);
			break;
					 }
		case MODULUS: {
			modulus(array,&Accumulator,Operand);
			break;
					  }
		default: {
			cerr<<endl<<"*** Fatal runtime error - undefined code ***"<<endl;
			dump(array,Accumulator,InstructionRegister,OpCode,Operand,(Counter-1));
			exit(0);
				 }
		}
	}
}

void read(signed int array[],int Operand)
{
	cout<<endl<<"Enter word for location :- "<<Operand<<" ? ";
	char buffer[81];
	bool ok=TRUE;
	while (ok)
	{
entry: cin.getline(buffer,80);
		if (buffer[0] != '+' && buffer[0] != '-')// expect + or - as first char
		{
			cout<<endl<<"First character has to be a + or - sign."<<endl<<"Try again:- ? ";
				goto entry;
		}
		signed int a=atoi(buffer);
		if (a<-9999 || a>9999)
		{
			cout<<endl<<"Number entered out of range (-9999 to +9999) "<<endl<<"Try again :- ? ";
	   goto entry;
		}
		array[Operand]=a;
		ok=FALSE;
	}
}

void write(signed int array[],int Operand)
{
	cout<<endl<<"Word at memory location :- "<<Operand<<" is "<<showpos<<array[Operand];
}

void add (signed int array[],signed int* Acc,int Operand)
{
	if ((*Acc+array[Operand])>9999)

	{
		cout<<endl<<"*** Fatal error :- Accumulator overflow ***"<<endl<<"*** Program terminated ***"<<endl;
			exit(0);
	}
	else
		*Acc += array[Operand];
}

void subtract (signed int array[],signed int* Acc,int Operand)
{
	if ((*Acc-array[Operand])<-9999)
	{
		cout<<endl<<"*** Fatal error :- Accumulator overflow ***"<<endl<<"*** Program terminated ***"<<endl;
			exit(0);
	}
	else
		*Acc -= array[Operand];
}

void multiply(signed int array[],signed int* Acc,int Operand)
{
	if (((*Acc * array[Operand]) < -9999) || ((*Acc * array[Operand]) > 9999))
	{
		cout<<endl<<"*** Fatal error :- Accumulator overflow ***"<<endl<<"*** Program terminated ***"<<endl;
			exit(0);
	}
	else
		*Acc *= array[Operand];
}

void divide (signed int array[],signed int* Acc,int Operand)
{
	if (array[Operand]==0)
	{
		cout<<endl<<"*** Fatal error :- Division by zero ***"<<endl;
		exit(0);
	}
	if (((*Acc / array[Operand]) < -9999) || ((*Acc / array[Operand]) > 9999))
	{
		cout<<endl<<"*** Fatal error :- Accumulator overflow ***"<<endl<<"*** Program terminated ***"<<endl;
			exit(0);
	}
	else
		*Acc /= array[Operand];
}

void modulus (signed int array[],signed int* Acc,int Operand)
{
	if (array[Operand]==0)
	{
		cout<<endl<<"*** Fatal error :- Division by zero ***"<<endl;
		exit(0);
	}
	if (((*Acc / array[Operand]) < -9999) || ((*Acc / array[Operand]) > 9999))
	{
		cout<<endl<<"*** Fatal error :- Accumulator overflow ***"<<endl<<"*** Program terminated ***"<<endl;
			exit(0);
	}
	else
		*Acc %= array[Operand];
}

void dump(signed int array[],signed int Acc,signed int IR,signed int OpCode,int
		  operand,int counter)
{
	system("PAUSE");
	clrscr();
	cout<<"REGISTERS :-"<<endl<<"Accumulator "<<showpos<<setfill('0')<<left<<setw(5)<<Acc<<endl
		<< "Counter "<<noshowpos<<setw(2)<<counter<<endl<<
		"Instruction Register "<<showpos<<setw(5)<<IR<<endl<<
		"Operation Code "<<setw(3)<<OpCode<<endl<<
		"Operand "<<noshowpos<<setw(2)<<operand<<endl<<endl;
	cout<<"MEMORY :-"<<endl;
	cout<<" 0 1 2 3 4 5 6 7 8 9";
	for (int i=0;i<100;i++)
	{
		if (i%10==0)
		{
			cout<<noshowpos<<endl<<setw(2)<<i;
		}
		cout<<" "<<setw(5)<<showpos<<array[i];
	}
}