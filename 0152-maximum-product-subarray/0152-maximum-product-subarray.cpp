class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Brute force 
        // int n=nums.size();
        // long long ans= LLONG_MIN;

        // for(int i=0;i<n;i++){
        //     long long curr=1;
        //     for(int j=i;j<n;j++){
        //         curr=curr*nums[j];
        //         ans=max(ans,curr);
        //     }
        // }
        // return ans; // tle exceed for [1,0,-5,2,3,-8,-9]

        // Optimal 
        int n=nums.size();
        int maxi=nums[0];
        int mini=nums[0];
        int result=nums[0];

        for(int i=1;i<n;i++){
            if(nums[i]<0){
                swap(maxi,mini);
            }
            maxi=max(nums[i],maxi*nums[i]);
            mini=min(nums[i],mini*nums[i]);

            result=max(result,maxi);
        }
        return result;
    }
};