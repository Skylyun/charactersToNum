//大写汉字与阿拉伯数字的相互转换(零~一亿)
#include <iostream>
#include <string>
#include <hash_map>

using namespace std;

//汉字数字转化为数字
int StringToNum(string singleCharacter)
{
	hash_map<string,int> hashTable;

	hashTable["零"] = 0;
	hashTable["一"] = 1;
	hashTable["二"] = 2;
	hashTable["三"] = 3;
	hashTable["四"] = 4;
	hashTable["五"] = 5;
	hashTable["六"] = 6;
	hashTable["七"] = 7;
	hashTable["八"] = 8;
	hashTable["九"] = 9;

	hash_map<string,int>::iterator it = hashTable.find(singleCharacter);

	if (it != hashTable.end())
	{
		return it->second;
	}
	else
		return -1;
}

//汉字单位转化为数字
int StringToUnit(string singleCharacter)
{
	hash_map<string,int> hashTable;

	hashTable["十"] = 10;
	hashTable["百"] = 100;
	hashTable["千"] = 1000;
	hashTable["万"] = 10000;
	hashTable["亿"] = 100000000;

	hash_map<string,int>::iterator it = hashTable.find(singleCharacter);

	if (it != hashTable.end())
	{
		return it->second;
	}
	else
		return 1;
}

//一组汉字转数字
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

//*********************    测试   ************************//
void Test(char *testName,string characters,int expectNum)
{
	if (testName == NULL)
	{
		cout<<"无效测试文件"<<endl;
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
	string characters = "三千三百万";
	Test("test1",characters,33000000);
}

void test2()
{
	string characters = "零";
	Test("test2",characters,0);
}


void test3()
{
	string characters = "七";
	Test("test3",characters,7);
}

void test4()
{
	string characters = "十";
	Test("test4",characters,10);
}

void test5()
{
	string characters = "二十八";
	Test("test5",characters,28);
}

void test6()
{
	string characters = "一百一十";
	Test("test6",characters,110);
}

void test7()
{
	string characters = "五百零二";
	Test("test7",characters,502);
}

void test8()
{
	string characters = "八千四百零三";
	Test("test8",characters,8403);
}

void test9()
{
	string characters = "五万七千零三十五";
	Test("test9",characters,57035);
}

void test10()
{
	string characters = "四十五万六千三百五十三";
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
