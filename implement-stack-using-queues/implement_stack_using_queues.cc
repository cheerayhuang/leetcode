/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: implement_stack_using_queues.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-04-2016 16:07:15
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <queue>

using namespace std;

class Stack {

private:
    queue<int> q_;

public:
    void push(int x) {


        queue<int> tmp_q;
        tmp_q.push(x);
        auto size = q_.size();

        for(int i = 0; i < size; ++i) {
            x = q_.front();
            q_.pop();
            tmp_q.push(x);
        }

        q_ = tmp_q;
    }

    void pop() {
        if (empty()) {
            cerr << "stack is empty!" << endl;
            return ;
        }
        q_.pop();
    }

    int top() {
        if (empty()) {
            cerr << "stack is empty!" << endl;
            exit(-1);
        }
        return q_.front();
    }

    bool empty() {
        return q_.empty();
    }
};

int main() {
    Stack s;

    for (int i = 0; i < 5; ++i)
        s.push(i);
    for (int i = 0; i < 5; ++i) {
        cout << s.top() << endl;
        s.pop();
    }

    cout << s.empty() << endl;
    cout << s.top() << endl;

    return 0;
}

