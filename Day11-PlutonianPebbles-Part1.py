with open('Day11-PlutonianPebbles.txt') as fi:
    a = list(map(int, fi.read().strip().split()))
    for i in range(25):
        b = []
        for v in a:
            if 0 == v:
                b.append(1)
            else:
                s = str(v)
                if len(s) % 2 == 0:
                    b.append(int(s[:len(s) // 2]))
                    b.append(int(s[len(s) // 2:]))
                else:
                    b.append(v * 2024)
        a = b
    print(len(a))
