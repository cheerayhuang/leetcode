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
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std; 

class Solution {

public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        unordered_map<int, bool> min(s.size());                  

        for (string::size_type i = 0; i < s.size(); ++i) {
            string prefix = string(s, 0, i+1);
            if (dict.find(prefix) != dict.end()) {
                min[i] = true;
            }
            else {
                for(string::size_type j = 0; j < i; ++j) {
                    if (min[j] && dict.find(string(s, j+1, i-j)) != dict.end()) {
                        min[i] = true;    
                    }
                }
            }
        }
        
        return min[s.size()-1];
    }
};

int main() {

    Solution s;

    unordered_set<string> u {"he", "lo", "o" , "ell"};

    cout << s.wordBreak("hello", u) << endl;

    unordered_set<string> uu {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

    cout << s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", uu) << endl;
    
    return 0;
}

