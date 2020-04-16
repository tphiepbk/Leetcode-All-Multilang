#include <iostream>
#include <vector>

using namespace std;

    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        vector<int> res(nums.size());
        res[0] = 1;
        for (int i = 1 ; i < nums.size() ; i++) {
            res[i] = res[i-1] * nums[i-1];
        }
        int temp = 1;
        for (int i = nums.size() - 2 ; i >= 0 ; i--) {
            temp = temp * nums[i+1];
            res[i] = res[i] * temp;
        }
        return res;
        */

        vector<int> res(nums.size());
        int temp = 1;
        for (int i = 0 ; i < nums.size() ; i++) {
            res[i] = temp;
            temp *= nums[i];
        }
        temp = 1;
        for (int i = nums.size() - 1 ; i >= 0 ; i--) {
            res[i] *= temp;
            temp *= nums[i];
        }
        return res;
    }
int main() {
    vector<int> arr = {1,2,3,4};
    vector<int> res = productExceptSelf(arr);
    while (!res.empty()) {
        cout << res.front() << " ";
        res.erase(res.begin());
    }
}