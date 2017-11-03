# When we look at the problem a little closer, we can see a pattern that both players must follow in order to win.
# During each round of turns, Alice and Bob choose a number. This means that the sum (l+r) is always possible during each round. Whichever number Alice chooses, Bob can choose a new number to ensure the sum at the end of the round is (l+r). Now, let's find : k % (l+r)
# If it's 0, Bob wins.
# If it's <= r, then Alice wins.
# If it's > r, then Bob wins.

t = input()
for _ in xrange(t):
    l,r,k = map(int,raw_input().split())
    s = l+r
    rem = k%s
    b = "second"
    a = "first"
    if(rem==0):
        print b
    elif(rem<=r):
        print a
    else:
        print b