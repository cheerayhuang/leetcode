// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        
        unsigned int left = 1;
        unsigned int right = n;
        
        while (right - left > 1) {
            auto mid = (left + right) / 2;
            auto res = guess(mid);
            if (res == 0) return mid;
            if (res == -1) right = mid;
            if (res == 1) left = mid;
        }
        
        return (guess(left) == 0 ? left : right);
    }
};
