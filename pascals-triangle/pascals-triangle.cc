#include <iostream> 
#include <vector>
#include <iterator>

using namespace std; 

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result; 

        for(auto i = 0; i < numRows; ++i) {
            if (i == 0) {
                result.push_back({1});
                continue;
            }

            if (i == 1) {
                result.push_back({1, 1});
                continue;
            }

            vector<int> row{1};
            for (auto j = 1; j < i; ++j) {
                row.push_back(result[i-1][j-1] + result[i-1][j]);
            }
            row.push_back(1);
            result.push_back(row);
        }

        return result;
    }
};

int main() {
    Solution s; 
    ostream_iterator<int> os_iter(cout, " ");

    auto res = s.generate(2);
    for (auto &r : res) {
        copy(r.begin(), r.end(), os_iter);
        cout << endl;
    }
    return 0;
}
