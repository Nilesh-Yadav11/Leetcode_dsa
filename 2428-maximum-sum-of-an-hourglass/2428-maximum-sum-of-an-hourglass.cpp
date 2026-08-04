class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int maxi=INT_MIN;
        for(int r=0;r<=grid.size()-3;r++){
            for(int c=0;c<=grid[0].size()-3;c++){
                int sum=(grid[r][c]+grid[r][c+1]+grid[r][c+2]+
                        grid[r+1][c+1]+grid[r+2][c]+grid[r+2][c+1]+
                        grid[r+2][c+2]);
                
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};