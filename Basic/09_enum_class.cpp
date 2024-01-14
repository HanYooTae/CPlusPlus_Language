#include <iostream>
using namespace std;

int main()
{
	//c style enum�� ������
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

			//�̸� �� ��ü�� ����� �����ϱ� ������ �ߺ��ؼ� ��� �Ұ���
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

		//�Ѵ� ���� �ǹ��� 0��
		Color color = Color_Red;
		Fruit fruit = APPLE;

		if (color == fruit)	//�ǹ̰� �ٸ����� ���� ���� �񱳰���
		{

		}

		if (color == Color_Red)	//������ �ǹ̸� �ο��ϴ°Ŷ� ����. �����(0)�̶� �� ����
		{

		}

		if (color == 0)
		{

		}
	}

	/*
		Scoped Enumerations(C++ 11)
		- ���� ���� ������
	*/

	{
		enum class BaseColor : unsigned long long int	//enum class�� ������� �ڷ����� �������� �� �ִ�. �������� ����
		{
			Red,
			Blue
		};

		enum class BaseTintColor
		{
			Red,
			Blue
		};

		//�̸������� �ٿ��� �ϹǷ� �ߺ� ������ �ذ�
		BaseColor::Red;
		BaseTintColor::Red;
		//Red;		//namespace�� �Ⱥٿ����Ƿ� error

		BaseColor c = BaseColor::Red;
		BaseTintColor tc = BaseTintColor::Red;

		//if (c == tc)	//���� Ÿ�Գ����� �� ����
		//{

		//}

		//if (c == 0)				//c�� ������Ÿ���� enum class BaseColor�� ������ �ȵ�
		//{

		//}

		if (static_cast<int>(BaseColor::Red) == 0)		// ��� ���� �����ְ� ������ ĳ������ ����� ��
		{

		}

		if (static_cast<int>(c) == 0)
		{

		}
	}

	return 0;
}