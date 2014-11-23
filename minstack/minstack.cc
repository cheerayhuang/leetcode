#include <iostream> 
#include <stack>
#include <climits>

using namespace std; 

class MinStack {
private:
    stack<int> s_; 
    stack<int> min_s_;

public:
    void push(int x) {
        s_.push(x); 
        if (min_s_.empty() || x < min_s_.top()) {
            min_s_.push(x);
        }
    }

    void pop() {
        if (s_.empty()) {
            return;
        }

        auto tmp = s_.top();
        s_.pop();
        if (tmp == min_s_.top()) {
            min_s_.pop(); 
        }
    }

    int top() {
        if (s_.empty()) {
            return INT_MIN;
        }
        return s_.top();
    }

    int getMin() {
        if (s_.empty()) {
            return INT_MIN;
        }
        return min_s_.top();
    }

};

int main() {
    return 0;
}
