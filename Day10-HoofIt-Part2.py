import numpy as np

def dfsx(A, f, cx, cy):
    if -1 != f[cx][cy]:
        return f[cx][cy]
    if A[cx][cy] == '9':
        f[cx][cy] = 1
        return 1
    ans = 0
    for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        ex, ey = cx + dx, cy + dy
        if 0 <= ex and ex < f.shape[0] and 0 <= ey and ey < f.shape[1] and int(A[cx][cy]) + 1 == int(A[ex][ey]):
            ans += dfsx(A, f, ex, ey)
    f[cx][cy] = ans
    return ans

def dfs(A, sx, sy):
    f = np.full((len(A), len(A[0])), -1, dtype=int)
    return dfsx(A, f, sx, sy)

with open("Day10-HoofIt.txt") as f:
    A = list(map(str.strip, f.readlines()))
    ans = 0
    for i in range(len(A)):
        for j in range(len(A[i])):
            if '0' == A[i][j]:
                ans += dfs(A, i, j)
    print(ans)
