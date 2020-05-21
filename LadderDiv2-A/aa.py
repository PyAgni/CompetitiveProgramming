def solution(x, y):
    # Your code here
    i,j,k = [0,0,0]
    x.sort()
    y.sort()
    while(i<len(x) and j<len(y)):
        if(x[i]<y[j]):
            return x[i]
            i+=1
            k+=1
        elif(y[j]<x[i]):
            return y[j]
            k+=1
            j+=1
        else:
            i+=1
            j+=1
    while(i<len(x)):
        return x[i]
        i+=1
        k+=1
    while(j<len(y)):
        return y[j]
        j+=1
        k+=1



# print(solution([14, 27, 1, 4, 2, 50, 3, 1], [2, 4, -4, 3, 1, 1, 14, 27, 50]))