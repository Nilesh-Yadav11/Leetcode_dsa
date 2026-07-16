class Solution {
public:
    int myAtoi(string s) {
        
        int i=0;
        int l=s.length();

        // ignoring the leading whitespaces 
        while(i<l && isspace(s[i])){
            // isspace ek inbulit fxn hai 
            i++; // agar aisa hai toh aage bdho 
        }

        //if no more charachters 
        if(i==l){
            return 0;
        }

        // for checking valid sign 

        bool negative=false;
        if(s[i]=='-'){
            negative=true;
            i++; // just move aage 
        } 
        else if(s[i]=='+'){
            // just aage badh jaao 
            i++;
        }
        else if(!isdigit(s[i])){
            return 0; 
        }
        // if no more charachters 
        if(i==l){
            return 0;
        }

        // skipping the leading zeroes 
        while(i<l &&  s[i]=='0'){
            i++; // jst move aage
        }

        if(i==l){
            return 0;
        }
        // checking if the value is within the limits

        // Int_max=2^31-1 (2147483647)
        // Int_min=-2^31   (-2147483648)


        // extracting numbers and giving an integer
        long long value=0;
        int max=INT_MAX/10;
        int min=INT_MIN/10;

        while(i<l && isdigit(s[i])){
            int digit=s[i]-'0';

            // checking if its in range or not 
            // overflow
            if(value>max){
                return INT_MAX;
            }
            else if(value==max && digit>7){
                return INT_MAX;
            }

            // underflow 
            if(value<min){
                return INT_MIN;
            }
            if(value==min && digit>8){
                return INT_MIN;
            }

            // yaha se number generation
            if(negative){
                value=value*10+(-digit);
            }
            else{
                value=value*10+(digit);
            }
            i++;
        }
        return value;
    }
};