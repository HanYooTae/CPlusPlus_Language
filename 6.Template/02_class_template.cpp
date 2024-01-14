#include <iostream>
#include "02_my_array.h"
//#include "02_my_array.cpp"	//3. 구현부가 있는 cpp까지 추가해준다. 좋은 방법이 아님
using namespace std;

int main()
{
	MyArray<int> my_array(10);
	my_array.Print();

	MyArray<float> my_array2(10);
	my_array2.Print();


	return 0;
}

/*
	만약 템플릿 코드를 작성할 때 선언과 정의를 분리하면
	링크 에러가 발생한다.
	
	* 이유
	- 템플릿 코드는 함수를 정의한게 아니라 함수의 정의를 생성하기 위해 만들어진 툴이다.
	- 템플릿 코드는 컴파일 타임 때 구체화가 된다. -> 특정 데이터형에 맞게 함수를 작성하여 inline화 시킴.
	- 컴파일 타임에서 사용될 때 정해진다. -> 사용시점에서 이미 구현부가 정의되어 있어야 함.
	- 만약 구현부가 분리되어있다면, 코드가 작성되지 않아 실제 함수와 연결시켜주는 링크타임에서 에러 발생
*/

