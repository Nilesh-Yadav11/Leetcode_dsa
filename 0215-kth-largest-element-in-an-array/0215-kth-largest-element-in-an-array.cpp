class Solution {
public:

    int partition(vector<int>&nums,int L, int R){
        int i=L+1;
        int j=R;
        int pivot=nums[L];

        while(i<=j){
            if(pivot>nums[i] && nums[j]>pivot){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(i <= j && nums[i]>=pivot){
                i++;
            }
            if(i <= j && nums[j]<=pivot){
                j--;
            }
        }
        swap(nums[L],nums[j]);
        return j ; // pivot element jth index pr hi toh hoga 
    }
    int findKthLargest(vector<int>& nums, int k) {
        
    //     kth largest element , agr descending order mein krkr sort krenge toh 
    //     it would be nums[k-1];
         int n=nums.size();
         int L=0;
         int R=n-1;
         while(L<=R){

            int pivot_index=partition(nums,L,R);
            if(pivot_index==k-1){
            return nums[pivot_index];
            }
            else if(pivot_index>k-1){
            R=pivot_index-1;
         }
         else{
            L=pivot_index+1;
         }
        }
        return -1;
    }  
};