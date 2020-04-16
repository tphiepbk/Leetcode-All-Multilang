#include <iostream>
#include <string>
#include <vector>

using namespace std;

    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        if (strs.size() == 0) return res;
        else if (strs.size() == 1) return strs[0];

        int index = 0;

        char cur = strs[0][index], pre = strs[0][index];

        while (true) {
            int check = 0;
            for (int i = 0 ; i < strs.size() ; i++) {

                if (i == 0) {
                    pre = strs[i][index];
                }
                else {
                    cur = strs[i][index];
                    if (cur != pre) {
                        check++;
                        break;
                    }
                }
            }

            if (cur == '\0') break;

            if (check == 0) {
                index++;
                res += cur;
            }
            else break;
        }
        return res;
    }

int main() {
    vector<string> strs = {""};
    string res = longestCommonPrefix(strs);
    cout << "[" << res << "]";
}