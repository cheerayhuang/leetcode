#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string tmp_str;
        remove_copy_if(s.begin(), s.end(), back_inserter(tmp_str), [](char ch) { if (ch > 'z' || ch < '0' || (ch < 'a' && ch > 'Z') || (ch < 'A' && ch >'9')) return true; return false; }); 

        //transform(tmp_str.begin(), tmp_str.end(), tmp_str.begin(), [](char ch) ->char { if (ch < 'a') return 'a' + (ch-'A'); return ch; });
        for_each(tmp_str.begin(), tmp_str.end(), [](char &ch) { if (ch < 'a') ch = 'a' + (ch-'A'); });

        string rev_tmp_str; 
        copy(tmp_str.crbegin(), tmp_str.crend(), inserter(rev_tmp_str, rev_tmp_str.end()));

        return tmp_str == rev_tmp_str;
    }
};

int main() {
    Solution s;

    cout << s.isPalindrome(":ababa:a") << endl;
    cout << s.isPalindrome("b") << endl;
    cout << s.isPalindrome("ab") << endl;
    cout << s.isPalindrome("") << endl;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << s.isPalindrome("race a car") << endl;
    cout << s.isPalindrome(", ,") << endl;
    cout << s.isPalindrome("a111 111a") << endl;
    cout << s.isPalindrome("1a2") << endl;
    
    return 0;
}
