#include <iostream>
#include <time.h>
using namespace std;
const int MAX = 10000000;
int data_1[10] = { 8, 33, 8, 7, 8, 8, 7, 6, 19, 9};
int temp[11] = { 0 };
int count_1[60] = { 0 };
int Array[MAX];
int Array1[MAX] = { 0 };
void Index(int array[],int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
// 快速排序，双边单边，从小到大
void QuickSort(int array[], int start, int end)
{
	int left = start, rigth = end;
	int temp = array[left];
	if (left < rigth)// 此处条件写对很必要，不则死循环
	{
		while (left < rigth)
		{
			while (left < rigth && array[rigth] > temp)
				rigth--;
			if (left < rigth )
			{
				array[left] = array[rigth];
				left++;
			}
			while (left < rigth && array[left] < temp)
				left++;
			if (left < rigth )
			{
				array[rigth] = array[left];
				rigth--;
			}
		}
		array[left] = temp;
		QuickSort(array, start, left - 1);
		QuickSort(array, left + 1, end);
	}
}
int partition_v1(int array[], int start, int end)
{
	int left = start, rigth = end, temp = 0;
	int pivot = array[left];
	while (left != rigth)
	{	// 在过程中要经常进行编译查找错误，并且进行改正。
		// i，j进行查找时，一定要先移动j后再移动i，对基准数进行改变时是i和j重合。
		while (left < rigth && array[rigth] > pivot)
			rigth--;
		while (left < rigth && array[left] <= pivot)// 为什么等号只能放在left这里？？？
			left++;
		if (left < rigth)
		{
			temp = array[left];
			array[left] = array[rigth];
			array[rigth] = temp;
		}
	}
	array[start] = array[rigth];
	array[rigth] = pivot;
	return rigth;
}
int partition_v2(int array[], int start, int end)
{
	int left = start, rigth = end, mark = start;
	int pivot = array[start];
	for (int i = start + 1; i < end + 1; i++)
	{
		if (array[i] < pivot)
		{
			mark++;
			int temp = array[i];
			array[i] = array[mark];
			array[mark] = temp;
		}
	}
	array[start] = array[mark];
	array[mark] = pivot;
	return mark;
}
void QuickSort1(int array[], int start, int end)
{
	if(start >= end)
		return;
	int pivot = partition_v1(array, start, end);
	QuickSort1(array, start, pivot - 1);
	QuickSort1(array, pivot + 1, end);
}
// 冒泡排序优化-->鸡尾酒排序
void DubbleSort(int array[], int length)
{
	int temp = 0;
	bool isSort = false;
	int last_index = 0;
	int sort_border = length - 1;
	for (int i = 0; i < length-1; i++)
	{
		isSort = true;
		for (int j = 0; j < sort_border; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				isSort = false;
				last_index = j;
			}
		}
		sort_border = last_index;
		if (isSort)
			break;
	}
}
void DubbleSort1(int array[], int length)
{
	bool isSort = false;
	int n = 0;
	for (int i = 0; i < (length/2); i++)
	{
		n++;
		isSort = true;
		for (int j = i; j < length - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				isSort = false;
			}
		}
		isSort = true;
		for (int j = length - i - 1; j > i ; j--)
		{
			if (array[j] < array[j - 1])
			{
				int temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				isSort = false;
			}
		}
		if (isSort)
			break;
	}
	cout << n << endl;
}
// 插入排序
void InsertSort(int array[], int length)
{
	int i = 0, j = 0, temp = 0;
	for (i = 1; i < length; i++)
	{
		temp = array[i];
		for (j = i; j > 0 && array[j - 1] > temp; j--)
			array[j] = array[j - 1];
		array[j] = temp;
	}
}
// 希尔排序
void ShellSort(int array[], int length)
{
	int i = 0, j = 0, k = 0, temp = 0, increase = length;
	do
	{
		increase = increase / 3 + 1 ;
		cout << increase << endl;
		for (i = 0; i < increase; i++)
		{
			for (j = i + increase; j < length; j += increase)
			{
				if (array[j - increase] > array[j])
				{
					temp = array[j];
					for (k = j; k > 0 && array[k - increase] > temp; k -= increase)
						array[k] = array[k - increase];
					array[k] = temp;
				}
			}
		}

	} while (increase > 1);
}
// 选择排序
int min_select(int array[], int left, int rigth)
{
	int min = left;
	for (int cur = left + 1; cur <= rigth; cur++)
	{
		if (array[min] > array[cur])
			min = cur;
	}
	return min;
}
void SelectSort(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		int min = min_select(array, i, length - 1);
		int temp = array[min];
		array[min] = array[i];
		array[i] = temp;
	}
}
// 堆排序
void swap(int array[], int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
void HeapAdjust(int array[], int index, int length)
{
	int max = index;
	int left = 2 * index + 1;
	int rigth = 2 * index + 2;
	if (left < length && array[left] > array[max])
		max = left;
	if (rigth < length && array[rigth] > array[max])
		max = rigth;
	if (max != index)
	{
		swap(array, index, max);
		HeapAdjust(array, max, length);
	}
}
void HeapSort(int array[], int length)
{
	for (int i = length / 2 - 1; i >= 0; i--)
	{	// 初始化堆
		cout << i << endl;
		HeapAdjust(array, i, length);
	}
	for (int i = length - 1; i >= 0; i--)
	{
		swap(array, 0, i);
		HeapAdjust(array, 0, i);// 调整刚换去的头于堆中位置
	}
}
// 归并排序
void Merge(int array[], int low, int high)
{
	int i_start = low;
	int i_end = (low + high) / 2;
	int j_start = (low + high) / 2 + 1;
	int j_end = high;
	int k = 0;
	while (i_start <= i_end && j_start <= j_end)
	{
		if (array[i_start] < array[j_start])
		{
			temp[k] = array[i_start];
			k++;
			i_start++;
		}
		else
		{
			temp[k] = array[j_start];
			k++;
			j_start++;
		}
	}
	while (i_start <= i_end)
		temp[k++] = array[i_start++];
	while (j_start <= j_end)
		temp[k++] = array[j_start++];
	for (k = 0,low; low <= j_end; low++)
		array[low] = temp[k++];
}
void MergeSort(int array[], int low, int high)
{
	if (low == high)
		return;
	int mid = (low + high) / 2;
	MergeSort(array, low, mid);
	MergeSort(array, mid + 1, high);
	Merge(array, low, high);
}
// 计数排序
void CountSort(int array[], int length)
{
	int max = array[0];
	int min = array[0];
	for (int i = 1; i < length; i++)
	{
		if (max < array[i])
			max = array[i];
		if (min > array[i])
			min = array[i];
	}
	cout << max << "  " << min << endl;

	int* arr = new int[max+1]();
	for (int i = 0; i < length; i++)
		arr[array[i]] += 1;
	int index = 0;
	for (int j = min; j < max+1; j++)
		for (int i = 0; i < arr[j]; i++)
			array[index++] = j;
	delete[] arr;
}
void CountSort1(int array[], int length)
{
	int max = array[0];
	int min = array[0];
	for (int i = 1; i < length; i++)
	{
		if (max < array[i])
			max = array[i];
		if (min > array[i])
			min = array[i];
	}
	cout << max << "  " << min << endl; 
	int count = max - min + 1;

	int* arr = new int[count]();
	int* dest = new int[length]();
	for (int i = 0; i < length; i++)
		arr[array[i] - min] += 1;	// 使能 arr 的 count 数组
	for (int i = 1; i < count; i++)
		arr[i] += arr[i - 1];		// 形成一个累积的数组，基数是元素出现次数
	for (int i = length - 1; i >-1; i--)
	{
		dest[arr[array[i] - min] - 1] = array[i];
		arr[array[i] - min] -= 1;
	}
	for (int j = 0; j < length; j++)
	{
		array[j] = dest[j];
	}
	delete[] arr;
	delete[] dest;
}
// 桶排序
void BucketSort(int arr[], int n, int r)
{
	/*int max = array[0];
	int min = array[0];
	for (int i = 1; i < length; i++)
	{
		if (max < array[i])
			max = array[i];
		if (min > array[i])
			min = array[i];
	}
	int count = max - min;
	int bucket_num = length;*/
	if (arr == NULL || r < 1) return;
	// 根据最大/最小元素和桶数量，计算出每个桶对应的元素范围
	int max = arr[0], min = arr[0];
	int i, j;
	for (i = 1; i < n; i++) {
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}
	int range = (max - min + 1) / r + 1;
	// 建立桶对应的二维数组，一个桶里最多可能出现 n 个元素
	int* buckets = new int[r * n]();
	// memset(buckets, 0, sizeof(buckets));
	int* counts = new int[r]();
	// memset(counts, 0, sizeof(counts));
	for (i = 0; i < n; i++) {
		int k = (arr[i] - min) / range;
		buckets[k+counts[k]] = arr[i];
		counts[k]++;
	}

	int index = 0;
	for (i = 0; i < r; i++) {
		// 分别对每个非空桶内数据进行排序，比如计数排序
		if (counts[i] == 0) continue;
		DubbleSort((buckets+i), counts[i]);
		// 拼接非空的桶内数据，得到最终的结果
		for (j = 0; j < counts[i]; j++) {
			arr[index++] = buckets[i+j];
		}
	}
}






int main()
{
	Index(data_1, 10);
	// QuickSort1(data_1, 0, 9);
	DubbleSort(data_1, 10);
	// InsertSort(data_1, 10);
	// ShellSort(data_1, 10);
	// SelectSort(data_1, 10);
	// HeapSort(data_1, 10);
	// MergeSort(data_1, 0, 9);
	// CountSort(data_1, 10);
	// BucketSort(data_1, 10, 40);
	Index(data_1, 10);
	return 0;
}