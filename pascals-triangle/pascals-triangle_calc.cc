#include <iostream> 
#include <vector>
#include <iterator>

using namespace std; 

class Solution {
private:
    vector<int> GenerateRow(int x) {
        vector<int> result{1};

        long long  numerator = 1;
        long long denominator = 1;
        
        for (auto i = 1; i <= x; ++i) {
            // optimize multiplying
            auto tmp_int = result[i-1];
            
            if (tmp_int % i == 0) {
                result.push_back(tmp_int / i * (x-i+1));
            }
            else if ((x-i+1) % i == 0) {
                result.push_back(tmp_int * ((x-i+1) / i));
            }
            else {
                result.push_back(tmp_int * (x-i+1) / i);
            }

            // use this way, can only work for "n = 20"
            /*numerator *= (x-i+1);
            denominator *= i;
            result.push_back(numerator / denominator);*/
        }

        return result;
    }
    
public:
    vector<vector<int> > generate(int numRows) {
       vector<vector<int> > result; 

       for(auto i = 0; i < numRows; ++i) {
           result.push_back(GenerateRow(i));
       }

       return result;
    }
};

int main() {
    Solution s; 
    ostream_iterator<int> os_iter(cout, " ");

    auto res = s.generate(31);
    for (auto &r : res) {
        copy(r.begin(), r.end(), os_iter);
        cout << endl;
    }
    return 0;
}
