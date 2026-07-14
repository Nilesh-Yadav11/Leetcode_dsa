class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        vector<int> ans_final;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<grid[i].size();j++){
                ans_final.push_back(grid[i][j]);
            }
        }

        map<int,int>mpp;
        for(int i=0;i<ans_final.size();i++){
            mpp[ans_final[i]]++;
        }

        int repeated=0;
        for(auto it:mpp){
            if(it.second==2){
                repeated=it.first;
                ans.insert(ans.begin(),repeated);
            }
        }

        // actualSum = expectedSum - missing + repeated

        long long actual_sum=0;
        for( int nums:ans_final){
            actual_sum=actual_sum+nums;
        }

        int total_sum=n*n;
        long long expected_sum=1LL *(total_sum*(total_sum+1))/2;

        int missing=expected_sum-actual_sum+repeated;
        ans.push_back(missing);

        return ans;
    }
};