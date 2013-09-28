#include "stdafx.h"
//ð������:���������ķ�����
//��һ���������С��Ԫ��������
//�ڶ���������С��Ԫ���ڵڶ�λ
//�����˼·��������һ���ʹ���������a��Сһ��������b��ÿ���ó�a����Ӧλ�õ�ֵ����b����Ӧ��λ���ϡ�
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

//ֱ�Ӳ�������
void insert_sort(int a[], int len)
{
	int i,j;//i��j�ֱ���������Ԫ�ص�ָ���������Ԫ�ص�ָ��
	int tmp;
	for(i=0;i<len-1;i++) //���������������ܹ���Ҫ�����������Ĵ�����len-1����Ϊ�տ�ʼ������������1����һ���������������������ĳ�����2����len-1������������������ĳ��Ⱦ���len�ˣ�����������������ϣ�
	{
		j = i+1;
		if(a[j]<a[i]) //ֻ�е��������ĵ�һ��Ԫ��С�������������һ��Ԫ�أ�Ҳ��������Ԫ�أ�ʱ������Ҫ�ƶ�������������
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
	int i,j;//i��j�ֱ�Ϊִ�����������һ��Ԫ�غ���������һ��Ԫ�ص�ָ�루ע����������������������ģ��������d��Ԫ��λ�ã�
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

//ϣ������Ӧ���ǶԴ��������������������ʱЧ�ʸ�
void shell_sort(int a[], int len)
{
	int d = 2; //��������ʼ��������Ϊ2
	while(d >= 1)
	{
		do_shell_sort(a, len, d);
		d = d/2;
	}
}

//���������Ƕ�ð������ĸĽ������ڽ��������һ��
void do_quick_sort(int a[], int low, int high)
{
	if(low < high)//low��high�ֱ�Ϊָ�������Ԫ�����еĵ�һ�������һ��Ԫ��
	{
		int i=low, j=high;
		int standard = a[i];//�����Ե�һ��������Ԫ����Ϊ��׼Ԫ�أ�һ�ο���������׼Ԫ����ߵ�Ԫ�ض�С��������׼Ԫ���ұߵ�Ԫ�ض�������
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
		//�Ի�׼Ԫ����ߵ����н��еݹ��������
		do_quick_sort(a, low, i - 1);
		//�Ի�׼Ԫ���ұߵ����н��еݹ��������
		do_quick_sort(a, i + 1, high);
	}
}

//��������
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

// a�Ǵ������Ķ����飬i�Ǵ�����������Ԫ�ص�λ�ã���1��ʼ����size������ĳ���
//�����������ǣ���Ԫ��iΪ���ڵ��������������ѣ�ͨ���������ڵ����������������������
void HeapAdjust(int a[], int i, int size)
{
	int lchild = 2*i;
	int rchild = 2*i + 1;
	int max = i;
	if(i <= size/2) //���i��Ҷ�ӽڵ�Ͳ��ý��е���
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
			HeapAdjust(a, max, size); //�������֮����maxΪ���ڵ���������Ƕ�
		}
	}
}


// �������㷨
void HeapSort(int array[],int length)
{
    // �������е�ǰ�벿��Ԫ�أ�������֮���һ��Ԫ�������е�����Ԫ��
    //length/2�ǵ�һ����Ҷ�ڵ㣬�˴�"/"Ϊ����
    for (int i = length / 2; i > 0; --i)
	{
		HeapAdjust(array, i, length);
	}
    
	// �����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
    for (int i = length; i > 0; --i)
    {
        // �ѵ�һ��Ԫ�غ͵�ǰ�����һ��Ԫ�ؽ�����
        // ��֤��ǰ�����һ��λ�õ�Ԫ�ض��������ڵ��������֮������
        Swap(&array[0], &array[i-1]);
        // ������С����heap�ķ�Χ��ÿһ�ε�����ϱ�֤��һ��Ԫ���ǵ�ǰ���е����ֵ
        HeapAdjust(array, 1, i - 1);
    }
}


