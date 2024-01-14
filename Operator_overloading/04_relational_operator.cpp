#include <iostream>
#include <vector>		//동적 배열 자료구조
#include <algorithm>	//여러 알고리즘이 정의되어있음
using namespace std;

//class를 사용할 때 연산자를 만들어줘야 사용할 수 있다.
class Won
{
public:
	Won(int value = 0) : value(value) {}

	int GetValue() const { return value; }
	void SetValue(const int& value) { this->value = value; }

	bool operator == (const Won& rhs) const
	{
		return value == rhs.value && value1 == rhs.value1;
	}

	bool operator != (const Won& rhs) const
	{
		//return value != rhs.value || value1 != rhs.value1;
		return !(*this == rhs);
	}

	bool operator < (const Won& rhs) const
	{
		return value < rhs.value;
	}

	friend ostream& operator << (ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}

private:
	int value;
	int value1;
};

bool test(const Won& lhs, const Won& rhs)
{
	return lhs.GetValue() > rhs.GetValue();
}

int main()
{
	Won w1(10), w2(20);

	if (w1 == w2)
	{

	}

	vector<Won> wons(20);		//길이가 20인 Won 동적 배열 생성
	
	int i = 0;
	for (auto& won : wons)
	{
		won.SetValue(i);
		i++;
	}

	//알고리즘에 있는 무작위 셔플함수
	random_shuffle(wons.begin(), wons.end());

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;

	//<연산자가 정의되어있어야 한다.
	//기본 오름차순 정렬
	sort(wons.begin(), wons.end());				//오름차순

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;

	//사용자가 정의한 함수를 사용해 정렬
	sort(wons.begin(), wons.end(), test);		//내림차순

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;

	//람다식 사용(일회용 함수)
	sort(wons.begin(), wons.end(),
		[](const Won& lhs, const Won& rhs)
		{
			return lhs.GetValue() < rhs.GetValue(); 
		}
	);

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;


	return 0;
}

/*
	이 놀이기구는 20살 이상, 키 140 이상만 탈 수 있습니다.

	//가독성이 좋지 않음. 드모르간 법칙으로 정리
	if(!(age > 20 && height >= 140))
	{
		//해당 놀이기구를 이용할 수 없습니다!
	}

	!(age >= 20)		-> age < 20
	!(height >= 140)	-> height < 140
	age < 20 || height < 140;		-> 드모르간 법칙을 사용하여 정리

	** 드모르간 법칙 **
	논리곱/합의 부정은 각각 부정의 논리곱/합과 같다.
	- !(A && B) = (!A) || (!B)
	- !(A || B) = (!A) && (!B)
*/