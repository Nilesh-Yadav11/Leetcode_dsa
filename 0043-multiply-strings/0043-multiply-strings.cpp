class Solution {
public:
    string multiply(string num1, string num2) {
        
        bool isNegative=false;
        if(num1[0]=='-'){
            isNegative=!isNegative;
            num1=num1.substr(1); // ans me thodi -ve sign chahie , usme toh bss number chahiye 
        } // pehla number agr negtive hai toh bs ek hi baar negative me jayega 
        if(num2[0]=='-'){
            isNegative=!isNegative;
            num2=num2.substr(1); // ans me thodi -ve sign chahie , usme toh bss number chahiye 
        }
        // doosra number agr negtive hai toh, negative negative fir positive ho jayega 

        int n1=num1.length();
        int n2=num2.length();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        vector<int>result(n1+n2,0);

        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                result[i+j]+=(num1[i]-'0')*(num2[j]-'0'); // converting charachter to integer
                result[i+j+1]+=result[i+j]/10; // for carry doing /10 
                result[i+j]%=10; // for the digit , doing %10
            }
        }

        string ans="";
        bool zeroes=true;
        // as the number was reversed , so we would just track the result from back to remove the leading zeroes

        for(int i=result.size()-1;i>=0;i--){
            if(result[i]!=0){
                zeroes=false;
            }
            if(zeroes==false){
                ans=ans+char(result[i]+'0'); // vaapis string me laane ke liye + '0' kiya gaya 
            }
        }
        if(ans.empty()){
            return "0";
        }
        if(isNegative){
            ans="-"+ans;
        }
        return ans;
    }
};