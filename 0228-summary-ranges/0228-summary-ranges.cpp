class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        // observation -> b is decided by seeing the nums vector 
        // if nums[i+1] should have to be equal to nums[i]+1
        // then only we start from a and end till b 

        vector<string>new_vector;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            while(i+1<nums.size() &&nums[i+1]==nums[i]+1){
                i++;
            }
            int b=nums[i];

            if(a==b){
                new_vector.push_back(to_string(a));
            }
            else{
                new_vector.push_back(to_string(a)+"->"+to_string(b));
            }
        }
        return new_vector;
    }
};