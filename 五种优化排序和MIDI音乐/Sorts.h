// Sorts.h		���֣�ð�ݡ�ѡ�񡢿��١����롢�鲢�����������㷨������
#ifndef SORTS_H
#define SORTS_H
#include <iostream>

using namespace std;

double gettime(int restart = 0);

template <typename T> void GetMemory(T*& data, T*& data0, int n)	// ������ڴ�ռ䣬ͨ������"����"�׵�ַ
{																	// ����Լ����ָ��ǿվͱ�ʾָ��"ӵ��"�ѿռ���Դ
	if (data0 != NULL) delete[] data0;								// ���ͷ�ԭ����"ӵ��"�Ķѿռ���Դ
	if (data != NULL) delete[] data;
	data0 = new T[n];												// ���������µģ���������Ҫ��ģ��ѿռ���Դ
	data = new T[n];
}

template <typename T> void FreeMemory(T*& data, T*& data0)			// �ͷ�ָ����"ӵ��"�Ķѿռ���Դ
{
	if (data0 != NULL) delete[] data0;
	if (data != NULL) delete[] data;
	data0 = data = NULL;											// ��һ����ֵ���ǳ���Ҫ������"����Լ��"
}

template <typename T> void ReSet(T* data, const T* data0, int n)	// ���ڻָ�"ԭʼ����"���Ա�֤��ͬ�������㷨������ȫ��ͬ������
{
	for (int i = 0; i < n; i++)
		data[i] = data0[i];
}

template <typename T> bool Check(const T* a, int size)				// ��������Ԫ���Ƿ��Ѱ���������
{
	for (int i = 1; i < size; i++)
		if (a[i - 1] > a[i])
			return false;
	return true;
}

//ģ�廯 ���� 

/* ð������ */
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
	bool swapped; /* δ������-false  ������-true*/

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
		// ���swapped��false��˵��û�н��������������˳�����
		if (!swapped)
			break;
	}
}

template <typename T> void BubbleSort3(T* arr, int n)
{
	T temp;
	int i, j;
	bool swapped;/* δ������-false  ������-true*/
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
		//���swapped��false��˵��û�н��������������˳�����
		if (!swapped)
			break;
	}
}

/* ѡ������ */
template <typename T> void SelectionSort1(T* arr, int n)
{
	T temp;
	int i, j, minindex;
	for (i = 0; i < n - 1; i++)
	{
		minindex = i; //�Ѿ��������߽�
		/* �ҵ����������򲿷ֵ���С�ؼ��� */
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[minindex])
				minindex = j;
		/* ����С�ؼ��������򲿷ֵĵ�һ�ؼ��ֽ��� */
		temp = arr[i];						// ���� a[j] �� a[j+1]
		arr[i] = arr[minindex];
		arr[minindex] = temp;
	}
}

template <typename T> void SelectionSort2(T* arr, int n)
{
	/* a[i-1]��֮ǰ������ */
	/* a[i]-a[n-1]�ҳ���СԪ���±� */
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}

		/* ��С��Ԫ���Ƶ�λ��i */
		/* i -- min-1��Ԫ�ض�����ƶ�1λ*/
		T key = arr[min];
		while (min > i)
		{
			arr[min] = arr[min - 1];
			min--;
		}

		//��key��ǰ��Сֵ����a[i]λ��
		arr[i] = key;
	}
}

template <typename T> void SelectionSort3(T* arr, int n)
{
	T temp;
	int start = 0;
	int end = n - 1;
	while (end > start + 1) {

		int minIndex = start;//��Сֵ��Ӧ�±�
		int maxIndex = start;//���ֵ��Ӧ�±�
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
		}//����С�����λ�������ֵ����Сλ�ã��ٽ���һ��

		if (maxIndex != end) {
			temp = arr[end];						// ���� a[j] �� a[j+1]
			arr[end] = arr[maxIndex];
			arr[maxIndex] = temp;
		}
		start++;
		end--;
	}
	if (end == start + 1) {
		if (arr[end] < arr[start]) {
			temp = arr[end];						// ���� a[j] �� a[j+1]
			arr[end] = arr[start];
			arr[start] = temp;
		}
	}
}

