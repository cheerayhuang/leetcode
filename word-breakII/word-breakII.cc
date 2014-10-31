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

private:
    void Break(string s, vector<string> &dict) {
        if (s.size() == 0) {
            string str;
            for (auto &word : result_) {
                s += word + " ";
            }
            s_.push_back(string(s.begin(), s.end()-1));
            return;
        }
        for (vector<string>::size_type i = 0; i < dict.size(); ++i) {
            if (string(s, 0, dict[i].size()) == dict[i]) {
                result_.push_back(dict[i]);        
                Break(string(s, dict[i].size()), dict);  
                result_.pop_back();
            }
        }
    }

public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<int> point(s.size());
        struct Status{
            unordered_set<string>::size_type l;
            bool y;
            Status() = default;
        };
        vector<Status> has_solution(s.size());
        unordered_set<string>::size_type len_set = dict.size();

        for (string::size_type i = 0; i < s.size(); ++i) {
            if (dict.find(string(s, 0, i+1)) != dict.end()) {
                has_solution[i] = Status{1, true};
            }
            else {
                for(string::size_type j = 0; j < i; ++j) {
                    if (has_solution[j].y 
                        && has_solution[j].l+1 <= len_set
                        && dict.find(string(s, j+1, i-j)) != dict.end()) {

                        has_solution[i].y = true;
                        if (has_solution[i].l == 0 || (has_solution[i].l > has_solution[j].l+1)) {
                            has_solution[i].l = has_solution[j].l + 1;
                        }
                        if (i == s.size()-1) {
                            break;
                        }
                    } 
                }
            }
        }

        s_.clear();
        if (has_solution[s.size()-1].y) {
            result_.clear();
            vector<string> d(dict.begin(), dict.end());
            Break(s, d);
        }
        
        return s_;
    }
};

int main() {

    Solution s;

    unordered_set<string> u {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"}; 
    auto res =  s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", u);

    /*unordered_set<string> u {"cat", "cats", "and", "sand", "dog"};
    auto res = s.wordBreak("catsanddog", u);*/

    /*unordered_set<string> u {"a"};
    auto res = s.wordBreak("a", u);*/

    /*unordered_set<string> u {"aaaa", "aa", "a"};
    auto res = s.wordBreak("aaaaaaa", u);*/

    for (auto & s : res) {
        cout << s << "|";
    }
    cout << endl;
    
    return 0;
}

