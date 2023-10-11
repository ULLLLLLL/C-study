#pragma once

#include <string>

enum CardMark // ī�� ������ ������ ��
{
	None = 0, // �ϳ��� ���� �������ָ� �Ʒ��� ++1�� �ö󰣴�.
	Clover, // 1
	Heart, //2
	Dia, //3
	Spade, //4
	MaxMark // 5 ������ �ִ� ��
};

class CCard
{
public:
	CCard(CardMark mark = CardMark::None, int number = 0); // �̷� �� ���� ::�� CardMark�� None, ~�Ƿ� �� �� �ִ�.

	std::string GetMarkStr();

	std::string GetCardStr();

	void printCard();

public: // CCard��� Ŭ������ � ������ ������ ���̳�?
	CardMark m_mark;
	int m_number; // �� �ΰ��� ������ ������ ���̴�!
};
