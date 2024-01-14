#include <iostream>
#include <string>

using namespace std;

struct person
{
	person(int b)		//구조체안에 생성자 함수명은 구조체명과 같아야 함
	{
		cout << "person이 생성됨!" << endl;
		this->b = b;
	};

	int b;
};

int main()
{
	int* ptr1 = new int(100);	//동적 할당
	delete ptr1;			//동적 해제
	cout << ptr1 << endl;	// *ptr1의 값은 100
	//cout << *ptr1 << endl;	// *ptr1의 값이 사라졌기 때문에 *ptr1은 출력이 안됨. 하지만 ptr1(주소값)은 남아있음.
	ptr1 = nullptr;
	cout << ptr1 << endl;	// 허상포인터 문제를 해결해주기 위하여 ptr1의 주소값을 초기화시킴.
	cout << endl;
	int* pt1 = new int(10);
	cout << pt1 << endl;
	cout << *pt1 << endl;

	delete pt1;
	pt1 = nullptr;
	cout << pt1 << endl;

	cout << endl;

	//다이렉트 초기화가 무엇인가?
	int* ptr2 = new int(7);	//다이렉트 초기화로 초기화 가능
	cout << ptr2 << endl;
	delete ptr2;
	cout << ptr2 << endl;
	ptr2 = nullptr;
	cout << ptr2 << endl;
	cout << endl;

	int* ptr3 = new int{ 7 };
	delete ptr3;
	ptr3 = nullptr;
	cout << ptr3 << endl;

	cout << endl;
	//여기부터 다시 보기
	//new는 할당 실패 시 nullptr를 리턴하지 않기 때문에 C에서 하던 방법으로 예외처리가 되지 않는다.
	//-> std::nothrow를 사용할 경우 할당 실패 시 nullptr를 리턴받는다.		//try catch대신 예외처리하는 방법
	int* ptr4 = new/*(std::nothrow)*/ int(7);

	int* ptr5 = new(std::nothrow) int(7);

	if (ptr4 == nullptr)
		std::cout << "Error";

	if (ptr4 != nullptr)
	{
		delete ptr4;
		ptr4 = nullptr;
	}

	cout << "test : " << endl;
	int* test1 = new(nothrow) int(7);
	
	cout << test1 << endl;
	if (test1 == nullptr)
		cout << "Error!" << endl;

	if (test1 != nullptr)
	{
		delete test1;
		test1 = nullptr;
	}

	cout << test1 << endl;

	cout << "test over" << endl;

	//배열 형태 선언
	int* arr = new int[10]{ 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;

	delete[] arr;	//배열 데이터를 해제 시 []를 추가해야한다.
	arr = nullptr;

	for (int i = 0; i < 5; i++)
	{
		cout << &arr[i] << ", ";
	}
	cout << endl;
	cout << endl;

	//포인터 배열을 이차원 포인터로 받을 수 있다.
	int** ptr_arr = new int* [5];
	
	ptr_arr[0] = new int[10];
	ptr_arr[1] = new int[10];
	ptr_arr[2] = new int[10];
	ptr_arr[3] = new int[10];
	ptr_arr[4] = new int[10];

	for (int i = 0; i < 5; i++)
		cout << ptr_arr[i] << ", ";
	cout << endl;

	for (int i = 0; i < 5; i++) {
		delete[] ptr_arr[i];
		//ptr_arr[i] = nullptr;		//왜 nullptr로 초기화시켜주지 않았는지 질문하기
		cout << ptr_arr[i] << ", ";
	}
	cout << endl;

	delete[] ptr_arr;
	cout << ptr_arr << ", ";
	cout << endl;

	for (int i = 0; i < 5; i++) {
	}
		ptr_arr = nullptr;
		cout << ptr_arr << ", ";
	cout << endl;

	person avc(10);

	return 0;
}

// 과제 new와 malloc차이 어디서 사용하는지 조사
//https://flower0.tistory.com/500, calloc과 realloc도 찾아보기

/*
	new
	- 만들 자료형을 알고 있는 상태. 그렇기 때문에 해당 데이터의 생성자를 호출해준다. ex) int* ptr = new int(100);
	- delete를 했을 때 지우는 객체를 알기 때문에 해당 객체의 소멸자를 호출해줄 수 있다. ex) delete ptr;

	malloc
	- 반환 값이 void*이기 때문에 원하는 형태로 캐스팅해줘야 함.
	- 어떤건지 알지 못하고 넣어준 byte크기의 공간만 만들어줘서 맞게 캐스팅해서 쓰라고 void*형태로 리턴해줌.
	
*/


//struct Test
//{
//   int a;
//   int b;
//   std::string str;
//};
//
//int main()
//{
//   Test* test = new Test;
//
//   test->a = 10;
//   test->b = 20;
//   test->str = "Hello!!";
//
//   std::cout << test->a << std::endl;
//   std::cout << test->b << std::endl;
//   std::cout << test->str << std::endl;
//   // 과제 malloc를 사용해 위의 Test동적 할당하고, 위의 코드 재실행하고 문제점이나 위험성 찾아보기
//   return 0;
//}