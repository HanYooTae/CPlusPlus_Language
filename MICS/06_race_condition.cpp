#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>
using namespace std;

//#define _RACE
#ifdef _RACE
//================================================
// [Race Condition 문제 확인]
//================================================
int shared_memory = 0;

int main()
{
	auto count_func = []()
	{
		for (int i = 0; i < 1000; i++)
		{
			std::this_thread::sleep_for(chrono::milliseconds(1));
			++shared_memory;
		}
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);

	t1.join();
	t2.join();

	cout << "After : " << shared_memory << endl;

	/*
		2000이 나와야 하지만 그것보다 부족한 값이 나올 때가 있다.
		-> 서로 다른 스레드들이 공통된 자원에 접근할 때 실행결과가 달라지는 문제가 발생
		   이걸 경쟁 상태(race condition)이라고 부른다.
	*/

	return 0;
}
#endif // _RACE

//================================================
// [Race Condition 문제 해결하기 1 : mutex]
//================================================
/*
	mutex
		- 특정 공간을 잠궈 한 번에 한 스레드만 접근할 수 있도록 만든다.
		- 해당 공간을 임계 영역이라고 부름
*/

//#define MUTEX
#ifdef MUTEX
int shared_memory = 0;
mutex mtx;

int main()
{
	auto count_func = []()
	{
		for (int i = 0; i < 1000; i++)
		{
			std::this_thread::sleep_for(chrono::milliseconds(1));

			// lock() : 한 스레드가 lock()함수를 호출해 공간을 잠궈 다른 스레드가 이후에 접근하지 못하도록 막음
			mtx.lock();
			{// 임계 영역 -> 하나의 스레드만 들어갈 수 있는 공간

				++shared_memory;

			}
			// unlock() : 한 스레드가 unlock()함수를 호출해 공간을 다시 풀어주어 다른 스레드가 접근하도록 허용
			mtx.unlock();
		}
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);

	t1.join();
	t2.join();

	cout << "After : " << shared_memory << endl;

	return 0;
}
#endif // MUTEX

#define ATOMIC
#ifdef ATOMIC
/*
	atomic
		- 스레드가 특정 데이터를 동시에 접근하지 못하게 한다.
		- atomic으로 만든 데이터는 atomic에서 재정의된 연산자를 사용한다. -> 느림
		- 반복적으로 호출되는 데이터에 사용하면 성능이 저하될 수 있다.
*/
atomic<int> shared_memory = 0;

int main()
{
	auto count_func = []()
	{
		for (int i = 0; i < 1000; i++)
		{
			std::this_thread::sleep_for(chrono::milliseconds(1));

			++shared_memory;
		}
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);

	t1.join();
	t2.join();

	cout << "After : " << shared_memory << endl;

	return 0;
}
#endif // ATOMIC