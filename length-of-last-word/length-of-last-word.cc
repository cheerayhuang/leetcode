#include <iostream> 
#include <string> 

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string str(s);

        auto rbeg = str.find_last_not_of(' ');
        if (rbeg == string::npos) {
            return 0;
        }
        auto rend = str.find_last_of(' ', rbeg);
        if (rend == string::npos) {
            return rbeg+1;
        }

        return rbeg-rend;
    }
};

int main() {

    return 0;
}
