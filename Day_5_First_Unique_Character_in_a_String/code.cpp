class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> arr(128,-2);
        for( int i = 0 ; i < s.length() ; i++){
            int c = (int) s[i] ;
            if(arr[c] == -2){
                arr[c] = i ;
            }else if (arr[c] == -3 ){

            }else {
                arr[c] = -3 ;
            }
        }

        int out = INT_MAX ;
        for(auto i : arr){
            if(i != -2 && i != -3){
                out = min (out, i);
            }
        }
        if(out == INT_MAX){
            return -1 ;
        }
        return out ;
    }
};
