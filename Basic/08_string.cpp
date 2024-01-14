#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
	//포인터로 받을 경우 문자열 상수의 주소를 받는거라 수정이 안됨
	//C++에서는 엄격하게 관리해 const를 붙이지 않으면 사용할 수 없다.
	const char* test = "Hello";
	char my_str[] = "Hello, C++";

	cout << *test << endl;		//맨앞 글자 H만 출력
	cout << test << endl;		//Hello 출력
	cout << my_str << endl;

	//string : 문자열을 다루기 쉽게 해주는 객체
	string str = "Hello, C++!";

	cout << str << endl;

	//길이 반환
	cout << str.size() << endl;
	cout << str.length() << endl;

	//변수처럼 초기화 가능
	string a("Hello, ");
	string b("C++!!");

	//+연산 가능
	string c = a + b;

	c += ", good";
	cout << c << endl;

	/*
		string함수 검색
	*/

	//배열처럼 사용 가능	const char*도 가능
	cout << c[5] << endl;

	char String[10] = "abcd가나";
	int Len = strlen(String);
	cout << Len << endl;

	wchar_t String1[10] = L"abcd가나";
	int Len1 = wcslen(String1);
	cout << Len1 << endl;


	return 0;
}