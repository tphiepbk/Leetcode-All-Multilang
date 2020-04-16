#include <iostream>
#include <vector>

using namespace std;

    int findMax(int a, int b) {
        if (a >= b) return a;
        else return b;
    }

    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int sum = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            sum = findMax(sum + nums[i], nums[i]);
            max = findMax(sum, max);
        }
        return max;
    }

int main() {
    vector<int> nums = {-1,-2,0};
    cout << maxSubArray(nums);
}