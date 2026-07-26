class Solution {
public:
    int hammingDistance(int x, int y) {
        
        //  y <= 231 - 1, so i will go wfrom 0 to 30 only 
        int ans=x^y;
        int count=0;
        for(int i=0;i<31;i++){
            if ((ans&(1<<i)) !=0){
                count++;
            }
        }
        return count;
    }
};
// kiya ye hai ki different numbers ka xor kroge toh 1 ayega result me vhi logic apply kr kr , dono ko add kiya hai aur 1 bits ko bs gin liya hai , count aa gya 