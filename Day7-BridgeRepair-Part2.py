import math

with open('Day7-BridgeRepair.txt', 'r') as F:
    ans = 0
    for line in F:
        line = line.strip().split(':')
        n = int(line[0])
        a = list(map(int, line[1].strip().split()))
        f = set()
        g = set()
        for i in a:
            m = 10 ** ((0 if i == 0 else math.floor(math.log10(i))) + 1)
            if 0 == len(g):
                f.add(i)
            else:
                for j in g:
                    if i + j <= n:
                        f.add(i + j)
                    if i * j <= n:
                        f.add(i * j)
                    if j * m + i <= n:
                        f.add(j * m + i)
            g = f
            f = set()
        if n in g:
            ans += n
    print(ans)
