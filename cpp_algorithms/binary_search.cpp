#include <iostream>

using namespace std;

template<class T>
bool binary_search(size_t n, T* sorted_arr, T target) {
    int lo = 0, hi = n-1;

    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (sorted_arr[mid] == target) return true;
        (sorted_arr[mid] > target) ? hi = mid-1 : lo = mid+1;
    }

    return false;
}

int main() {
    int arr[7] = {1,2,3,4,5,6,7};
    cout << binary_search(7, arr, 10) << endl;
    cout << binary_search(7, arr, 1) << endl;
    cout << binary_search(7, arr, 5) << endl;
    int x = 9;
    int *p = &x;
    int **q = &p;
    cout << **q << endl;
    *p = 10;
    cout << **q << endl;
}
