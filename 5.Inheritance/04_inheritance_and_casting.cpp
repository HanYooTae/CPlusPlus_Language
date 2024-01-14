/*
	Up Casting
	- 자식 클래스를 부모 클래스 포인터로 가리키는 것
	- 자식 클래스가 더 크긴 하지만 개념적으로 더 큰 개념으로 가는 것이라
	  암시적 형변환 가능
	- 다양한 자식 클래스를 하나의 부모 클래스 자료형으로 다룰 수 있게 된다.

	Down Casting
	- 부모 클래스 포인터가 가리키는 객체를 자식 클래스 포인터로 가리키는 것
	- 부모 클래스 포인터가 부모의 객체를 가리킬 경우, 자식 클래스의 포인터로 변환될 수는 없다.
	- 개념적으로 아래로 가는 것이기에 명시적 형변환만 가능
*/

#include <iostream>
using namespace std;

class Snack {};

class Chitos : public Snack {};
class ChocoChip : public Snack {};
class Homerunball : public Snack {};

int main()
{
	//up-casting : 암시적 형변환 가능
	Snack* chocochip = new ChocoChip();
	Snack* chitos = new Chitos();

	//서로 다른 자식 클래스를 공통된 부모 클래스로 묶어 사용이 가능
	Snack* snack[2] = { chitos, chocochip };

	Chitos* test = static_cast<Chitos*>(chitos);		//명시적 형변환만 가능

	return 0;
}