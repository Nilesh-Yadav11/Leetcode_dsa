class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n1=s1.size();
        int n2=s2.size();

        if(n1>n2){
            return false;
        }
        vector<int>freq_s1(26,0);
        vector<int>freq_s2(26,0);

        for(int i=0;i<n1;i++){
            freq_s1[s1[i]-'a']++;
            freq_s2[s2[i]-'a']++;
        }

        if(freq_s1==freq_s2){
            return true;
        }

        for(int i=n1;i<n2;i++){
            freq_s2[s2[i-n1]-'a']--;// removing
            freq_s2[s2[i]-'a']++;

            // checking
            if(freq_s1==freq_s2){
            return true;
        }
        }
        return false;
    }
};