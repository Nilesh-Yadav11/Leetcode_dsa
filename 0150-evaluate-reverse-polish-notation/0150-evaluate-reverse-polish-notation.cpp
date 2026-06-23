class Solution {
public:
    int operate_result(int a, int b, string sign){
        if(sign == "+"){
            return a + b;
        }
        if(sign == "-"){
            return b - a;
        }
        if(sign == "*"){
            return (long)a * (long)b;
        }
        if(sign == "/"){
            return b / a;
        }
        return -1;
    } 

    int evalRPN(vector<string>& tokens) {
        stack<int> st; // Fixed typo 'stcak'
        int n = tokens.size();
        
        for(int i = 0; i < n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

               
                int result = operate_result(a, b, tokens[i]);
                st.push(result);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};