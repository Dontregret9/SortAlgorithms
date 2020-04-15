#include<iostream>
using namespace std;

void Swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}


// Thuật toán này đơn giản nhất nhưng về chi phí tính toán khá cao vì với mỗi vị trí đều phải so sánh với tất cả các số còn lại
// hơn nữa mỗi khi so sánh nếu gặp được cặp nghịch thế (tức là sai thứ tự) thì swap ngay
void InterchangeSort(int* A, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (A[i] > A[j])
			{
				Swap(&A[i], &A[j]);
			}
		}
	}
}

// Thuật toán này phức tạp hơn thuật toán InterchangeSort một chút vì nó cải tiến ở chỗ với mỗi vòng lặp khi tìm được phần tử lớn (nhỏ) nhất
// thì nó mới Swap() dẫn đến số lượng Swap() giảm
void SelectionSort(int* A, int length)
{
	for (int i = 0; i < length; i++)
	{
		int min = A[i], pos = i;// cài min=A[i] và vị trí swap pos=i
		for (int j = i + 1; j < length; j++)
		{
			if (min > A[j])// nếu tìm được phần tử nhỏ hơn thì cập nhật lại min và vị trí của phần tử cần swap()
			{
				min = A[j];
				pos = j;
			}
		}
		Swap(&A[i], &A[pos]);// sau khi tìm được phần tử nhỏ nhất (trong phần còn lại) thì swap()
	}
}

