class Solution {
public:

    static bool cmp(vector<int>&a , vector<int>&b){
        return a[1]<b[1]; // for sorting in ascending order 
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();

        sort(intervals.begin(),intervals.end(),cmp); 
        // saare intervals end time ke hisaab se sort honge isse 
        //[[1,100],[11,22],[1,11],[2,12]] vrna ye wla pass na hota 

        int ansEnd=intervals[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(ansEnd>intervals[i][0]){
                count++;
            }
            else{
                // overlapping nahi hai jb 
                ansEnd=intervals[i][1];
            }
        }

        return count;
    }
};