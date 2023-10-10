#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct stTest
{
	string m_name = ""; // ���ڴ� ū����ǥ�� �ִ´�.
	int m_math = 0;
	int m_eng = 0;
	int m_lang = 0;

	stTest(string name, int math, int eng, int lang):
		m_name(name), m_math(math), m_eng(eng), m_lang(lang) {}

	void printTest()
	{
		printf("name=%s, math=%d, eng=%d, lang=%d\n", m_name.c_str(), m_math, m_eng, m_lang);
	}
};

void pushStTest(vector<stTest>& vecTest, string& str)
{
		stringstream ssTest(str);//string ���ڿ��� stringstream ���� ���·� �����.
		string line; // �о�� string ��Ƶ� ����

		// ssTest�� ���ʺ��� ','�� �������� ���ڸ� �о line�� �ִ´�.
		// getline ����� false(���̻� ���� ���ڿ��� ����)�� ����
		while (getline(ssTest, line, ','))
		{
			line.erase(remove(line.begin(), line.end(), ' '), line.end());
			printf("line[%s]\n", line.c_str());
		}

}


int main()
{
	// ���� ����
	/*
	std::ofstream writeFile;
	writeFile.open("test.txt"); // "test.txt" ������ ����(���� ������ ������ �����Ѵ�.)

	std::string strTest = "test 1234 abcd �Դϴ�.\n";
	writeFile.write(strTest.c_str(), strTest.size());
	writeFile.write(strTest.c_str(), strTest.size());

	writeFile.close(); // ������ �������� �ݵ�� �ݱ� ����
	*/

	// ���� �б�
	std::ifstream readFile; // readFile�̶�� ������ ����� ������ ������ش�.
	readFile.open("test.txt"); // readFile�̶�� ������ "test.txt"�̶�� �̸��� �޸����� ��� �д´�.

	vector<stTest> vecTest; // vecTest��� �̸��� stTest ������ �迭(���� ���µ��� ����)(vector)�� �����.
	//stTest aaa("aaa", 80, 60, 70); // stTest ������ aaa�� ����� aaa�� ���� ( ) �� ���� �ִ´�.
	//vecTest.push_back(aaa); // vecTest��� �迭 �ڿ� aaa�� ���� �ִ´�. push_back�̴� �ڿ� �ִ´�.
	//stTest bbb("bbb", 90, 30, 40);
	//vecTest.push_back(bbb);
	//stTest ccc("ccc", 20, 90, 80);
	//vecTest.push_back(ccc);

	if (readFile.is_open()) // is�� ������ �ǹ���. �����ִ�? if �� ������ Ʈ���(����������)
	{
		while (!readFile.eof()) // eof : �ݺ��� �� ������ �����ߴ��� �������ִ� �뵵
		{
			std::string str;
			std::getline(readFile, str); // readFile�� �ؽ�Ʈ�� ���� �о  str�� �ִ´�.
			printf("str=%s\n", str.c_str());

			pushStTest(vecTest, str);
			//// str
			//// a=100
			//// b=200
			//size_t index = str.find('=');
			//str.substr(index, str.length() - index);
			//std::string strRight = str.substr(index+1, str.length() - index);
			//printf("strRight=%s\n", str.c_str());
			//std::string strleft = str.substr(0, index);
			//printf("strleft=%s\n", str.c_str());
			//int num = atoi(strleft.c_str());

			//if (strleft == "a")
			//{
			//	test.a = num;
			//}
			//else if(strleft =="b")
			//{
			//	test.b = num;
			//}

			//int nPointA = str.find('='); // ���ʿ������� ���� ã��
			//printf("Find Point[%d] Character = %c\n", nPointA, str[nPointA]);
			//int nPointB = str.rfind('='); // �����ʿ������� ���� ã��
			//printf("rFind Point[%d] Character = %c\n", nPointB, str[nPointB]);

			//string strrightA = str.substr(nPointA + 1, str.length() - nPointA);
			//printf("A=%s\n", strrightA.c_str());

			//string strrightB = str.substr(nPointB + 1, str.length() - nPointB);
			//printf("B=%s\n", strrightB.c_str());

			//size_t index = 0;
			//int nResultA = stoi(strrightA, &index);
			//int nResultB = stoi(strrightB, &index); // ���� -> ���ڷ� ��ȯ
			//printf("A=%d\n", nResultA); // nResult : ��ȯ�� ����
			//printf("B=%d\n", nResultB);



			//test.a = nResultA;
			//test.b = nResultB;
		}
		readFile.close();
			
	}
	for (stTest& test : vecTest) // for���� �迭�� ó������ ������ �ݺ��Ѵٴ� �ǹ��̴�. �ݺ��� �迭�� :�ڿ� ���ش�(vecTest)
								 // �����ؿ� �ּҴ� stTest&�̴�. test�� ������ �� ������ ������� ���̴�(���ϴ� ��� �����൵ �ȴ�)
	{
		test.printTest();
	}
	


}