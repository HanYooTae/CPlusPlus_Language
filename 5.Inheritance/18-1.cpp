
#include<iostream>
#include<vector>
using namespace std;



struct Character
{
public:
    void Move() { cout << "ĳ���� �̵� ���� ����" << endl; };
    void Attack() { cout << "ĳ���� ���� ���� ����" << endl; };

    void Init() { cout << "ĳ���� �ʱ�ȭ ���� ����" << endl; }
    void Update() { cout << "ĳ���� ������Ʈ ���� ����" << endl; }
    void Render() { cout << "ĳ���� ���� ���� ����" << endl; }

private:
    // ������ �ҽ��� ���� ���� �Ǽ��� ǥ��
    float HP;
    float Attack;
};

class Player : public Character
{
public:
    void Move() { cout << "�÷��̾� �̵� ���� ����" << endl; };
    void Attack() { cout << "�÷��̾� ���� ���� ����" << endl; };

    void Init() { cout << "�÷��̾� �ʱ�ȭ ���� ����" << endl; }
    void Update() { cout << "�÷��̾� ������Ʈ ���� ����" << endl; }
    void Render() { cout << "�÷��̾� ���� ���� ����" << endl; }

    void Loot() {}

private:
    string equipment;
};

class Monster1 : public Character
{
public:
    void Move() { cout << "����1 �̵� ���� ����" << endl; };
    void Attack() { cout << "����1 ���� ���� ����" << endl; };

    void Init() { cout << "����1 �ʱ�ȭ ���� ����" << endl; }
    void Update() { cout << "����1 ������Ʈ ���� ����" << endl; }
    void Render() { cout << "����1 ���� ���� ����" << endl; }

private:
    string Ai;
};

class Monster2 : public Character
{
public:
    void Move() { cout << "����2 �̵� ���� ����" << endl; };
    void Attack() { cout << "����2 ���� ���� ����" << endl; };

    void Init() { cout << "����2 �ʱ�ȭ ���� ����" << endl; }
    void Update() { cout << "����2 ������Ʈ ���� ����" << endl; }
    void Render() { cout << "����2 ���� ���� ����" << endl; }

private:
    string Ai;
};

class Monster3 : public Character
{
public:
    void Move() { cout << "����3 �̵� ���� ����" << endl; };
    void Attack() { cout << "����3 ���� ���� ����" << endl; };

    void Init() { cout << "����3 �ʱ�ȭ ���� ����" << endl; }
    void Update() { cout << "����3 ������Ʈ ���� ����" << endl; }
    void Render() { cout << "����3 ���� ���� ����" << endl; }

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