#include <iostream>

/*
	�̱��� ����
	- ��ü�� �ν��Ͻ��� �ϳ��� �����ϴ� ����
*/

using namespace std;

class Audio
{
public:
	//Audio() = delete;

	//static Audio& GetInstance()		//���������� �ڱ� �ڽ��� ���� �������ִ� �Լ�
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
		cout << "�Ҹ� ��� : " << music << endl;
	}

	//������, ���� ������, ���� ���� �����ڸ� ����ų� ������ �ν��Ͻ��� ���� �� �����Ǵ� ���� ����
private:
	// Ŭ���� ��ü�� �����ϴ� ������
	static Audio* ptr;

	Audio() {};
	//Audio(const Audio& audio) = delete;
	//Audio& operator=(const Audio& audio) = delete;
};

Audio* Audio::ptr = nullptr;

int main()
{
	//Audio a;	//�ܺο��� �����Ǵ� ���� ����
	Audio::GetInstance().PlaySound("����");

	//Audio a, b, c, d;
	//A a, b;
	//B c;
	//a + b;		//class A
	//c + 10;		//class B

	return 0;
}