/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: generate_test.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-05-2014 10:43:50
 * @version $Revision$
 *
 **************************************************************************/

#include <fstream> 
#include <cstdlib> 
#include <ctime>
#include <string>

using namespace std; 

int main() {
    ofstream fout("1.txt");

    srand(time(nullptr));

    for(auto i = 0; i < 10; ++i) {
        string str;
        for (auto j = 0; j < 1000000; ++j) {
            str.push_back(rand() % 26 + 97);
        }

        fout << str << endl;
        auto pos = rand() % 1000000;
        if (pos > 990000) {
            fout << str.substr(pos) << endl;
        }
        else {
            fout << str.substr(pos, 10000) << endl;
        }
    }

    fout.close();

    return 0;
}

