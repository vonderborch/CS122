#ifndef LAB9_H
#define LAB9_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;

class Life
{
	public:
		//Life ();
		Life (double init_size = 1, double init_rate = 0);

		virtual void simulate_week ();
		void assign_rate (double new_rate);
		void alter_size (double amount);
		void death ();

		double get_size () const;
		double get_rate () const;
		bool is_alive () const;

	protected:
		double size;
		double rate;
};

class Plant: public Life
{
	public:
		Plant (double init_size = 0, double init_rate = 0);

		void nibbled_on (double amount);
};

class Animal: public Life
{
	public:
		Animal (double init_size = 0, double init_rate = 0, double init_need = 0);

		void assign_need (double new_need);
		void eat (double amount);
		void simulate_week ();
		double still_need () const;
		double total_need () const;
	protected:
		double need;
		double food;
};

class GoldFish: public Animal
{
	public:
		GoldFish (double init_size=0, double init_rate=0, double init_need=0);
		void nibble (Plant& meal);
};

#endif