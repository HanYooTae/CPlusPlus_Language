#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	int x = 0;
	cout << x << endl;

	//true가 들어있다면 계속 진행, false가 들어온다면 프로그램 종료(에러발생시킴)
	//특정 조건의 성공유무를 체크할 수 있다.
	//debug모드에서만 체크함. release모드에서는 체크하지 않는다.

	//runtime 때 체크됨. compiletime 때는 체크가 되지 않음.
	//일반적으로 컴파일 타임 때는 체크가 안된다. 런타임 때 체크됨.
	//assert(false);
	assert(x != 0 && "x is 0");		//둘다 true일 경우 참
									//문자열 상수는 항상 참이므로 &&를 사용하여 문자열을 추가적으로 붙여줄 수 있음.

	cout << "Hello" << endl;

	//static_assert(false);		//컴파일 타임 때 체크할 수 있는 assert

	//컴파일 타임 때 알 수 있는 것만 넣을 수 있다.
	const int x1 = 6;
	//아래 있는 static_assert의 조건이 틀린다면 에러가 생김
	//const int x1 = 10;
	const int y1 = 7;
	//문자열을 추가해줘야 함
	static_assert(x1 < y1, "x is bigger than y1");
	cout << x1 << endl;
	cout << y1 << endl;

	//런타임 때 체크되는 값은 들어갈 수 없다.
	int z = 10;
	/*constexpr을 붙이면 무조건 컴파일 타임 때 실행*/const int w = z;		//런타임 때 실행된다.

	return 0;
}