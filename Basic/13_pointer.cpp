#include<iostream>
#include<cstddef>

using namespace std;

int main()
{
	int* ptr = nullptr; // c++에서는 NULL안씀
	//int* ptr2(nullptr);
	//int* ptr2{ nullptr };

	//null만 받아서 할 수 있는 일이 뭐가 있을까?
	std::nullptr_t nptr; // null만 받는 자료형

	cout << ptr << endl;

	int a = NULL;
	int* b = nullptr;

	if (a == NULL) cout << a << endl;
	if (b == nullptr) cout << a << endl;


	//int의 0이 아닌 int*의 0을 가리키는 것이기 때문에 nullptr과의 비교가 가능해짐
	int* ptr1 = NULL;
	int* ptr2 = nullptr;

	if (ptr1 == NULL) cout << "ptr1은 NULL" << endl;
	if (ptr1 == nullptr) cout << "ptr1은 nullptr" << endl;
	if (ptr2 == NULL) cout << "ptr2은 NULL" << endl;
	if (ptr2 == nullptr) cout << "ptr2은 nullptr" << endl;

	const char* str = "DiDi";		//배열 형태
	char str1 = 'd';				//문자 형태

	std::cout << str[0] << std::endl;
	std::cout << *str << std::endl;
	std::cout << str1 << std::endl;

	return 0;
}