#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {

public:
    bool isIsomorphic(string pattern, string str) {
        //if (pattern.size() == 0 && str.size() == 0) return true;
        if (str.size() != pattern.size()) return false;

        map<char, char> dict;
        map<char, char> dict2;

        auto iter = str.begin();
        for(auto ch : pattern) {
            if ((dict.find(ch) == dict.end()) && (dict2.find(*iter) == dict2.end())) {
                dict[ch] = *iter;
                dict2[*iter] = ch;
                ++iter;
                continue;
            }

            if (dict.count(ch) && dict[ch] != *iter) return false;
            if (dict2.count(*iter) && dict2[*iter] != ch) return false;

            ++iter;
        }

        return true;
    }
};

int main() {
    Solution s;

    cout << s.wordPattern("title", "paper") << endl;
    cout << s.wordPattern("egg", "add") << endl;

    return 0;
}
