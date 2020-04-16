#include <iostream>
#include <vector>

using namespace std;

int DACmaxUltility(vector<int> arr, int index, int size) {
    int max = 0;
    if (index >= size-2) {
        if (arr[index] >= arr[index+1]) return arr[index];
        else return arr[index+1]; 
    }
    max = DACmaxUltility(arr, index+1, size);

    if (max >= arr[index]) return max;
    else return arr[index];
}

int DACmax(vector<int> arr) {
    return DACmaxUltility(arr, 0, arr.size());
}

int main() {
    vector<int> arr = {1,6,8,9,2};
    cout << DACmax(arr);
}