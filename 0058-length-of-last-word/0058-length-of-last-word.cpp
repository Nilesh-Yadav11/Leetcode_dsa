class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int counter=0;
        int i=n-1;
        while(i>=0 && s[i]==' '){
            i--; // empty space removed 
        }
        while(i>=0 && s[i]!=' '){
            counter++;
            i--;
        }
        return counter;
    }
};