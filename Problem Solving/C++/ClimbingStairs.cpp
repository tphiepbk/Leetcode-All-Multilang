#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

    int climbStairs(int n) {
        vector<int> arr(n+1);
        arr[0] = 1;
        arr[1] = 1;
        for (int i = 2 ; i < arr.size() ; i++) {
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n];       
    }

int main() {
    cout << climbStairs(45);
}