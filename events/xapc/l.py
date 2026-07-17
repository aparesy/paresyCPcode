import queue

t = [int(x) for x in input().split()]
(m,n) = (t[0],t[1])

tab = []
for i in range(m):
    t = [int(x) for x in input().split()]
    tab.append(t)


# print((n,m))

def dfs(h):
    # print((m,n))
    # print(tab[m-1][n-1])
    vu = [[(tab[j][i]<h) for i in range(n)] for j in range(m)]
    # print(vu)
    if vu[m-1][n-1] or vu[0][0]:
        return False
    vu[0][0]=True
    q = queue.Queue()
    q.put((0,0))
    while q.qsize():
        (a,b) = q.get()
        if a==m-1 and b==n-1:
            return True 
        # print((a,b))
        if a and not vu[a-1][b]:
            vu[a-1][b]=True
            q.put((a-1,b))
        if b and not vu[a][b-1]:
            vu[a][b-1]=True
            q.put((a,b-1))
        if a<m-1 and not vu[a+1][b]:
            vu[a+1][b]=True
            q.put((a+1,b))
        if b<n-1 and not vu[a][b+1]:
            vu[a][b+1]=True
            q.put((a,b+1))
    return vu[m-1][n-1]


l=0
r=10**9+1
while r-l>1:
    mm = (r+l)//2
    if not dfs(mm):
        r=mm
    else:
        l=mm
print(l)