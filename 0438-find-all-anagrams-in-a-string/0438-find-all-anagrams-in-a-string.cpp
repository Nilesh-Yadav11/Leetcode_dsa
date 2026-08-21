class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int n1=s.size();
        int n2=p.size();

        vector<int>ans;

        if(n2>n1){
            return ans;
        }

        vector<int>freq_s(26,0); // there are exactly 26 letters only , so the freq array would be of 26 only 
        vector<int>freq_p(26,0);

        // first window 
        for(int i=0;i<n2;i++){ // n2 would work as k as upto that size only we have to do the search
            freq_s[s[i]-'a']++;
            freq_p[p[i]-'a']++;
        }

        if(freq_s==freq_p){
            ans.push_back(0); // 0th index inserted , mtlb dono baraabar hi agye 
        }

        for(int i=n2;i<n1;i++){
            
            // removing
            freq_s[s[i-n2]-'a']--;

            // adding 
            freq_s[s[i]-'a']++;

            // checking and then inserting 
            if(freq_s==freq_p){
                ans.push_back(i-n2+1);
            }
        }

        return ans;
    }
};