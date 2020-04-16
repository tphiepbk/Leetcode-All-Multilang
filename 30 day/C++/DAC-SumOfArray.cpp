#include <iostream>
#include <vector>

using namespace std;

int sumArray(int anArray[], int size)
{
    //base case
    if (size == 0)
    {
        return 0;
    }
    else if (size == 1)
    {
        return anArray[0];
    }

    //divide and conquer
    int mid = size / 2;
    int rsize = size - mid;
    int lsum = sumArray(anArray, mid);
    int rsum = sumArray(anArray + mid, rsize);
    return lsum + rsum;
}

int main() {
    int arr[7] = {1,4,6,3,2,9,8};
    cout << sumArray(arr, 7); 
}