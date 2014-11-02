#include <iostream>
#include <vector> 
#include <string>

using namespace std; 

class Solution {
private:
    vector<int> board_;
    vector<bool> column_;
    vector<vector<string>> result_;
    int total_;

    bool CheckDiagonal(int x, int y) {
        for (auto i = 0; i < x; ++i) {
            if (x-i == abs(y - board_[i])) {
                return false;
            }
        }

        return true;
    }

    int PlaceChess(int step, int n) {
        if (step == n) {
            ++total_; 
            vector<string> res;
            for(auto i = 0; i < n; ++i) {
                res.push_back(string(board_[i], '.') + "Q" + string(n-board_[i]-1, '.'));     
            }
            result_.push_back(res);
            return 0;
        }

        for (auto i = 0; i < n; ++i) {
           if (column_[i] && CheckDiagonal(step, i)) {
               column_[i] = false;  
               board_.push_back(i); 
               PlaceChess(step+1, n);
               board_.pop_back();
               column_[i] = true;
           }
        }

        return 0;
    }

public:
    vector<vector<string> > SolveNQueen(int n) {
        board_.clear(); 
        column_.assign(n, true);
        total_ = 0;
        result_.clear();
        PlaceChess(0, n);

        return result_;
    }
};

int main() {
    Solution s;

    auto result = s.SolveNQueen(8);

    for(auto &i : result) {
        for (auto &j : i) {
            cout << j << endl;
        }
        cout << endl;
    }

    return 0;
}
