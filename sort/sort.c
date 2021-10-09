#include<stdio.h>
#include<stdlib.h>


//��������
void arrSwap(int *a, int x, int y)
{
		int temp = a[x];
		a[x] = a[y];
		a[y] = temp;
}

//ð��
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

//����
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

//ѡ��
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

//ϣ��
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

//����
void fast_sort(int *arr,int start,int end)
{
	int i = start;
	int j = end;
	int base = arr[start];//Ĭ�Ͻ���һ������Ϊ��׼��
	if (i < j)
	{
		while (i < j)
		{
			//��С�ڻ�׼����ֵ�ŵ���׼�������
			while (i < j && arr[j] < base)
				j--;
			if (i < j) {
				arr[i] = arr[j];
			}
			//�����ڻ�׼����ֵ�ŵ���׼�����ұ�
			while (i < j && arr[i] >= base)
				i++;
			if (i < j) {
				arr[j] = arr[i];
			}
		}
		//ָ����ײ
		arr[i] = base;
		fast_sort(arr, start, i - 1);
		fast_sort(arr, i + 1,end);
	}
}

//������ĵ�������
void heap_sort_func(int *arr,int index,int len)
{
	int min = index;//���浱ǰ�����±�
	int left = index * 2 + 1;
	int right = index * 2 + 2;

	//��ȡ��ǰ�������Ԫ��
	if (left<len && arr[left]>arr[min])
	{
		min = left;
	}
	if (right < len && arr[right] > arr[min])
	{
		min = right;
	}
	//min��ֵ�����ı�,˵����Сֵ���±겻��min,���ǽ���
	if (min != index){
		arrSwap(arr,min,index);
		//�ݹ����,��Ϊ����֮��,����Ľ�㲻��Ҷ�ӽڵ�
		//��ôӦ�ü���������
		heap_sort_func(arr,min,len);
	}
}


//������
void heap_sort(int *arr, int len)
{
	//��ʼ����
	for (int i = len / 2-1; i >= 0; i--)
	{
		heap_sort_func(arr,i,len);
	}
	for (int i = len - 1; i >= 0; i--)
	{
		//�����Ѷ������һ��Ԫ��
		arrSwap(arr,0,i);
		//���϶��µ�����
		heap_sort_func(arr,0,i);
	}
}


//��ӡ
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