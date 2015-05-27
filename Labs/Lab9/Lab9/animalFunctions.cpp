#include "lab9.h"

Animal::Animal (double init_size, double init_rate, double init_need)
{
	this->rate = init_size;
	if (this->size == 0)
	{
		this->rate = 0;
	}
	else
	{
		this->rate = init_rate;
	}
	if (init_need <= 0)
	{
		this->need = 0;
	}
	else
	{
		this->need = init_need;
	}
	this->food = 0;
}

void Animal::assign_need (double new_need)
{
	this->need = new_need;
}

void Animal::eat (double amount)
{
	this->food += amount;
}

void Animal::simulate_week ()
{
	this->size += this->rate;
	if (this->size < 0)
	{
		//this->size = 0;
		//this->rate = 0;
	}
	if (this->still_need () > 0)
	{
		int random = rand () % 2;
		if (random == 0)
		{
			this->death ();
		}
	}
	if (this->size > 80)
	{
		int random = rand () % 10;
		if (random < 5)
		{
			this->death ();
		}
	}
	int random = rand () % 100;
	if (random < 1)
	{
		this->death ();
	}
}

double Animal::still_need () const
{
	return (this->need - this->food);
}

double Animal::total_need () const
{
	return this->need;
}
