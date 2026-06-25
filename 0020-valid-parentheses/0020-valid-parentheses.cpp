class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='(' || ch== '['|| ch== '{'){
                st.push(ch);}
            else{
                if(st.size()==0){
                    return false;}
                else{
                    if(ch==')' && st.top()!='(') return false;
                    if(ch==']' && st.top()!='[') return false;
                    if(ch=='}' && st.top()!='{') return false;
                    st.pop();}}}
        if(st.size()>0){
            return false;}
        else{
            return true;}}};