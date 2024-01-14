// 15_nested_types.cpp

#include<iostream>
using namespace std;

/*
	nested type
	- �ڷ����� ��ø�Ͽ� ���
	- �� �ڷ������� Ư�� �ڷ����� ����ϰ� ���� ��� ���
*/

class Character
{
public:

	//ĳ���� �̵� ���� ǥ��
	enum class Movement
	{
		Min		= 0,
		Idle	= Min,		// ���
		Walk,				// �ȱ�
		Run,				// �޸���
		Max		= Run,
		Count
	};

	void SetCharacterMovement(/*enum class*/ Movement in_move)
	{
		movement_state = in_move;
		speed = movement_speed[static_cast<int>(in_move)];
	}

	void PrintCurrentMovementState()
	{
		switch (movement_state)
		{
		case Character::Movement::Idle:
			cout << name << "�� ���� �̵� ���� : idle, ���� �ӵ� : " << speed << endl;
			break;

		case Character::Movement::Walk:
			cout << name << "�� ���� �̵� ���� : walk, ���� �ӵ� : " << speed << endl;
			break;

		case Character::Movement::Run:
			cout << name << "�� ���� �̵� ���� : run, ���� �ӵ� : " << speed << endl;
			break;

		default:
			break;
		}
	}

public:		//���� ���ϰ� �ϱ� ���ؼ� �缱��
	Character(string&& name) : name(name) { }		//&& Rvalue���·� �ްڴٰ� ���� or �ƹ��ų� �ްڴ�(&&�����)

private:
	//�̵� ���¿� ���� �ӵ��� ���� �迭
	static const int movement_speed[static_cast<int>(Movement::Count)];
	Movement movement_state = Movement::Idle;
	int speed = movement_speed[static_cast<int>(Movement::Idle)];

	//enum class Movement mo;

	std::string name;
};

const int Character::movement_speed[static_cast<int>(Movement::Count)] =
{
	0,
	200,
	500
};

/*
	speed[Count] = 
	{
		0,		//Idle
		200,	//Walk
		500		//Run
	}

	int sp = speed[Idle];

*/

int main()
{
	Character player(string("Player"));

	player.PrintCurrentMovementState();

	player.SetCharacterMovement(Character::Movement::Walk);

	player.PrintCurrentMovementState();

	return 0;
}