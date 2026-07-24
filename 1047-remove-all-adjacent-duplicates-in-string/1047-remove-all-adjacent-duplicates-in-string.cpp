class Solution {
public:
    string removeDuplicates(string s) {
        
        string unique="";
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(!st.empty() && s[i]==st.top()){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            unique.push_back(st.top());
            st.pop();
        }
        reverse(unique.begin(),unique.end());
        return unique;
    }
};