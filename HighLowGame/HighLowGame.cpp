#include <stdio.h>
#include <vector>
#include <string>
#include "Card.h"
#include <random> // 시스템 시간을 사용한다.

/*
1. 52개의 카드으로 게임을 합니다.
2. 52개의 카드를 무작위로 섞습니다.
3. 게임이 시작되면 카드 하나를 오픈 합니다.
4. 플레이어는 다음카드가 오픈된 카드보다 높은 카드인지 낮은 카드인지에 대해 배팅을 합니다.
5. 다음 카드를 오픈하고 높은지 낮은지에 대한 선택이 맞으면 승리 틀리면 패배
6. 카드를 1이 가장 낮고 K가 가장 높습니다. 같은 숫자라면 높은 문양의 카드가 승리합니다. 
7. 문양은 스페이드 > 다이아 > 하트 > 클로버 순으로 높습니다.
*/

void Shuffle(std::vector<CCard>& Cards) //Shuffle라는 함수(CCard 백터배열을 참조한 카드값)-랜덤으로 나오게 하려고 만든 함수
{
	std::random_device rd;; // 여기부터 아래로 3줄, 사용하는 방법까지 외우면 된다. 숫자가 랜덤으로 나오도록 하는 장치를 가져오고
	// 1234은 시드(seed)값이라고 해서 초기에 주어지는 키값
	// 같은 시드면은 랜덤 숫자가 정하게 나온다.
	// std::mt19937 mt(1234);		   entropy:무질서, mt19937: 큰 난수를 의미. 즉 많은 숫자 중에서 랜덤으로 숫자를 뽑아오기 위함이다.
	std::mt19937 mt(rd.entropy()); // 장치를 가져왔으니 여기에서 장치를 어떻게 쓸지 만들어준다. 큰 난수(mt19937)를 만들고 숫자(mt)가 랜덤으로 나오게 하는 장치(rd)로 숫자가 무질서(entropy)하게 나오도록 한다.
									// 시드 값도 랜덤으로 부여해서 거의 같은 결과가 나오지 않는다. 
	std::uniform_int_distribution<int> dist(0, Cards.size() - 1); // 0부터 Cards.size() - 1까지의 숫자가 랜덤으로 나오는 변수형태의 개체를 만들었다.
																  // uniform_int_distributio : mt19937로 만들어진 수많은 난수 사이에서 정수들을 균일하게 분포시켜주는 장치

	for (int i = 0; i < 100; i++)
	{
		int firstIndex = dist(mt);// 위에서 외우라고 한 3줄을 사용하는 방법
		int secondIndex = dist(mt);// 위에서 mt와 dist를 세팅해줬다. dist는 0부터 Cards.size() - 1까지 랜덤으로 나오도록 하는 것.

		CCard temp = Cards[firstIndex];
		Cards[firstIndex] = Cards[secondIndex];
		Cards[secondIndex] = temp;
	}
}

// 함수이름 : CompareCard
// 파라메타 : const CCard& CardA, const CCard& CardB
// 반환값 : bool
// 함수기능 : CardA와 CardB를 비교하여 CardA가 크다면 true, CardB가 크면 false 반환

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

bool CompareCard(const CCard& CardA, const CCard& CardB) // 이거를 통해서 ScoreA > ScoreB 의 여부를 확인한다.
{
	int ScoreA = CardA.m_number * 10 + CardA.m_mark; // 두 스코어의 비교를 할 것이다.
	int ScoreB = CardB.m_number * 10 + CardB.m_mark;

	return ScoreA > ScoreB;
}

int main()
{
	std::vector<CCard> Cards;

	for (int i = CardMark::Clover; i < CardMark::MaxMark; ++i) // 카드 문양과 숫자를 마지막 52번째까지 저장하겠다. (13까지 숫자가 있는 4개의 문양이니 52개)
	{
		//1,2,3,4,5,6,7,8,9,10,J(11),Q(12),K(13)
		for (int j = 1; j <= 13; ++j) // 숫자는 1부터 13까지 반복
		{
			CCard card; // CCard class에 card 변수를 생성 -> CCard를 card라고 부르게 됨.
			card.m_mark = (CardMark)i; // (CardMark)i은 캐스팅이다. i가 1이면 1에 해당하는 카드마크를 불러온다는 의미. 그리고 그 불러온 마크를 card에 저장
			card.m_number = j; //  1-13 숫자를 card에 저장
			Cards.push_back(card); // 저장된 마크와 숫자를 푸쉬백
		}
	}

	Shuffle(Cards);

	bool bRun = true; // while문이 반복되도록 하려고 true.
	int i = 0;

	while (bRun)
	{
		printf("첫번째 카드는 %s 입니다.\n", Cards[i].GetCardStr().c_str()); // string을 printf에 쓸 수 없어서 .c_str()으로 쓴다. // string 문자열에 쓸 수 있는 호출명령어가 정해져있다.
																			 // c_str은 string을 c에서 쓸 때 변환하는 방법이다.
		int input = 0;//input = 1 이면 Cards[0] 높다. 
		printf("두번째 카드가 높으면 0, 낮으면 1을 입력해주세요 : ");
		scanf_s("%d", &input);
		system("cls"); // 출력된 값 싹 지워주는 용도.

		printf("첫번째 카드는 %s 입니다.\n", Cards[i].GetCardStr().c_str()); // i번째에 있는 Cards를 가져와서 string을 가져온 후 char로 바꿔준다.
		printf("두번째 카드는 %s 입니다.\n", Cards[i + 1].GetCardStr().c_str()); // 랜덤하게 섞어서 나열한 것이니 0번째와 1번째를 가져와도 랜덤한 카드가 뽑힌다.
		// IsFirstHigh = 1 이면 Cards[0] 높다.
		bool IsFirstHigh = CompareCard(Cards[i], Cards[i + 1]);

		if (IsFirstHigh == input)
		{
			printf("맞췄다.\n");
		}
		else
		{
			printf("틀렸다.\n");
		}

		i += 2;
	}

	//for (CCard& card : Cards) // CCard를 참조하고 card와 Cards에 저장된 값을 프린트
	//{
	//	card.printCard();
	//}
}