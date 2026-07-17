n=int(input())

tab = [int(x) for x in input().split()]

tab.sort()

x=0

for i in range(n):
    x+=tab[2*i+1]-tab[2*i]
    
print(x)