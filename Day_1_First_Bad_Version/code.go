/** 
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad 
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

func firstBadVersion(n int) int {
    s := 0 
    e := n-1
    m := (e-s)/2 + s ;
    for s<e {
        if(isBadVersion(m+1)){
            e = m ;
        }else {
            s = m+1 ;
        }
        m = (e-s)/2 + s ;
    }
    return m+1 ;
}