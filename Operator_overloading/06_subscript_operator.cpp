//참조 연산자
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class IntArray
{
public:
	//1.
	int Get(int index) { return arr[index]; }
	void Set(int index, int value) { arr[index] = value; }

	//2.
	int* GetArr() { return arr; }

	//3. 2보다 안전한 방법
	//좋다고 하기에는 애매함
	//[]를 반복적으로 호출될 상황이 많은데, if문이기 때문에 느려진다.
	int& operator[](int index)
	{
		//if (index >= 10)
		//{
		//
		//}

		//4. 디버그 시에만 체크하기 때문에 릴리즈에서는 빠름
		assert(index >= 0);
		assert(index < 10);

		return arr[index];
	}

	const int& operator[](int index) const
	{

	}

private:
	int arr[10];
};

int main()
{
	IntArray arr;
	//1. 오버로딩을 못했을 때 처리 방법(번거로움)
	/*arr.Set(0, 1);
	arr.Set(1, 2);
	arr.Set(2, 3);

	arr.Get(0);
	arr.Get(1);*/

	//2. 배열을 반환받아 사용
	//크기에 대한 정보를 알 수 없음 -> 안전하지 않음
	auto p_arr = arr.GetArr();

	p_arr[0] = 10;
	p_arr[1] = 10;

	//3. [] 오버로딩
	arr[0] = 1;
	arr[2] = 2;
	arr[3] = 3;

	IntArray* arr2 = new IntArray;

	//arr2[0] = 10;		//포인터 형태에 []을 붙이면 error
	(*arr2)[0] = 10;

	vector<int> vecs;
	
	//4.처럼 처리해줌
	vecs[0];
	vecs[1];

	//3.처럼 처리해줌
	vecs.at(0);
	vecs.at(1);

	//속도면에서 사용가능한 방법
	int* arr5 = vecs.data();		//0번 함수의 시작 주소를 반환
	arr5++;

	return 0;
}