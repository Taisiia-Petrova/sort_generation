#include "stdafx.h"
#include <iostream>
#include <cstdlib>

extern const int NMAX = 10000;
extern int arr[NMAX + 1];

using namespace std;


void heapify(int *arr, int pos, int n) {//pos - ������� ����� � ����, n - ���������� ��������� � �������
	while (2 * pos + 1 < n) {
		//���� �� ����� �� ������� �������
		int t = 2 * pos + 1; //������� ������� ����
		if (2 * pos + 2 < n && arr[2 * pos + 2] >= arr[t])
			//���� ������ ��� ��������� � ������ ��� ������
		{
			t = 2 * pos + 2;//����� ���
		}
		if (arr[pos] < arr[t])
		{
			//���� ���������� �� ������� ������
			//��� ������, �� ������ �� �������
			swap(arr[pos], arr[t]);
			pos = t;//������ ������� �������� ��������� �������
		}
		else break;
		//����� ���� � ������� � pos ���������
	}
}

void heap_make(int *arr, int n)//������� ���������� ����
{
	for (int i = n - 1; i >= 0; i--)
	{
		heapify(arr, i, n);// ������� ���������� ������ �������� � ����
	}
}

void heap_sort(int *arr, int n)//����������, ���� ����������
{
	heap_make(arr, n);//������ ����(��������)
	while (n > 0)
	{
		swap(arr[0], arr[n - 1]);
		n--;
		heapify(arr, 0, n);
	}
}