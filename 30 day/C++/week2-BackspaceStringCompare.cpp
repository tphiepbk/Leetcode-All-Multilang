#include <iostream>
#include <string>

using namespace std;

    bool backspaceCompare(string S, string T) {
        string s = "";
        string t = "";
        for (int i = 0 ; i < S.length() ; i++) {
            if (S[i] == '#') {
                if (s.length() != 0) s.erase(s.length() - 1, 1);
            }
            else s += S[i];
        }
        for (int i = 0 ; i < T.length() ; i++) {
            if (T[i] == '#') {
                if (t.length() != 0) t.erase(t.length() - 1, 1);
            }
            else t += T[i];
        }

        int comp = t.compare(s);
        if (comp == 0) return true;
        else return false;
    }

int main() {
    string S = "a#c", T = "b";
    cout << backspaceCompare(S,T);
}