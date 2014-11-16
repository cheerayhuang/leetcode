#include <iostream> 
#include <stack>

using namespace std; 

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_s;

        for(auto &ch : s) {
            if (stack_s.empty()) {
                stack_s.push(ch);
                continue;
            }
            auto top_ch = stack_s.top();
            if ((top_ch == '(' && ch == ')') || 
               (top_ch == '{' && ch == '}') || 
               (top_ch == '[' && ch == ']')) {
                stack_s.pop();
            }
            else {
                stack_s.push(ch);
            }
        }

        return stack_s.empty();
    }
};

int main() {
    Solution s;

    cout << s.isValid("((()))[[]]") << endl;
    cout << s.isValid("{{]]]") << endl;
    cout << s.isValid("(") << endl;
    cout << s.isValid("])([") << endl;
    cout << s.isValid("[(])") << endl;
    cout << s.isValid("[()]") << endl;

    return 0;
}
