#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
/*
дһ���ַ������жϸ��ַ����Ƿ�Ϊabcdef�����ַ���
��  cdefab Ϊabcdef�����ַ���
*/
//int judge(char* a,char* b)
//{	
//	int sza = strlen(a);
//	int szb = strlen(b);
//	if (szb != 6)
//	{
//		return 0;
//	}
//	int i = 0;
//	for (i = 0; i < sza; i++)
//	{
//		//�ҵ�b��a�ص��ĵ�һ����ĸ
//		if (*b == *(a + i))
//		{
//			break;
//		}
//		if (i == sza - 1)
//		{
//			return 0;
//		}
//
//	}
//		//�Ӹ���ĸb��a��ʼƥ��
//	int m = i;
//	for (; i < m + szb; i++)
//	{
//		
//		if (*(b+i-m) != *(a + i))
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	char a[] = "abcdefabcde";
//	char b[] = "fabcde";
//	int ret=judge(a,b);
//	if (ret == 1)
//		printf("YES\n");
//	else
//		printf("NO\n");
//	return 0;
//}
//׷�Ӻ�����strcat��
//int main()
//{
//	char arr1[10] = "abc";//10һ��Ҫ�ӣ�Ҫȷ��arr1��װ����
//	char arr2[] = "def";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);//abcdef
//	return 0;
//}
//int main()
//{
//	char arr1[10] = "abcd";
//	strcat(arr1, arr1);
//	printf("%s\n", arr1);//ϵͳ���������������������Լ����Լ�׷���ַ���
//	return 0;
//}
//strcat �� strncat
//char * strcat ( char * destination, const char * source );  strcat  ��������Ϊchar*   ֻ��Ҫ�����ַ�������
//char * strncat ( char * destination, const char * source, size_t num );  ��������Ϊchar*  ���������ַ����⻹�к���ӵ��ַ����Ĵ�С
//int main()
//{
//	char arr1[10] = "abcd";
//	char arr2[] = "cdef";
//	strncat(arr1, arr2, 3);//��ʾ��arr2�и���3���ַ���ȥ
//	printf("%s\n", arr1);//abcdcde
//	return 0;
//}
//ʹ�ÿ⺯��strstr��strcat
//int judge(char* arr1, char* arr2)
//{
//	int sz1 = strlen(arr1);
//	int sz2 = strlen(arr2);
//	if (sz1 != sz2)
//	{
//		return 0;
//	}
//	strncat(arr1, arr1, 6);
//	char* p = strstr(arr1, arr2);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret = judge(arr1,arr2);
//	if (ret == 0)
//	{
//		printf("NO\n");
//	}
//	else
//	{
//		printf("YES\n");
//	}
//	return 0;
//}
/*
���Ͼ���
��һ���������ִ������ҵ������������µ���
�磺
1  3  6
2  6  7
7  8  9
����һ�����Ͼ���
�����Ͼ����п��ٲ���һ�����Ƿ����
*/
//int findnum(int arr[3][3],int n,int row,int lis,int* p1,int* p2)
//{
//	int i = 0;
//	int j = 0;
//	while (i<row && j<lis)//�÷����Խ����Ż�ʹ����Ӿ���
//	{
//		if (arr[0+i][2-j] < n)
//		{
//			i++;
//		}
//		else if (arr[0 + i][2 - j] == n)
//		{
//			*p1 = i;
//			*p2 = j;
//			return 1;
//		}
//		else
//		{
//			j++;
//		}
//		if (arr[0 + i][2 - j] == n)
//		{
//			*p1 = i;
//			*p2 = j;//�ҵ����ֲ���֪�����±�
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { {1,3,6},{2,6,7},{7,8,9} };
//	//Ҫ���ٲ���  ��ÿ�Ƚ�һ�ο��ų�һ�л�һ��
//	//��ɴӵ�һ�����һ���������һ�е�һ������ʼ��
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	int* p1 = &n;
//	int* p2 = &i;
//	int ret = findnum(arr, n, 3, 3,p1,p2);
//	if (ret == 0)
//	{
//		printf("��\n");
//	}
//	else
//	{
//		printf("�� ����Ϊ:(%d,%d)\n",*p1+1,3-*p2);
//	}
//	return 0;
//}����������������������������������������������������������
//int main()
//{
//	int arr[3][3] = { { 1,3,6 },{ 2,6,7 },{ 7,8,9 } };//��֤��д�ĺ����Ƿ���ȫ��ȷ
//	int n = 0;
//	for (n = 0; n < 10; n++)
//	{
//		int ret = findnum(arr, n, 3, 3);
//		if (ret == 1)
//		{
//			printf("%d ", n);
//		}
//	}
//	return 0;
//}����������������������������������������������������
//void move(int arr[3][3])
//{
//	printf("%d\n", arr[1][1]);//6  �����ҵ��ڶ��еڶ��е�6 ��arr�ĳ�ʼֵΪ1 3 6  ������{ 1,3,6 },{ 2,6,7 },{ 7,8,9 }
//}
//int main()
//{
//	int arr[3][3] = { { 1,3,6 },{ 2,6,7 },{ 7,8,9 } };
//	move(arr);
//	return 0;
//}������������������������������������������������������������
//�Ż���
//int findnum(int arr[3][3],int n,int* p1,int*p2)
//{
//	int i = 0;
//	int j = 0;
//	while (i<*p1 && j<*p2)
//	{
//		if (arr[0+i][2-j] < n)
//		{
//			i++;
//		}
//		else if (arr[0 + i][2 - j] == n)
//		{
//			*p1 = i+1;
//			*p2 = 3-j;
//			return 1;
//		}
//		else
//		{
//			j++;
//		}
//		if (arr[0 + i][2 - j] == n)
//		{
//			*p1 = i+1;
//			*p2 = 3-j;//�ҵ����ֲ���֪�����±�
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { {1,3,6},{2,6,7},{7,8,9} };
//	//Ҫ���ٲ���  ��ÿ�Ƚ�һ�ο��ų�һ�л�һ��
//	//��ɴӵ�һ�����һ���������һ�е�һ������ʼ��
//	int n = 0;
//	int x = 3;
//	int y = 3;
//	scanf("%d", &n);
//	int ret = findnum(arr, n, &x,&y);
//	if (ret == 0)
//	{
//		printf("��\n");
//	}
//	else
//	{
//		printf("�� ����Ϊ:(%d,%d)\n",x,y);
//	}
//	return 0;
//}
