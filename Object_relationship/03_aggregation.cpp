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

	// �����ֱ⸸ �� -> ���� ������ ����ϰ� �ִ� -> ��ü�� ������� ������
	// �Ҹ��ڿ��� ������ �ִٰ� �Ҹ��Ű�� �ȵ� 
	{
		Lecture l1("c_language");
		l1.Assignment_Teacher(&t);
		l1.Assignment_Student(&s1);
		l1.Assignment_Student(&s2);
		l1.Assignment_Student(&s3);
		l1.Print();
	}

	// ��ü(l1)�� �Ҹ��ϴ��� ��ǰ�� ���� �Ѵ�.
	std::cout << "t  : " << &t << std::endl;
	std::cout << "s1 : " << &s1 << std::endl;
	std::cout << "s2 : " << &s2 << std::endl;
	std::cout << "s3 : " << &s3 << std::endl;
	std::cout << std::endl;

	return 0;
}