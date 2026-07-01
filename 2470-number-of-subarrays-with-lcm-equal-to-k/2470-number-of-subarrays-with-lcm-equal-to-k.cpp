class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            long long curr_lcm=nums[i];
            for(int j=i;j<n;j++){
                curr_lcm=lcm(curr_lcm,nums[j]);

                 if(curr_lcm>k){
                    break;
                }
                if(curr_lcm==k){
                    count++;
                 }
            }
        }
        return count;
    }
};