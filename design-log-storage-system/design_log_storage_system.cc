/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: design_log_storage_system.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-02-2017 09:57:43
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class LogSystem {

private:
    map<string, vector<int>> day_;
    map<string, vector<int>> year_;
    map<string, vector<int>> month_;
    map<string, vector<int>> hour_;
    map<string, vector<int>> second_;
    map<string, vector<int>> min_;

    enum class Granularity_ {year, month, day, hour, min, second};


public:
    LogSystem() {

    }

    void put(int id, string timestamp) {
        auto p = 0;
        auto g = Granularity_::year;

        while (p != string::npos) {
            auto beg = 0;
            if (p != 0) beg = p + 1;
            p = timestamp.find(':', beg);
            auto num_str = timestamp.substr(0, p);

            switch(g) {
                case Granularity_::year:
                    year_[num_str].push_back(id);
                    break;

                case Granularity_::month:
                    month_[num_str].push_back(id);
                    break;

                case Granularity_::day:
                    day_[num_str].push_back(id);
                    break;

                case Granularity_::hour:
                    hour_[num_str].push_back(id);
                    break;

                case Granularity_::min:
                    min_[num_str].push_back(id);
                    break;

                case Granularity_::second:
                    second_[num_str].push_back(id);
                    break;

                default:
                    break;
            }
            g = static_cast<Granularity_>(static_cast<int>(g) + 1);
        }
    }

    string GetGranularityNum(string str, Granularity_ g) {
        auto end = static_cast<int>(g);
        auto p = 0;
        for (auto i = 0; i <= end; ++i) {
            p = str.find(':', p+1);
        }

        return str.substr(0, p);
    }

    map<string, vector<int>>& GetMap(Granularity_ g) {
        auto i = static_cast<int>(g);

        switch (i) {
            case 0:
                return year_;
            case 1:
                return month_;
            case 2:
                return day_;
            case 3:
                return hour_;
            case 4:
                return min_;
            case 5:
                return second_;
        }
    }

    vector<int> retrieve(string s, string e, string gra) {
        auto g = Granularity_::year;

        if (gra == "Month") g = Granularity_::month;
        if (gra == "Day") g = Granularity_::day;
        if (gra == "Hour") g = Granularity_::hour;
        if (gra == "Minute") g = Granularity_::min;
        if (gra == "Second") g = Granularity_::second;

        auto s_key = GetGranularityNum(s, g);
        auto e_key = GetGranularityNum(e, g);

        auto m = GetMap(g);

        vector<int> result;
        for(auto i = m.lower_bound(s_key); i != m.upper_bound(e_key); ++i) {
            result.insert(result.end(), (i->second).begin(), (i->second).end());
        }

        return result;
    }

    void PrintMaps() {

    }
};

int main() {
    LogSystem l;

    l.put(1, "2017:01:01:23:59:59");
    l.put(2, "2017:01:01:22:59:59");
    l.put(3, "2016:01:01:00:00:00");
    auto v = l.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year");

    for_each(v.begin(), v.end(), [](int i){ cout << i << ' ';});
    cout << endl;

    v = l.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour");
    for_each(v.begin(), v.end(), [](int i){ cout << i << ' ';});
    cout << endl;

    return 0;
}

