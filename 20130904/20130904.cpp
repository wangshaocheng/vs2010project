// 20130904.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "first.h"
#include "sort_study.h"
#include <conio.h>


int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {28, 39, 3, 9, 2929, 22};
	
	HeapSort(a, 6);
	
	for(int i = 0; i < 6; i++)
	{
		printf("%d ", a[i]);
	}
	_getch();
	return 0;
}

