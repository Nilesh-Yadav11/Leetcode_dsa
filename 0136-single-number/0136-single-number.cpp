class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();

    int xorr = 0; // variable xor is reserved in c++
    for(int i=0;i<n;i++){
        xorr = xorr^nums[i];
    }

    return xorr;
    }
};