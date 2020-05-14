func removeKdigits(num string, k int) string {
    if k==0 {
        return num
    }
    if k==len(num) {
        return "0"
    }
    var out string
    for i:=0;i<len(num);i++ {
        for len(out) >0 &&  k > 0 && out[len(out)-1] > num[i] {
            out = out[:len(out)-1]
            k--
        }
        out  += string(num[i])
    }
    for k!=0 {
        out = out[:len(out)-1]
        k--
    }
    j :=0
    for j!= len(out) && out[j]=='0'{
        j++
    }
    if len(out[j:]) == 0 {
        return "0"
    }
    return out[j:]
}
