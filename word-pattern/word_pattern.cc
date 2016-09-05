#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {

private:

public:
    bool wordPattern(string pattern, string str) {
        if (pattern.size() == 0 && str.size() == 0) return true;
        if (pattern.size() == 0) return false;
        if (str.size() == 0) return false;

        map<string, string> dict;
        map<string, string> dict2;
        istringstream iss(str);

        vector<string> strings;
        string tmp_str;

        while(iss >> tmp_str) {
            strings.push_back(tmp_str);
        }
        if (strings.size() != pattern.size()) return false;

        auto iter = strings.begin();
        for(auto ch : pattern) {
            string tmp_str{ch};
            if ((dict.find(tmp_str) == dict.end()) && (dict2.find(*iter) == dict2.end())) {
                dict[tmp_str] = *iter;
                dict2[*iter] = tmp_str;
                ++iter;
                continue;
            }

            if (dict.count(tmp_str) && dict[tmp_str] != *iter) return false;
            if (dict2.count(*iter) && dict2[*iter] != tmp_str) return false;

            ++iter;
        }

        return true;
    }
};

int main() {
    Solution s;

    cout << s.wordPattern("abab", "cat dog cat dog") << endl;
    cout << s.wordPattern("abcd", "cat dog cat dog") << endl;
    cout << s.wordPattern("aaaa", "cat dog cat dog") << endl;
    cout << s.wordPattern("abc", "cat1 dog2 cat3 dog4") << endl;
    cout << s.wordPattern("abcd", "cat1 dog2 cat3 dog4") << endl;
    cout << s.wordPattern("abab", "dog dog dog dog") << endl;

    return 0;
}
