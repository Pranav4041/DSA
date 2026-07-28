class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int longest =0;
        if(st.size()==0)
        {
            return 0;
        }
        for(auto a :st){
            if(st.find(a-1)==st.end())
            {
                int current=a;
                int length=1;
                while(st.find(current+1)!=st.end())
                {
                    current++;
                    length++;
                }
                longest=max(longest,length);
            }  
        }
        return longest;
    }
};