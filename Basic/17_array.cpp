#include <iostream>
#include <array>

using namespace std;

int main()
{
	//int arr1[] = {1, 2, 3, 4, 5};//copy 초기화		//ok
	//int arr2[]{1, 2, 3, 4, 5};	//uniform 초기화		//ok
	////int arr[](1, 2, 3, 4, 5);	//direct 초기화		//error
	//int test(1);

	////Uniform Initialization은 객체지향 시 중요하게 작용하기 때문
	//int test1 = 1.2;			//축소변환
	////int test2{ 1.2 };			//error
	//int test3(1.2);				//축소변환

	//cout << test << endl;
	//cout << test1 << endl;
	////cout << test2 << endl;
	//cout << test3 << endl;

	/*
		STL : Standard Template Libraries
		-> 데이터를 손쉽게 사용하도록 만든 라이브러리
	*/

	array<int, 5> arr4;							//int가 5개인 메모리 생성
	array<int, 5> arr5{1, 2, 3, 4, 5};			//초기화도 가능



	// []는 예외처리를 하지 않기 때문에 빠르지만 위험성이 있음
	// at()은 예외 처리를 하기 때문에 []보단 안전하지만 느리다.
	// 그냥 범위에 벗어나지 않게 []를 사용하는 것이 좋음
	cout << arr5[0] << endl;
	cout << arr5[1] << endl;
	cout << arr5.at(0) << endl;
	cout << arr5.at(1) << endl;
	cout << arr5.at(5) << endl;		// 런타임 시 에러 발생
	cout << arr5.size() << endl;

	return 0;
}

/*
	과제 : STD, STL 조사. 각각 무엇인지, 차이가 무엇인지
*/