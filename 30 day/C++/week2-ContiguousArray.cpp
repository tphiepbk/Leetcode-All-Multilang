#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>

using namespace std;

    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m.insert(pair<int, int>(0, -1));
        int count = 0, maxLen = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            count += (nums[i] == 1) ? 1 : -1;
            auto it = m.find(count);
            if (it != m.end()) {
                maxLen = (maxLen >= (i - it->second)) ? maxLen : (i - it->second);
            }
            else {
                m.insert(pair<int, int>(count, i));
            }
        }   
        return maxLen;
    }

int main() {
    vector<int> nums = {0,0,1,0,0,0,1,1};
    cout << findMaxLength(nums);
}   