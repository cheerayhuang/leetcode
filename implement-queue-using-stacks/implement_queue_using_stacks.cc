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
#include <stack>

using namespace std;

class Queue {

private:
    stack<int> s_;

public:
    void push(int x) {
        stack<int> tmp_s;
        auto size = s_.size();

        for(int i = 0; i < size; ++i) {
            tmp_s.push(s_.top());
            s_.pop();
        }
        s_.push(x);

        for (int i = 0; i < size; ++i) {
            s_.push(tmp_s.top());
            tmp_s.pop();
        }

    }

    void pop() {
        if (empty()) {
            cerr << "Queue is empty!" << endl;
            return ;
        }
        s_.pop();
    }

    int peek() {
        if (empty()) {
            cerr << "Queue is empty!" << endl;
            exit(-1);
        }
        return s_.top();
    }

    bool empty() {
        return s_.empty();
    }
};

int main() {
    Queue q;

    for (int i = 0; i < 5; ++i)
        q.push(i);
    for (int i = 0; i < 5; ++i) {
        cout << q.peek() << endl;
        q.pop();
    }

    cout << q.empty() << endl;
    cout << q.peek() << endl;

    return 0;
}

