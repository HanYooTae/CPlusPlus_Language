// 15_nested_types.cpp

#include<iostream>
using namespace std;

/*
	nested type
	- 자료형을 중첩하여 사용
	- 한 자료형에서 특정 자료형을 사용하고 싶을 경우 사용
*/

class Character
{
public:

	//캐릭터 이동 상태 표시
	enum class Movement
	{
		Min		= 0,
		Idle	= Min,		// 대기
		Walk,				// 걷기
		Run,				// 달리기
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
			cout << name << "의 현재 이동 상태 : idle, 현재 속도 : " << speed << endl;
			break;

		case Character::Movement::Walk:
			cout << name << "의 현재 이동 상태 : walk, 현재 속도 : " << speed << endl;
			break;

		case Character::Movement::Run:
			cout << name << "의 현재 이동 상태 : run, 현재 속도 : " << speed << endl;
			break;

		default:
			break;
		}
	}

public:		//보기 편하게 하기 위해서 재선언
	Character(string&& name) : name(name) { }		//&& Rvalue형태로 받겠다고 선언 or 아무거나 받겠다(&&지우기)

private:
	//이동 상태에 따른 속도를 담은 배열
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