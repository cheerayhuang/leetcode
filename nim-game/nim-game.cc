/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: nim-game.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-06-2016 21:30:58
 * @version $Revision$
 *
 **************************************************************************/


class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
