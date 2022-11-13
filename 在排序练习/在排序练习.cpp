// 在排序练习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
int data_1[10] = { 10, 0, 3, 5, 8, 9, 9, 6 ,9, 4 };

void IndexArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << "  ";
    }
    cout << endl;
}


void QuickSort(int array[], int start, int end)
{
    int left = start, right = end;
    
    if (left < right)
    {
        int temp = array[left];
        while (left < right)
        {
            while (left < right && array[right] > temp)
                right--;
            if (left < right)
            {
                array[left] = array[right];
                left++;
            }
            while (left < right && array[left] < temp)
                left++;
            if (left < right)
            {
                array[right] = array[left];
                right--;
            }
        }
        array[left] = temp;
        QuickSort(array, start, left - 1);
        QuickSort(array, left + 1, end);
    }
}


int Partition_1(int array[], int start, int end)
{
    int left = start, right = end;
    int pivot = array[start];
    while (left < right)
    {
        while (left < right && array[right] > pivot)
            right--;
        while (left < right && array[left] <= pivot)
            left++;
        if (left < right)// && array[left] < array[right]
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }
    array[start] = array[left];
    array[left] = pivot;
    return left;
}
int Partition_2(int array[], int start, int end)
{
    int left = start, right = end;
    int pivot = array[start];
    int mark = start;
    for (int index = left + 1; index < end + 1; index++)
    {
        if (array[index] < pivot)
        {
            mark++;
            int temp = array[index];
            array[index] = array[mark];
            array[mark] = temp;
        }
    }
    array[start] = array[mark];
    array[mark] = pivot;
    return mark;
}
void QuickSort_1(int array[], int start, int end)
{
    if (start >= end || array == NULL)
        return;
    int pivot = Partition_2(array, start, end);
    QuickSort(array, start, pivot - 1);
    QuickSort_1(array, pivot + 1, end);
}


void BubbleSort(int array[], int length)
{
    for (int index = 0; index < length - 1; index++)
    {
        for (int j = 0; j < length - index - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
void BubbleSort_1(int array[], int length)
{
    int temp = 0;
    int last_exchange_index = 0;
    int sort_border = length - 1;
    bool is_sort = false;
    for (int i = 0; i < length - 1; i++)
    {
        is_sort = true;
        for (int j = 0; j < sort_border; j++)
        {
            if (array[j] > array[j + 1])
            {
                is_sort = false;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                last_exchange_index = j;
            }
        }
        sort_border = last_exchange_index;
        if (is_sort == true)
            break;
    }
}
void BubbleSort_2(int array[], int length)
{
    int temp = 0;
    int is_sort = false;
    for (int i = 0; i < length/2; i++)
    {
        is_sort = true;
        for (int j = i; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                is_sort = false;
            }
        }
        is_sort = true;
        for (int j = length-i - 1; j > i; j--)
        {
            if (array[j] < array[j - 1])
            {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                is_sort = false;
            }
        }
        if (is_sort == true)
            break;
    }
}


void InsertSort(int array[], int length)
{
    int temp = 0;
    int j;
    for (int i = 1; i < length; i++)
    {
        temp = array[i];
        for (j = i - 1; j >= 0 && array[j] > temp; j--)
            array[j + 1] = array[j];
        array[j + 1] = temp;
    }
}


void ShellSort(int array[], int length)
{
    int increase = length;
    int i, j, temp = 0, k;
    do{
        increase = increase / 3 + 1;
        for (i = 0; i < length; i++)
        {
            for (j = i + increase; j < length; j += increase)
            {
                temp = array[j];
                for (k = j; k >= 0 && array[k - increase] > temp; k -= increase)
                    array[k] = array[k - increase];
                array[k] = temp;
            }
        }
    } while (increase > 1);
}

int selectmin(int array[], int start, int end)
{
    int min = start;
    for (int i = start+1; i < end + 1; i++)
        if (array[min] > array[i])
            min = i;
    return min;
}
void SelectSort(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int min = selectmin(array, i, length - 1);
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
        // array[i] = min;
    }
}


int main()
{
    IndexArray(data_1, 10);


    // QuickSort_1(data_1, 0, 9);
    // BubbleSort(data_1, 10);
    // BubbleSort_2(data_1, 10);
    // InsertSort(data_1, 10);
    // ShellSort(data_1, 10);
    // SelectSort(data_1, 10);


    IndexArray(data_1, 10);
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
