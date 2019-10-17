#include<iostream>
#include<climits>
using namespace std;

int partition(int arr[], int l, int r);


int kthSmallest(int arr[], int l, int r, int k)
{

	if (k > 0 && k <= r - l + 1)
	{

		int pos = partition(arr, l, r);


		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1)
			return kthSmallest(arr, l, pos-1, k);


		return kthSmallest(arr, pos+1, r, k-pos+l-1);
	}


	return INT_MAX;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}


int main()
{
	int arr[] = {3, 2, 5, 1, 8, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"enter start and end and k\n";
	int s,e,k;
	cin>>s>>e>>k;
	cout << "K'th smallest element is " << kthSmallest(arr, s-1, e-1, k);
	return 0;
}

