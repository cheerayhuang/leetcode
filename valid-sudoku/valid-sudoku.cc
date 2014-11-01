#include <iostream> 
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<string> column(9);
        vector<string> sub_region(9);

        for(vector<vector<char> > :: size_type i = 0; i < board.size(); ++i) {
            vector<bool> hash(10, true);
            for(vector<char> :: size_type j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                auto num = board[i][j] - 48;
                if (hash[num]) {
                    hash[num] = false;
                    column[j].push_back(num+48);
                    sub_region[(i/3)*3+j/3].push_back(num+48);
                }
                else {
                    return false;
                }
            }
        }

        for (vector<string> :: size_type i = 0; i < 9; ++i) {
            vector<bool> hash(10, true);
            for (string::size_type j = 0; j < column[i].size(); ++j){
                auto num = column[i][j] - 48;
                if (hash[num]) {
                    hash[num] = false;
                }
                else {
                    return false;
                }
            }
        }

        for (vector<string> :: size_type i = 0; i < 9; ++i) {
            vector<bool> hash(10, true);
            for (string::size_type j = 0; j < sub_region[i].size(); ++j){
                auto num = sub_region[i][j] - 48;
                if (hash[num]) {
                    hash[num] = false;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    vector<vector<char> > v {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
                             {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
                             {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
                             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                             {'.', '.', '2', '4', '1', '9', '.', '.', '5'},
                             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    vector<vector<char> > null_v {{'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
                             {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
                             {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
                             {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    Solution s;
    cout << s.isValidSudoku(v) << endl;

    cout << s.isValidSudoku(null_v) << endl;

    return 0;
}
