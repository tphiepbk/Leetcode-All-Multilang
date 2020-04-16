#include <iostream>
#include <vector>
#include <map>

using namespace std;

    int singleNumber(vector<int>& nums) {
        map<int, vector<int>> m;
        map<int, vector<int>>::iterator it;
        for (int i = 0 ; i < nums.size() ; i++) {
            int idx = nums[i];
            m[idx].push_back(1);
        }
        int res = -1;
        for (auto it = m.begin() ; it != m.end() ; it++) {
            if (it->second.size() == 1) {
                res = it->first;
                break;
            }
        } 
        
        return res;
    }

int main() {
    vector<int> nums = {2,2,4,7,4,5,5};
    cout << singleNumber(nums);
}