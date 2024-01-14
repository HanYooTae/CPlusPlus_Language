#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
	//�����ͷ� ���� ��� ���ڿ� ����� �ּҸ� �޴°Ŷ� ������ �ȵ�
	//C++������ �����ϰ� ������ const�� ������ ������ ����� �� ����.
	const char* test = "Hello";
	char my_str[] = "Hello, C++";

	cout << *test << endl;		//�Ǿ� ���� H�� ���
	cout << test << endl;		//Hello ���
	cout << my_str << endl;

	//string : ���ڿ��� �ٷ�� ���� ���ִ� ��ü
	string str = "Hello, C++!";

	cout << str << endl;

	//���� ��ȯ
	cout << str.size() << endl;
	cout << str.length() << endl;

	//����ó�� �ʱ�ȭ ����
	string a("Hello, ");
	string b("C++!!");

	//+���� ����
	string c = a + b;

	c += ", good";
	cout << c << endl;

	/*
		string�Լ� �˻�
	*/

	//�迭ó�� ��� ����	const char*�� ����
	cout << c[5] << endl;

	char String[10] = "abcd����";
	int Len = strlen(String);
	cout << Len << endl;

	wchar_t String1[10] = L"abcd����";
	int Len1 = wcslen(String1);
	cout << Len1 << endl;


	return 0;
}