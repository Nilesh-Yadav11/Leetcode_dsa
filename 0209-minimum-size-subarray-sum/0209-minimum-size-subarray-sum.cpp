class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        // varable size sliding window 

        int n=nums.size();
        int left=0;
        int sum=0;
        int ans=INT_MAX;

        for(int right=0;right<n;right++){
            sum=sum+nums[right];

            while(sum>=target){
                ans=min(ans,right-left+1);

                sum=sum-nums[left];
                left++;
            }
        }
            if(ans==INT_MAX){ // in the case of like when nums is[1,1,1] , in this case the ans would be 0 , so the ans initially would not change to INT_MAX , so we would have to return 0 only 
            return 0;
            }
        return ans;
    }
};