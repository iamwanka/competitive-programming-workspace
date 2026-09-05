from math import comb

def count_palindromes(n, x):
    if n % 2 == 0:
        if x % 2 != 0:
            return 0
        return comb(n // 2, x // 2)
    else:
        if x % 2 == 0:
            return comb(n // 2, x // 2)
        else:
            return comb(n // 2, (x - 1) // 2)

def solve(n, k):
    ans = 0
    for x in range(0, k // 2 + 1):
        if k - x > n: continue
        ans += comb(n, x) + comb(n, n - x)
        
    return ans

n, k = map(int, input().split())
print(solve(n, k))
