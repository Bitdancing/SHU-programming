#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;

#define NUM 20

//void Swap1(char*a, char* b) //����ֻ�ں����ڲ���������
//{
//	char* temp;
//	temp = a;
//	a = b;
//	b = temp;
//}


void BubbleA(char (*str)[NUM], int size)			// ����ָ��
{	
	/* ���ַ������ȣ�����ȣ����ֵ��� */
	int i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (strlen(str[j]) > strlen(str[j+1]))
			{
				/* ���ַ���������Ҫ�ú���strcpy�����ַ������� */
				char temp[1000];
				strcpy(temp, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], temp);
			}
			if (strlen(str[j]) == strlen(str[j + 1]))
			{
				if (strcmp(str[j], str[j + 1]) > 0)
				{
					char temp[1000];
					strcpy(temp, str[j]);
					strcpy(str[j], str[j + 1]);
					strcpy(str[j + 1], temp);
				}
			}
		}
	}
}

void BubbleB(char *str[], int size)					// ָ������
{
	/* ���ַ������ȣ�����ȣ����ֵ��� */
	char* temp;
	int i, j;
	for (i = 0; i < size-1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (strlen(str[j]) > strlen(str[j + 1]))
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}

			if (strlen(str[j]) == strlen(str[j + 1]))
			{
				if (strcmp(str[j], str[j + 1]) > 0)
				{
					temp = str[j];
					str[j] = str[j + 1];
					str[j + 1] = temp;
				}
			}
		}
	}

}

template <typename T> void ShowStrings(const char *prompt, const T *strs, int n)
{
	if(n>0)
		cout << prompt << strs[0];
	for(int i=1; i<n; i++)
		cout << ", " << strs[i];
	cout << endl;
}

template <typename T> void GetStrings(char **&dest, const T *source, int n)
{
	dest = new char*[n];
	if(dest == NULL) return;
	int len;
	for(int i=0; i<n; i++)
	{
		len = strlen(source[i]);
		dest[i] = new char[len+1];
		strcpy(dest[i], source[i]);
	}
}

void FreeStrings(char **&strs, int n)
{
	if(strs!=NULL)
	{
		for(int i=0; i<n; i++)
			if(strs[i]!=NULL)
				delete [] strs[i];
		delete [] strs;
		strs = NULL;
	}
}

void TestString()
{
	char strA[][NUM]={"enter", "number", "size", "begin", "of", "cat", "case", "program", "certain", "a", "cake", "side"};
	char *strB[]    ={"enter", "number", "size", "begin", "of", "cat", "case", "program", "certain", "an", "cake", "side"};
	char **strC, **strD;
	int n1 = sizeof(strA)/sizeof(*strA), n2 = sizeof(strB)/sizeof(*strB);
	//cout << n1 << "  " << n2 << endl;
	GetStrings(strC, strA, n1);
	GetStrings(strD, strB, n2);

	cout << "\n\t*** ���ֲ�ͬ�洢��ʽ��C-�ַ������������ ***" << endl;
	ShowStrings("\nԭʼ����: ", strA, n1);
	BubbleA(strA, n1);
	ShowStrings("������: ",   strA, n1);
	
	ShowStrings("\nԭʼ����: ", strB, n2);
	BubbleB(strB, n2);
	ShowStrings("������: ",   strB, n2);
	
	ShowStrings("\nԭʼ����: ", strC, n1);
	BubbleB(strC, n1);						// ����һ��������ִ���������
	ShowStrings("������: ",   strC, n1);

	ShowStrings("\nԭʼ����: ", strD, n2);
	BubbleB(strD, n2);						// ����һ��������ִ���������
	ShowStrings("������: ",   strD, n2);

	FreeStrings(strC, n1);
	FreeStrings(strD, n2);
}
