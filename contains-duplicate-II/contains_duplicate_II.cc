class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k==0) return false;
        
        map<int, vector<int>::iterator> nums_pos;

        
        for (auto iter=nums.begin(); iter < nums.end(); ++iter) {
            if (nums_pos.count(*iter)) {
                if (iter-nums_pos[*iter] <= k) return true;
            }
            nums_pos[*iter] = iter;
            
        }
        
       
        return false;   
    }
};
