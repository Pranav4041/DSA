class Solution {
public:
    bool isPalindrome(string s) {
        string a;
        for(char r:s)
        {
            if(isalnum(r)){
                a += tolower(r);
            }
        }
        
        int left=0;
        int right=a.length()-1;
        while(left<right)
            {
                if(a[left]==a[right])
                {
                    left++;
                    right--;
                    continue;
                    
                }
                else{
                    return false;
                }
            }
        return true;
    }
};