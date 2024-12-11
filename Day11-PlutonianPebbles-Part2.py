f = dict()

def dfs(i, n):
    if 0 == n:
        return 1
    if (i, n) in f:
        return f[(i, n)]
    if 0 == i:
        return dfs(1, n - 1)
    s = str(i)
    ans = 0
    if len(s) % 2 == 0:
        ans += dfs(int(s[:len(s) // 2]), n - 1)
        ans += dfs(int(s[len(s) // 2:]), n - 1)
    else:
        ans += dfs(i * 2024, n - 1)
    f[(i, n)] = ans
    return ans

with open('Day11-PlutonianPebbles.txt') as fi:
    a = list(map(int, fi.read().strip().split()))
    ans = 0
    for v in a:
        ans += dfs(v, 75)
    print(ans)
