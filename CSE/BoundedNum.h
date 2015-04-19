#pragma once

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
	void DivideBy(double d);
};

