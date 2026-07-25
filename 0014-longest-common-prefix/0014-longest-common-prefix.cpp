class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        //M1-> Vertical scanning
        // for(int i=0;i<strs[0].length();i++){
        //     char ch=strs[0][i];
        //     for(int j=1;j<strs.size();j++){
        //         if(i ==strs[j].length() || strs[j][i]!=ch){
        //             return strs[0].substr(0,i);
        //         }
        //     }
        // }
        // return strs[0];

        // M2-> Horizontal scanning 

        if(strs.empty()){
            return "";
        }
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++){
            while(strs[i].find(prefix)!=0){
                prefix.pop_back();

                if(prefix.empty()){
                    return "";
                }
            }
        }
        return prefix;
    }
};