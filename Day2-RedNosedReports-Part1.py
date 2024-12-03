import numpy as np

with open('Day2-RedNosedReports.txt', 'r') as f:
    ans = 0
    for line in f:
        a = np.array(list(map(int, line.strip().split())))
        d = a[1:] - a[:-1]
        if (np.all(1 <= d) and np.all(d <= 3)) or (np.all(-3 <= d) and np.all(d <= -1)):
            ans += 1
    print(ans)
