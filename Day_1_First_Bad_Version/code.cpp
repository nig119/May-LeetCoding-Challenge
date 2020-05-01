// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 0 ;
        int e = n-1 ;
        int m = (e-s)/2 + s ;
        while(s<e){
            // cout << s << " " << e << " "<< m << "\n" ;
            if(isBadVersion(m+1)){
                e = m ;
            }else {
                s = m+1 ;
            }
            m = (e-s)/2 + s ;
        }
        return m+1 ;
    }
};