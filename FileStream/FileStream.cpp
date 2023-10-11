#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct stTest // 구조체 : 메인문 밖에만 쓸 수 있다. 형태가 다른 함수들을 포함할 수 있다.
{			  // 배열 : 형태가 같은 변수들을 포함할 수 있다.
	string m_name; // 멤버변수 : 구조체 안에 있는 함수들
	int m_math;
	int m_eng;
	int m_lang;

	stTest(string name = "", int math = 0, int eng = 0, int lang = 0) : // 문자는 큰따옴표로 넣는다. // stTest라는 함수에 string, int들이 포함되어 있는 것이다.
		m_name(name), m_math(math), m_eng(eng), m_lang(lang) {} // 멤버 변수에 위에서 만든 변수들의 값이 들어가는 것이다.

	void printTest()
	{
		printf("name=%s, math=%d, eng=%d, lang=%d\n", m_name.c_str(), m_math, m_eng, m_lang);
	}

	void SetData(string& str)
	{
		stringstream ssTest(str);//string 문자열을 stringstream 변수 형태로 만든다.
		string line; // 읽어온 string 담아둘 변수

		// ssTest을 왼쪽부터 ','를 기준으로 문자를 읽어서 line에 넣는다.
		// getline 결과가 false(더이상 읽은 문자열이 없다)면 종료
		while (getline(ssTest, line, ','))
		{
			line.erase(remove(line.begin(), line.end(), ' '), line.end());

			int index = line.find('=');
			string leftStr = line.substr(0, index);
			string rightStr = line.substr(index + 1, line.length() - index);

			if (leftStr == "name")
			{
				m_name = rightStr;
			}
			else if (leftStr == "math")
			{
				m_math = stoi(rightStr);
			}
			else if (leftStr == "eng")
			{
				m_eng = stoi(rightStr);
			}
			else if (leftStr == "lang")
			{
				m_lang = stoi(rightStr);
			}
		}
	}
};


int main()
{
	// 파일 쓰기
	/*
	std::ofstream writeFile;
	writeFile.open("test.txt"); // "test.txt" 파일을 연다(만약 파일이 없으면 생성한다.)

	std::string strTest = "test 1234 abcd 입니다.\n";
	writeFile.write(strTest.c_str(), strTest.size());
	writeFile.write(strTest.c_str(), strTest.size());

	writeFile.close(); // 파일을 열었으면 반드시 닫기 실행
	*/

	// 파일 읽기
	std::ifstream readFile; // readFile이라는 변수를 만들어 공간을 만들어준다.
	readFile.open("test.txt"); // readFile이라는 공간에 "test.txt"이라는 이름의 메모장을 열어서 읽는다.

	vector<stTest> vecTest; // vecTest라는 이름의 stTest 공간을 배열(같은 형태들의 나열)(vector)로 만든다.
	//stTest aaa("aaa", 80, 60, 70); // stTest 형태인 aaa를 만들고 aaa의 값이 ( ) 안 값을 넣는다.
	//vecTest.push_back(aaa); // vecTest라는 배열 뒤에 aaa의 값을 넣는다. push_back이니 뒤에 넣는다.
	//stTest bbb("bbb", 90, 30, 40);
	//vecTest.push_back(bbb);
	//stTest ccc("ccc", 20, 90, 80);
	//vecTest.push_back(ccc);

	if (readFile.is_open()) // is가 붙으면 의문문. 열려있니? if 안 내용이 트루면(열려있으면)
	{
		while (!readFile.eof()) // eof : 반복할 때 어디까지 실행했는지 저장해주는 용도
		{
			std::string str;
			std::getline(readFile, str);// readFile에 텍스트를 한줄 읽어서 str에 넣는다.
			//printf("str=%s\n", str.c_str());

			stTest newData;
			newData.SetData(str);
			vecTest.push_back(newData);
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

			//int nPointA = str.find('='); // 왼쪽에서부터 문자 찾기
			//printf("Find Point[%d] Character = %c\n", nPointA, str[nPointA]);
			//int nPointB = str.rfind('='); // 오른쪽에서부터 문자 찾기
			//printf("rFind Point[%d] Character = %c\n", nPointB, str[nPointB]);

			//string strrightA = str.substr(nPointA + 1, str.length() - nPointA);
			//printf("A=%s\n", strrightA.c_str());

			//string strrightB = str.substr(nPointB + 1, str.length() - nPointB);
			//printf("B=%s\n", strrightB.c_str());

			//size_t index = 0;
			//int nResultA = stoi(strrightA, &index);
			//int nResultB = stoi(strrightB, &index); // 문자 -> 숫자로 변환
			//printf("A=%d\n", nResultA); // nResult : 변환된 숫자
			//printf("B=%d\n", nResultB);



			//test.a = nResultA;
			//test.b = nResultB;
		}
		readFile.close();
			
	}
	for (stTest& test : vecTest) // for문은 배열의 처음부터 끝까지 반복한다는 의미이다. 반복할 배열은 :뒤에 써준다(vecTest)
								 // 참조해올 주소는 stTest&이다. test는 변수를 둘 공간을 만들어준 것이다(원하는 대로 지어줘도 된다)
	{
		test.printTest();
	}
	


}