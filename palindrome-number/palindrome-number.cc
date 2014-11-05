#include <iostream> 
#include <string> 

using namespace std; 

class Solution {

public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        string reverse_str = string(str.rbegin(), str.rend());

        return str == reverse_str;
    }
};

int main() {

    Solution s;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(-121) << endl;
    cout << s.isPalindrome(0) << endl;
    cout << s.isPalindrome(1) << endl;

    return 0;
}
