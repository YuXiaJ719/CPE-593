#include <iostream>
#include <vector>
using namespace std;


void insertsort(vector<double> &a, int n){
	int l, r;
	 for(int i = 0; i < n; i++){
		l = i;
		r = i + 1;
		while(a[l] > a[r] && l >= 0){
			swap(a[l], a[r]);
			r = l;
			l--;
		}
	}
}

int partition(int arr[], int low, int high){
	int i = low - 1;
	double pivot = arr[high];
	for(int j = low; j < high; i++){
		if(arr[j] <= pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quicksort(int arr[], int low, int high){
	if(low < high){
		int pos = partition(arr, low, high);
		quicksort(arr, low, pos - 1);
		quicksort(arr, pos + 1, high);
	}
}


void heapify(int arr[], int n, int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if(l < n && arr[l] > arr[largest])
		largest = l;
	if(r < n && arr[r] > arr[largest])
		largest = r;

	if(largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapsort(int arr[], int n){
	for(int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for(int i = n - 1; i >= 0; i--){
		swap(arr[0], arr[i]);
		heapify(arr, n, 0);
	}
}





