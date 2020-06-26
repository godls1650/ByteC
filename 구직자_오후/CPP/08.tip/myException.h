#pragma once
#include <iostream>
class ArithmeticException : public std::exception {
public :
	ArithmeticException():exception("Arithmetic Exception") {}
};

