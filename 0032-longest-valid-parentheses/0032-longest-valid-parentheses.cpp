class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int>st;
        st.push(-1);
        int n=s.length();
        int maxi=0;
        for(int i=0;i<n;i++){
            char ch=s[i];

            if(ch=='('){
                st.push(i); // index ko kr rhe instead of char
            }
            else{// ")"
                st.pop(); // for removing -1 or ( which would be unmatched

                if(st.empty()){

                    st.push(i); // storing the index ; agr khaali ho fir bhi ye ek new boundary bnegi 
                }
                else{
                    int length=i-st.top();
                    maxi=max(maxi,length);
                }
            }
        }
        return maxi;
    }
};