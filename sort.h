#ifndef SORT_H
#define SORT_H

#include <vector>
#include <algorithm>

template <typename T>

void  downHeap(std::vector <T> &arr, int k, int n)
{
	T new_elem;
	int child;
	child = 2 * k;
	new_elem = arr[k];

	while (k <= n)// ���� � a[k] ���� ���� 
	{

		if (child < n && arr[child] < arr[child + 1]) child++;    //  �������� �������� ���� 
		else if (new_elem > arr[child]) break;

		else {
			arr[child / 2] = arr[child]; // ��������� ���� ������ 
			child = child * 2;
		}
		arr[child / 2] = new_elem;
	}
}
template<typename T>
void sort(std::vector<T> &arr)
{
	for (int i = (arr.size() / 2); i >= 1; i--)  downHeap <T>(arr, i, arr.size());// ������ ��������  ������ [0]...[size-1] �������� 

	for (int i = arr.size(); i >= 2; i--)		// ������ ������ � ��������� 
	{
		T 	temp = arr[i]; arr[i] = arr[0]; arr[0] = temp; //  ��������������� �������� � [0]..[i-1]
		downHeap <T>(arr, 0, i - 1);
	}
}


#endif // SORT_H
