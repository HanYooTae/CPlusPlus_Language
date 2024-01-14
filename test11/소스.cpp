#include<iostream>

class Number

{

public:

	Number(int value = 0) : value(value)

	{

		std::cout << "constructor" << std::endl;

	}


	Number(const Number& other)

	{

		std::cout << "copy_constructor" << std::endl;

	}


	Number& operator=(const Number& rhs)

	{

		std::cout << "copy_assignment_operator" << std::endl;

	}


	~Number() = default;


private:

	int value = 0;

};


int main()

{

	Number num1;

	Number num2(num1);

	Number num3 = num2;


	return 0;

}