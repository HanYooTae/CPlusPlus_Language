#include <iostream>
#include <numeric>

int main()
{
	/*
		Initialization
	*/

	int x = 10;		//copy
	int y(10);		//direct	: ���� ���� �־��ش�.(����)
	int z{ 10 };	//uniform	: ����ȯ�� ������� ���� -> ������

	/*
		type casting
		https://doitnow-man.tistory.com/215
	*/

	int a = 1.1;		//warning : ������ �ս�
	//int b = { 1.1 };	//error	  : ������ �ս�
	char c = 500;		//warning : ������ �߸�
	//char d = { 500 };	//error	  : ������ �߸�

	int e = 10, f(1), g{ 2 };

	/*
		limits
		- ������ �ڷ����� �Ѱ谪�� ������ �ִ� Ŭ����
	*/

	// <> : template
	std::cout << std::numeric_limits<short>::max() << std::endl;
	std::cout << std::numeric_limits<int>::min() << std::endl;
	std::cout << std::numeric_limits<int>::max() << std::endl;
	std::cout << std::numeric_limits<float>::min() << std::endl;
	std::cout << std::numeric_limits<float>::max() << std::endl << std::endl;

	/*
		Casting
	*/

	int i = 10;
	float k = 10.0f;

	std::cout << k << std::endl;
	std::cout << (int)k << std::endl;					// C style �ʹ� ������ -> ������� �ڷ��������� ����ȯ�� ������
	std::cout << int(k) << std::endl;					// C++ style
	std::cout << static_cast<int>(k) << std::endl;		// C++ style -> ��ȯ�� �� ���� ��쿡�� ��ȯ������
	
/*
	���� : cast ���� 4���� ����
*/

	/*
		const vs constexpr
	*/

	/*
		const
		- �޴� ���� ���� ������ Ÿ���̳� ��Ÿ�� �� ���� ��������.
	*/


	//������ Ÿ�� �� ���� ������
	const int c1(123);

	//�ʱ�ȭ�Ǵ� ���� ������ ������ ��Ÿ�� �� ���� ������
	int i1 = 10;
	const int c2 = i1; 

	int c3(111);

	int arr_1[c1];
	//int arr_1[c2];
	//int arr_1[c3];

	/*
		constexpr
		- ������ Ÿ�� �� ������ ���� Ȯ���Ǿ�� �Ѵ�.
		- ��ũ�ο� ���������� ������� �����ϴ�.
	*/

	constexpr float pi1 = 3.141592f;	//������ ������ ������ ��������.

	float pi2 = 3.141592f;

	constexpr float pi3 = pi1;
	//constexpr float pi3 = pi2;		//������ ������ Ÿ�� �� ���� �� �� ���� �־��� �� ����

	constexpr int arr_size = 10;
	int arr[arr_size];					//������ ������ Ȯ���ȴ�.
	
	return 0;
}