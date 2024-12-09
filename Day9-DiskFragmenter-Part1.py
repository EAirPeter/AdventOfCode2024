with open('Day9-DiskFragmenter.txt', 'r') as f:
    A = f.read().strip()
    A = map(lambda tp: [(tp[0] // 2 if 0 == tp[0] % 2 else -1) for _ in range(int(tp[1]))], enumerate(A))
    A = [i for l in A for i in l]
    i = 0
    j = len(A) - 1
    while i < j:
        while i < j and -1 != A[i]:
            i += 1
        while i < j and -1 == A[j]:
            j -= 1
        A[i], A[j] = A[j], A[i]
    ans = sum(map(lambda tp: tp[0] * tp[1] if -1 != tp[1] else 0, enumerate(A)))
    print(ans)
