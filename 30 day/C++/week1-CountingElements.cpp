#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    int countElements(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int index1 = 0, index2 = 0;
        int size = arr.size();
        vector<int> res;
        while (index2 < size) {
            if (index1 == index2) index2++;
            if (index1 >= size || index2 >= size) break;
            if (arr[index2] - 1 == arr[index1]) {
                res.push_back(arr[index1]);
                index1++;
            }
            else if (arr[index1] == arr[index2]) {
                index2++;
                if (index2 >= size) break;
            }
            else {
                index1++;
            }
        }        
        return res.size();
    }
    
int main() {
    vector<int> arr = {1,3,2,3,4,3,3,3,3,0};
    cout << countElements(arr);
}