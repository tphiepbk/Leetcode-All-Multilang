#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

    vector<int> sortedSquares(vector<int>& A) {
        // Solution 1 : Sort Algorithm
        /*
        vector<int> res(A.size());
        for (int i = 0 ; i < A.size() ; i++) {
            res[i] = pow(A[i], 2);
        }
        sort(res.begin(), res.end());
        return res;
        */

        // Solution 2 : Two pointer;
        vector<int> res;
        int index1 = 0, index2 = 0;
        while (index2 < A.size() && A[index2] < 0) {
            index2++;
        }
        index1 = index2 - 1;

        while (index1 >= 0 && index2 < A.size()) {
            int temp1 = pow(A[index1], 2);
            int temp2 = pow(A[index2], 2);
            if (temp1 <= temp2) {
                res.push_back(temp1);
                index1--;
            }
            else {
                res.push_back(temp2);
                index2++;
            }
        }

        while (index1 >= 0) res.push_back(pow(A[index1--], 2));
        while (index2 < A.size()) res.push_back(pow(A[index2++], 2));
        return res;
    }

int main() {
    vector<int> A = {-7,-3,2,3,11};
    vector<int> res = sortedSquares(A);
    while (!res.empty()) {
        cout << res.front() << " ";
        res.erase(res.begin());
    }
}