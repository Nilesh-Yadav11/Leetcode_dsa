class Solution {
    int lower_bound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();
        while (low <= high) {
            int mid = (low + (high - low) / 2);
            if (nums[mid] >= target) {
                ans=mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
int upper_bound(vector<int>&nums,int target){
    int low=0;
    int high=nums.size()-1;
    int ans1= nums.size();
    while(low<=high){
        int mid=(low+(high-low)/2);

        if(nums[mid]>target){
            ans1=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans1;  
}

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums, target);
        int last = upper_bound(nums, target);
        if (first==nums.size()|| nums[first]!=target) { 
            return {-1,-1};
        }
        return {first,last-1};
    }
};