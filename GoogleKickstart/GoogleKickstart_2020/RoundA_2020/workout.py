# N sessions
# ith session lasts Mi minutes, strictly increasing
# difficulty is max difference between any two consecutive workouts
# add K additional sessions to make it less difficult and find new least difficulty
# T number of test cases

def recursiveSolve(M,difficulty,K):
    if K==0:
        return M
    
    # add new workout session between highest difficulty
    maxDifficulty = max(difficulty)
    idx = difficulty.index(maxDifficulty)
    avg = int(maxDifficulty/2)
    M.insert(idx+1,int(M[idx]+avg))
    
    # find the new highest difficulty
    newDifficulty = []
    for i in range(len(M)-1):
        newDifficulty.append(M[i+1]-M[i])
    return recursiveSolve(M,newDifficulty,K-1)

T = int(input())
answers = []
for j in range(1,T+1):
    N, K = [int(x) for x in input().split()] # Number of sessions, extra sessions
    M = list(map(int,input().split())) # minutes of exercises

    # finding difficulties in plan
    difficulty = []
    for i in range(N-1):
        difficulty.append(M[i+1]-M[i])

    # getting new workout 
    M = recursiveSolve(M,difficulty,K)
    print(M)

    # finding new difficulties in plan
    newDifficulty = []
    for i in range(len(M)-1):
        newDifficulty.append(M[i+1]-M[i])
    
    y = max(newDifficulty)
    answers.append("Case #{}: {}".format(j,y))

for answer in answers:
    print(answer)

'''
Analysis
Test set 1
Since K=1, all that we need to do is to find the maximum difference and split it into 2 halves. For example, given a sequence [2, 12, 18] and K = 1, the difficulty is 10, since the maximum difference is in [2, 12]. The best way to minimize this is to take the maximum difference and split it in half giving us the final sequence of [2, 7, 12, 18]. The difficulty for this final sequence now is 6. The time complexity is O(N).

Test set 2
For this test case, we cannot perform such direct splits because repeatedly splitting the maximum difference into halves is not optimal. For example, given a sequence [2, 12] and K = 2, splitting into halves will result in [2, 12] → [2, 7, 12] → [2, 7, 9, 12]. This way, the difficulty would be 5. However, if we perform [2, 12] → [2, 5, 12] → [2, 5, 8, 12], the difficulty would be 4. This clearly demonstrates that continuous halving of the maximum difference is sub-optimal. Okay, so how do we do this?

Consider the i-th adjacent pair of training sessions with an initial difference di. If we want to insert some number of training sessions in between this pair such that the maximum difference among those is at most a certain value, let's say doptimal, then how many training sessions can be inserted in between? The answer to this is ceiling(di / doptimal)-1. Let's call that k'i. Doing this for all N-1 adjacent pairs in the given array would give us k'[1, ..., N-1]. Let's denote k'sum = k'1+k'2+ ....+k'N-1. From the constraints, we can insert at most K training sessions. Therefore, we need to make sure k'sum ≤ K while minimizing doptimal as much as possible.

If you observe, doptimal can lie anywhere between [1, max(di)] (1 ≤ i ≤ N-1). Linear search would be to check every value here starting from 1 and output the first value that satisfies the above condition. A quicker way to do this is using binary search. On closer observation, you can see that increasing the value of doptimal decreases the value of ceiling(di / doptimal)-1 and hence smaller is the value of k'sum. Therefore, we can perform a binary search in the range [1, max(di)] to find the least value of doptimal that makes k'sum ≤ K. That is our answer.

Since the max(di) could be as much as 109, we might have to search [1, 109] making time complexity of the solution is O(log(109)*N).
'''
