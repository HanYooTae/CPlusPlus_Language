#include <iostream>		//input + output + stream

int main()
{
	std::cout << "Hello, C++!!" << std::endl;
	//endl : \n + fflush();
	//fflush(); => buffer �ʱ�ȭ
	std::cout << "Hello, C++!!" << '\n';

	int x = 10;
	int y = 10;

	std::cout << "x = " << x  << ", y = " << y << std::endl;
	std::cout << "x + y = " << x + y << std::endl;

	return 0;
}