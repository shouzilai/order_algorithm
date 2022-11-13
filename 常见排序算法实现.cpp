//// 常见排序算法实现.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
//#include <iostream>
//#include <time.h>
//using namespace std;
//const int MAX =  10000000;
//int data_1[10] = { 11, 21, 19, 71, 35, 8, 1, 1, 8, 6 };
//int temp[100] = { 0 };
//int count_1[60] = { 0 };
//int Array[MAX];
//int Array1[MAX] = { 0 };
//
//void Time_Efficiency()
//{
//    double start = clock();
//}
//
//
//
//void Index(int* data, int length)
//{
//    for (int i = 0; i < length; i++)
//    {
//        cout << data[i] << "  ";
//    }
//    cout << endl;
//}
//// 快速排序
//void QuickSort(int* data, int start ,int end)
//{
//    int i = start, j = end;
//    if (i < j)
//    {
//        int temp = data[i];
//        while (i != j)
//        {
//            // 从右往左依次寻找 小于 基准数 
//            while (i < j && data[j] > temp)
//                j--;
//            // 填入基准数的位置（左端）
//            if (i < j)
//            {
//                data[i] = data[j];
//                i++;
//            }
//            // 从左往右依次寻找 大于 基准数 
//            while (i < j && data[i] < temp)
//                i++;
//            // 填入基准数的位置（右端）
//            if (i < j)
//            {
//                data[j] = data[i];
//                j--;
//            }
//        }
//        data[i] = temp;
//        QuickSort(data, start, i - 1);
//        QuickSort(data, i + 1, end);
//    }
//    
//}
//// 快速排序，双边循环法，单边循环法
//int partition_v1(int* data, int start, int end)
//{
//    int left = start, rigth = end, privot = 0, temp = 0;
//    privot = data[start];// 不能放入大循环内，因为start随时可能被调换，从而失去 基准值 得作用！！！
//    while (left != rigth)
//    {
//		while (left < rigth && data[rigth] >= privot)
//            rigth--;
//        while (left < rigth && data[left] <= privot)
//            left++;
//        
//        if (left < rigth)
//        {
//            temp = data[left];
//            data[left] = data[rigth];
//            data[rigth] = temp;
//        }
//    }
//    data[start] = data[left];
//    data[left] = privot;
//    return left;
//}
//int partition_v2(int* data, int start, int end)
//{
//    int mark = start;
//    int pivot = data[start];
//    /*int i = start + 1,temp = 0;
//    while (i <= end)
//    {
//        if (data[i] < pivot)
//        {
//            mark++;
//            temp = data[mark];
//            data[mark] = data[i];
//            data[i] = temp;
//        }
//        i++;
//    }*/
//    for (int temp, i = start + 1; i <= end; i++)
//    {
//        if (data[i] < pivot)
//        {
//            mark++;
//            temp = data[mark];
//            data[mark] = data[i];
//            data[i] = temp;
//        }
//    }
//    data[start] = data[mark];
//    data[mark] = pivot;
//    return mark;
//}
//void QuickSort1(int* data, int start, int end)
//{
//    if (start >= end)
//    {
//        return;
//    }
//    int pivot = partition_v1(data, start, end);
//    QuickSort1(data, start, pivot - 1);
//    QuickSort1(data, pivot + 1, end);
//}
//// 冒泡排序
//void DubbleSort(int* data, int length)
//{
//    int i, j, temp;
//    for (i = 0; i < length - 1; i++)
//    {
//        for (j = 0; j < length - i - 1; j++)
//        {
//            if (*(data + j) > *(data + j + 1))
//            {
//                temp = *(data + j);
//                *(data + j) = *(data + j + 1);
//                *(data + j + 1) = temp;
//            }
//        }
//    }
//}
//// 冒泡排序的优化
//void DubbleSort1(int* data, int length)
//{
//    int temp = 0;
//    int last_exchange_index = 0;
//    int sort_border = length - 1;
//    bool is_sort = false;
//    for (int i = 0; i < length - 1; i++)
//    {
//        is_sort = true;
//        for (int j = 0; j < sort_border; j++)
//        {
//            if (data[j] > data[j + 1])
//            {
//                temp = data[j];
//                data[j] = data[j + 1];
//                data[j + 1] = temp;
//                last_exchange_index = j;
//                is_sort = false;
//            }
//        }
//        sort_border = last_exchange_index;
//        if (is_sort == true)
//            break;
//    }
//}
//// 冒泡再优化，鸡尾酒排序
//void DubbleSort2(int* data, int length)
//{
//    bool is_sort = true;
//    int temp = 0;
//    for (int i = 0; i < length; i++)
//    {
//        is_sort = true;
//        for (int j = i; j < length - i - 1; j++)
//        {
//            if (data[j] > data[j + 1])
//            {
//                temp = data[j];
//                data[j] = data[j + 1];
//                data[j + 1] = temp;
//                is_sort = false;
//            }
//        }
//        if (is_sort == true)
//            break;
//        is_sort = true;
//        for (int j = length - i - 1; j > i; j--)
//        {
//            if (data[j] < data[j - 1])
//            {
//                temp = data[j];
//                data[j] = data[j - 1];
//                data[j - 1] = temp;
//                is_sort = false;
//            }
//        }
//        if (is_sort == true)
//            break;
//    }
//}
//// 直接插入排序
//void InsertSort(int* A, int len)
//{
//    int i, j, temp;
//    for (i = 1; i < len; i++)
//    {
//        temp = A[i];// 留存
//        j = i - 1;// 从右到左储存
//        while (j >= 0 && temp < A[j])// 如果A[i] < A[i-1],交换
//        {
//            A[j + 1] = A[j];
//            j--;
//        }
//        A[j + 1] = temp;
//    }
//}
//// 希尔排序
//void ShellSort(int* A, int len)
//{
//    int change = 0, temp, interval = len / 2;
//    int i, j;
//    while (interval != 0)
//    {
//        for (i = interval; i < len; i += interval)
//        {
//            j = i - interval;// 每趟比较中个起始点位置
//            while (j >= 0 && A[j] > A[j + interval])// 此时，需要交换位置 
//            {
//                temp = A[j + interval];
//                A[j + interval] = A[j];
//                A[j] = temp;
//                j = j - interval;// 相当于j--
//            }  
//        }
//        interval = interval / 2;// 缩小查找范围
//        change++;
//    }
//    cout << change << endl;
//}
//// 希尔再排序 前一个版本更好，简单，但效率差很多于这个
//void ShellSort1(int* data, int length)
//{
//    int i, j, k;
//    int increase = length;
//    do
//    {
//        increase = increase / 3 + 1;// 缩小排序范围，最后是全部进行一轮 插入排序
//        // cout << increase << endl;
//        for (i = 0; i < increase; i++)// 由数组长度决定，组数大小，4——>2——>1
//        {
//            for (j = i + increase; j < length; j += increase)// (i={0,1,2,3,...} 每一组 插入排序 一次
//            {
//                if (data[j] < data[j - increase])// 开始组内 插入排序 
//                {
//                    int temp = data[j];
//                    for (k = j - increase; k >= 0 && data[k] > temp; k -= increase)
//                    {
//                        data[k + increase] = data[k];
//                    }
//                    data[k + increase] = temp;
//                }
//            }
//        }
//    } while (increase > 1);// 只要间隔不小于 1 ，数组继续分割
//}
//// 选择排序
//int selectpass(int* Sqlist, int left, int rigth)
//{   // left为当前数组的最左端索引，rigth为当前数组的最右端索引（恒为len-1)
//    int min, curr;
//    min = left;
//    curr = left + 1;
//    for (; curr <= rigth; curr++)
//    {
//        if (Sqlist[min] > Sqlist[curr])
//            min = curr;
//    }
//    return min;
//}
//void SelectSort(int* Sqlist, int len)
//{
//    int temp;
//    int min = 0, i;
//    for (i = 0; i < len - 1; i++)
//    {
//        int min = selectpass(Sqlist, i, len - 1);
//        temp = Sqlist[i];
//        Sqlist[i] = Sqlist[min];
//        Sqlist[min] = temp;
//    }
//}
//// 堆排序
///*
//    1.初始化堆，大顶堆，从小到大,内含调整堆、交换数组值函数
//    2.初始调整完不一定是有序的，但一定是个最大堆了，再将顶结点与倒数1,2,3,...依次交换顺序，调整堆顶。最终完成排序
//*/
//void Swap(int* data, int a, int b)
//{
//    int temp = data[a];
//    data[a] = data[b];
//    data[b] = temp;
//}
//void HeapAdjust(int* data, int index, int length)
//{   // 感觉这里很妙，调整了堆，也不逾数组的界限
//    int max = index;
//    int left = 2 * index + 1;
//    int rigth = 2 * index + 2;// 保留了 父节点下标 和 左右孩子节点下标
//    if (left < length && data[max] < data[left])
//        max = left;
//    if (rigth < length && data[max] < data[rigth])
//        max = rigth;
//    if (max != index)
//    {   // 如果 max 发生变化，交换下标为 max 和 index 的元素 
//        Swap(data, max, index);
//        HeapAdjust(data, max, length);
//    }
//}
//void HeapSort(int* data, int length)
//{
//    for (int i = length / 2 - 1; i >= 0; i--)
//    {   // 初始化堆
//        HeapAdjust(data, i, length);
//    }
//    // cout << data[0] << " "; 调整最大堆的功能实现了，加油小子！！！
//    for (int i = length - 1; i >= 0; i--)
//    {   // 交换堆顶元素后，调整堆顶元素在 堆 的位置
//        Swap(data, 0, i);
//        HeapAdjust(data, 0, i);
//    }
//    // 自己或许天赋不错的，一直看不懂的堆排序，今天看过B站的一节课之后，直接手写出堆排序！！！代码实现不到20分钟
//    
//}
//// 归并排序
//void Merge(int* data,int low, int mid ,int high,int* temp)
//{   
//    int i_start = low;
//    int i_end = mid;
//    int j_start = mid + 1; 
//    int j_end = high;
//    int k = 0;
//    while (i_start <= i_end && j_start <= j_end )
//    {   // 大循环的条件 自己少考虑了，等于情况；测试过了，不加的话，排序错误，因为该给定序列最后元素入temp的机会；
//        // 直到另一序列为空，退出循环，接应后面的两个小循环
//        if (data[i_start] < data[j_start])
//        {   
//            temp[k] = data[i_start];
//            i_start++;
//            k++;
//        }
//        else
//        {
//            temp[k] = data[j_start];
//            j_start++;
//            k++;
//        }
//    }
//    while (i_start <= i_end)
//    {   //检查左半部分是否还有未放入temp的data元素
//        temp[k] = data[i_start];
//        i_start++;
//        k++;
//    }
//    while (j_start <= j_end)
//    {   // 检查右半部分是否还有未放入temp的data元素
//        temp[k] = data[j_start];
//        j_start++;
//        k++;
//    }
//    // memcpy(data, temp, high - low + 1);
//    for (k = 0, i_start = low; i_start <= high; i_start++)// 复制数组temp到data中,temp必须给不小于data的大小，不然一直都是一个数
//        data[i_start] = temp[k++];
//    // 看了一遍28分钟的视频，10分钟的书，吃完饭，手写出了归并排序，中间有些边界条件不清晰，需要加强
//    // 能写出大致逻辑，很不错了
//}
//void MergeSort(int* data, int low, int high,int* temp)
//{
//    if (low == high)// 递归结束的条件，由于函数的 第二个函数 有加一，可能大于或等于 第三参数
//        return;
//    int mid = (low + high) / 2;// 将序列划分两半
//    MergeSort(data, low, mid,temp);// 对序列的左半部分，实现归并排序
//    MergeSort(data, mid + 1, high,temp);// 对序列的右半部分，实现归并排序
//    Merge(data, low, mid, high,temp);// 实现一次归并排序
//}
//// 计数排序
//void Count_sort(int* data, int length)
//{
//    int index = 0;
//    for (int i = 0; i < length; i++)
//    {
//        temp[data[i]] += 1;
//    }
//    for (int i = 0; i < 100; i++)
//    {
//        /*if (temp[i] == 0)
//        {
//            data[i] = 0;
//        }*/ // 思路错误
//        for (int j = 0; j < temp[i]; j++)
//        {
//            
//            data[index++] = i;
//            // python中的sorted_array.append(i),看了我十分钟才看懂，原来就是把data的下标 i ,写 j 次到data里
//            // 如若想模拟 array.append(i) 需要设置一个index,它只与进入数组的个数有关，而不是遍历的 i 或 j 相关!!!
//            // 花了一个半小时多的时间，一直在想怎么用 i 和 j 来表示 index   -\./- 
//        }
//    }
//    return;
//}
//void CountSort1(int arr[], int n) 
//{   // 说起来，python里的方法真是奇怪，只要最大值和最小值变化超过13就不能正确排序，基数可以很大，但是不能变化范围大
//    if (arr == NULL) return;
//    // 定义辅助空间并初始化
//    int max = arr[0], min = arr[0];
//    int i;
//    for (i = 1; i < n; i++) {
//        if (max < arr[i]) max = arr[i];
//        if (min > arr[i]) min = arr[i];
//    }
//    int bins = max - min + 1;
//    // int* count = (int*)malloc(bins * sizeof(int));
//    int* count = new int[bins]();// 分配堆中的数组最安全的方法
//    //memset(count, 0, bins*sizeof(int));
//    ///*for (int i = 0; i < bins; i++)
//    //{
//    //    count[i] = 0;
//    //}*/
//    // 定义目标数组
//    int* dest = new int[MAX]();
//    // 统计每个元素出现的次数
//    for (i = 0; i < n; i++) count[arr[i] - min]++;
//    for (int i = 0; i < bins; i++)
//    {
//        cout << count[i] << "  ";
//    }
//    cout << endl;
//    // 对辅助空间内数据进行计算
//    for (i = 1; i < bins; i++) count[i] += count[i - 1];
//    for (int i = 0; i < bins; i++)
//    {
//        cout << count[i] << "  ";
//    }
//    cout << endl;
//    // 反向填充目标数组
//    for (i = n - 1; i >= 0; i--) dest[--count[arr[i] - min]] = arr[i];
//    // 目标数组里的结果重新赋值给 arr
//    for (i = 0; i < n; i++) arr[i] = dest[i];
//    delete[] count;
//    delete[] dest;
//}
//void Count_sort1(int data[], int length)
//{
//    if (data == NULL) return;
//    // 1.获取数组的最大值和最小值，得于获取 计算数组 的大小
//    int min = data[0], max = data[0];
//    for (int i = 1; i < length; i++)
//    {
//        if (data[i] < min)
//            min = data[i];
//        if(data[i] > max)
//            max = data[i];
//    }
//    int count = max - min + 1;
//    // 2.动态声明中间数组 和 计数数组 
//    int* dest = new int[length]();
//    int* count_1 = new int[count]();
//    // 3.统计原数组中每个数值的个数，作为计算数组的元素值，随后改动，令其后面的元素值等于前面元素值的总和
//    for (int j = 0; j < length; j++)
//    {
//        count_1[data[j] - min] += 1;
//    }
//    for (int i = 1; i < count; i++)
//    {
//        count_1[i] += count_1[i - 1];
//    }
//    // 4.倒序遍历原始数组，随其元素值为中间数组赋值，再转回到原数组
//    for (int j = length - 1; j >= 0; j--)
//        dest[--count_1[data[j]-min]] = data[j];
//    for (int i = 0; i < length; i++)
//        data[i] = dest[i];
//
//    delete[] dest;
//    delete[] count_1;
//}
//int main01()
//{
//    srand(clock());
//    for (int k = 0; k < MAX; k++)
//    {
//        Array[k] = rand() % 60 + 40;// 40~99 的随机数
//    }
//    // Index(Array,MAX);
//    /*DubbleSort(data_1, 10);
//    Index(data_1);*/
//
//    Index(data_1,10);
//    double start = clock();
//    // QuickSort(Array, 0, MAX);     // 0.009    1.156  前一排均为100000个数的时间结果，后一排为一千万个数的结果
//    // QuickSort1(Array, 0, 9);// 0.104 不论单双边均不能跑一百万以上级别的数据，但递归写在同一函数里的快排可以跑
//    DubbleSort1(Array, MAX);      // 26.985
//    // DubbleSort2(Array,MAX);       // 19.756
//    // InsertSort(Array, MAX);       // 5.057
//    // ShellSort(Array, MAX);        // 8.743 
//    // ShellSort1(Array,MAX);        // 0.014    2.1
//    // SelectSort(Array, MAX);       // 7.689
//    // HeapSort(Array, MAX);         // 0.028
//    // MergeSort(Array, 0, MAX - 1, temp);   // 0.0014   1.98
//    // Count_sort(data_1, 10);       // 小于0.001    0.04
//    // CountSort1(Array, MAX);    //0.018  0.168  外援
//    // Count_sort1(Array, MAX);   // 0.001   0.12 模仿外援编写的
//    double end = clock();
//    cout << "总共耗时: " << double(end - start) / CLOCKS_PER_SEC << endl;
//    // Index(temp,10);
//    Index(data_1,10);
//    
//
//    std::cout << "Hello World!\n";
//    return 0;
//}
//
//// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
//// 调试程序: F5 或调试 >“开始调试”菜单
//
//// 入门使用技巧: 
////   1. 使用解决方案资源管理器窗口添加/管理文件
////   2. 使用团队资源管理器窗口连接到源代码管理
////   3. 使用输出窗口查看生成输出和其他消息
////   4. 使用错误列表窗口查看错误
////   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
////   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
