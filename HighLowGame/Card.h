#pragma once

#include <string>

enum CardMark // 카드 문양을 정의한 것
{
	None = 0, // 하나만 값을 설정해주면 아래는 ++1씩 올라간다.
	Clover, // 1
	Heart, //2
	Dia, //3
	Spade, //4
	MaxMark // 5 문양의 최대 값
};

class CCard
{
public:
	CCard(CardMark mark = CardMark::None, int number = 0); // 이럴 때 쓰는 ::은 CardMark의 None, ~의로 볼 수 있다.

	std::string GetMarkStr();

	std::string GetCardStr();

	void printCard();

public: // CCard라는 클래스에 어떤 변수를 저장할 것이냐?
	CardMark m_mark;
	int m_number; // 옆 두개의 변수를 저장할 것이다!
};
