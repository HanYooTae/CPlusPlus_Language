#include <iostream>
#include <iomanip>

/*
	stream(>>, <<)
	- 데이터의 입력과 출력의 흐름을 표시한 것
*/

int main()
{
	/*
		cout, endl
	*/

	int x = 1028;
	double pi = 3.141592;

	std::cout << "x is " << x << " pi is " << pi << std::endl << std::endl;
	
	/*
		cin
	*/

	/*
		>> input operator(stream)
	*/

	int z;
	std::cin >> z;
	std::cout << "input : " << z << std::endl;
	std::cout << std::endl;

	/*
		조정자 (manipulator)
		- 출력 형식을 지정해줄 수 있다.
		- 바꿔주지 않는 한 계속 유지된다.
	*/

	int num = 100;

	// 진수 출력 형식 조정자, 바꾼 후에 다른 진법으로 바꿔주고 싶다면, 반드시 진수 출력 형식 조정자를 바꿔주어야 한다.
	// 8진수
	std::cout << std::oct << num << std::endl;
	// 10진수
	std::cout << std::dec << num << std::endl;
	// 16진수
	std::cout << std::hex << num << std::endl << std::endl;

	/*
		showbase : 어떤 진수 형태로 출력되는지 표시
		showpos	 : 십진수 정수의 부호 표시
		-> noshowbase, noshowpos로 각각 해제 가능
	*/
	std::cout << std::showbase << std::showpos;	
	std::cout << std::oct << num << std::endl;					// 8진수  = 0144	(8진수는 앞에 0이 붙음)
	std::cout << std::dec << num << std::endl;					// 10진수 = +100	(10진수는 앞에 +가 붙음)
	std::cout << std::hex << num << std::endl << std::endl;		// 16진수 = 0x64	(16진수는 앞에 0x가 붙음)
	std::cout << std::noshowbase << std::noshowpos;

	bool is_true = true;
	bool is_false = false;

	std::cout << std::boolalpha;	// true, false 형식으로 출력
	std::cout << is_true << std::endl;
	std::cout << is_false << std::endl;

	std::cout << std::noboolalpha;	// boolalpha 취소 (1, 0으로 출력)
	std::cout << is_true << std::endl;
	std::cout << is_false << std::endl;

	


	return 0;
}

#include <iomanip>		//조정자 헤더