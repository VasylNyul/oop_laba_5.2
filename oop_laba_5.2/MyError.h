#include <iostream>
#include <string>

using namespace std;
#pragma once

class MyError
{
	string message;
public:
	MyError(string message) : message(message) {}

	string what() { return message; }
};

