#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class MinStack {
private:
    vector<pair<int, int>> data;
    int minValue;
public:
    /** initialize your data structure here. */
    MinStack() {
        this->minValue = INT_MAX;
    }
    
    void push(int x) {
        if (data.size() == 0) {
            this->minValue = x;
            this->data.push_back(make_pair(x, this->minValue));
        }
        else {
            if (x < this->minValue) {
                this->minValue = x;
            }
            this->data.push_back(make_pair(x, this->minValue));
        }    
    }
    
    void pop() {
        this->data.pop_back();
        if (data.size() != 0) {
            auto p = this->data.back();
            this->minValue = p.second;
        }
        else {
            this->minValue = INT_MAX;
        }
    }
    
    int top() {
        auto it = this->data.back();
        return it.first;
    }
    
    int getMin() {
        auto it = this->data.back();
        return it.second;
    }
};

int main() {
    
    MinStack* minStack = new MinStack();
    minStack->push(-10);
    minStack->push(14);
    cout << minStack->getMin() << "\n";
    cout << minStack->getMin() << "\n";
    minStack->push(-20);
    cout << minStack->getMin() << "\n";
    cout << minStack->getMin() << "\n";
    cout << minStack->top() << "\n";
    cout << minStack->getMin() << "\n";
    minStack->pop();
    minStack->push(10);
    minStack->push(-7);
    cout << minStack->getMin() << "\n";
    minStack->push(-7);
    minStack->pop();
    cout << minStack->top() << "\n";
    cout << minStack->getMin() << "\n";  
    minStack->pop();
    

    
    MinStack* ms = new MinStack();
    cout << "null, ";
    ms->push(85); cout << "null, ";
    ms->push(-99); cout << "null, ";
    ms->push(67); cout << "null, ";
    cout << ms->getMin() << ", ";
    ms->push(-27); cout << "null, ";
    ms->push(61); cout << "null, ";
    ms->push(-97); cout << "null, ";
    ms->push(-27); cout << "null, ";
    ms->push(35); cout << "null, ";
    cout << ms->top() << ", ";
    ms->push(99); cout << "null, ";
    ms->push(-66); cout << "null, ";
    cout << ms->getMin() << ", ";
    ms->push(-89); cout << "null, ";
    cout << ms->getMin() << ", ";
    ms->push(4); cout << "null, ";
    ms->push(-70); cout << "null, ";
    cout << ms->getMin() << ", ";
    ms->push(52); cout << "null, ";
    cout << ms->top() << ", ";
    ms->push(54); cout << "null, ";
    cout << ms->getMin() << ", ";
    ms->push(94); cout << "null, ";
    ms->push(-41); cout << "null, ";
    ms->push(-75); cout << "null, ";
    ms->push(-32); cout << "null, ";
    cout << ms->getMin() << ", ";
    ms->push(5); cout << "null, ";
    ms->push(29); cout << "null, ";
    cout << ms->top() << ", ";
    ms->push(-78); cout << "null, ";
    ms->push(-74); cout << "null, ";
    cout << ms->getMin() << ", ";
    ms->pop(); cout << "null, ";
    cout << ms->getMin() << ", ";
    ms->push(-58); cout << "null, ";
    ms->push(-44); cout << "null, ";
    cout << ms->getMin() << ", ";
    cout << ms->getMin() << ", ";
    ms->push(-64); cout << "null, ";
    cout << ms->getMin() << ", ";
    ms->pop(); cout << "null, ";
    

    /*
    ms->pop(); cout << "null, ";
    ms->push(); cout << "null, ";
    cout << ms->top() << ", ";
    cout << ms->getMin() << ", ";
    */
    MinStack* ms2 = new MinStack(); cout << "null, ";
    ms2->push(2147483646); cout << "null, ";
    ms2->push(2147483646); cout << "null, ";
    ms2->push(2147483647); cout << "null, ";
    cout << ms2->top() << ", ";
    ms2->pop(); cout << "null, ";
    cout << ms2->getMin() << ", ";
    ms2->pop(); cout << "null, ";
    cout << ms2->getMin() << ", ";
    ms2->pop(); cout << "null, ";
    ms2->push(2147483647); cout << "null, ";
    cout << ms2->top() << ", ";
    cout << ms2->getMin() << ", ";
    ms2->push(-2147483648); cout << "null, ";
    cout << ms2->top() << ", ";
    cout << ms2->getMin() << ", ";
    ms2->pop(); cout << "null, ";
    cout << ms2->getMin() << ", ";


        // ms2->pop(); cout << "null, ";
        // ms2->push(); cout << "null, ";
        // cout << ms2->top() << ", ";
        // cout << ms2->getMin() << ", ";
}