#include <iostream>
#include <vector>
#include <string>

using namespace std;

    string stringShift(string s, vector<vector<int>>& shift) {
        
        if (s == "") return s;
        vector<int> line;
        string res = "";
        for (int i = 0 ; i < shift.size() ; i++) {
            string temp = "";
            line = shift[i];
            int numOfShifts = line[1];
            if (line[0] == 1) {  // Shift right
                while (numOfShifts--) {
                    if (s.back() != '\0')temp.insert(temp.begin(), s.back());
                    if (s != "") s.pop_back();
                }
                s = temp + s;
            }
            else { // Shift left
                while (numOfShifts--) {
                    if (s.front() != '\0') temp.push_back(s.front());
                    if (s != "") s.erase(s.begin());
                }
                s = s + temp;
            }
        }
        return s;
        

        // Hint solution
        /*
        int totalShifts = 0;
        vector<int> line;
        for (int i = 0 ; i < shift.size() ; i++) {
            line = shift[i];
            if (line[0] == 0) totalShifts -= line[1];
            else totalShifts += line[1];
        }
        string temp = "";
        if (totalShifts > 0) {
            // Shift right
            while (totalShifts--) {
                temp = "";
                if (s.back() != '\0') temp.insert(temp.begin(), s.back());
                if (s != "") s.pop_back();
                s = temp + s;
            }
        }
        else if (totalShifts < 0){
            totalShifts *= -1;
            // Shift left
            while (totalShifts--) {
                temp = "";
                if (s.front() != '\0') temp.push_back(s.front());
                if (s != "") s.erase(s.begin());
                s = s + temp;      
            }
        }
        return s;
        */
    }

int main() {
    vector<vector<int>> shift = {{1,8},{1,4},{1,3},{1,6},{0,6},{1,4},{0,2},{0,1}};
    string s = "yisxjwry";
    cout << "[" << stringShift(s, shift) << "]";
}