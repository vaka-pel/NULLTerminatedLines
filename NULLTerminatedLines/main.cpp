#include<iostream>
#include<Windows.h>
using namespace std;


int StringLenght(const char str[]);
char* ToUpper(char str[]);
char* Shrink(char str[]);
bool isPalindrome(const char str[]);

void main()
{
	cout << '�' << "\t" << '�' << endl;
	cout << (int)'�' << "\t" << (int)'�' << endl;
	setlocale(LC_ALL, "");
	const int SIZE = 256;
	//char str[SIZE] = {};
	//char str[SIZE] = "������   �����   ��   �����   �����   ���";
	char str[] = "��������� ����� �����";
	//cout << "������� ������: ";
	//SetConsoleCP(1251);
	// cin >> str;
	//cin.getline(str, SIZE);
	//SetConsoleCP(866);
	cout << str << endl;
	cout << StringLenght(str) << endl;
	cout << strlen(str) << endl; // ���������� ������ ������ � ��������
	//cout << ToUpper(str) << endl;
	cout << Shrink(str) << endl;
	cout << "������ " << (isPalindrome(str) ? "" : "�� ") << "�������� �����������" << endl;
}

int StringLenght(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

char* ToUpper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		//if (str[i] >= 'a' && str[i] <= 'z')str[i] -= ' ';
		//if (str[i] >= '�' && str[i] <= '�')str[i] -= ' ';
		//if (str[i] == '�')str[i] -= 16;
		str[i] = toupper(str[i]);
	}
	return str;

}

char* Shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)str[j] = str[j + 1];
		}
		return str;
	}
}
char* RemoveSymbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
}
bool isPalindrome(const char str[])
{
	int n = strlen(str);
	char* buffer = new char[n + 1] {};
	for (int i = 0; str[i]; i++)buffer[i] = str[i];
	ToUpper(buffer);
	n = strlen(RemoveSymbol(buffer, ' '));
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}