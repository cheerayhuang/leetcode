/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: student_attendance_record_i.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-30-2017 15:42:51
 * @version $Revision$
 *
 **************************************************************************/

class Solution {
    public:
        bool checkRecord(string s) {
            if (s == "") return true;
            auto count_a = 0;
            auto count_l = 0;
            for (auto c : s) {
                switch (c) {
                    case 'A':
                        ++count_a;
                        count_l = 0;
                        break;
                    case 'L':
                        ++count_l;
                        break;
                    default:
                        count_l = 0;
                }

                if (count_a > 1 || count_l > 2) return false;
            }

            return true;
        }
};

