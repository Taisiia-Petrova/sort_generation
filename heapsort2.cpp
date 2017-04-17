// heapsort2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "heapsort.h"
#include <fstream>
#include <cstdlib>
#include <time.h>  /* clock_t, clock, CLOCKS_PER_SEC */
#include <ctime>
#include <windows.h>
#include <chrono>

using namespace std;

int main()
{
	SetConsoleCP(1251);			// ��� ������ ��������
	SetConsoleOutputCP(1251);	// ��� ������ ��������

	//ifstream fin;
	//ofstream fout;
	//clock_t t, t1, t2, t3, t4, t5, t6, t7, t8;
	bool exit = false;
	char your_answer;
	ifstream fin("data.txt");
	while (!exit)
	{

		cout << "              MENU:" << endl;
		cout << "*******************************" << endl;
		cout << "1. ������� ������ � �������." << endl;
		cout << "2. ������� ������ �� �����." << endl;
		cout << "3. �� �������� ������ ��������� �����, �� ����������� ������� ������� - ��� �� ������� ����." << endl;
		cout << "4. ��������� ���������." << endl;
		cout << "*******************************" << endl;
		cout << "����, ��� �����:" << endl;
		cin >> your_answer;
		cout << "                 " << endl;
		
		switch (your_answer)
		{
		case '1': {

			int n = -1;
			while (n <= 0)
			{
				cout << "������� ������ �������: " << endl;
				cin >> n;
			}
			cout << "������� �������� �������: " << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}

			auto start_time = chrono::steady_clock::now();

			heap_sort(arr, n);

			auto end_time = chrono::steady_clock::now();

			cout << "��������������� ������: " << endl;
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << "  ";
			}
			cout << "\n";

			cout << "����� ����������: " << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << " ������������" << endl;
			cout << "\n\n\n";
			break;
		}
		case '2': {
			int n;

			if (!fin.is_open()) // ���� ���� �� ������
				cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
			else
			{
				fin >> n;
				cout << "��� ������� ������:  ";
				for (int i = 0; i < n; i++)
				{
					fin >> arr[i];
					cout << arr[i] << "  ";
				}

				cout << endl;

				auto start_time1 = chrono::steady_clock::now();
				heap_sort(arr, n);
				auto end_time1 = chrono::steady_clock::now();

				cout << "��������������� ������: " << endl;
				for (int i = 0; i < n; i++)
				{
					cout << arr[i] << "  ";
				}
				cout << "\n";

				cout << "����� ����������: " << chrono::duration_cast<chrono::microseconds>(end_time1 - start_time1).count() << " ������������" << endl;
				cout << "\n\n\n";
				fin.close(); // ��������� ����
			}

			break;
		}
		case '3': {
			int n;
			cout << "������� ������ �������: " << endl;
			cin >> n;
			int random_arr[NMAX + 1];

			cout << "��� ������� ��������� ������: ";
			for (int i = 0; i < n; i++)
			{
				random_arr[i] = rand() % 10000; //������ ���������� �����
				cout << random_arr[i] << "  ";
			}
			cout << endl;

			auto start_time2 = chrono::steady_clock::now();

			heap_sort(random_arr, n);

			auto end_time2 = chrono::steady_clock::now();

			cout << "��������������� ������: " << endl;
			for (int i = 0; i < n; i++)
			{
				cout << random_arr[i] << "  ";
			}
			cout << "\n";
			cout << "����� ����������: " << chrono::duration_cast<chrono::microseconds>(end_time2 - start_time2).count() << " ������������" << endl;

			cout << "\n\n\n";
			break;
		}
		case '4':

			exit = true;
			break;

		default:
			cout << " Error \n";
			system("cls");
			}
		
	}

	//_getch();
	return 0;
}



