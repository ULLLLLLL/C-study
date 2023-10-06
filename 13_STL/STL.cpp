#include <stdio.h>
#include <vector>
#include <list>

struct stMonster
{
	int index = 0; // ���� Ÿ��
};

bool IsFindMonIndex(const stMonster& mon)
{
	return mon.index == 3; // ���� mon.index�� 3�̸� true�� ��ȯ, �ƴϸ� false ��ȯ
}

class CShop
{
public:
	int isOpen = false;
};

int main()
{
	// STL
	// �������� ���� �������� �迭
	// �迭 �����ϸ鼭 ó������ ������ �������� �ʰ� �ʿ��� ������ �ø��� ���� �� �ִ� �迭

	/*
	* ����(vector) - ����(Stack) ����
	* �������� �޸𸮸� Ȯ���Ѵ�.
	* �ڽ��� ��Ҹ� ������ ���� �迭(dynamic array)�� �����Ѵ�.
	* ���� ���� �����ڸ� ����([])�ϱ� ������ ��� ���� �����ϵ� ����ð�(������ �ð�)�� �ҿ�ȴ�.
	* ���� �迭�̱� ������ �迭�� �߰��� ���� �߰��ϰų� �����ϸ� ���� ���� �̵��ؾ� �ϱ� ������ ���� �ð��� �ɸ���.
	* �߰��� �߰��ϴ� ���� ������尡 ũ�� ������ ���� �޺κп� �߰��Ѵ�. (push_back)
	* ���� �迭�̱� ������ ũ���� Ȯ��� ��Ұ� ���������� ���Ҵ� ����� ũ��
	* 
	* ����
	* - ���� ������ ����ð�(������ �ð�)�� �����ϹǷ�, �б� �ӵ��� �ſ� ������.
	* 
	* ����
	* - �߰��� ���� �߰�/�����ϴ� ����� ũ��
	* - ���Ҵ� ����� ũ��
	*/

	//std::vector<int> : int���� vector �迭
	//vecint : vetor �迭�� �̸�
	//{0, 1, 2, 3, 4} : veint�� �ʱⰪ �ֱ�
	//std::vector<int> vecint{ 0, 1, 2, 3, 4 };
	//int vectorSize = vecint.size(); // ������ ��� ���� ��ȯ
	//int vec0 = vecint[0]; // [] ��Ȯ�� ��ġ�� �־ ���� ����
	//int* pData = vecint.data(); // ���� �迭 ���� ������ �޸� ������ �ּ�(������)�� ��ȯ
	//int vCap = vecint.capacity(); // ������ ũ�� ���鿡���� ���� ���� ũ�⸦ ��ȯ
	//printf("vecint capacity=%d\n", vCap);

	//for (int i = 0; i < vecint.size(); i++)
	//{
	//	printf("vecint[%d]=%d\n", i, vecint[i]);
	//}

	//for (int value : vecint) // �� ���� ������� ���� �����ϸ� ���� �����ʹ� ���� �ȵ� &�� �� �����Ƿ� ���Ŀ��� ������� ����.
	//{
	//	value = 0;
	//	printf("vecint=%d\n", value);
	//}

	//for (const int& value : vecint) // ���۷��� ���� �� const ������ �����ϸ� �� ���� �Ұ���
	//{
	//	//value = 0;
	//	printf("vecint=%d\n", value);
	//}

	//for (int& value : vecint) // ���۷��� ���� ������� ���� �����ϸ� ���� ������ ����. &�� ���ؼ� value ���� �ٲ㼭 ���Ŀ��� ����ȴ�.
	//{
	//	value = 1;
	//	printf("Ref vecint=%d\n", value);
	//}

	//for (const int& value : vecint) // ���۷��� ���� �� const ������ �����ϸ� �� ���� �Ұ���
	//{
	//	//value = 0;
	//	printf("vecint=%d\n", value);
	//}

	//std::vector<int> vecInt{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//std::vector<int>::iterator vecIter = vecInt.begin();
	//vecIter++; // ���⼭ ++�� ������ �迭�� ��ġ�� ����Ű�ڴٴ� �ǹ��̴�.
	//vecIter += 2; // 0�������� ���������� 2�� �̵��� �迭�� ��ġ�� ����Ű�ڴ�.
	//vecIter -- ;// -- �� �������� ��ĭ �̵��Ѵٴ� �ǹ��̴�.
	//// vecInt.end(); // �迭�� �����ٴ� �ǹ�(������ �迭�� ���ϴ� �� �ƴ϶� �迭�� ������!)
	//vecInt.push_back(100); // �迭�� �������� 100 ��Ҹ� �߰��ϰڴ�.
	//for (std::vector<int>::iterator iter = vecInt.begin(); iter != vecInt.end(); ++iter)
	//{
	//	printf("iter=%d\n", *iter);
	//}

	//vecInt.pop_back(); // ������ �迭�� ��Ҹ� �����ϰڴ�.
	//vecIter = vecInt.begin();
	//while (vecIter != vecInt.end())
	//{
	//	printf("while iter=%d\n", *vecIter);
	//	vecIter++;
	//}
	//printf("vecInt=%d\n", int(vecInt.size()));

	//vecIter = vecInt.begin();
	//while (vecIter != vecInt.end())
	//{
	//	if (*vecIter == 5)
	//	{
	//		vecIter = vecInt.erase(vecIter); // vecIter�� ����Ű�� �ִ� �迭 ��Ҹ� �����ϰڴ�. (5�� ����� ���� �� �� ����)
	//	}
	//	else
	//	{
	//		vecIter++;
	//	}
	//}

	//vecIter = vecInt.begin();
	//while (vecIter != vecInt.end())
	//{
	//	printf("while iter=%d\n", *vecIter);
	//	vecIter++;
	//}



	/*
	* ����Ʈ(list)
	* ����Ʈ�� ��ҵ��� ����� ���Ḯ��Ʈ�� ���·� �����Ѵ�. (Doubly linked List) // (1���)-(1����) -> (2���)-(2����) -> (3���)-(3����) -> ...
	* ����Ʈ ��ü�� ��Ŀ�� �Ҹ��� ������ 2���� �����ϴµ� �̴� head�� tail���� ����Ų��.
	* ���ο� ��Ҹ� �����ϱ� ���ؼ��� �� ������(��Ŀ)�� �����Ѵ�.
	* ����Ʈ�� ���� ����([]])�� �������� �ʴ´�. (n��° ��ҿ� �����ϱ� ���ؼ� ������ ���ľ� �ϱ� ����)
	* Ư�� ��ġ�� �߰�/������ �����Ӵ�. (Ư�� ��ġ�� ã�� �ð��� ����)
	* ���Ҵ� ������ ����. �������� �޸𸮰� �ƴϱ� ������(�޸𸮰� �����Ǵ� ��) ������ �߰��� �� �ִ�.
	* 
	* ����
	* - ������ ��ġ�� ��Ҹ� �߰��ϴ� ���� �����Ӵ�(Ư�� ��ġ�� ã�� �ð��� ����) ���� ���⿡ �ſ� ���ϴ�
	* 
	* ����
	* - ���������� �Ұ����ϱ� ������ ���� Ž���Ͽ� ��ġ�� ã�´�.
	* - ���Ұ��� ������ ���� �߰����� �޸𸮸� �Ҹ��Ѵ�(���� ����� ������ �޸�)
	*/

	// std::list<int> : ����Ʈ�� ������ ������
	// listInt : ������ ����Ʈ�� �̸�
	// { 0, 1, 2, 3, 4 }; : ����Ʈ�� �⺻��
	//std::list<int> listInt{ 0, 1, 2, 3, 4 };
	//
	//for (int value : listInt)
	//{
	//	value = 0;
	//	printf("List Value=%d\n", value);
	//}

	//for (const int& value : listInt)
	//{
	//	printf("List Value=%d\n", value);
	//}

	//std::list<int>::iterator listIter = listInt.begin();
	//printf("listIter=%d\n", *listIter);
	//for (std::list<int>::iterator iter = listInt.begin(); iter != listInt.end(); ++iter)
	//{
	//	printf("For List Balue=%d\n", *iter);
	//}

	//listIter = listInt.begin();
	//while (listIter != listInt.end())
	//{
	//	printf("while List Value=%d\n", *listIter);
	//	listIter++;
	//}

	std::list<int> listInt{ 10, 7, 31, 22, 75 };
	listInt.push_back(100); // ����Ʈ�� ���ʿ� ���� �߰� �����Ѵ�.
	listInt.push_front(200);// ����Ʈ�� ���ʿ� ���� �߰� �����Ѵ�.

	listInt.pop_back();// ����Ʈ�� ���ʿ� ���� �����Ѵ�.
	listInt.pop_front();// ����Ʈ�� ���ʿ� ���� �����Ѵ�.

	for (const int& value : listInt)
	{
		printf("List Value=%d\n", value);
	}

	// ����Ʈ���� Ư�� ���� ã��
	std::list<int>::iterator it = std::find(listInt.begin(), listInt.end(), 75);
	if(it != listInt.end())
	{
		// ã�Ҵ�.
		printf("Find List Value=%d\n", *it);
		// listInt.erase(it);// ����Ʈ �ȿ� Ư�� ��� �����ϱ�
		int value = 2023;
		// listInt.insert(it, value); // Ư�� ��� ���ʿ� ���ο� ��� �����ֱ� (Ư�� ��Ҵ� �� std���� 75�� ������)
		 listInt.emplace(it, 2024); // Ư�� ��� ���ʿ� ���ο� ��� �����ֱ�
	}
	else
	{
		// �� ã�Ҵ�.
		printf("Find List Fail!\n");
	}

	for (const int& value : listInt)
	{
		printf("List Value=%d\n", value);
	}



	// ����ü �迭 find_if�� Ư�� ��� ã��
	std::list<stMonster> arrMon;

	for (int i = 0; i < 6; i++)
	{
		stMonster temp;
		temp.index = i+10;
		arrMon.push_back(temp);
	}

	std::list<stMonster>::iterator monIter;
	// monIter = std::find_if(arrMon.begin(), arrMon.end(), IsFindMonIndex);
	monIter = std::find_if(arrMon.begin(), arrMon.end()
		, [](const stMonster& mon)
		{
			return mon.index ==12;
		});
	
	if (monIter != arrMon.end())
	{
		// ã�Ҵ�
		printf("monIter index=%d\n", monIter->index);
	}
	else
	{
		// ��ã��
		printf("monIter find Fail!\n");
	}


	for (const stMonster& value : arrMon)
	{
		printf("Monster index=%d\n", value.index);
	}

}