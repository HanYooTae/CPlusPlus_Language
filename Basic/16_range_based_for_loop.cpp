//https://openmynotepad.tistory.com/15

// range based for문에서 사본을 가져올 때는 왜 주소가 모두 똑같은걸까?


//2번 영상 32:20
#include <iostream>
#include <vector>

using namespace std;

struct array5
{
	int* begin()
	{
		return arr;		//배열의 시작점은 배열의 이름
	}

	int* end()
	{
		return &arr[4] + 1;
	}

	int arr[5] = { 1, 2, 3, 4, 5 };
};

struct test
{
	int* begin()
	{
		return arr;
	}

	int* end()
	{
		return &arr[0] + 1;
	}

	int arr[5] = { 1, 2, 3, 4, 5};
};

int main()
{
	int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	for (int i = 0; i < sizeof(fibonacci) / sizeof(fibonacci[0]); i++)
		cout << fibonacci[i] << ' ';
	cout << endl;
	cout << endl;
	cout << "test" << endl;
	cout << *fibonacci << endl;				// == fibonacci[0]
	cout << fibonacci << endl;				// 배열은 그 자체로 포인터이기 때문에 자기자신의 주소를 출력해줌.
	cout << &fibonacci << endl;				// 그렇기 때문에 fibonacci == &fibonacci
	cout << sizeof(fibonacci) << endl;		// 배열의 숫자가 12개이기 때문에, integer형 의 4바이트*12 = 48
	cout << sizeof(fibonacci[0]) << endl;	// 첫 번째 배열 요소의 크기는 integer형이기 때문에 4바이트
	cout << endl;

	/*
		연속된 데이터를 끝까지 접근하는 것
		자료형이나 auto로 가능
		&를 붙이면 실제 값에 접근함
	*/

	//사본 형식으로 원소를 받는다.
	cout << "사본" << endl;
	for (int number : fibonacci)
		//cout << number << ' ';
		cout << &number << ' ';
	cout << endl;
	cout << endl;
	cout << endl;
	
	//원본을 그대로 가져온다
	//원본을 가져오는 것이기 때문에 const를 붙여주는 것이 안전함
	cout << "원본 값" << endl;
	for (const int& number : fibonacci)
		//number = 0;			//원본을 그대로 가져오는 것이니 number에 R-value를 넣어주면 원본 값이 변한다.
		number;
	for (int& number : fibonacci)
		cout << number << ' ';
		cout << endl;
		cout << endl;

	cout << "보이는 값" << endl;
	//주소값이 바뀌는 것이 아닌 보이는 값만 0으로 바뀜
	for (int number : fibonacci) {
		number = 0;
		cout << number << ' ';	
	}
	cout << endl;
	cout << endl;

	for (int number : fibonacci) {
		number = 0;
		cout << &number << ' ';
	}
	cout << endl;
	cout << endl;
	cout << "check" << endl;
	for (const auto& number : fibonacci)
		cout << number << ' ';
	cout << endl;

	for (const auto& number : {0, 1, 2, 3, 4, 5, 6})
		cout << number << ' ';
	cout << endl;
	
	//문자열 배열의 주소값을 출력하면 이상한 값이 나온다. 왜????
	/*for (const auto& number : { 'a', 'b', 'c', 'd'})
		cout << &number << ' ';
	cout << endl;*/


	//struct array5
	//{
	//	int* begin()
	//	{
	//		return arr;		//배열의 시작점은 배열의 이름
	//	}

	//	int* end()
	//	{
	//		return &arr[4] + 1;
	//	}

	//	int arr[5] = { 1, 2, 3, 4, 5 };
	//};


	//사용자가 정의한 자료형의 경우 begin, end함수를 정의해주면 사용 가능
	array5 arr;

	cout << "dd" << endl;
	for (auto& t : arr)		//시작점과 끝점을 찾지 못해서 error가 남
		cout << t << ' ';
	cout << endl;

	//array5가 돌아가고 있는 방식
	for (int* p = &arr.arr[0]; p != &arr.arr[4] + 1; p++)
		cout << *p << ' ';

	cout << endl;


	//나중에 시간되면 확인
	// Create a vector object that contains 10 elements.
	vector<double> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i + 0.14159);
	}

	// Range-based for loop to iterate through the vector, observing in-place.
	for (const auto& j : v) {
		cout << j << " ";
	}
	cout << endl;
	cout << "end of vector test" << endl;

	return 0;
}