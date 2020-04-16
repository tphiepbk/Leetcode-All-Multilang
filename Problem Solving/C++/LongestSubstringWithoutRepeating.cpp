#include <iostream>
#include <string>

using namespace std;

    int lengthOfLongestSubstring(string s) {
        string res = "";
        int len = s.length();
        if (len == 1) return 1;
        int resLen = 0;
        int maxLen = 0;
        int pivot = 0;
        int count = 0;
        for (int i = pivot ; i < len ; i++) {
            count = 0;
            for (int j = i - 1; j >= pivot ; j--) {
                if (s[i] == s[j]) {
                    resLen = res.length();
                    if (resLen >= maxLen) maxLen = resLen;
                    res = "";
                    pivot++;
                    i = pivot - 1;
                    count++;
                    break;
                }
            }
            if (count == 0) res += s[i];
            if (res.length() >= maxLen) maxLen = res.length();
        } 
        if (maxLen == 0) maxLen = res.length();
        return maxLen;
    }

int main() {
    string s = "abcaabcd";
    cout << lengthOfLongestSubstring(s);
}