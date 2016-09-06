/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: reverse_string.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-05-2016 19:41:52
 * @version $Revision$
 *
 **************************************************************************/

class Solution {
public:
    string reverseString(string s) {
        return string(s.rbegin(), s.rend());
    }
};

