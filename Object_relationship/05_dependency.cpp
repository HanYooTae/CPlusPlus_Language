#include <iostream>
#include <chrono>		//시간 관련 함수들이 있는 라이브러리
using namespace std;
using namespace std::chrono;

class Timer
{
public:
	Timer()
	{
		start_time = high_resolution_clock::now();
	}

	void Elapsed()		//얼마나 시간이 흘렀는지		//스톱워치와 비슷한 개념
	{
		auto current_time = high_resolution_clock::now();
		duration<double, std::milli/*milli를 double형으로 저장하겠다*/> delta = current_time - start_time;		//duration : 시간을 저장하는 자료형

		cout << delta.count() << endl;
	}

private:
	time_point<high_resolution_clock> start_time;		//time_point : 임의의 시간 한 축을 저장
};

class Worker
{
public:
	void DoSomething()
	{
		//필요할 때 사용하고 필요없을 때 버리는 관계
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

//과제 : chrono 조사(time.h와 어떤 차이인지도)