#include <iostream>
#include <vector>

using namespace std;

    int binarySearch(vector<int> nums, int l, int r, int target) {
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return m;
            } 
            else if (target > nums[m]) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int pivot = 1;
        for (pivot ; pivot < nums.size() ; pivot++) {
            if (nums[pivot] < nums[pivot-1]) break;
        }
        if (target == nums[0]) return 0;
        else if (target > nums[0]) {
            return binarySearch(nums, 0, pivot-1, target);
        }
        else {
            return binarySearch(nums, pivot, nums.size() - 1, target);
        }
    }

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    for (int i = 0 ; i < nums.size() ; i++) {
        cout << nums[i] << " : " << search(nums, nums[i]) << "\n";
    }
}