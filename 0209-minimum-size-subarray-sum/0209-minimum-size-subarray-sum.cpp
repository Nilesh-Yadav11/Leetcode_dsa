class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int sum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // Shrink the window from the left as long as the condition is met
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        // If ans was never updated, no valid subarray was found, return 0
        if(ans==INT_MAX){
            return 0;
        }
        else{
            return ans;
        }
    }
};