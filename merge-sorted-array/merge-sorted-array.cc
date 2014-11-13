#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        vector<int> a(A, A+m);
        a.insert(a.end(), B, B+n);
        sort(a.begin(), a.end());
        copy(a.begin(), a.end(), A);
    }
};

int main() {

    int a[20] = {1, 3, 5, 7, 9};
    int b[5] = {2, 4, 6, 8}; 

    Solution s; 

    s.merge(a, 5, b, 4);

    for(auto &i : a) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
