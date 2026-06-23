class Solution {
public:
    bool checkValidString(string s) {
        stack <char>ch1,ch2_star;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                ch1.push(i);
            }
            else if(s[i]=='*'){
                ch2_star.push(i);
            }

            else{ // )
                if(!ch1.empty()){
                    ch1.pop();
                }
                else if(!ch2_star.empty()){
                    ch2_star.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!ch1.empty() && !ch2_star.empty()){
            if(ch1.top()>ch2_star.top()){
                return false;
            }

            ch1.pop();
            ch2_star.pop();
        }
    return ch1.empty();
    }
};