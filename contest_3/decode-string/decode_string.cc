/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: decode_string.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-04-2016 21:23:13
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <stack>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
private:
    stack<char> char_stack_;

public:
    string decodeString(string s) {
        string res;
        for (auto ch : s) {
            if (ch != ']') {
                char_stack_.push(ch);
                continue;
            }

            string tmp_str;
            while (char_stack_.top() != '[') {
                tmp_str.insert(tmp_str.begin(), char_stack_.top());
                char_stack_.pop();
            }
            // pop '['
            char_stack_.pop();

            // pop numbers
            string str_times;
            while (!char_stack_.empty() && char_stack_.top() >= '0' && char_stack_.top() <= '9') {
                str_times.insert(0, 1, char_stack_.top());
                char_stack_.pop();
            }

            auto times = stoi(str_times);

            string tmp_res;
            for (auto i = 0; i < times; ++i) {
                tmp_res.append(tmp_str);
            }
            for (auto tmp_ch : tmp_res) char_stack_.push(tmp_ch);
        }

        while(!char_stack_.empty()) {
            res.insert(0, 1, char_stack_.top());
            char_stack_.pop();
        }

        return res;
    }
};

int main() {
    Solution s;

    cout << s.decodeString("3[a]2[bc]") << endl;
    cout << s.decodeString("3[a2[c]]") << endl;
    cout << s.decodeString("10[a2[c]]") << endl;

    return 0;
}

