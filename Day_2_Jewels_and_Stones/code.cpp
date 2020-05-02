class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<bool> map(52 , false);
        for(auto c : J){
            int k = (int) c ;  // a-z 97-122 , A-Z 65-90
            if(k<95){
                map[k-65]= true;        // A-Z
            } else {
                map[k-97+26]= true;     // a-z
            }
        }
        int out = 0 ;
        for(auto c : S){
            int k = (int)c;
            if(k<95){
                out += (map[k-65])?1:0 ;
            }else {
                out += (map[k-97+26])?1:0 ;
            }
        }
        return out ;
    }
};