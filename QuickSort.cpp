#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition (int arr[], int p, int r)
    {
    int end = arr[r];
    int i = p - 1;
    for (int j = p; j <= r- 1; j++)
    {
        if (arr[j] <= end)
        {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return i;
    }


void quickSort(int arr[], int p, int r)
    {
    if (p < r)
    {
        int pivot = partition(arr, p,r);
        quickSort(arr, p, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }
    else{
        return;
    }
    }


int main()
    {
    srand(time(NULL));

    int arr[10000];
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) arr[i] = rand() % 100;

    auto start = chrono::high_resolution_clock::now();

    quickSort(arr,0,n-1);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
    }
