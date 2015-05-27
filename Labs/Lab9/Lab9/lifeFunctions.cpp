#include "lab9.h"

/*
Life::Life ()
{
	this->size = 1;
	this->rate = 0;
}*/

Life::Life (double init_size, double init_rate)
{
	this->size = init_size;
	this->rate = init_rate;
}

void Life::simulate_week ()
{
	this->size += this->rate;
}

void Life::assign_rate (double new_rate)
{
	this->rate = new_rate;
}

void Life::alter_size (double amount)
{
	this->size += amount;
	if (this->size < 0)
	{
		this->size = 0;
	}
}

void Life::death ()
{
	this->size = 0;
	this->rate = 0;
}

double Life::get_size () const
{
	return this->size;
}

double Life::get_rate () const
{
	return this->rate;
}

bool Life::is_alive () const
{
	bool isAlive = false;
	if (this->size > 0)
	{
		isAlive = true;
	}
	return isAlive;
}
