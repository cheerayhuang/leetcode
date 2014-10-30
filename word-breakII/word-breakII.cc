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
        vector<vector<int> > f(s.size());
        vector<int> point(s.size(), -1);

        for (string::size_type i = 0; i < s.size(); ++i) {
            string prefix = string(s, 0, i+1);
            if (dict.find(prefix) != dict.end()) {
                f[i].push_back(-1);
                ++point[i];
            }
            
            for(string::size_type j = 0; j < i; ++j) {
                if (point[j] >= 0 && dict.find(string(s, j+1, i-j)) != dict.end()) {
                        for (int k = 0; k <= point[j]; ++k) {
                           f[i].push_back(j);
                        }
                        point[i] += point[j]+1;
                } 
            }
        }
        
        /*cout << "point: ";
        for(auto &i : point) {
            cout << i << " ";
        }
        cout << endl;

        for(auto &i : f) {
            cout << "f: ";
            for (auto &j : i) {
                cout << j << " ";
            }
            cout << endl;
        }*/    

        deque<string> solution;
        int end = s.size()-1;
            
        while (point[end] >= 0) {
            deque<string> result;

            auto i = f[end][point[end]];
            auto j = end;
            while (true) {
                result.push_front(string(s, i+1, j-i));  
                --point[j]; 
                j = i; 
                if (j == -1) break;
                i = f[j][point[j]];
            }

            string tmp_str;
            for(auto &str : result) {
                tmp_str += str + " ";                    
            }
            solution.push_front(string(tmp_str.begin(), tmp_str.end()-1));
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

