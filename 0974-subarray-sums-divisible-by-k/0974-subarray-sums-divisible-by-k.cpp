class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

    //   m1  
        // int n=nums.size();
        // int count=0;

        // for(int i=0;i<nums.size();i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum=sum+nums[j];

        //         int remainder=sum%k;
        //         // for the negative numbers
        //         if(remainder<0){
        //             remainder=remainder+k;
        //         }
        //         if(remainder==0){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        // m2 ->O(n)

        // [4,5,0,-2,-3,1] ; let s1 be till -2 
        // and s2 till 0 , s1 and s2 are of form s1=k*n1+x
        // s2=k*n2+x , both having same remainder then s1-s2 would definiely be divisible by k , we would use map in order to store all of the prv remainders , and then update the frequencies of those which are divisible by k 

        int n=nums.size();
        int sum=0;
        unordered_map<int,int>mpp;
        mpp[0]=1; //as 0 would be divisible by all numbers whatever k is
        int result=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];

            int remainder=sum%k;
            if(remainder<0){
                remainder+=k;
            }
            if(mpp.find(remainder)!=mpp.end()){// matlabmap mein phle humne kahi dekha hai 
                result=result+mpp[remainder];
            }
            mpp[remainder]++;
        } 
        return result;
    }
};