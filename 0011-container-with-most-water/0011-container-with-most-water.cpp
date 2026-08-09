class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // int n=height.size();
        // long long area=0;
        // for (int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int height_new=min(height[i],height[j]);
        //         int current_area=height_new*(j-i);

        //         area=max(area,current_area);
        //     }
        // }
        // return area; // TLE 

        int n=height.size();
        int i=0;
        int j=n-1;

        int ans=0;
        while(i<j){
            int height_new=min(height[i],height[j]);
            int width=(j-i);

            int area=height_new*width;
            ans=max(ans,area);

            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};