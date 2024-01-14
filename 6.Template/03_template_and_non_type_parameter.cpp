#include <iostream>
#include <array>
using namespace std;

/*
	non - type parameter
	- 자료형이 아닌 템플릿 매개변수
	- 템플릿 매개변수 값에 자료형이 아닌 값을 넣어준다.
*/

template<typename T/*type*/, unsigned int SIZE/*value*/>
class MyArray
{
public:
	MyArray()
	{

	}

	~MyArray()
	{

	}

private:
	T arr[10];		//정적 할당(이미 정해져있는 값, 컴파일 시점에 확인가능한 값만 가능)
	T arr2[SIZE];	//템플릿 구체화시점(컴파일 타임)에 값이 들어감
};

int main()
{
	MyArray<int, 10> arr1;
	MyArray<float, 20> arr2;

	array<int, 10> stl_arr;

	return 0;
}