#!/usr/bin/env python3

result = 0
num = pow(2, 1000)

for i in str(num):
    result += int(i)

print(result)
