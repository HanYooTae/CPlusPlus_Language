#include"03_lecture.h"

int main()
{

	Teacher t("didi");
	Student s1("titi");
	Student s2("ruru");
	Student s3("corgi");

	std::cout << "t  : " << &t << std::endl;
	std::cout << "s1 : " << &s1 << std::endl;
	std::cout << "s2 : " << &s2 << std::endl;
	std::cout << "s3 : " << &s3 << std::endl;
	std::cout << std::endl;

	// 빌려주기만 함 -> 같은 공간을 사용하고 있다 -> 객체가 사라져도 존재함
	// 소멸자에서 포인터 있다고 소멸시키면 안됨 
	{
		Lecture l1("c_language");
		l1.Assignment_Teacher(&t);
		l1.Assignment_Student(&s1);
		l1.Assignment_Student(&s2);
		l1.Assignment_Student(&s3);
		l1.Print();
	}

	// 전체(l1)가 소멸하더라도 부품은 존재 한다.
	std::cout << "t  : " << &t << std::endl;
	std::cout << "s1 : " << &s1 << std::endl;
	std::cout << "s2 : " << &s2 << std::endl;
	std::cout << "s3 : " << &s3 << std::endl;
	std::cout << std::endl;

	return 0;
}