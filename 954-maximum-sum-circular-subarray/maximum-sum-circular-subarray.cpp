class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int best=nums[0];
        int ans=nums[0];
        int worst=nums[0];
        int sum=nums[0];
        int minans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int a=nums[i];
            int b=nums[i]+best;
            int c=nums[i]+worst;
            
            worst=min(a,c);
            best=max(a,b);
            ans=max(ans,best);
            sum=sum+nums[i];
            minans=min(worst,minans);
            

        }
        if(ans<0)
        {
            return ans;

        }
        return max(ans,sum-minans);
        
    }
};