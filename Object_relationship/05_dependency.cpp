#include <iostream>
#include <chrono>		//�ð� ���� �Լ����� �ִ� ���̺귯��
using namespace std;
using namespace std::chrono;

class Timer
{
public:
	Timer()
	{
		start_time = high_resolution_clock::now();
	}

	void Elapsed()		//�󸶳� �ð��� �귶����		//�����ġ�� ����� ����
	{
		auto current_time = high_resolution_clock::now();
		duration<double, std::milli/*milli�� double������ �����ϰڴ�*/> delta = current_time - start_time;		//duration : �ð��� �����ϴ� �ڷ���

		cout << delta.count() << endl;
	}

private:
	time_point<high_resolution_clock> start_time;		//time_point : ������ �ð� �� ���� ����
};

class Worker
{
public:
	void DoSomething()
	{
		//�ʿ��� �� ����ϰ� �ʿ���� �� ������ ����
		Timer timer;
		for (int i = 0; i < 10000000; i++);
		timer.Elapsed();
	}

private:
};

int main()
{
	Timer t;
	for (int i = 0; i < 10000000; i++)
	{
		int* temp = new int;
		delete temp;
	}
	t.Elapsed();

	return 0;
}

//���� : chrono ����(time.h�� � ����������)