def solution(A, B):
    A.sort()
    B.sort()
    
    set_A = set(A)
    set_B = set(B)
    
    gold = len(A) // 2
    silver = len(B) // 2
    
    res = 0
    
    for candy in set_A:
        if candy not in set_B and gold > 0:
            res += 1
            gold -= 1
    
    for candy in set_B:
        if candy not in set_A and silver > 0:
            res += 1
            silver -= 1
    
    common = set_A & set_B
    # print("Common: ",common)
    for candy in common:
        if gold > 0:
            res += 1
            gold -= 1
        elif silver > 0:
            res += 1
            silver -= 1
    
    return res


A1 = [1, 2, 3, 4]
B1 = [3, 3, 3, 7]
print(solution(A1, B1))  # Output: 4

A2 = [2, 2, 2, 2, 2, 2]
B2 = [7, 4, 2, 5, 1, 2]
print(solution(A2, B2))  # Output: 4