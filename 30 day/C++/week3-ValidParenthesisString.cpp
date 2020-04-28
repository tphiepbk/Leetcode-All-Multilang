#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


    bool checkValidString(string s) {
        int low = 0;
        int high = 0;
        for (int i = 0 ; i < s.length() ; i++) {
            low += (s[i] == '(') ? 1 : -1;
            high += (s[i] != ')') ? 1 : -1;
            if (high < 0) break;
            if (low < 0) low = 0; 
        }
        return low == 0;
    }


int main() {
    string s = "(*)";
    cout << checkValidString(s);
}