#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1; // Pointer for the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment the smaller element index
            swap(arr[i], arr[j]); // Swap
        }
    }
    swap(arr[i + 1], arr[high]); // Swap the pivot element with the element at i + 1
    return i + 1; // Return the partition index
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1); // Recursively sort elements before partition
        quickSort(arr, pi + 1, high); // Recursively sort elements after partition
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    cout << "Input array: ";
     for (int num : arr) {
        cout << num << " ";
    }

    quickSort(arr, 0, n - 1);

    cout <<endl<< "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
