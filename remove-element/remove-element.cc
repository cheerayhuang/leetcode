#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (A == nullptr || n == 0) {
            return 0;
        }

        auto a = A;
        auto j = 0;
        for(auto i = 0; i < n; ++i) {
            if (a[i] != elem) {
                swap(a[i], a[j]);
                ++j;
            }
        }
        return j;
    }
};

int main() {
    return 0;
}
