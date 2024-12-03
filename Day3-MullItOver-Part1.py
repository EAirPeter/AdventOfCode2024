import re

with open('Day3-MullItOver.txt', 'r') as f:
    ans = 0
    for m in re.findall(r'mul\((\d{1,3}),(\d{1,3})\)', f.read()):
        ans += int(m[0]) * int(m[1])
    print(ans)
