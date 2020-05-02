func numJewelsInStones(J string, S string) int {
    var arr = make([]bool, 52) 
    for _, c := range J {
        k := int(c)  // a-z 97-122 , A-Z 65-90
        if(k<95){
            arr[k-65]= true       // A-Z
        } else {
            arr[k-97+26]= true     // a-z
        }
    }
    out := 0 
    for _, c  := range S{
        k := int(c) 
        if(k<95){
            if arr[k-65] {
                out += 1 
            }
        }else {
            if arr[k-97+26] {
                out += 1 
            }
        }
    }
    return out 
}