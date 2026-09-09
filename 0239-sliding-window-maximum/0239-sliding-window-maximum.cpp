class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n=nums.size();
        deque<int>dq;
        vector<int>res;

        // first window  O(k)
        for(int i=0;i<k;i++){
            while(dq.size()>0 && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]); // first window ka max 

        // other windows O(n-k)
        for(int i=k;i<n;i++){
            // ab dekhna hai ki current window ka part hai ki nahi koi element 

            while(dq.size()>0 && dq.front()<=i-k){
                dq.pop_front();
            }

            // yha pr bhi upar jaise check krenge 
            while(dq.size()>0 && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            // last window ke liye 
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

// total O(n)