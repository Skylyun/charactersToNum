//��д�����밢�������ֵ��໥ת��(��~һ��)
#include <iostream>
#include <string>
#include <hash_map>

using namespace std;

//��������ת��Ϊ����
int StringToNum(string singleCharacter)
{
	hash_map<string,int> hashTable;

	hashTable["��"] = 0;
	hashTable["һ"] = 1;
	hashTable["��"] = 2;
	hashTable["��"] = 3;
	hashTable["��"] = 4;
	hashTable["��"] = 5;
	hashTable["��"] = 6;
	hashTable["��"] = 7;
	hashTable["��"] = 8;
	hashTable["��"] = 9;

	hash_map<string,int>::iterator it = hashTable.find(singleCharacter);

	if (it != hashTable.end())
	{
		return it->second;
	}
	else
		return -1;
}

//���ֵ�λת��Ϊ����
int StringToUnit(string singleCharacter)
{
	hash_map<string,int> hashTable;

	hashTable["ʮ"] = 10;
	hashTable["��"] = 100;
	hashTable["ǧ"] = 1000;
	hashTable["��"] = 10000;
	hashTable["��"] = 100000000;

	hash_map<string,int>::iterator it = hashTable.find(singleCharacter);

	if (it != hashTable.end())
	{
		return it->second;
	}
	else
		return 1;
}

//һ�麺��ת����
int ChineseToNum(string characters)
{
	int size = characters.size();
	int index = 0;
	int num = 1;
	int res = 0;
	bool flag = true;

	while(index < size)
	{
		string singleCharacter;
		singleCharacter.push_back(characters[index]);
		singleCharacter.push_back(characters[index+1]);

		int numBit = StringToNum(singleCharacter);
		int unit = StringToUnit(singleCharacter);
		index += 2;

		if (numBit == 0)
		{
			flag = true;
			continue;
		}
		else if (numBit != -1)
		{
			flag = true;
			if (index<size)
			{
				num = numBit;
			}
			else
			{
				res += numBit;
			}	
		}
		else
		{
			if (flag)
			{
				if (unit == 10000)
				{
					res += num;
					res *= unit;
				}
				else
				{
					//num = num*unit;
					res += num*unit;
				}
				flag = false;
			}
			else
			{
				res *= unit;
			}
			flag = false;
		}
	}
	return res;
}

//*********************    ����   ************************//
void Test(char *testName,string characters,int expectNum)
{
	if (testName == NULL)
	{
		cout<<"��Ч�����ļ�"<<endl;
		return;
	}

	int num = ChineseToNum(characters);
	cout << testName <<":"<<characters<<" == "<< num<<"	";
	if (num == expectNum)
	{
		cout<< "pass"<<endl;
	}
	else
		cout<<"fail"<<endl;
}

void test1()
{
	string characters = "��ǧ������";
	Test("test1",characters,33000000);
}

void test2()
{
	string characters = "��";
	Test("test2",characters,0);
}


void test3()
{
	string characters = "��";
	Test("test3",characters,7);
}

void test4()
{
	string characters = "ʮ";
	Test("test4",characters,10);
}

void test5()
{
	string characters = "��ʮ��";
	Test("test5",characters,28);
}

void test6()
{
	string characters = "һ��һʮ";
	Test("test6",characters,110);
}

void test7()
{
	string characters = "������";
	Test("test7",characters,502);
}

void test8()
{
	string characters = "��ǧ�İ�����";
	Test("test8",characters,8403);
}

void test9()
{
	string characters = "������ǧ����ʮ��";
	Test("test9",characters,57035);
}

void test10()
{
	string characters = "��ʮ������ǧ������ʮ��";
	Test("test10",characters,456353);
}

int main()
{   
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();

	system("pause");
	return 0;
}
