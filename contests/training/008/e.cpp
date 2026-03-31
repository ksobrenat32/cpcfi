n = int(input())


resp=-1
mn=1
mx=1000
for _ in range(n):
    
    a,b,v = [x for x in input().split()]
    a=int(a)
    b=int(b)

    if v == "E":
        if (a+b)%2 != 0:
            print('*')
            exit()
        if resp!=-1 and (a+b)//2!=resp:
            print('*')
            exit()
        resp=(a+b)//2
    
    elif v == "A":
        
        if((a+b)%2==0):
            mx=min(mx,(a+b)//2-1)
        else:
            mx=min(mx,(a+b)//2)
    else:
        
        mn=max(mn,(a+b)//2+1)
        
if(mn>mx or (resp!=-1 and (resp<mn or resp>mx))):
    
    print('*') 
else:
    if resp!=-1:
        mn=mx=resp
    print(mn,mx,end=" ")
    
 