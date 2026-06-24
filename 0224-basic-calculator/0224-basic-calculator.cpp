class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        long long number=0;
        long long result=0;
        long long sign=1;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                number=number*10+(s[i]-'0'); // number bnn gaya
            }
            else if(s[i]=='+'){
                result+=(number*sign);
                number=0;
                sign=1;
            }
            else if(s[i]=='-'){
                result+=(number*sign);
                number=0;
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result=0;
                number=0;
                sign=1;
            }
            else if(s[i]==')'){
                result+=(number*sign);
                number=0;

                int stack_ka_sign=st.top();
                st.pop();

                int stack_ka_numberorlastresult=st.top();
                st.pop();

                result*=stack_ka_sign;
                result+=stack_ka_numberorlastresult;
                 
            }
        }
        result+=(number*sign);
        return result;
    }
};