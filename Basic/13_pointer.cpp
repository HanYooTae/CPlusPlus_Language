#include<iostream>
#include<cstddef>

using namespace std;

int main()
{
	int* ptr = nullptr; // c++������ NULL�Ⱦ�
	//int* ptr2(nullptr);
	//int* ptr2{ nullptr };

	//null�� �޾Ƽ� �� �� �ִ� ���� ���� ������?
	std::nullptr_t nptr; // null�� �޴� �ڷ���

	cout << ptr << endl;

	int a = NULL;
	int* b = nullptr;

	if (a == NULL) cout << a << endl;
	if (b == nullptr) cout << a << endl;


	//int�� 0�� �ƴ� int*�� 0�� ����Ű�� ���̱� ������ nullptr���� �񱳰� ��������
	int* ptr1 = NULL;
	int* ptr2 = nullptr;

	if (ptr1 == NULL) cout << "ptr1�� NULL" << endl;
	if (ptr1 == nullptr) cout << "ptr1�� nullptr" << endl;
	if (ptr2 == NULL) cout << "ptr2�� NULL" << endl;
	if (ptr2 == nullptr) cout << "ptr2�� nullptr" << endl;

	const char* str = "DiDi";		//�迭 ����
	char str1 = 'd';				//���� ����

	std::cout << str[0] << std::endl;
	std::cout << *str << std::endl;
	std::cout << str1 << std::endl;

	return 0;
}