#pragma once


// Bounded numbers are a specific type of number that should only range between their bounds (here its -1 and 1)
// all the functions to edit the number are contained within this class.
class BoundedNum
{
private:
	double value;

	double BtoD(double);
	double DtoB(double);
public:
	BoundedNum();
	BoundedNum(double);
	~BoundedNum();

	void change(double);
	void increase(double);
	void decrease(double);

	double Value() { return value; }
	void setValue(double d);
	void DivideBy(double d);	// somewhat a cheat. used by coolMoods.
};

