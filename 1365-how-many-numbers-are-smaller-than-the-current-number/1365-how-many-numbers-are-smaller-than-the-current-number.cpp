class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        // Brute
        // int n=nums.size();
        // vector<int>ans(nums.size());
        // for(int i=0;i<nums.size();i++){
        //     int count=0;
        //     for(int j=0;j<nums.size();j++){
        //         if(nums[i]>nums[j]){
        //             count++;
        //         }
        //     }
        //     ans[i]=count;
        // }
        // return ans;

        // Optimal

        // [8,1,2,2,3]

        // sorting -> 1 2 2 3 8 temp vector 
        // now map for storing first occurence only ; like 1=0;2=1;3=3;8=4
        // see that ans is their first occurence only 

        // vector<int>temp=nums;

        // sort(temp.begin(),temp.end());
        // unordered_map<int,int>mpp;
        
        // for(int i=0;i<nums.size();i++){
        //     if(!mpp.count(temp[i])){
        //         mpp[temp[i]]=i;
        //     }
        // }
        // vector<int>ans;
        // for(int x:nums){
        //     ans.push_back(mpp[x]);
        // }

        // return ans; 

        // O(nlog n)

        // best-> as the numbers are upto 100 only 

        vector<int>freq(101,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
         //prefix sum
        for(int i=1;i<=100;i++){
            freq[i]=freq[i]+freq[i-1];
        }
        vector<int>ans;
        for(int x:nums){
           if(x==0){
               ans.push_back(0);
           }
           else{
               ans.push_back(freq[x-1]);
           }
        }
        return ans;
    }
};