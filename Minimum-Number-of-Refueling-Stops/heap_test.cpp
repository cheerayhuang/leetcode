/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: heap_test.cpp
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 08-31-2018 15:53:19
 * @version $Revision$
 *
 **************************************************************************/

#include <vector>

#include "heap.hpp"



int main() {
    Heap h;

    vector<Stop*> s;

    for (auto i = 0; i < 10; ++i) {
        auto t = new Stop{i+1, i+1};
        s.push_back(t);

        h.Insert(t);
    }


    h.Print();

    vector<Stop*> r;

    h.HeapSort(r);
    for (auto i : r) {
        cout << i->index << endl;
    }

    return 0;
}
