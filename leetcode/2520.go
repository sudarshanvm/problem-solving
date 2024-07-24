// problem: https://leetcode.com/problems/count-the-digits-that-divide-a-number/
func countDigits(num int) int {
    s := strconv.Itoa(num)
    count := 0
    for _,v := range s {
        temp,_ := strconv.Atoi(string(v))
        // temp := int(v)
        if num % temp == 0 {
            count++
        }
    }
    return count
}
