//排序算法头文件

//冒泡排序：交换排序的一种，第一次冒泡排序把最小的元素交换到第一个元素的位置，以此类推
void bubble_sort(int a[], int len);
//快速排序：交换排序的一种，以基准元素大小为界，把待排序序列分为左右两个序列，其中左边序列元素都小于基准元素，右边序列元素都大于基准元素
void quick_sort(int a[], int len);

//直接插入排序：划分待排序数组为有序区和无序区，第一次插入排序后有序区变为2，无序区长度减1，以此类推
void insert_sort(int a[], int len);
//希尔排序：又称增量排序，为插入排序的一种，这里的有序区不是连续的，而是相隔增量个元素的位置
void do_shell_sort(int a[], int len, int d);
void shell_sort(int a[], int len);

// 堆排序算法
void HeapSort(int array[],int length);