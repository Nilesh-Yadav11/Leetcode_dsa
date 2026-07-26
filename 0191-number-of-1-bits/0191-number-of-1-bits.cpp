class Solution {
public:
    // string decimal_to_binary(int n){
    //     if(n==0){
    //         return "0";
    //     }
    //     string res="";
    //     while(n>0){
    //         if(n%2==1){
    //             res=res+"1";
    //         }
    //         else{
    //             res=res+"0";
    //         }
    //         n=n/2;
    //     }
    //     reverse(res.begin(),res.end());
    //     return res;
    // }
    int hammingWeight(int n) {
        
        // string s=decimal_to_binary(n);
        // int count=0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='1'){
        //         count++;
        //     }
        // }
        // return count;

        int count=0;
        for(int i=0;i<32;i++){
            
            if((n&(1<<i))!=0){
                count++;
            }
        }
        return count;
    }
};