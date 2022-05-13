#include "Empty.h"
#include "MyError.h"
#include "Error_ex.h"
#include <cmath>

using namespace std;

double D1(double x, double y, double a, double b, double c)
{
	if (a == 0 && b == 0)
		throw 1;
	return abs(a * x + b * y + c) / (sqrt(pow(a, 2) + pow(b, 2)));
}

double D2(double x, double y, double a, double b, double c) throw()
{
	if (a == 0 && b == 0)
		throw 2.1;
	return abs(a * x + b * y + c) / (sqrt(pow(a, 2) + pow(b, 2)));
}
double D3(double x, double y, double a, double b, double c) throw(char)
{
	if (a == 0 && b == 0)
		throw '3';
	return abs(a * x + b * y + c) / (sqrt(pow(a, 2) + pow(b, 2)));
}

double D4(double x, double y, double a, double b, double c) throw(Empty)
{
	if (a == 0 && b == 0)
		throw Empty();
	return abs(a * x + b * y + c) / (sqrt(pow(a, 2) + pow(b, 2)));
}

double D5(double x, double y, double a, double b, double c) throw(MyError)
{
	if (a == 0 && b == 0)
		throw MyError("a = b = 0");
	return abs(a * x + b * y + c) / (sqrt(pow(a, 2) + pow(b, 2)));
}

double D6(double x, double y, double a, double b, double c) throw(Error_ex)
{
	if (a == 0 && b == 0)
		throw Error_ex("a = b = 0");
	return abs(a * x + b * y + c) / (sqrt(pow(a, 2) + pow(b, 2)));
}

void FU()
{
	cout << "unexpected error! - bad_exception" << endl;
	throw;
}
void FT()
{
	cout << "unknown error! - terminate" << endl;
	abort();
}

int main()
{
	//set_unexpected(FU);
	set_terminate(FT);

	double x, y, a, b, c;
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;
	
	cout << " Point = P(" << x << "," << y << ")  " << endl;
	cout << a << "x + " << b << "y + " << c << " = 0 " << endl;

	try
	{
		//cout << "D1 = " << D1(x, y, a, b, c) << endl;
		//cout << "D2 = " << D2(x, y, a, b, c) << endl;
		cout << "D3 = " << D3(x, y, a, b, c) << endl;
		//cout << "D4 = " << D4(x, y, a, b, c) << endl;
		//cout << "D5 = " << D5(x, y, a, b, c) << endl;
		//cout << "D6 = " << D6(x, y, a, b, c) << endl;
	}
	catch (int i)
	{
		cout << " catch (int) <= D1() : " << i << endl;
	}
	catch (double d)
	{
		cout << " catch (double) <= D2() : " << d << endl;
	}
	catch (char c)
	{
		cout << " catch (char) <= D3() : " << c << endl;
	}
	catch (Empty)
	{
		cout << " catch (Empty) <= D4()" << endl;
	}
	catch (MyError e)
	{
		cout << " catch (Error) <= D5() : " << e.what() << endl;
	}
	catch (Error_ex q)
	{
		cout << " catch (MyException) <= D6() : " << q.what() << endl;
	}
	/*catch (bad_exception)
	{
		cout << " catch (bad_exception) " << endl;
	}*/

	return 0;
}