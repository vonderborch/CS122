#include "lab9.h"

GoldFish::GoldFish (double init_size, double init_rate, double init_need)
{
	this->size = init_size;
	this->rate = init_rate;
	this->need = init_need;
	this->food = 0;
}

void GoldFish::nibble (Plant& meal)
{
	double amount = meal.get_size () / 2;
	
	if (amount > (this->total_need () / 10))
	{
		amount = this->total_need () / 10;
	}
	meal.nibbled_on (amount);
	this->eat (amount);
}