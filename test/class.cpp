#include <iostream>
using namespace std;
class container
{
protected:
	double radius;
public:
	//container(double radius);
	virtual double surface_area()=0;
	virtual double volume()=0;
};
//container::container(double radius)
//{
//	this->radius = radius;
//}
class cube : public container
{
public:
	cube(double r) { this->radius = r;}
	double surface_area()
	{
		return radius*radius*6;
	}
	double volume()
	{
		return radius*radius*6;
	}
	void set_radius(double r)
	{
		this->radius = r;
	}
};
int main()
{
	container *mycube = new cube(6.0);
	cout << " cube : " << mycube->surface_area() << " " <<mycube->volume() << endl;
	delete mycube;
	return 0;
}