#include <iostream>
#include <stack>

using namespace std;

    bool matching(char a, char b) {
        if (a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}') return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0 ; i < s.length() ; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else {
                if (!st.empty()) {
                    if (!matching(st.top(), s[i])) return false;
                    else st.pop();
                }
                else st.push(s[i]);
            }
        }
        if (st.empty()) return true;
        else return false;
    } 

int main() {
    string s = "(){}]";
    cout << isValid(s);
}