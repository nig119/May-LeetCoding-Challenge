class Solution {
public:
    int findComplement(int num) {
        int k = num ;
        int pow = 1 ;
        while(k>0){
            k = k>>1 ;
            pow +=1 ;
        }
        int out = 1 ;
        if(pow == 32){
            out = INT_MAX ;
        }else {
            while(pow!=1){
                out *= 2 ;
                pow -=1 ;
            }
            out -= 1 ;
        }
        out -= num ;
        return out ;
    }
};
