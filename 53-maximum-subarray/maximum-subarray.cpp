class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int a =nums[i];
            int b=nums[i]+best;
            best=max(b,a);
            ans=max(best,ans);
        }
        return ans;
    }
};