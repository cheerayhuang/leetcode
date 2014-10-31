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

public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<int> point(s.size());

        for (string::size_type i = 0; i < s.size(); ++i) {
            if (dict.find(string(s, 0, i+1)) != dict.end()) {
                ++point[i];
            }
            
            for(string::size_type j = 0; j < i; ++j) {
                if (point[j] > 0 && dict.find(string(s, j+1, i-j)) != dict.end()) {
                        point[i] += point[j];
                } 
            }
        }
        
        deque<string> result;
        deque<string> solution;
        if (!point[s.size()-1]) {
            return vector<string>();            
        }

        while(point[s.size()-1]) {
            int j = s.size()-1;
            while(j > 0) {
                auto i = j;
                for (; i > 0; --i) {
                    string str = string(s, i, j-i+1);
                    if (point[i-1] && dict.find(str) != dict.end()) {
                            result.push_front(str);
                            --point[j];
                            j = i-1;
                            break;
                    }
                }
                if (i == 0 && dict.find(string(s, i, j-i+1)) != dict.end()) {
                    --point[j];
                    result.push_front(string(s, i, j-i+1));
                    j = 0;
                }
            }

            string str; 
            for(auto &word : result) {
                str += word + " ";
            }
            solution.push_front(string(str.begin(), str.end()-1));
            result.clear();
        }

        return vector<string>(solution.begin(), solution.end());
    }
};

int main() {

    Solution s;

    unordered_set<string> u {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"}; 
    auto res =  s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", u); 

    /*unordered_set<string> u {"cat", "cats", "and", "sand", "dog"};
    auto res = s.wordBreak("catsanddog", u);*/

    for (auto & s : res) {
        cout << s << "|";
    }
    cout << endl;

    return 0;
}

