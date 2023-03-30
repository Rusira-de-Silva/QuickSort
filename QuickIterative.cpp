#include <iostream>
#include <stack>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;


void quickSort(int arr[], int left, int right) {
    stack<int> stk;
    stk.push(right);
    stk.push(left);

    while (!stk.empty()) {
        int l = stk.top();
        stk.pop();
        int r = stk.top();
        stk.pop();

        int pivot = arr[(l + r) / 2];
        int i = l, j = r;

        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }

        if (l < j) {
            stk.push(j);
            stk.push(l);
        }
        if (i < r) {
            stk.push(r);
            stk.push(i);
        }
    }
}

int main() {
    srand(time(NULL));

    int arr[10000];
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) arr[i] = rand() % 100;

    auto start = chrono::high_resolution_clock::now();

    quickSort(arr, 0, n - 1);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    // for (int i = 0; i < n; i++) cout << arr[i] << " ";

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}