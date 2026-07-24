class Solution {
public:
    bool rotateString(string s, string goal) {

        // if(s==goal){
        //     return true;
        // }

        // for(int i=0;i<goal.size()-1;i++){
        //     if(goal[i]>goal[i+1]){
        //         reverse(goal.begin(),goal.begin()+i+1);
        //         reverse(goal.begin()+i+1,goal.end());
        //         reverse(goal.begin(),goal.end());
        //     }

        //     if(goal ==s){
        //         return true;
        //     }
        // }
        // return false; passed for 391  test cases , but failed for many

        return ((s.size()==goal.size()) && ((s+s).find(goal)!=string::npos));
    }
};