class Solution {
public:
    bool rotateString(string A, string B) {
        if (A == B) return true;
        
        for (auto i = 0; i < A.length(); ++i) {
            auto part1 = A.substr(0, i);
            auto part2 = A.substr(i);
            if (part2 + part1 == B) {
                return true;
            }
        }
        
        //cout << part1 << endl;
        
        return false;
    }
};
