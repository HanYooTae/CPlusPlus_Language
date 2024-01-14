//https://morning97.tistory.com/39
#include <iostream>

using namespace std;

struct Data1		//public�� �����Ǿ�����.
{
	//public : ����ü�� public�� �⺻ ���� ������
//public: 
//private:
	int hp;
	int attack;
	float luck;
};

/*
	C++�� ��ü ������ ����°� �⺻
	������ �����ؼ� �ڵ带 ¥�� �ʵ��� �Ѵ�.	hp -= 1; hp -= 1; hp -= 1; hp -= 1;
	-> ���������� ���� �Ͽ� ���Ͽ�				ex) void attack() { hp-= 1; }
	������ �ٷ� �����ϴ°� �ƴ� �Լ��� ���� ������ �ϸ� -> ������� �߻� (�ӵ� �鿡���� ���� ���� �� ����)
*/

class Data2		//������ ����� �ִ´ٸ� ���� class���
{
	//class�� �⺻ ���� �����ڰ� private
public:	// ���̸� ���������� ���� ����
	/*access function, getter, setter*/

	//setter : ����� �����͸� �ʱ�ȭ/�����ϴ� ��
	void SetHp(int hp) { this->hp = hp; cout << hp << endl; }
	void SetAttack(int attack) { this->attack = attack; cout << attack << endl; }
	void SetLuck(int luck) { this->luck = luck; cout << luck << endl; }
	//getter : ����� ������ ���� ��� ��
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
	//data2.hp;		//class�� �⺻ ���� �����ڰ� private

	//���� ȣ������ ������ ��ü ��� ������ ������ ���� ������ �ȴ�.
	// -> constructor�� �ذ�

	cout << data2.GetHp() << endl;
	cout << data2.GetAttack() << endl;
	cout << data2.GetLuck() << endl;

	data2.SetHp(10);
	data2.SetAttack(100);
	data2.SetLuck(50);

	cout << data2.GetHp() << endl;
	cout << data2.GetAttack() << endl;
	cout << data2.GetLuck() << endl;


	//���������� ����� ��� -> ������ϱ⿡�� �����ϱ⿡�� ������
	//data2.hp -= 1;
	//data2.hp -= 1;
	//data2.hp -= 1;
	//data2.hp -= 1;
	//data2.hp -= 1;


	//�Լ��� ���� �����ϸ� ���������� ��������.
	cout << endl;

	data2.SetHp(data2.GetHp() - 1);
	data2.SetHp(data2.GetHp() - 1);
	data2.SetHp(data2.GetHp() - 1);
	data2.SetHp(data2.GetHp() - 1);
	data2.SetHp(data2.GetHp() - 1);

	return 0;
}