class Solution {
public:
    int findComplement(int num) {
        if(num ==0){
            return 1;
        }
        if(num==1){
            return 0;
        }
        // int bits=num.size(); // aise nhi pta krte kisi number ki length ko , digits%10 aur num/10 nhi use krr skte kyuki hum binary bits se khel rhe hai naaki number se 

        int temp=num;
        int bits=0;
        
        while(temp>0){
            bits++;
            temp/=2; //only 2 possibilities na 
        }
        unsigned stopper=(1U<<bits)-1; // U is for unsigned

        int result=num^stopper;
        return result;
    }
};