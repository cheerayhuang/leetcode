/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: base_ball.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 10-13-2017 14:53:03
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <deque>

using namespace std;

class Solution {
    public:

    int calPoints(vector<string>& ops) {
        vector<int> valid_num;
        int sum = 0;

        unordered_set<string> symbols {"D", "+", "C"};
        deque<int> q;

        for (auto op : ops) {
            if (symbols.find(op) != symbols.end()) {
            //if (symbols.count(op) != 0) {
                switch (op[0]) {

                case 'D':
                    if (q.size() == 0) break;
                    sum += q.back() * 2;
                    q.push_back(q.back()*2);
                    break;

                case '+':
                    {
                    if (q.size() < 2) break;
                    auto s = q.size();
                    auto v = q[s-1] + q[s-2];
                    sum += v;
                    q.push_back(v);
                    break;
                    }

                case 'C':
                    {
                    if (q.size() == 0) break;
                    sum -= q.back();
                    q.pop_back();
                    }
                }

                continue;
            }

            sum += stoi(op);
            q.push_back(stoi(op));
        }

        return sum;
    }
};

int main() {
    Solution s;
    vector<string> v1 {"5", "+"};
    cout << s.calPoints(v1) << endl;  // 5

    v1.assign({"5", "2", "+"});
    cout << s.calPoints(v1) << endl;  // 14

    v1.assign({"5","2","C","D","+"}); // 30
    cout << s.calPoints(v1) << endl;

    v1.assign({"5", "2", "D"});  // 11
    cout << s.calPoints(v1) << endl;

    v1.assign({"5", "D"}); // 15
    cout << s.calPoints(v1) << endl;

    v1.assign({"+", "5"}); // 5
    cout << s.calPoints(v1) << endl;

    v1.assign({"D", "5"});
    cout << s.calPoints(v1) << endl;

    v1.assign({"C", "5"});
    cout << s.calPoints(v1) << endl;

    v1.assign({"5", "C"});
    cout << s.calPoints(v1) << endl;

    v1.assign({"C"});
    cout << s.calPoints(v1) << endl;

    return 0;
}
