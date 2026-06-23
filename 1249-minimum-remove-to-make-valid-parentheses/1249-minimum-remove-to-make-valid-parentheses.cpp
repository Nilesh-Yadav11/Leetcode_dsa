class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n =s.length();
        stack<int>st;
        unordered_set<int> remove_idx;

        for(int i=0;i<n;i++){
            char ch =s[i];
            if(ch=='('){
                st.push(i);
            }
            else if (ch ==')'){// ')'
                if(st.size()==0){
                    // matlab stack phle se hi empty thi ;
                    remove_idx.insert(i);
                }
                else{
                    st.pop(); // normal case like we used to do earlier
                }
            }
        }

        // case when there are only open brackets like ((((

        while(!st.empty()){
                remove_idx.insert(st.top()); // simply insert those elements in stack , as thery are not going to be paired up 
                st.pop();
            }

        string result ="";
        for(int i=0;i<n;i++){
            if(remove_idx.find(i)== remove_idx.end()){
                result.push_back(s[i]); // jaise ki jb stack me keval 1 element bach jaaye uss case mein  , like jb stack mein last mein 3 bach gya tha 
            }
        }
        return result;
    }
};