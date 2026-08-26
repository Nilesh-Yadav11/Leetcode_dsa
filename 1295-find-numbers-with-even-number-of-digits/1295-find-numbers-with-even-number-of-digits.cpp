class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evendigitcount = 0;
        for (int i=0;i<nums.size();i++){
            int count = nums[i];
            int digit = 0;
            while (count > 0){
                digit++;
                count=count/10;
            }
            // digit will tell about how many digits will there be in a number of a string
            if(digit % 2 == 0){
                evendigitcount++;
            }
        }
        return evendigitcount;
    }
};