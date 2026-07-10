class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // unordered_map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     if(mp.count(nums[i])&& (i-mp[nums[i]]<=k)){
        //         return true;
        //     }
        //     mp[nums[i]]=i;
        // }
        // return false;
        unordered_set<int>window;
        for(int i =0;i<nums.size();i++)
        {
            if(window.count(nums[i]))
                return true;

            window.insert(nums[i]);
            if(window.size()>k){
                window.erase(nums[i-k]);
            }
        }
        return false;
    }
};