//������� 

const int NMAX = 100000;
int arr[NMAX + 1];

void heapify(int *arr, int pos, int n);//������������ ����
//void heap_push(int *arr, int v);//���������� �������� � ����
					//��������� �� ���� ����� �������� � �������,
					 //������� ���������� �������� � ����
void heap_make(int *arr, int n);//������� ���������� ����
void heap_sort(int *arr, int n);//����������