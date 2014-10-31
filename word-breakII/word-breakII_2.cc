/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: word-break.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-30-2014 13:14:58
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector> 
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std; 

class Solution {
private: 
    vector<string> result_;
    vector<string> s_;

    void Break(string s, unordered_set<string> &dict) {
        if (s.size() == 0) {
            string str;
            for (auto &word : result_) {
                s += word + " ";
            }
            s_.push_back(string(s.begin(), s.end()-1));
            return;
        }
        for (string::size_type i = 0; i < s.size(); ++i) {
            string prefix = string(s, 0, i+1); 
            if (dict.find(prefix) != dict.end()) {
                result_.push_back(prefix);        
                auto d = dict;
                d.erase(prefix);
                Break(string(s, i+1), d);  
                result_.pop_back();
            }
        }
    }

public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        result_.clear();
        s_.clear();

        Break(s, dict);

        return s_; 
    }
};

int main() {

    Solution s;

    /*unordered_set<string> u {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

    auto res =  s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", u); */

    /*unordered_set<string> u {"cat", "cats", "and", "sand", "dog"};
    auto res = s.wordBreak("catsanddog", u);*/

    /*unordered_set<string> u {"h", "cats", "and", "sand", "dog"};
    auto res = s.wordBreak("hh", u);*/

    unordered_set<string> u {"aaaa", "aa", "a"};
    auto res = s.wordBreak("aaaaaaa", u);

    for (auto & s : res) {
        cout << s << "|";
    }
    cout << endl;

    return 0;
}

