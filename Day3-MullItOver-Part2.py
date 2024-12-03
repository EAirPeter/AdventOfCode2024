import re

with open('Day3-MullItOver.txt', 'r') as f:
    ans = 0
    enabled = True
    for m in re.findall(r'(do\(\))|(don\'t\(\))|mul\((\d{1,3}),(\d{1,3})\)', f.read()):
        if m[0]:
            enabled = True
        elif m[1]:
            enabled = False
        elif m[2] and m[3] and enabled:
            ans += int(m[2]) * int(m[3])
    print(ans)
