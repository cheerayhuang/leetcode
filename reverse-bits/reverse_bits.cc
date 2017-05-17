/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: reverse_bits.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-17-2017 15:13:57
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <climits>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<uint32_t> power{1};

        auto k = 1;
        for (auto i = 1; i < 32; ++i) {
            k *= 2;
            power.push_back(k);
        }

        uint32_t res = 0;
        for (auto i = power.crbegin(); i != power.crend(); ++i) {
            res += (*i) * (n % 2);
            n = n / 2;
        }

        return res;
    }
};

class Test {
    public:
        const Test& operator()(int, int, bool) const;
};
const Test& Test::operator()(int, int, bool=true) const { return *this; }

int main() {

    Solution s;

    cout << bitset<32>(s.reverseBits(7)) << endl;
    cout <<  bitset<32>(s.reverseBits(43261596)) << endl;
    cout <<  s.reverseBits(43261596) << endl;
    cout <<  s.reverseBits(1) << endl;
    cout <<  s.reverseBits(2147483648) << endl;
    cout <<  s.reverseBits(4294967295) << endl;
    cout <<  s.reverseBits(0) << endl;
    cout <<  bitset<32>(43261596) << endl;

    Test t;

    t(5, 5, false);
    t(5, 5);
    return 0;
}
