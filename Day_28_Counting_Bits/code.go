func countBits(num int) []int {
    out := make ([]int , num+1 )
    if num ==0 {
        return out;
    }
    out[1] = 1 ;
    for i:=2 ; i < num+1 ; i++ {
        if i%2 ==0 {
            out[i] = out[i/2]
        }else {
            out[i] = 1+ out[i-1]
        }
    }
    return out
}