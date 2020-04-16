#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

    bool sameDigit(string str1, string str2) {
        if (str1 == "" && str2 == "") return true;
        else if (str1 == "" || str2 == "") return false; 
        if (str1.length() != str2.length()) return false;
        while (!str1.empty()) {
            int count = 0;
            for (int i = 0 ; i < str2.length() ; i++) {
                if (str1[0] == str2[i]) {
                    str1.erase(0,1);
                    str2.erase(str2.begin() + i);
                    count++;
                    break;
                }
            }
            if (count == 0) return false;
        } 
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        map<string, vector<string>>::iterator it;

        for (int i = 0 ; i < strs.size() ; i++) {

            string str = strs[i];
            vector<int> c(26);
            for (int j = 0 ; j < str.length() ; j++) {
                c[(int)str[j] - 97]++;
            }

            string key = "";
            for (int i = 0 ; i < 26 ; i++) {
                key += to_string(c[i]);
            }
            vector<string> content;
            content.push_back(str);

            if (m.empty()) {
                m.insert(pair<string, vector<string>>(key, content));
            }
            else {
                if (m.find(key) != m.end()) { // Key is found
                    m.at(key).push_back(str);
                }
                else {
                    m.insert(pair<string, vector<string>>(key, content));
                }
            }
        }
        for (auto it = m.begin() ; it != m.end() ; it++) {
            vector<string> line = it->second;
            sort(line.begin(), line.end());
            res.push_back(line);
        }
        return res;
    }

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    while (!res.empty()) {
        vector<string> line = res.front();
        res.erase(res.begin());
        for (int i = 0 ; i < line.size() ; i++) cout << line[i] << " ";
        cout << "\n";
    }
}