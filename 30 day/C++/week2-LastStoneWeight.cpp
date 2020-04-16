#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int stone1 = stones.back();
            stones.pop_back();
            int stone2 = stones.back();
            stones.pop_back();
            int stoneLeft = stone1 - stone2;
            if (stoneLeft != 0) stones.push_back(stoneLeft);
        }
        if (stones.empty()) return 0;`
        else return stones.back();
    }

int main() {
    vector<int> s = {2,7,4,1,8,1};
    cout << lastStoneWeight(s);
}