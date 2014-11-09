#include <iostream> 

using namespace std; 

class Solution {
public:
    int sqrt(int x) {
        auto len = to_string(x).size();

        auto result_max = 0;
        auto result_min = 0;

        if (len % 2) {
            result_max = stoi("4" + string((len+1)/2-1, '0')); 
        } else {
            result_max = stoi("1" + string((len+1)/2, '0'));
        }

        auto result = 0; 
        do {
            result = (result_max + result_min) / 2;
            if (static_cast<unsigned>(result * result) > x) {
                result_max = result; 
            } else {
                result_min = result;
            }
        } while(result_max-result_min > 1);             

        if (result_max*result_max - x) {
            result = result_min;
        }
        else {
            result = result_max;
        }

        return result;
    }
};

int main() {
    Solution s;

    cout << s.sqrt(0) << endl;
    cout << s.sqrt(100) << endl;
    cout << s.sqrt(10) << endl;
    cout << s.sqrt(2) << endl;
    cout << s.sqrt(3) << endl;
    cout << s.sqrt(4) << endl;
    cout << s.sqrt(5) << endl;
    cout << s.sqrt(1000) << endl;
    cout << s.sqrt(10000) << endl;
    cout << s.sqrt(5000) << endl;
    cout << s.sqrt(2147395599) << endl;

    return 0;
}
