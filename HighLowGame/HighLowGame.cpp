#include <stdio.h>
#include <vector>
#include <string>
#include "Card.h"
#include <random> // �ý��� �ð��� ����Ѵ�.

/*
1. 52���� ī������ ������ �մϴ�.
2. 52���� ī�带 �������� �����ϴ�.
3. ������ ���۵Ǹ� ī�� �ϳ��� ���� �մϴ�.
4. �÷��̾�� ����ī�尡 ���µ� ī�庸�� ���� ī������ ���� ī�������� ���� ������ �մϴ�.
5. ���� ī�带 �����ϰ� ������ �������� ���� ������ ������ �¸� Ʋ���� �й�
6. ī�带 1�� ���� ���� K�� ���� �����ϴ�. ���� ���ڶ�� ���� ������ ī�尡 �¸��մϴ�. 
7. ������ �����̵� > ���̾� > ��Ʈ > Ŭ�ι� ������ �����ϴ�.
*/

void Shuffle(std::vector<CCard>& Cards) //Shuffle��� �Լ�(CCard ���͹迭�� ������ ī�尪)-�������� ������ �Ϸ��� ���� �Լ�
{
	std::random_device rd;; // ������� �Ʒ��� 3��, ����ϴ� ������� �ܿ�� �ȴ�. ���ڰ� �������� �������� �ϴ� ��ġ�� ��������
	// 1234�� �õ�(seed)���̶�� �ؼ� �ʱ⿡ �־����� Ű��
	// ���� �õ���� ���� ���ڰ� ���ϰ� ���´�.
	// std::mt19937 mt(1234);		   entropy:������, mt19937: ū ������ �ǹ�. �� ���� ���� �߿��� �������� ���ڸ� �̾ƿ��� �����̴�.
	std::mt19937 mt(rd.entropy()); // ��ġ�� ���������� ���⿡�� ��ġ�� ��� ���� ������ش�. ū ����(mt19937)�� ����� ����(mt)�� �������� ������ �ϴ� ��ġ(rd)�� ���ڰ� ������(entropy)�ϰ� �������� �Ѵ�.
									// �õ� ���� �������� �ο��ؼ� ���� ���� ����� ������ �ʴ´�. 
	std::uniform_int_distribution<int> dist(0, Cards.size() - 1); // 0���� Cards.size() - 1������ ���ڰ� �������� ������ ���������� ��ü�� �������.
																  // uniform_int_distributio : mt19937�� ������� ������ ���� ���̿��� �������� �����ϰ� ���������ִ� ��ġ

	for (int i = 0; i < 100; i++)
	{
		int firstIndex = dist(mt);// ������ �ܿ��� �� 3���� ����ϴ� ���
		int secondIndex = dist(mt);// ������ mt�� dist�� ���������. dist�� 0���� Cards.size() - 1���� �������� �������� �ϴ� ��.

		CCard temp = Cards[firstIndex];
		Cards[firstIndex] = Cards[secondIndex];
		Cards[secondIndex] = temp;
	}
}

// �Լ��̸� : CompareCard
// �Ķ��Ÿ : const CCard& CardA, const CCard& CardB
// ��ȯ�� : bool
// �Լ���� : CardA�� CardB�� ���Ͽ� CardA�� ũ�ٸ� true, CardB�� ũ�� false ��ȯ

/*
bool CompareCard(const CCard& CardA, const CCard& CardB)
{   
	bool compare;
	if (int(CardA.m_number) > int(CardB.m_number)) return true;
	else if (int(CardA.m_number) < int(CardB.m_number)) return false;

	compare = CardA.m_mark > CardB.m_mark ? true : false;

	return compare;
}
*/

bool CompareCard(const CCard& CardA, const CCard& CardB) // �̰Ÿ� ���ؼ� ScoreA > ScoreB �� ���θ� Ȯ���Ѵ�.
{
	int ScoreA = CardA.m_number * 10 + CardA.m_mark; // �� ���ھ��� �񱳸� �� ���̴�.
	int ScoreB = CardB.m_number * 10 + CardB.m_mark;

	return ScoreA > ScoreB;
}

int main()
{
	std::vector<CCard> Cards;

	for (int i = CardMark::Clover; i < CardMark::MaxMark; ++i) // ī�� ����� ���ڸ� ������ 52��°���� �����ϰڴ�. (13���� ���ڰ� �ִ� 4���� �����̴� 52��)
	{
		//1,2,3,4,5,6,7,8,9,10,J(11),Q(12),K(13)
		for (int j = 1; j <= 13; ++j) // ���ڴ� 1���� 13���� �ݺ�
		{
			CCard card; // CCard class�� card ������ ���� -> CCard�� card��� �θ��� ��.
			card.m_mark = (CardMark)i; // (CardMark)i�� ĳ�����̴�. i�� 1�̸� 1�� �ش��ϴ� ī�帶ũ�� �ҷ��´ٴ� �ǹ�. �׸��� �� �ҷ��� ��ũ�� card�� ����
			card.m_number = j; //  1-13 ���ڸ� card�� ����
			Cards.push_back(card); // ����� ��ũ�� ���ڸ� Ǫ����
		}
	}

	Shuffle(Cards);

	bool bRun = true; // while���� �ݺ��ǵ��� �Ϸ��� true.
	int i = 0;

	while (bRun)
	{
		printf("ù��° ī��� %s �Դϴ�.\n", Cards[i].GetCardStr().c_str()); // string�� printf�� �� �� ��� .c_str()���� ����. // string ���ڿ��� �� �� �ִ� ȣ���ɾ �������ִ�.
																			 // c_str�� string�� c���� �� �� ��ȯ�ϴ� ����̴�.
		int input = 0;//input = 1 �̸� Cards[0] ����. 
		printf("�ι�° ī�尡 ������ 0, ������ 1�� �Է����ּ��� : ");
		scanf_s("%d", &input);
		system("cls"); // ��µ� �� �� �����ִ� �뵵.

		printf("ù��° ī��� %s �Դϴ�.\n", Cards[i].GetCardStr().c_str()); // i��°�� �ִ� Cards�� �����ͼ� string�� ������ �� char�� �ٲ��ش�.
		printf("�ι�° ī��� %s �Դϴ�.\n", Cards[i + 1].GetCardStr().c_str()); // �����ϰ� ��� ������ ���̴� 0��°�� 1��°�� �����͵� ������ ī�尡 ������.
		// IsFirstHigh = 1 �̸� Cards[0] ����.
		bool IsFirstHigh = CompareCard(Cards[i], Cards[i + 1]);

		if (IsFirstHigh == input)
		{
			printf("�����.\n");
		}
		else
		{
			printf("Ʋ�ȴ�.\n");
		}

		i += 2;
	}

	//for (CCard& card : Cards) // CCard�� �����ϰ� card�� Cards�� ����� ���� ����Ʈ
	//{
	//	card.printCard();
	//}
}