func checkInclusion(s1 string, s2 string) bool {
    arr1 := make([]int,26)
    for i:=0 ; i < len(s1) ; i++ {
        arr1[s1[i]-'a'] +=1
    }
    arr2 := make([]int,26)
    comp := func (arr1 []int, arr2 []int) bool {
        for i:=0;i<len(arr1) ;i++{
            if arr1[i] != arr2[i] {
                return false
            }
        }
        return true
    }
    for i :=0 ;i < len(s2) ; i++ {
        arr2[s2[i]-'a'] +=1
        j := i-len(s1)
        if j>= 0 {
            arr2[s2[j]-'a'] -=1
        }
        if comp(arr1,arr2) {
            return true
        }
    }
    return false
}
