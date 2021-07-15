// Sorts.h		五种（冒泡、选择、快速、插入、归并）基本排序算法（升序）
#ifndef SORTS_H
#define SORTS_H
#include <iostream>

using namespace std;

double gettime(int restart = 0);

template <typename T> void GetMemory(T*& data, T*& data0, int n)	// 分配堆内存空间，通过参数"返回"首地址
{																	// 隐含约定：指针非空就表示指针"拥有"堆空间资源
	if (data0 != NULL) delete[] data0;								// 先释放原先所"拥有"的堆空间资源
	if (data != NULL) delete[] data;
	data0 = new T[n];												// 重新申请新的（容量符合要求的）堆空间资源
	data = new T[n];
}

template <typename T> void FreeMemory(T*& data, T*& data0)			// 释放指针所"拥有"的堆空间资源
{
	if (data0 != NULL) delete[] data0;
	if (data != NULL) delete[] data;
	data0 = data = NULL;											// 这一条赋值语句非常重要！保持"隐含约定"
}

template <typename T> void ReSet(T* data, const T* data0, int n)	// 用于恢复"原始数据"，以保证不同的排序算法处理完全相同的数据
{
	for (int i = 0; i < n; i++)
		data[i] = data0[i];
}

template <typename T> bool Check(const T* a, int size)				// 检验数组元素是否已按升序排列
{
	for (int i = 1; i < size; i++)
		if (a[i - 1] > a[i])
			return false;
	return true;
}

//模板化 函数 

/* 冒泡排序 */
template <typename T> void BubbleSort1(T* arr, int n)
{
	T temp;
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

template <typename T> void BubbleSort2(T* arr, int n)
{
	T temp;
	int i, j;
	bool swapped; /* 未经排序-false  已排序-true*/

	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}
		// 如果swapped是false，说明没有交换，数组有序，退出排序
		if (!swapped)
			break;
	}
}

template <typename T> void BubbleSort3(T* arr, int n)
{
	T temp;
	int i, j;
	bool swapped;/* 未经排序-false  已排序-true*/
	int lastswappedindex = 0;
	int sortborder = n - 1;

	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < sortborder; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];	
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
				lastswappedindex = j;
			}
		}
		sortborder = lastswappedindex;
		//如果swapped是false，说明没有交换，数组有序，退出排序
		if (!swapped)
			break;
	}
}

/* 选择排序 */
template <typename T> void SelectionSort1(T* arr, int n)
{
	T temp;
	int i, j, minindex;
	for (i = 0; i < n - 1; i++)
	{
		minindex = i; //已经排序的左边界
		/* 找到数组中无序部分的最小关键字 */
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[minindex])
				minindex = j;
		/* 将最小关键字与无序部分的第一关键字交换 */
		temp = arr[i];						// 交换 a[j] 与 a[j+1]
		arr[i] = arr[minindex];
		arr[minindex] = temp;
	}
}

template <typename T> void SelectionSort2(T* arr, int n)
{
	/* a[i-1]及之前已排序 */
	/* a[i]-a[n-1]找出最小元素下标 */
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}

		/* 最小的元素移到位置i */
		/* i -- min-1的元素都向后移动1位*/
		T key = arr[min];
		while (min > i)
		{
			arr[min] = arr[min - 1];
			min--;
		}

		//把key当前最小值放在a[i]位置
		arr[i] = key;
	}
}

template <typename T> void SelectionSort3(T* arr, int n)
{
	T temp;
	int start = 0;
	int end = n - 1;
	while (end > start + 1) {

		int minIndex = start;//最小值对应下标
		int maxIndex = start;//最大值对应下标
		for (int i = start + 1; i <= end; i++) {
			if (arr[i] < arr[minIndex]) {
				minIndex = i;
			}
			else if (arr[i] >= arr[maxIndex]) {
				maxIndex = i;
			}
		}
		if (minIndex != start)
		{
			temp = arr[start];
			arr[start] = arr[minIndex];
			arr[minIndex] = temp;
		}
		if (maxIndex == start) {
			maxIndex = minIndex;
		}//若最小在最大位置且最大值在最小位置，再交换一次

		if (maxIndex != end) {
			temp = arr[end];						// 交换 a[j] 与 a[j+1]
			arr[end] = arr[maxIndex];
			arr[maxIndex] = temp;
		}
		start++;
		end--;
	}
	if (end == start + 1) {
		if (arr[end] < arr[start]) {
			temp = arr[end];						// 交换 a[j] 与 a[j+1]
			arr[end] = arr[start];
			arr[start] = temp;
		}
	}
}

/* 插入排序 */
template <typename T>void InsertionSort1(T* arr, int n)
{
	T temp;
	int i, j;
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		while (j >= 0 && arr[j + 1] < arr[j])
		{
			//交换
			temp = arr[j + 1];
			arr[j + 1] = arr[j];
			arr[j] = temp;
			j--;
		}

	}
}


