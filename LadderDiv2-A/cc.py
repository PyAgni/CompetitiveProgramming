# def solve(n):
#     n = long(n)
#     dp = {1L:0,2L:1}
#     if n in dp:
#         return dp[n]
#     if n&1:
#         dp[n]=min(solve((n-1)>>1) +2,solve((n+1)>>1) +2)
#     else:
#         dp[n] = solve((n>>1))+1
    
#     return dp[n]
    


# def solution(n):
#     # Your code here
#     return solve(n)


# print solution(4)

def solution(n):
    # Your code here
    # return solve(n)
    n = long(n)
    ans =0
    while n!=1:
        if(n&1==0):
            n=n>>1
        elif ((n+1)&n)>((n-1)&(n-2)):
            n-=1
        elif n==3:
            n-=1
        else:
            n+=1
        ans+=1
    return ans

print solution("15")