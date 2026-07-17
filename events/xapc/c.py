from math import sqrt

def is_square(x):
    return (int(sqrt(x))*(int(sqrt(x)))==x)

t = int(input())
for i in range(t):
    tab = input().split()
    h=int(tab[0])
    m=int(tab[1])
    tot = 0
    i = 0
    while i*i<m*h:
        a = (i*i)//m
        b = (i*i)%m
        x = 1
        while x<=m-1:
            x*=10
        if is_square(a*(x)+b):
            tot+=1
        i+=1
    print(tot)