template <typename T>void InsertionSort2(T* arr, int n)
{
	int i, j;
	T insert;
	for (i = 1; i < n; i++)
	{
		insert = arr[i];
		j = i - 1;
		//在0到i-1中从后往前找到插入位置
		while (j >= 0 && insert < arr[j])
		{
			//移动
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = insert;
	}
}



template <typename T> void InsertionSort3(T* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int min = 0, max = i - 1, j;
		T insert = arr[i];
		//通过二分法寻找插入的位置
		while (min <= max)
		{
			int mid = (min + max) / 2;
			//逐步缩小范围
			if (arr[mid] <= insert)
				min = mid + 1;
			else
				max = mid - 1;
		}
		if (i > min)
		{
			//移动
			for (j = i; j > min; j--)
				arr[j] = arr[j - 1];
			arr[j] = insert;
		}
	}
}

/*归并排序递归法*/
template <typename T> void merge(T arr[], int l, int m, int r)
{
	//计算两个子数组的大小
	int n1 = m - l + 1;
	int n2 = r - m;

	//创建临时数组，存放两个要合并的子数组
	T* L = new T[n1];
	//int *R = new int[n2];

	/* 拷贝数据 */
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];

	int i = 0, j = 0;
	int k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= arr[m + 1 + j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = arr[m + 1 + j];
			j++;
		}
		k++;
	}
	/* 如果L[]有剩余 */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	delete[] L;
}

template <typename T> void mergeSort1(T* arr, int left, int right) {
	if (left < right)
	{
		//计算mid
		int mid = (left + right) / 2;
		//分 的两个子数组进行排序
		mergeSort1(arr, left, mid); //左边
		mergeSort1(arr, mid + 1, right); //右边
		//合
		merge(arr, left, mid, right);
	}
}

template <typename T> void MergeSort1(T* arr, int n)
{
	return mergeSort1(arr, 0, n - 1);
}
/*归并排序迭代法*/
//在一个总长为n的数组中，将a开头长度为length，b开头长度为length的两段数组进行归并排序
template <typename T> void Merge2(T* arr, int a, int b, int length, int n)
{
	int rest = length;
	//判断最后一个步长时b开头的数组长度
	if (length + b - 1 >= n - 1)
		rest = n - b;

	int i = 0, j = 0;
	T* L = new T[length];

	for (; i <= length - 1; i++)
		L[i] = arr[a + i];

	i = 0;
	/*对两个数组进行归并排序*/
	while (i < length && j < rest)
	{
		if (L[i] <= arr[b + j])
		{
			arr[a + i + j] = L[i];
			i++;
		}
		else
		{
			arr[a + i + j] = arr[b + j];
			j++;
		}
	}
	while (i < length)
	{
		arr[a + i + j] = L[i];
		i++;
	}
	delete[] L;
}

template <typename T> void MergeSort2(T* arr, int length)
{

	int step = 1;
	while (step < length)
	{
		for (int i = 0; i <= length - step - 1; i = i + 2 * step)
		{
			Merge2(arr, i, i + step, step, length);
		}
		step = 2 * step;
	}

}

/* 快速排序 */
template <typename T> void quickSort(T* arr, int left, int right)
{

	if (left < right)
	{
		T standard = arr[left]; //让最左边的数成为基准数
		int i = left;
		int j = right;

		while (i < j)  //将右边的数与基准数比较
		{

			while (i<j && arr[j] > standard)//从右往左比基准数大的交换
				j--;

			arr[i] = arr[j];//依次放左边

			while (i < j && arr[i] <= standard)//从左往右比基准数小的交换
				i++;

			arr[j] = arr[i];  //依次放右边
		}

		arr[i] = standard; //左右重合

		quickSort(arr, left, i - 1);//对左子序重复排列

		quickSort(arr, i + 1, right);//对右子序重复排列
	}

	else
		return;
}
template <typename T> void QuickSort1(T* arr, int n)
{
	return quickSort(arr, 0, n - 1);
}


template <typename T> void quickSortgreater(T* arr, int left, int right)
{

	if (left < right)
	{
		int mid = (left + right) / 2;

		if (arr[right] < arr[left])//对left ，right，mid进行排序
		{
			T temp;
			temp = arr[right];
			arr[right] = arr[left];
			arr[left] = temp;
		}
		else arr[right] = arr[right];
		if (arr[mid] > arr[right])
		{
			T temp;
			temp = arr[right];
			arr[right] = arr[mid];
			arr[mid] = temp;
		}
		else arr[right] = arr[right];
		if (arr[mid] < arr[left])
		{
			T temp;
			temp = arr[mid];
			arr[mid] = arr[left];
			arr[left] = temp;

		}
		else arr[right] = arr[right];

		T temp = arr[mid]; //让最中间的数成为基准数
		int i = left + 1;
		int j = right - 1;

		while (i < j)
		{

			while (i<j && arr[j] > temp)//从右往左比基准数大的交换
				j--;

			arr[i] = arr[j];//依次放左边

			while (i < j && arr[i] <= temp)//从左往右比基准数小的交换
				i++;

			arr[j] = arr[i];  //依次放右边
		}

		arr[i] = temp; //左右重合

		quickSortgreater(arr, left, i - 1);//对左子序重复排列

		quickSortgreater(arr, i + 1, right);//对右子序重复排列
	}

	else
		return;
}

template <typename T> void QuickSort2(T* arr, int n)
{
	return quickSortgreater(arr, 0, n - 1);

}
#endif