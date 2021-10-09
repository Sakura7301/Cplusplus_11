#include<stdio.h>
#include<stdlib.h>


//交换函数
void arrSwap(int *a, int x, int y)
{
		int temp = a[x];
		a[x] = a[y];
		a[y] = temp;
}

//冒泡
void bubble_sort(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				arrSwap(arr,j,j+1);
			}
			
		}
	}

}

//插入
void insert_sort(int *arr, int len)
{
	for (int i = 1; i < len; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j>=0 && temp > arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

//选择
void choose_sort(int *arr, int len)
{
	int min = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[min]>arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			arrSwap(arr, i, min);
		}
	}
}

//希尔
void shell_sort(int *arr, int len)
{
	int step = len / 2;
	int temp = 0;
	int j = 0;
	while (step > 0)
	{
		for (int i = step; i < len; i ++)
		{
			temp = arr[i];
			j = i - step;
			while (j >= 0 && temp > arr[j])
			{
				arr[j + step] = arr[j];
				j -= step;
			}
			arr[j + step] = temp;
		}
		step = step / 2;
	}
}

//快排
void fast_sort(int *arr,int start,int end)
{
	int i = start;
	int j = end;
	int base = arr[start];//默认将第一个数作为基准数
	if (i < j)
	{
		while (i < j)
		{
			//将小于基准数的值放到基准数的左边
			while (i < j && arr[j] < base)
				j--;
			if (i < j) {
				arr[i] = arr[j];
			}
			//将大于基准数的值放到基准数的右边
			while (i < j && arr[i] >= base)
				i++;
			if (i < j) {
				arr[j] = arr[i];
			}
		}
		//指针相撞
		arr[i] = base;
		fast_sort(arr, start, i - 1);
		fast_sort(arr, i + 1,end);
	}
}

//堆排序的调整函数
void heap_sort_func(int *arr,int index,int len)
{
	int min = index;//保存当前结点的下标
	int left = index * 2 + 1;
	int right = index * 2 + 2;

	//获取当前树的最大元素
	if (left<len && arr[left]>arr[min])
	{
		min = left;
	}
	if (right < len && arr[right] > arr[min])
	{
		min = right;
	}
	//min的值发生改变,说明最小值的下标不是min,我们交换
	if (min != index){
		arrSwap(arr,min,index);
		//递归调用,因为调整之后,如果改结点不是叶子节点
		//那么应该继续调整堆
		heap_sort_func(arr,min,len);
	}
}


//堆排序
void heap_sort(int *arr, int len)
{
	//初始化堆
	for (int i = len / 2-1; i >= 0; i--)
	{
		heap_sort_func(arr,i,len);
	}
	for (int i = len - 1; i >= 0; i--)
	{
		//交换堆顶和最后一个元素
		arrSwap(arr,0,i);
		//自上而下调整堆
		heap_sort_func(arr,0,i);
	}
}


//打印
void print_func(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[10] = {4,8,1,2,9,7,0,6,5,3};
	int len = sizeof(arr)/sizeof(arr[0]);

	printf("choose_sort:\n");
	choose_sort(arr, len);
	print_func(arr, len);

	printf("insert_sort:\n");
	insert_sort(arr, len);
	print_func(arr, len);

	printf("bubble_sort:\n");
	bubble_sort(arr, len);
	print_func(arr, len);

	printf("shell_sort:\n");
	shell_sort(arr, len);
	print_func(arr, len);

	printf("heap_sort:\n");
	heap_sort(arr, len);
	print_func(arr, len);


	printf("fast_sort:\n");
	fast_sort(arr, 0,len-1);
	print_func(arr, len);
	return 0;
}