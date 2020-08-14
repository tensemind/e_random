import random

i = 10000000
t_sum = 0
for n in range(i):
    x = 0
    digits = 0
    while True:
        x+=random.random()
        digits+=1
        if x > 1:
            t_sum += digits
            break

print(t_sum / float(i))
