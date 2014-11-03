#include <iostream>
#include <vector> 

using namespace std; 

class Solution {
private:
    vector<int> board;
    vector<bool> column;
    int total;

    bool CheckDiagonal(int x, int y) {
        for (auto i = 0; i < x; ++i) {
            if (x-i == abs(y - board[i])) {
                return false;
            }
        }

        return true;
    }

    int PlaceChess(int step, int n) {
        if (step == n) {
            ++total; 
            return 0; 
        }

        for (auto i = 0; i < n; ++i) {
           if (column[i] && CheckDiagonal(step, i)) {
               column[i] = false;  
               board.push_back(i); 
               PlaceChess(step+1, n);
               board.pop_back();
               column[i] = true;
           }
        }
    }

public:
    int totalNQueens(int n) {
        board.clear(); 
        column.assign(n, true);
        total = 0;
        PlaceChess(0, n);

        return total;
    }
};

int main() {
    Solution s;

    cout << s.totalNQueens(8) << endl;
    cout << s.totalNQueens(1) << endl;
    cout << s.totalNQueens(4) << endl;

    return 0;
}
