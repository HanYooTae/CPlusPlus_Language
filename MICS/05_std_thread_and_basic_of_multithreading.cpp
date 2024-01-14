
/*
    Process와 Thread
    - Process
        - 운영 체제에서 실행되는 프로그램의 최소 단위
            -> 보통 1개의 프로그램은 1개의 프로세스를 의미한다.

        - 서로 다른 프로세스 끼리는 메모리를 공유하지 않는다.
        - 프로세스는 CPU 코어에서 실행이 된다.

    - Thread
        - CPU 코어에서 돌아가는 프로그램 단위
        - CPU코어 하나당 한 번에 한 개의 쓰레드의 명령을 실행시킨다.
        - 프로세스는 최소 한 개 이상의 쓰레드로 이루어져 있으며 여러 개의 쓰레드로
        구성될 경우 멀티 쓰레드 프로그램이라고 부른다.
        - 같은 프로세스 내의 쓰레드들은 서로 메모리를 공유한다.

    멀티 스레드를 사용하는 경우
        - 하나의 큰 작업을 병렬화 하여 효율적으로 처리
            -> +1을 10000번 해줘야 한다고 할 때 하나의 스레드로 처리하는게 아닌
            여러 스레드에게 작업을 분할해줘서 하나가 처리하는것보다 빠르게 처리

        - 여러 작업을 동시에 처리해야 하는 경우
            -> 로딩하는 동안 게임 정보나 애니메이션 등을 보여주는 등
            여러개의 작업을 동시에 할 수 있다.


    std::thread -> c++ 11

    <Process>

    //thread가 실타래라는 의미를 가지고 있어서 찌글찌글한 선으로 표기하기도함

    main thread
        *
        |
        |            thread 0
        *----------------*
        |                |
        |                |                thread 1
        *---------------------------------------*
        |                |                      |
        |                |                      |                    thread 2
        *-------------------------------------------------------------------*
        |                |                      |                           |
        |                |                      |                           |
        |                |                      |                           |
        |                |                      |                           |
        *----------------*                      |                           |
        |                                       |                           |
        *---------------------------------------*                           |
        |                                                                   |
        *-------------------------------------------------------------------*
        |
        *

*/

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <Windows.h>
using namespace std;

//#define BEFORE
#ifdef BEFORE
//======================================================
// [멀티 스레드를 사용하기 전 ]
//======================================================

int main()
{
    // 맨위의 작업만 루프가 돌고 있음 -> 작업 1이 끝날 때 까지 아래의 작업이 처리되지 않음
    // -> 하나의 스레드로 처리하고 있기 때문이고, CPU 사용량이 100%가 안되는 이유도 모든 쓰레드가 작업을 하고 있기 때문이다.
    while (true) { cout << "작업 1" << endl; }
    while (true) { cout << "작업 2" << endl; }
    while (true) { cout << "작업 3" << endl; }
    while (true) { cout << "작업 4" << endl; }
    while (true) { cout << "작업 5" << endl; }
    while (true) { cout << "작업 6" << endl; }
    while (true) { cout << "작업 7" << endl; }
}
#endif // BEFORE

//#define COUT
#ifdef COUT
//======================================================
// [멀티 스레드를 사용하여 여러 작업을 처리해보자1]
//======================================================
int main()
{
    // 동시에 처리 가능한 쓰레드 개수 확인
    // 쓰레드 제한보다 개수가 많으면, 번갈아가면서 처리해줌. -> 작업속도가 느려질 수 있음.
    cout << std::thread::hardware_concurrency() << endl;

    // 현재 돌고있는 스레드 id출력
    cout << std::this_thread::get_id() << endl;

    std::thread t1 = std::thread(
        []() {
            cout << "ID1 : " << std::this_thread::get_id() << endl;
            while (true) {}
        }

    );

    std::thread t2 = std::thread(
        []() {
            cout << "ID2 : " << std::this_thread::get_id() << endl;
            while (true) {}
        }
    );

    std::thread t3 = std::thread(
        []() {
            cout << "ID3 : " << std::this_thread::get_id() << endl;
            while (true) {}
        }
    );

    std::thread t4 = std::thread(
        []() {
            cout << "ID4 : " << std::this_thread::get_id() << endl;
            while (true) {}
        }
    );

    std::thread t5 = std::thread(
        []() {
            cout << "ID5 : " << std::this_thread::get_id() << endl;
            while (true) {}
        }
    );

    std::thread t6 = std::thread(
        []() {
            cout << "ID6 : " << std::this_thread::get_id() << endl;
            while (true) {}
        }
    );

    /*
        출력 후 결과 1
            - 에러가 발생함
                -> 스레드가 join이나 detach가 되지 않은 상태에서
                   소멸자가 호출이 되면 예외를 발생시키도록 되어있다.

            join : 해당 스레드가 실행을 종료하면 리턴하는 함수
            -> 해당 스레드가 종료될 때까지 대기한다.
            -> 스레드의 순서는 구분하지 않기 때문에
               랜덤으로 뽑힌 첫 번째 쓰레드가 종료되면 랜덤으로 뽑힌 두 번째 쓰레드가 시작된다.

            detach : 해당 스레드를 잊어버리는 것,
                     스레드가 종료되기를 기다리지 않고 프로그램을 진행한다.
                     -> 이럴 경우, 해당 스레드는 백그라운드에서 돌아가게 된다.
                     -> 동시에 모든 쓰레드가 동작하기 때문에 뒤죽박죽 섞임


            출력 후 결과 2
            - ID가 이상하게 출력이 된다.
                -> cout은 "cout << A"처럼 하나의 데이터를 출력할 때는 다른 스레드가 접근하지 못하도록 막지만
                   "cout << A << B"인 상황에는 A를 출력하고 B를 출력하기 전에 다른 스레드가 접근할 수 있다.
                   이 문제를 해결하기 위해서는 mutex를 사용하거나 printf()를 사용하면 된다.


            출력 후 결과 3
            - 작업 관리자에서 CPU 사용률을 보면 100%가 나옴
                -> 현재 CPU가 한 번에 처리할 수 있는 스레드의 개수만큼 만들어 동작했기 때문
    */

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();


    //t1.detach();
    //t2.detach();
    //t3.detach();
    //t4.detach();
    //t5.detach();
    //t6.detach();

    Sleep(1);

    return 0;
}
#endif // COUT

//#define PRINTF
#ifdef PRINTF
//======================================================
// [멀티 스레드를 사용하여 여러 작업을 처리해보자2]
//======================================================
int main()
{
    auto work_func = [](const string& name)
    {
        for (int i = 0; i < 5; ++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            printf("%s %d : is working %d\n", name.c_str(), std::this_thread::get_id(), i);
        }
    };

    // 실행할 함수의 매개변수가 필요하다면 추가적으로 넣어준다.
    std::thread t1 = std::thread(work_func, "Jung");
    std::thread t2 = std::thread(work_func, "Bin");

    t1.join();
    t2.join();

    return 0;
}
#endif // PRINTF

