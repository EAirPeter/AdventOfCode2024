with open('Day9-DiskFragmenter.txt', 'r') as f:
    A = f.read().strip()
    A = map(lambda tp: [tp[0] // 2 if 0 == tp[0] % 2 else -1, int(tp[1])], enumerate(A))
    A = list(filter(lambda tp: 0 != tp[1], A))
    k = max(map(lambda tp: tp[0], A))
    while k >= 0:
        j = next(filter(lambda tp: k == tp[1], enumerate(map(lambda tp: tp[0], A))))[0]
        for i in range(j):
            if -1 == A[i][0] and A[i][1] >= A[j][1]:
                n = A[j][1]
                A[j][0] = -1
                if j < len(A) - 1 and -1 == A[j + 1][0]:
                    A[j][1] += A[j + 1][1]
                    A.pop(j + 1)
                if 0 < j and -1 == A[j - 1][0]:
                    A[j][1] += A[j - 1][1]
                    A.pop(j - 1)
                r = A[i][1] - n
                A[i][0] = k
                A[i][1] = n
                if 0 != r:
                    A.insert(i + 1, [-1, r])
                break
        k -= 1
    ans = 0
    p = 0
    for i, n in A:
        if -1 != i:
            ans += (p + p + n - 1) * n // 2 * i
        p += n
    print(ans)
