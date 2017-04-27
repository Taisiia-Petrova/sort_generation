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

	while (k <= n)// пока у a[k] есть дети 
	{

		if (child < n && arr[child] < arr[child + 1]) child++;    //  выбираем большего сына 
		else if (new_elem > arr[child]) break;

		else {
			arr[child / 2] = arr[child]; // переносим сына наверх 
			child = child * 2;
		}
		arr[child / 2] = new_elem;
	}
}
template<typename T>
void sort(std::vector<T> &arr)
{
	for (int i = (arr.size() / 2); i >= 1; i--)  downHeap <T>(arr, i, arr.size());// строим пирамиду  теперь [0]...[size-1] пирамида 

	for (int i = arr.size(); i >= 2; i--)		// меняем первый с последним 
	{
		T 	temp = arr[i]; arr[i] = arr[0]; arr[0] = temp; //  восстанавливаем пирамиду с [0]..[i-1]
		downHeap <T>(arr, 0, i - 1);
	}
}


#endif // SORT_H
