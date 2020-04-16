#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <set>

using namespace std;

    bool isHappy(int n) {

        if (n == 1) return true;
        if (n == 0) return false;

        int temp = n;
        int digit = 0;
        set<int> visited;
        while (true) {
            int sum = 0;
            while (temp > 0) {
                digit = temp % 10;
                temp /= 10;
                sum += pow(digit, 2);
            }

            int sum2 = 0;
            string sNum = to_string(sum);
            for (int i = 0 ; i < sNum.length() ; i++) {
                sum2 += pow((int)sNum[i] - 48, 2);
            }

            if (sum2 == 1) return true;

            if (sum > 100) {
                
                if (visited.empty()) {
                    visited.insert(sum);
                }
                else {
                    set<int>::iterator it = visited.find(sum);
                    if (*it == sum) return false;
                    else visited.insert(sum);
                }
            }

            temp = sum;
        }
    }

int main() {
    cout << isHappy(59);
}