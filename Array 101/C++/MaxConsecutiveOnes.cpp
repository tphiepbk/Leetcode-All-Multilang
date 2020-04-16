#include <iostream>
#include <vector> 
#include <map>

using namespace std;

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int index1 = 0;
        int index2 = 0;
        int countForOnes = 0;
        while (index1 < nums.size() && index2 < nums.size()) {
            if (nums[index2] == 0) {
                countForOnes = index2 - index1;
                if (countForOnes >= maxCount) maxCount = countForOnes;
                index2++;
                index1 = index2;
            }
            else {
                index2++;
            }
        } 
        countForOnes = index2 - index1;
        if (countForOnes >= maxCount) maxCount = countForOnes;
        return maxCount; 
    }

int main() {
    vector<int> nums = {1,0,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,1,10};
    cout << findMaxConsecutiveOnes(nums);
}