#include "lab9.h"

Plant::Plant (double init_size, double init_rate)
{
	this->size = init_size;
	this->rate = init_rate;
}

void Plant::nibbled_on (double amount)
{
	this->size -= amount;
	if (this->size < 0)
	{
		this->death ();
	}
}