// Referensi dari https://www.geeksforgeeks.org/dsa/binary-search/
#include<iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main(void)
{
	int x;
    int arr[] = {11, 22, 33, 44, 55, 66, 77};
	cout << "Input: ";
	cin >> x;
	
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    if(result == -1) cout << "Data tidak ditemukan";
    else cout << "posisi index berada di index: " << result << " dari 0 || " << result + 1 << " dari 1";
    return 0;
}
