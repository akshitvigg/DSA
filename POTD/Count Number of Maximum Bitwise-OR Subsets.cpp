class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        
        int i,j,max_possible_or=0,n=nums.size(),ans=0;
        
       
        for(i=0;i<n;i++)
        {
            max_possible_or=nums[i]|max_possible_or;
        }
        
         
        
        
        for(i=1;i<(1<<n);i++)
        {
            int p=0;
            for(j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    p=p|nums[j];
                }
            }
           
			
            if(p==max_possible_or)
            {
                ans++;
            }
        }
        
        return ans;
        
    }
};
