class Solution {
public:
    string reverseVowels(string s) {
        
        int i=0;
        int j=s.length()-1;
       
        string vowels="aeiouAEIOU";

        while(i<j){
            // npos-> no position 

            while(i<j && vowels.find(s[i])==string::npos){
                i++; // aage bdh chlo agar vowel na ho toh 
            }

            while(i<j && vowels.find(s[j])==string::npos){
                j--; // peeche bdh chlo agar vowel na ho toh 
            }

            if(i<j){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};