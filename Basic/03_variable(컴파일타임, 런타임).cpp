#include <iostream>
#include <numeric>

int main()
{
	/*
		Initialization
	*/

	int x = 10;		//copy
	int y(10);		//direct	: 값을 직접 넣어준다.(전달)
	int z{ 10 };	//uniform	: 형변환을 허용하지 않음 -> 안전함

	/*
		type casting
		https://doitnow-man.tistory.com/215
	*/

	int a = 1.1;		//warning : 데이터 손실
	//int b = { 1.1 };	//error	  : 데이터 손실
	char c = 500;		//warning : 데이터 잘림
	//char d = { 500 };	//error	  : 데이터 잘림

	int e = 10, f(1), g{ 2 };

	/*
		limits
		- 각각의 자료형의 한계값을 가지고 있는 클래스
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
	std::cout << (int)k << std::endl;					// C style 너무 강력함 -> 관계없는 자료형끼리의 형변환도 가능함
	std::cout << int(k) << std::endl;					// C++ style
	std::cout << static_cast<int>(k) << std::endl;		// C++ style -> 변환될 수 있을 경우에만 변환시켜줌
	
/*
	과제 : cast 종류 4가지 조사
*/

	/*
		const vs constexpr
	*/

	/*
		const
		- 받는 값에 따라 컴파일 타임이나 런타임 때 값이 정해진다.
	*/


	//컴파일 타임 때 값이 정해짐
	const int c1(123);

	//초기화되는 값이 변수기 때문에 런타임 때 값이 정해짐
	int i1 = 10;
	const int c2 = i1; 

	int c3(111);

	int arr_1[c1];
	//int arr_1[c2];
	//int arr_1[c3];

	/*
		constexpr
		- 컴파일 타임 때 무조건 값이 확정되어야 한다.
		- 매크로와 유사하지만 디버깅이 가능하다.
	*/

	constexpr float pi1 = 3.141592f;	//무조건 컴파일 시점에 정해진다.

	float pi2 = 3.141592f;

	constexpr float pi3 = pi1;
	//constexpr float pi3 = pi2;		//변수는 컴파일 타임 때 값을 알 수 없어 넣어줄 수 없음

	constexpr int arr_size = 10;
	int arr[arr_size];					//컴파일 시점에 확정된다.
	
	return 0;
}