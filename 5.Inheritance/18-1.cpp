
#include<iostream>
#include<vector>
using namespace std;



struct Character
{
public:
    void Move() { cout << "캐릭터 이동 로직 실행" << endl; };
    void Attack() { cout << "캐릭터 공격 로직 실행" << endl; };

    void Init() { cout << "캐릭터 초기화 로직 실행" << endl; }
    void Update() { cout << "캐릭터 업데이트 로직 실행" << endl; }
    void Render() { cout << "캐릭터 렌더 로직 실행" << endl; }

private:
    // 데이터 소실을 막기 위해 실수로 표현
    float HP;
    float Attack;
};

class Player : public Character
{
public:
    void Move() { cout << "플레이어 이동 로직 실행" << endl; };
    void Attack() { cout << "플레이어 공격 로직 실행" << endl; };

    void Init() { cout << "플레이어 초기화 로직 실행" << endl; }
    void Update() { cout << "플레이어 업데이트 로직 실행" << endl; }
    void Render() { cout << "플레이어 렌더 로직 실행" << endl; }

    void Loot() {}

private:
    string equipment;
};

class Monster1 : public Character
{
public:
    void Move() { cout << "몬스터1 이동 로직 실행" << endl; };
    void Attack() { cout << "몬스터1 공격 로직 실행" << endl; };

    void Init() { cout << "몬스터1 초기화 로직 실행" << endl; }
    void Update() { cout << "몬스터1 업데이트 로직 실행" << endl; }
    void Render() { cout << "몬스터1 렌더 로직 실행" << endl; }

private:
    string Ai;
};

class Monster2 : public Character
{
public:
    void Move() { cout << "몬스터2 이동 로직 실행" << endl; };
    void Attack() { cout << "몬스터2 공격 로직 실행" << endl; };

    void Init() { cout << "몬스터2 초기화 로직 실행" << endl; }
    void Update() { cout << "몬스터2 업데이트 로직 실행" << endl; }
    void Render() { cout << "몬스터2 렌더 로직 실행" << endl; }

private:
    string Ai;
};

class Monster3 : public Character
{
public:
    void Move() { cout << "몬스터3 이동 로직 실행" << endl; };
    void Attack() { cout << "몬스터3 공격 로직 실행" << endl; };

    void Init() { cout << "몬스터3 초기화 로직 실행" << endl; }
    void Update() { cout << "몬스터3 업데이트 로직 실행" << endl; }
    void Render() { cout << "몬스터3 렌더 로직 실행" << endl; }

private:
    string Ai;
};

int main()
{
    Player p;
    vector<Monster1> m1;
    vector<Monster2> m2;

    p.Init();
    for (auto& e : m1)
        e.Init();
    for (auto& e : m2)
        e.Init();

    p.Update();
    for (auto& e : m1)
        e.Update();
    for (auto& e : m2)
        e.Update();

    p.Move();
    for (auto& e : m1)
        e.Move();
    for (auto& e : m2)
        e.Move();

    p.Render();
    for (auto& e : m1)
        e.Render();
    for (auto& e : m2)
        e.Render();


    vector<Character*> c;

    Character* cp = &Player();

    Player* pp = static_cast<Player*>(cp);
    pp->Loot();


    c.push_back(&Player());
    c.push_back(&Player());
    c.push_back(&Player());
    c.push_back(&Monster1());
    c.push_back(&Monster1());
    c.push_back(&Monster1());
    c.push_back(&Monster1());
    c.push_back(&Monster2());
    c.push_back(&Monster2());
    c.push_back(&Monster2());
    c.push_back(&Monster2());
    c.push_back(&Monster3());
    c.push_back(&Monster3());

    for (auto& e : c)
        e->Init();

    for (auto& e : c)
        e->Update();

    for (auto& e : c)
        e->Render();

    return 0;
}