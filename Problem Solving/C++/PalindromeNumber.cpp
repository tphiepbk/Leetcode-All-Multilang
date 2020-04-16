#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

    // bool isPalindrome(int x) {
    //     string init = to_string(x);
    //     string rev = init;
    //     reverse(rev.begin(), rev.end());
    //     int comp = init.compare(rev);
    //     if (comp == 0) return true;
    //     return false;
    // }

    bool isPalindrome(int x) {
        long init = x, rev = 0;
        while (x > 0) {
            long lastDigit = x % 10;
            rev = rev * 10 + lastDigit;
            x /= 10;
        }
        return (init == rev);
    }

int main() {
    cout << isPalindrome(2147483647);
}