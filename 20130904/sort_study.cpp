#include "stdafx.h"
//冒泡排序:借助交换的方法，
//第一趟排序后最小的元素在最上
//第二趟排序后次小的元素在第二位
//错误的思路：先声明一个和待排序数组a大小一样的数组b，每次拿出a中相应位置的值放在b的相应的位置上。
void bubble_sort(int a[], int len) {
	int min, tmp;
	for(int i=0;i<len;i++) 
	{
		min = i;
		for(int j=i+1;j<len;j++) 
		{
			if(a[j]<a[min])
			{
				min = j;
			}
		}
		if(min != i)
		{
			tmp = a[i];
			a[i] = a[min];
			a[min] = tmp;
		}
	}
}

//直接插入排序
void insert_sort(int a[], int len)
{
	int i,j;//i和j分别是有序区元素的指针和无序区元素的指针
	int tmp;
	for(i=0;i<len-1;i++) //逐步扩大有序区（总共需要扩大有序区的次数是len-1，因为刚开始有序区长度是1，第一次扩大有序区后有序区的长度是2，第len-1次扩大有序后有序区的长度就是len了，即整个数组排序完毕）
	{
		j = i+1;
		if(a[j]<a[i]) //只有当无序区的第一个元素小于有序区的最后一个元素（也就是最大的元素）时，才需要移动并扩大有序区
		{
			tmp = a[j];
			while(a[i] > tmp) 
			{
				a[i+1] = a[i];
				i--;
			}
			a[i+1] = tmp;
		}
		i = j - 1;
	}
}

void do_shell_sort(int a[], int len, int d)
{
	int i,j;//i和j分别为执行有序区最后一个元素和无序区第一个元素的指针（注：这里的有序区不是连续的，而是相隔d个元素位置）
	int tmp;
	for(j=d;j<len;j++)
	{
		i = j - d;
		if(a[j] < a[i])
		{
			tmp = a[j];
			while(i>=0 && a[i]>tmp) 
			{
				a[i+d] = a[i];
				i = i-d;
			}
			a[i+d] = tmp;
		}
	}
}

//希尔排序：应该是对待排序数组整体大致有序时效率高
void shell_sort(int a[], int len)
{
	int d = 2; //这里假设初始化的增量为2
	while(d >= 1)
	{
		do_shell_sort(a, len, d);
		d = d/2;
	}
}

//快速排序是对冒泡排序的改进，属于交换排序的一种
void do_quick_sort(int a[], int low, int high)
{
	if(low < high)//low和high分别为指向待排序元素序列的第一个和最后一个元素
	{
		int i=low, j=high;
		int standard = a[i];//这里以第一个待排序元素作为基准元素，一次快速排序后基准元素左边的元素都小于他，基准元素右边的元素都大于他
		while(i<j)
		{
			while(j>=0 && a[j]>standard)
			{
				j--;
			}
			if(i < j)
			{
				a[i] = a[j];
				i++;
			}

			while(i<j && a[i] < standard)
			{
				i++;
			}
			if(i < j)
			{
				a[j] = a[i];
				j--;
			}
		}
		a[i] = standard;	
		//对基准元素左边的序列进行递归快速排序
		do_quick_sort(a, low, i - 1);
		//对基准元素右边的序列进行递归快速排序
		do_quick_sort(a, i + 1, high);
	}
}

//快速排序
void quick_sort(int a[], int len) 
{
	do_quick_sort(a, 0, len-1);
}



void Swap(int* p1, int* p2) 
{
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// a是待调整的堆数组，i是待调整的数组元素的位置（从1开始），size是数组的长度
//本函数功能是：对元素i为根节点的子树调整大根堆（通过交换根节点和左子树或者是右子树）
void HeapAdjust(int a[], int i, int size)
{
	int lchild = 2*i;
	int rchild = 2*i + 1;
	int max = i;
	if(i <= size/2) //如果i是叶子节点就不用进行调整
	{
		if(lchild <= size && a[lchild-1]>a[max-1])
		{
			max = lchild;
		}
		if(rchild <= size && a[rchild-1]>a[max-1])
		{
			max = rchild;
		}
		if(max != i)
		{
			Swap(&a[i-1], &a[max-1]);
			HeapAdjust(a, max, size); //避免调整之后以max为父节点的子树不是堆
		}
	}
}


// 堆排序算法
void HeapSort(int array[],int length)
{
    // 调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
    //length/2是第一个非叶节点，此处"/"为整除
    for (int i = length / 2; i > 0; --i)
	{
		HeapAdjust(array, i, length);
	}
    
	// 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for (int i = length; i > 0; --i)
    {
        // 把第一个元素和当前的最后一个元素交换，
        // 保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
        Swap(&array[0], &array[i-1]);
        // 不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        HeapAdjust(array, 1, i - 1);
    }
}


