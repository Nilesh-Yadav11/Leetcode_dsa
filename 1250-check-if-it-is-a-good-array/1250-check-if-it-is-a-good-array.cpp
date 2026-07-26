class Solution {
public:

    int gcd(int a, int b){
        // another method of finding gcd 
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    bool isGoodArray(vector<int>& nums) {
        
        // we will use here bezouts identity or extended euclideans algorithm which says that ax+by=gcd(a,b) , and according to our prblm also we need ti find where ax+by=1 means we have to give gcd of two numbers like gcd(a,b)=1 means two numbers which are coprime to each other 

        int g=nums[0];
        for(int i=0;i<nums.size();i++){
            g=gcd(g,nums[i]);

            if(g==1){
                return true;
            }
        }
        if(g==1){
            return true;
        }
        else{
            return false;
        }
    }
};