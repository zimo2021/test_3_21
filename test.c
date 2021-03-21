#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
/*
写一个字符串，判断该字符串是否为abcdef的子字符串
如  cdefab 为abcdef的子字符串
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
//		//找到b与a重叠的第一个字母
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
//		//从该字母b与a开始匹配
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
//追加函数（strcat）
//int main()
//{
//	char arr1[10] = "abc";//10一定要加，要确保arr1中装得下
//	char arr2[] = "def";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);//abcdef
//	return 0;
//}
//int main()
//{
//	char arr1[10] = "abcd";
//	strcat(arr1, arr1);
//	printf("%s\n", arr1);//系统崩溃，不可以这样可以自己给自己追加字符串
//	return 0;
//}
//strcat 和 strncat
//char * strcat ( char * destination, const char * source );  strcat  返回类型为char*   只需要两个字符串即可
//char * strncat ( char * destination, const char * source, size_t num );  返回类型为char*  除了两个字符串外还有后面接的字符串的大小
//int main()
//{
//	char arr1[10] = "abcd";
//	char arr2[] = "cdef";
//	strncat(arr1, arr2, 3);//表示从arr2中复制3个字符过去
//	printf("%s\n", arr1);//abcdcde
//	return 0;
//}
//使用库函数strstr和strcat
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
杨氏矩阵：
即一个数组数字从左往右递增，从上往下递增
如：
1  3  6
2  6  7
7  8  9
就是一个杨氏矩阵
从杨氏矩阵中快速查找一个数是否存在
*/
//int findnum(int arr[3][3],int n,int row,int lis,int* p1,int* p2)
//{
//	int i = 0;
//	int j = 0;
//	while (i<row && j<lis)//该法可以进行优化使其更加精简
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
//			*p2 = j;//找到数字并告知该数下标
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { {1,3,6},{2,6,7},{7,8,9} };
//	//要快速查找  则每比较一次可排除一行或一列
//	//则可从第一行最后一个数或最后一行第一个数开始找
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	int* p1 = &n;
//	int* p2 = &i;
//	int ret = findnum(arr, n, 3, 3,p1,p2);
//	if (ret == 0)
//	{
//		printf("无\n");
//	}
//	else
//	{
//		printf("有 坐标为:(%d,%d)\n",*p1+1,3-*p2);
//	}
//	return 0;
//}—————————————————————————————
//int main()
//{
//	int arr[3][3] = { { 1,3,6 },{ 2,6,7 },{ 7,8,9 } };//验证我写的函数是否完全正确
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
//}——————————————————————————
//void move(int arr[3][3])
//{
//	printf("%d\n", arr[1][1]);//6  可以找到第二行第二列的6 但arr的初始值为1 3 6  而不是{ 1,3,6 },{ 2,6,7 },{ 7,8,9 }
//}
//int main()
//{
//	int arr[3][3] = { { 1,3,6 },{ 2,6,7 },{ 7,8,9 } };
//	move(arr);
//	return 0;
//}——————————————————————————————
//优化版
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
//			*p2 = 3-j;//找到数字并告知该数下标
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { {1,3,6},{2,6,7},{7,8,9} };
//	//要快速查找  则每比较一次可排除一行或一列
//	//则可从第一行最后一个数或最后一行第一个数开始找
//	int n = 0;
//	int x = 3;
//	int y = 3;
//	scanf("%d", &n);
//	int ret = findnum(arr, n, &x,&y);
//	if (ret == 0)
//	{
//		printf("无\n");
//	}
//	else
//	{
//		printf("有 坐标为:(%d,%d)\n",x,y);
//	}
//	return 0;
//}
