class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> out (num+1 , 0) ;
        if (num == 0 )return out;
        out[1] = 1 ;
        for (int i = 2 ; i < num+1 ; i++){
            if (i%2 == 0){
                out[i] = out[i/2] ;
            }else {
                out[i] = out[i-1] +1 ;
            }
        }
        return out;
    }
};