/* �������� */
template <typename T>void InsertionSort1(T* arr, int n)
{
	T temp;
	int i, j;
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		while (j >= 0 && arr[j + 1] < arr[j])
		{
			//����
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
		//��0��i-1�дӺ���ǰ�ҵ�����λ��
		while (j >= 0 && insert < arr[j])
		{
			//�ƶ�
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
		//ͨ�����ַ�Ѱ�Ҳ����λ��
		while (min <= max)
		{
			int mid = (min + max) / 2;
			//����С��Χ
			if (arr[mid] <= insert)
				min = mid + 1;
			else
				max = mid - 1;
		}
		if (i > min)
		{
			//�ƶ�
			for (j = i; j > min; j--)
				arr[j] = arr[j - 1];
			arr[j] = insert;
		}
	}
}

/*�鲢����ݹ鷨*/
template <typename T> void merge(T arr[], int l, int m, int r)
{
	//��������������Ĵ�С
	int n1 = m - l + 1;
	int n2 = r - m;

	//������ʱ���飬�������Ҫ�ϲ���������
	T* L = new T[n1];
	//int *R = new int[n2];

	/* �������� */
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
	/* ���L[]��ʣ�� */
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
		//����mid
		int mid = (left + right) / 2;
		//�� �������������������
		mergeSort1(arr, left, mid); //���
		mergeSort1(arr, mid + 1, right); //�ұ�
		//��
		merge(arr, left, mid, right);
	}
}

template <typename T> void MergeSort1(T* arr, int n)
{
	return mergeSort1(arr, 0, n - 1);
}
/*�鲢���������*/
//��һ���ܳ�Ϊn�������У���a��ͷ����Ϊlength��b��ͷ����Ϊlength������������й鲢����
template <typename T> void Merge2(T* arr, int a, int b, int length, int n)
{
	int rest = length;
	//�ж����һ������ʱb��ͷ�����鳤��
	if (length + b - 1 >= n - 1)
		rest = n - b;

	int i = 0, j = 0;
	T* L = new T[length];

	for (; i <= length - 1; i++)
		L[i] = arr[a + i];

	i = 0;
	/*������������й鲢����*/
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

/* �������� */
template <typename T> void quickSort(T* arr, int left, int right)
{

	if (left < right)
	{
		T standard = arr[left]; //������ߵ�����Ϊ��׼��
		int i = left;
		int j = right;

		while (i < j)  //���ұߵ������׼���Ƚ�
		{

			while (i<j && arr[j] > standard)//��������Ȼ�׼����Ľ���
				j--;

			arr[i] = arr[j];//���η����

			while (i < j && arr[i] <= standard)//�������ұȻ�׼��С�Ľ���
				i++;

			arr[j] = arr[i];  //���η��ұ�
		}

		arr[i] = standard; //�����غ�

		quickSort(arr, left, i - 1);//���������ظ�����

		quickSort(arr, i + 1, right);//���������ظ�����
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

		if (arr[right] < arr[left])//��left ��right��mid��������
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

		T temp = arr[mid]; //�����м������Ϊ��׼��
		int i = left + 1;
		int j = right - 1;

		while (i < j)
		{

			while (i<j && arr[j] > temp)//��������Ȼ�׼����Ľ���
				j--;

			arr[i] = arr[j];//���η����

			while (i < j && arr[i] <= temp)//�������ұȻ�׼��С�Ľ���
				i++;

			arr[j] = arr[i];  //���η��ұ�
		}

		arr[i] = temp; //�����غ�

		quickSortgreater(arr, left, i - 1);//���������ظ�����

		quickSortgreater(arr, i + 1, right);//���������ظ�����
	}

	else
		return;
}

template <typename T> void QuickSort2(T* arr, int n)
{
	return quickSortgreater(arr, 0, n - 1);

}
#endif