# The key to the solution is to note that any four consecutive turns of the form 4k+1, 4k+2, 4k+3, 4k+4 the robot will shift to the vector (-2,-2). 
# So, the moves sequence can be represented as [1 2 3 4] [5 6 7 8] ... [4k+1 4k+2 4k+3 4k+4] ... N-1 N, where every four will add (-2,-2) to the answer and no more than 3 turns will don't belong to any four. 
# But they can be processed manually.

t = input()
for _ in range(t):
    n = input()
    if (n%4 == 0):
        print (n/-2),(n/-2)
    elif n%4 == 1:
        print n/2 + 1,(n-1)/-2
    elif n%4 == 2:
        print (n-1)/2 + 1, (n+2)/2
    elif n%4 == 3:
        print (n+1)/-2, (n+1)/2