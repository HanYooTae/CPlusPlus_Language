#include <iostream>
using namespace std;

int main()
{
	//c style enum의 문제점
	{
		/*
			enum Color
			{
				Red,
				Blue
			};

			enum TintColor
			{
				Red,
				Blue
			};

			//이름 그 자체로 사용이 가능하기 때문에 중복해서 사용 불가능
			Red;
		*/

		enum Color
		{
			Color_Red,
			Color_Blue
		};

		enum TintColor
		{
			TintColor_Red,
			TintColor_Blue
		};

		enum Fruit
		{
			APPLE,
			BANANA
		};

		//둘다 같은 의미의 0임
		Color color = Color_Red;
		Fruit fruit = APPLE;

		if (color == fruit)	//의미가 다르지만 값이 같아 비교가능
		{

		}

		if (color == Color_Red)	//고유한 의미를 부여하는거랑 동일. 상수값(0)이랑 비교 가능
		{

		}

		if (color == 0)
		{

		}
	}

	/*
		Scoped Enumerations(C++ 11)
		- 영역 제한 열거형
	*/

	{
		enum class BaseColor : unsigned long long int	//enum class는 상수값의 자료형을 지정해줄 수 있다. 정수형만 가능
		{
			Red,
			Blue
		};

		enum class BaseTintColor
		{
			Red,
			Blue
		};

		//이름공간을 붙여야 하므로 중복 문제가 해결
		BaseColor::Red;
		BaseTintColor::Red;
		//Red;		//namespace를 안붙였으므로 error

		BaseColor c = BaseColor::Red;
		BaseTintColor tc = BaseTintColor::Red;

		//if (c == tc)	//같은 타입끼리만 비교 가능
		//{

		//}

		//if (c == 0)				//c의 데이터타입은 enum class BaseColor기 때문에 안됨
		//{

		//}

		if (static_cast<int>(BaseColor::Red) == 0)		// 상수 값과 비교해주고 싶으면 캐스팅을 해줘야 함
		{

		}

		if (static_cast<int>(c) == 0)
		{

		}
	}

	return 0;
}