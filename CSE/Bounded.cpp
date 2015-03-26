#include "stdafx.h"
#include "BoundedNum.h"

BoundedNum::BoundedNum()
{

}

BoundedNum::BoundedNum(double value_)
{
	if (value_ > 1.0 || value_ < -1.0){
		//error
	}
	value = value_;
}

BoundedNum::~BoundedNum()
{
}

void BoundedNum::setValue(double d)
{
	if (d > 1.0 || d < -1.0){
		//error
	}
	value = d;
}

void BoundedNum::change(double delta)
{
	double distance;
	if ( delta > 0.0)
	{	distance = 1.0 - value;	}
	else if ( delta < 0.0)
	{	distance = 1.0 + value;	}

	if ((delta <= 1.0) && (delta >= -1.0))
		distance = distance * delta;

	value += distance;
}

void BoundedNum::increase(double increase)
{
	double distance = 1.0 - value;

	if((increase <= 1.0) && (increase >= -1.0))
	distance = distance * increase;

	value += distance;
}

void BoundedNum::decrease(double decrease)
{
	double distance = -1.0 - value;

	if ((decrease <= 1.0) && (decrease >= -1.0))
		distance = distance * decrease;

	value += distance;
}

double BoundedNum::BtoD(double Bounded)
{
	if (Bounded > 0.0){
		return ((1 / (1 - Bounded)) -1);
	}
	else {
		return (1- (1 / (1 + Bounded)));
	}
}

double BoundedNum::DtoB(double unBounded)
{
	if (unBounded > 0.0){
		return (1 - (1 / (1 + unBounded)));
	}
	else {
		return ((1 / (1 - unBounded)) - 1);
	}
}