#include <iostream>

/*
	싱글톤 패턴
	- 객체의 인스턴스가 하나만 존재하는 패턴
*/

using namespace std;

class Audio
{
public:
	//Audio() = delete;

	//static Audio& GetInstance()		//내부적으로 자기 자신을 만들어서 리턴해주는 함수
	//{
	//	static Audio audio;
	//	return audio;
	//}

	static Audio& GetInstance()
	{
		if (ptr == nullptr)
		{
			ptr = new Audio;
		}
	
		return *ptr;
	}
	
	void PlaySound(std::string music)
	{
		cout << "소리 출력 : " << music << endl;
	}

	//생성자, 복사 생성자, 복사 대입 연산자를 숨기거나 삭제해 인스턴스가 여러 개 생성되는 것을 방지
private:
	// 클래스 전체가 공유하는 데이터
	static Audio* ptr;

	Audio() {};
	//Audio(const Audio& audio) = delete;
	//Audio& operator=(const Audio& audio) = delete;
};

Audio* Audio::ptr = nullptr;

int main()
{
	//Audio a;	//외부에서 생성되는 것을 방지
	Audio::GetInstance().PlaySound("던전");

	//Audio a, b, c, d;
	//A a, b;
	//B c;
	//a + b;		//class A
	//c + 10;		//class B

	return 0;
}