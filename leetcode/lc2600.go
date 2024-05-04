//problem: https://leetcode.com/problems/k-items-with-the-maximum-sum/
func kItemsWithMaximumSum(numOnes int, numZeros int, numNegOnes int, k int) int {
    sum := 0
    m := int(math.Min(float64(numOnes),float64(k)))
    sum += m
    numOnes -= m
    k -= m

    if k>0 {
        m := int(math.Min(float64(k),float64(numZeros)))
        k -= m
        numZeros -= m
    }

    if k>0 {
        m := int(math.Min(float64(k),float64(numNegOnes)))
        k -= m
        numNegOnes -= m
        sum -= m
    }

    return sum
}
