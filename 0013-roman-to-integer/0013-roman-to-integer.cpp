class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            // kyuki jb pair banega toh do charchters ka sum ek number milega toh aage vale ko skip jb kernge toh index out 
            // of bound na ho jaaye isiliye i<s.size()-1 kiya gaya hai , aur i++ , pair vaali me kyuki fir next vali digit hum skip bhi toh kr dete 

            if(i<s.size()-1 && s[i]=='I' && s[i+1]=='V'){
                sum=sum+4;
                i++;
            }
            else if (i<s.size()-1 && s[i]=='I' && s[i+1]=='X'){
                sum=sum+9;
                i++;
            }
            else if (i<s.size()-1 && s[i]=='X' && s[i+1]=='L'){
                sum=sum+40;
                i++;
            }
            else if (i<s.size()-1 && s[i]=='X' && s[i+1]=='C'){
                sum=sum+90;
                i++;
            }
            else if (i<s.size()-1 && s[i]=='C' && s[i+1]=='D'){
                sum=sum+400;
                i++;
            }
            else if (i<s.size()-1 && s[i]=='C' && s[i+1]=='M'){
                sum=sum+900;
                i++;
            }
            else{
                switch (s[i]){
                
                case 'I':{
                    sum=sum+1;
                    break;
                }

                case 'V':{
                    sum=sum+5;
                    break;
                }

                case 'X':{
                    sum=sum+10;
                    break;
                }

                case 'L':{
                    sum=sum+50;
                    break;
                }

                case 'C':{
                    sum=sum+100;
                    break;
                }

                case 'D':{
                    sum=sum+500;
                    break;
                }

                case 'M':{
                    sum=sum+1000;
                    break;
                }
            }
            }
        }
        return sum;
    }
};