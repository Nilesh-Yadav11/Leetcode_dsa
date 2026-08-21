class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double n=nums.size();

        double avg=0;
        double sum=0;
        for(double i=0;i<k;i++){
            sum=sum+nums[i];
            avg=sum/k;
        }

        double ans=avg;
        for(double i=k;i<n;i++){
            sum=sum-nums[i-k];
            sum=sum+nums[i];
            avg=sum/k;

            ans=max(ans,avg);
        }

        return ans;
    }
};