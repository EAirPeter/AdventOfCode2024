import numpy as np

def is_good(a):
    d = a[1:] - a[:-1]
    return (np.all(1 <= d) and np.all(d <= 3)) or (np.all(-3 <= d) and np.all(d <= -1))

with open('Day2-RedNosedReports.txt', 'r') as f:
    ans = 0
    for line in f:
        a = np.array(list(map(int, line.strip().split())))
        if is_good(a):
            ans += 1
        else:
            n = len(a)
            for i in range(n):
                if is_good(np.delete(a, i)):
                    ans += 1
                    break
    print(ans)
