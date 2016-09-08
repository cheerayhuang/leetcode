/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: add_digits.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-08-2016 11:16:53
 * @version $Revision$
 *
 **************************************************************************/

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num-1)%9;
    }
};

