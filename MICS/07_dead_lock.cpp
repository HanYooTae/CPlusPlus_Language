#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

//#define LOCK_GUARD
#ifdef LOCK_GUARD
//========================================
// [dead lock ���� Ȯ�ΰ� �ذ� 1]
//========================================
mutex mtx1;

int main()
{
	//================
	// ���� Ȯ��
	//================
	auto worker1 = []()
	{
		for (int i = 0; i < 1000; i++)
		{
			mtx1.lock();

			// mtx1�� unlock�Ǳ� ���� ����Ǿ� ������ ������ ���
			// -> Ư�� �����̳� �ڿ��� Ǯ���⸦ ������ ����� -> dead lock
			if (i == 10) return;		// early return

			mtx1.unlock();
		}
	};

	//================
	// ���� �ذ�
	//================
	auto solution = []()
	{
		for (int i = 0; i < 1000; i++)
		{
			/*
				lock_guard�� ����Ͽ� �ذ�
					- �����ڿ��� ���� mutex�� lock() ȣ��
					- �Ҹ��ڿ��� ������ mutex�� unlock() ȣ��
			*/
			lock_guard<mutex> guard1(mtx1);
	
			if (i == 10) return;		// early return
		}
	};

	return 0;
}
#endif // LOCK_GUARD

#define Starving
#ifdef Starving
//========================================
// [dead lock ���� Ȯ�ΰ� �ذ� 2]
//========================================
mutex mtx1;
mutex mtx2;

int main()
{
	//================
	// ���� Ȯ��
	//================
	//auto worker1 = []()
	//{
	//	for (int i = 0; i < 1000; i++)
	//	{
	//		lock_guard<mutex> guard1(mtx1);
	//		lock_guard<mutex> guard2(mtx2);
	//	}
	//};
	//
	//auto worker2 = []()
	//{
	//	for (int i = 0; i < 1000; i++)
	//	{
	//		lock_guard<mutex> guard2(mtx2);
	//		lock_guard<mutex> guard1(mtx1);
	//	}
	//};
	//
	//thread t1(worker1);
	//thread t2(worker2);
	//
	//t1.join();
	//t2.join();

	/*
		������ -> ���α׷��� �������� �ʴ´�.

		worker1 : mtx1�� lock�ϰ� mtx2�� lock�Ѵ�.
		worker2 : mtx2�� lock�ϰ� mtx1�� lock�Ѵ�.

		�� �ڵ忡�� woker1���� mtx1�� lock()�ϰ� work2���� mtx2�� lock()�ϰ� �ȴٸ�
		worker1�� mtx2�� lock()���� ���ϰ� �ǰ� worker2�� mtx2�� unlock()�Ҷ����� ����Ѵ�.
		������ worker2�� mtx1�� unlock() �ɶ����� ����ؾ� �ϱ� ������ mtx2�� unlock()�� �������Ѵ�.
		-> ���ΰ� ������ �ڿ��� �����Ǳ⸦ ������ ����� -> dead lock()

		�ذ� ��� �� �ϳ��δ� �� �����忡�� �켱���� �ִ� ������ִ�.
	*/

	//================
	// ���� �ذ�
	//================
	auto worker1 = []()
	{
		for (int i = 0; i < 10; i++)
		{
			mtx1.lock();
			mtx2.lock();
	
			printf("t1 working!\n");
	
			mtx2.unlock();
			mtx1.unlock();
		}
	};
	
	auto worker2 = []()
	{
		for (int i = 0; i < 10; i++)
		{
			mtx2.lock();
			//try_lock() : lock()�� �� �ִٸ� lock()�� �� �� true ��ȯ. 
			//            lock()�� �� ���ٸ� ������� �ʰ� false ��ȯ.
			// -> mtx1�� ��� �ִٸ� worker2�� �ٸ� �����尡 ���� ó���ϵ��� �纸�� �� ��
			if (mtx1.try_lock() == false)
			{
				mtx2.unlock();
				i--;
				continue;
			}
	
			printf("t2 working!\n");
	
	
			mtx1.unlock();
			mtx2.unlock();
		}
	};
	
	thread t1(worker1);
	thread t2(worker2);
	
	t1.join();
	t2.join();

	/*
		** ������ ���� �� ���̵� ���� **
		
		������ �ذ������� ��� ���¸� �߻���ų �� �ִ�.
		-> ������ ������ ������ ���� �� �����常 �۾��� �ϰ� �ٸ� ������� �۾��� ���� ���ϴ� ��Ȳ

		����� ��Ȳ�� ���ϱ� ���� ���̵� ����
			  - ��ø�� Lock�� ����ϴ� ���� ���ض�.
				 -> ��� �����尡 lock()�� �ϳ��� ����Ѵٸ� ������� ���� �� �ִ�.

			  - Lock�� �����ϰ� ���� �� ���� �ڵ带 ȣ���ϴ� ���� ���ض�.
				 -> ���� �ڵ� ���ο� Lock()�� ���� �� �ֱ� ������ ��ø�� �� �ִ�.

			  - �������� Lock()���� ���� �Ѵٸ� ������ ������ ������ ŉ���ض�.
				 -> ���� �츮�� �߻��� ��Ȳ�� lock�� ��� ������ ���� �޶� ���� �����̴�.
				 ���࿡ ������ ������� �޾Ҵٸ� ������� �߻����� �ʾ��� ���̴�.
	*/

	return 0;
}
#endif // Starving