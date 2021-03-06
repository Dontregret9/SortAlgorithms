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

// Thuật toán về ý tưởng giống như xếp bài khi nhận được từng là bài một, tìm vị trí chèn vào thích hợp
// Thuật toán này thích hợp cho các trường hợp dữ liệu chưa đầy đủ đang truyền tới.
void InsertionSort(int* A, int length)
{
	for (int i = 1; i < length; i++)// xét từ phần tử vị trí 1 (xem phần tử 0 như là dãy đã sắp xếp)
	{
		int pos = i;
		for (int j = 0; j < i; j++)// duyệt trong mảng từ 0 đến vị trí đang xét để tìm vị trí chèn
		{
			if ((j == 0 && A[i] < A[j]))// nếu nhỏ hơn phần tử đầu tiên thì chèn vào vị trí A[0]
			{
				pos = 0;
				break;
			}
			if (A[i]<A[j] && A[i]>A[j - 1])// nếu tìm được vị trí mà nó nằm giữa thì cũng chèn vào vị trí đó
			{
				pos = j;
				break;
			}
		}
		if (pos != i)
		{
			int tmp = A[i];
			for (int x = i; x >= pos; x--)// thực hiện dịch chuyển đoạn từ i đến pos sang phải 1 đơn vị để cho A[i] vào vị trí pos
			{
				A[x] = A[x - 1];
			}
			A[pos] = tmp;
		}
	}
}



// Thuật toán này cải tiến từ thuật toán Insertion Sort, cải tiến trong lúc tìm vị trí để chèn. Ta nhận thấy với những phần tử đã được sắp
// xếp nên sẽ có thứ tự nên lúc tìm vị trí chèn ta áp dụng tìm kiếm nhị phân để tăng tốc từ O(n) thành O(log(n))

int BinarySearch(int* A, int left, int right, int value)// hàm này trả về vị trí mà value phải nằm
{
	if (left == right)
	{
		if (A[left] <= value)
			return left + 1;
		else
			return left;
	}
	else if (right - left == 1)
	{
		if (A[left] >= value)
			return left;
		else if (A[right] <= value)
			return right + 1;
		else
			return right;
	}
	else if (A[left] < value && value < A[right])
	{
		int mid = (left + right) / 2;
		if (A[mid] == value)
			return mid;
		else if (A[mid] < value)
		{
			return BinarySearch(A, left, mid, value);
		}
		else
			return BinarySearch(A, mid, right, value);
	}
}

void BinaryInsertionSort(int* A, int length)
{
	for (int i = 1; i < length; i++)
	{
		int pos = BinarySearch(A, 0, i - 1, A[i]);
		int tmp = A[i];
		for (int j = i; j > pos; j--)
		{
			A[j] = A[j - 1];
		}
		A[pos] = tmp;
	}
}


// thuật toán này không khác Interchange sort lắm, chỉ là thay đổi cách hình dung ra thuật toán thôi
// ý tưởng: để mảng theo chiều dọc, xem vị trí dưới là đáy, vị trí trên là bề mặt, mỗi phần tử như là những vật thể có khối lượng
// khi nó những vật nhẹ hơn sẽ nổi lên trên (nổi bọt) những vật thể nặng hơn(giá trị lớn hơn)
void BubleSort(int* A, int length)
{
	int bottom = length-1, surface = 0;
	while (bottom > surface)
	{
		for (int i = bottom; i > surface; i--)// nối bọt từ từ
		{
			if (A[i] < A[i - 1])
			{
				Swap(&A[i], &A[i - 1]);
			}
		}
		surface++;// khi có phần tử nhỏ nhất thì hạ bề mặt xuống
	}
}


// thuật toán này cải tiếng hơn Buble sort được một xíu. Đó là trong lúc nổi bọt thì nó cũng lắng đọng
void ShakerSort(int* A, int length)
{
	int bottom = length - 1, surface = 0;
	while (bottom > surface)
	{
		for (int i = bottom; i > surface; i--)// nổi bọt
		{
			if (A[i] < A[i - 1])
				Swap(&A[i], &A[i - 1]);
		}
		surface++;

		for (int i = surface; i < bottom; i++)// lắng đọng
		{
			if (A[i] > A[i + 1])
				Swap(&A[i], &A[i + 1]);
		}
		bottom--;
	}

}
// còn tiếp ........