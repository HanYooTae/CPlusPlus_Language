/*
	- Composition(����) part-of
		�� Ư�� Ŭ����(��ü)�� ��� �Ϻθ� �ٸ� Ŭ����(��ǰ)���� �д��ϴ� ��
		�� ��ǰ Ŭ������ ��ü Ŭ�������� ���ԵǾ� ������, �ٸ� Ŭ�������� ���Ե��� �ʴ´�.
		�� ��ü/��ǰ Ŭ������ �����ֱ⸦ �����Ѵ�. -> ��ü�� ������� ��ǰ�� �Ҹ�
		�� ����/�γ��� ����

		struct pos
		{
			int x;
			int y;
		};

		class player
		{
			pos a;		//Ŭ������ ������� �Ҹ�
		};

	- Aggregation(����) has-a
		�� Ư�� Ŭ����(��ü)�� ��� �Ϻθ� �� �� �̻��� �ٸ� Ŭ����(��ǰ)���� �д��ϴ� ��
		�� ��ü/��ǰ Ŭ������ �����ֱ⸦ �������� �ʴ´� -> ���� ���������� ��ü�� �������
			��ǰ�� ������ �� �ִ�.
		�� ���/�ڵ����� ����
	
	struct pos
		{
			int x;
			int y;
		};

		class player
		{
			pos* a;
		};

	- Association(����) uses-a
		�� Ư�� Ŭ������ �ٸ� Ŭ������ ���� ������ ����� ������ ���
		�� ���� �������� ����� ������ ������ �ٸ� Ŭ������ ������ �ʿ��ϱ⿡ ������ ���� ���̴�.
		�� �� �ʸ� ������ ���� ���� �ְ�, �Ѵ� ���� ���� �ִ�.
			-> ���ο��� ������ ��ĥ �� �ִ�(Ŀ�ø� �������� �θ��� ���������� ���� ���)
		�� �ǻ�/ȯ���� ����

	- Dependency(����)	depend-on
		�� Ư�� Ŭ������ �ٸ� Ŭ������ ����� ��� ������ ����ϴ� ����
		�� ���� ������ ���� ���� �����̴�.
		�� �ٸ� Ŭ������ �ʿ��� ��� �����ϰ� �ʿ���� �� �Ҹ��Ų��.
		�� ���/����� ����

	(�߰�)
	- Inheritance(���) is-a
		�� Ư�� Ŭ������ �ٸ� Ŭ������ ��ɰ� �Ӽ��� �����޴� ����(���)
		�� �θ�/�ڽ� ����, ���/�Ļ� Ŭ������ ����
		�� ������(�ڽ�)�� ����(�θ�)�̴�.

										 ���� ����    �ٸ� Ŭ������ ���Ҽ� �ִ°�  ����� ���縦 Ŭ������ ����  ���⼺
   Composition(����)     part-of     ��ü/��ǰ                   No                        Yes             �ܹ���
   Aggregation(����)     has-a       ��ü/��ǰ                   Yes                       No              �ܹ���
   Association(����)     uses-a      �뵵 �ܿ� ����              Yes                       No              �ܹ��� or �����
   Dependency(����)      depends-on  �˵� �ܿ� ����              Yes                       Yes             �ܹ���
*/

//���� : Ŀ�ø� ����, ���Ե�/������ ����