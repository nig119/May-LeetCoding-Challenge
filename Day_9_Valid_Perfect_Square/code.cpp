class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num ==1) return true ;
        int e = 46340 ;
        int s = 1 ;
        while (s <= e){
            int mid = s + (e-s)/2 ;
            int mid2 = mid*mid ;
            if(mid2 == num) return true ;
            else if (mid2 > num) {
                e = mid-1 ;
            }else {
                s = mid+1 ;
            }
        }
        return false ;
    }
};