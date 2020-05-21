def solution(s):
    # Your code here
    ans = 0 
    for i in range(len(s)):
        if(s[i]=='>'):
            for j in range(i+1,len(s)):
                if(s[j]=='<'):
                    ans+=1
    return ans*2

print(solution("<<>><"))