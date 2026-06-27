class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=0;
        int maxSum=INT16_MIN;

        int start=0;
        int end=0;
        int temp_start=0;


        for(int i=0;i<nums.size();i++){

            currSum=currSum+nums[i];
            
            if(currSum>maxSum){
                maxSum=currSum;
                start=temp_start;
                end=i;
            }

            // this is declared atlast because supposewe have an array like 
            // arr=[-1,-2,-3,-4,-5]
            // the currsum here will always be 0 but the maxSumwould be -ve here 
            // and every time the loop will end only as currSum<0

            if(currSum<0){
                currSum=0;
                temp_start=i+1;
            }
        }
        cout<<"The subarray ";
        for(int i=start;i<=end;i++){
            cout<<nums[i]<<" ";
        }
        cout<<" has the largest sum ";
        return maxSum;
        }
};