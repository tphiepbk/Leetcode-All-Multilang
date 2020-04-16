#include <iostream>
#include <vector>

using namespace std;

    void moveZeroes(vector<int>& nums) {
        auto it1 = nums.begin();
        auto it2 = nums.begin() + 1;
        int temp = 0;
        while (it2 != nums.end() && it1 != nums.end()) {
            if (*it1 == 0 && *it2 != 0) {
                temp = *it1;
                *it1 = *it2;
                *it2 = temp;

                it1++;
                it2++;
            }
            else if (*it1 != 0 && *it2 == 0) {
                it1++;
                it2++;
            }
            else if (*it1 == 0 && *it2 == 0) {
                it2++;
            }
            else {
                it1++;
                it2++;
            }
        }
    }

int main() {
    vector<int> nums = {0,1,0,0,3,8,9,0,5};
    moveZeroes(nums);
}