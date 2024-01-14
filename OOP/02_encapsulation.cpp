//https://morning97.tistory.com/39
#include <iostream>

using namespace std;

struct Data1		//public이 생략되어있음.
{
	//public : 구조체는 public이 기본 접근 지정자
//public: 
//private:
	int hp;
	int attack;
	float luck;
};

/*
	C++의 객체 지향은 숨기는게 기본
	변수에 의존해서 코드를 짜지 않도록 한다.	hp -= 1; hp -= 1; hp -= 1; hp -= 1;
	-> 유지보수를 쉽게 하여 위하여				ex) void attack() { hp-= 1; }
	변수에 바로 접근하는게 아닌 함수를 통해 접근을 하면 -> 오버헤드 발생 (속도 면에서는 조금 느릴 수 있음)
*/

class Data2		//실제의 대상을 넣는다면 보통 class사용
{
	//class는 기본 접근 지정자가 private
public:	// 붙이면 접근지정자 변경 가능
	/*access function, getter, setter*/

	//setter : 멤버의 데이터를 초기화/수정하는 것
	void SetHp(int hp) { this->hp = hp; cout << hp << endl; }
	void SetAttack(int attack) { this->attack = attack; cout << attack << endl; }
	void SetLuck(int luck) { this->luck = luck; cout << luck << endl; }
	//getter : 멤버의 데이터 값을 얻는 것
	int GetHp() { return hp; }
	int GetAttack() { return attack; }
	int GetLuck() { return luck; }

private:
	int hp;
	int attack;
	float luck;
};

int main()
{
	Data1 data1;
	data1.hp;

	Data2 data2;
	//data2.hp;		//class는 기본 접근 지정자가 private

	//만약 호출하지 않으면 객체 멤버 변수가 쓰레기 값을 가지게 된다.
	// -> constructor로 해결

	cout << data2.GetHp() << endl;
	cout << data2.GetAttack() << endl;
	cout << data2.GetLuck() << endl;

	data2.SetHp(10);
	data2.SetAttack(100);
	data2.SetLuck(50);

	cout << data2.GetHp() << endl;
	cout << data2.GetAttack() << endl;
	cout << data2.GetLuck() << endl;


	//유지보수가 어려운 방식 -> 디버깅하기에도 수정하기에도 불편함
	//data2.hp -= 1;
	//data2.hp -= 1;
	//data2.hp -= 1;
	//data2.hp -= 1;
	//data2.hp -= 1;


	//함수를 통해 접근하면 유지보수가 쉬워진다.
	cout << endl;

	data2.SetHp(data2.GetHp() - 1);
	data2.SetHp(data2.GetHp() - 1);
	data2.SetHp(data2.GetHp() - 1);
	data2.SetHp(data2.GetHp() - 1);
	data2.SetHp(data2.GetHp() - 1);

	return 0;
}