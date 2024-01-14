#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>
using namespace std;

//#define _RACE
#ifdef _RACE
//================================================
// [Race Condition ���� Ȯ��]
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
		2000�� ���;� ������ �װͺ��� ������ ���� ���� ���� �ִ�.
		-> ���� �ٸ� ��������� ����� �ڿ��� ������ �� �������� �޶����� ������ �߻�
		   �̰� ���� ����(race condition)�̶�� �θ���.
	*/

	return 0;
}
#endif // _RACE

//================================================
// [Race Condition ���� �ذ��ϱ� 1 : mutex]
//================================================
/*
	mutex
		- Ư�� ������ ��� �� ���� �� �����常 ������ �� �ֵ��� �����.
		- �ش� ������ �Ӱ� �����̶�� �θ�
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

			// lock() : �� �����尡 lock()�Լ��� ȣ���� ������ ��� �ٸ� �����尡 ���Ŀ� �������� ���ϵ��� ����
			mtx.lock();
			{// �Ӱ� ���� -> �ϳ��� �����常 �� �� �ִ� ����

				++shared_memory;

			}
			// unlock() : �� �����尡 unlock()�Լ��� ȣ���� ������ �ٽ� Ǯ���־� �ٸ� �����尡 �����ϵ��� ���
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
		- �����尡 Ư�� �����͸� ���ÿ� �������� ���ϰ� �Ѵ�.
		- atomic���� ���� �����ʹ� atomic���� �����ǵ� �����ڸ� ����Ѵ�. -> ����
		- �ݺ������� ȣ��Ǵ� �����Ϳ� ����ϸ� ������ ���ϵ� �� �ִ�.
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