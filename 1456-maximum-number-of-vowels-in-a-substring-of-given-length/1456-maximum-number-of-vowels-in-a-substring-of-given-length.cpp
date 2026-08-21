class Solution {
public:
    int maxVowels(string s, int k) {
        
        int n=s.size();

        vector<char>vowels={'a','e','i','o','u'};
        int count=0;
        for(int i=0;i<k;i++){
            if(find(vowels.begin(),vowels.end(),s[i])!=vowels.end()){
                count++;
            }
        }

        int ans=count;
        for(int i=k;i<n;i++){

            // removing from starting 
            if(find(vowels.begin(),vowels.end(),s[i-k])!=vowels.end()){
                count--;
            }

            // adding at the end 
            if(find(vowels.begin(),vowels.end(),s[i])!=vowels.end()){
                count++;
            }

            ans=max(ans,count);
        }

        return ans;
    }
};