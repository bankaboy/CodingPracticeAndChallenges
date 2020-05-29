# N strings, only from A-Z
# Bundle string to groups of size K
# one string only in one group
# score of group is lenght of longest prefix shared by all the string in group
# Bundle strings into groups of size K, such that overall score is max

def longestCommonSubstring(str1, str2):
    m = len(str1)
    n = len(str2)
    LCSuff = [[0 for k in range(n+1)] for l in range(m+1)] 
    result = 0 

    for i in range(m + 1): 
        for j in range(n + 1): 
            if (i == 0 or j == 0): 
                LCSuff[i][j] = 0
            elif (str1[i-1] == str2[j-1]): 
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1
                result = max(result, LCSuff[i][j]) 
            else: 
                LCSuff[i][j] = 0
    return result


def findScore(strings):
    maxScore = 0
    for i in range(len(strings)):
        for j in range(i+1,len(strings)):
            score = longestCommonSubstring(strings[i],strings[j])
            if score>maxScore:
                maxScore = score
    print(maxScore)
    

T = int(input())
for i in range(1,T+1):
    N, K = [int(x) for x in input().split()]
    strings = []
    for i in range(N):
        strings.append(input())
    findScore(strings)


'''
Analysis
We need to maximise the sum of scores of each bundle. Let us consider a bundle and say longest prefix shared by all strings of this bundle is of length X. Now each prefix of length from 1 to X is shared by all of the strings in this bundle. Consider any prefix among these X prefixes, it is counted once in the score of this bundle. Thus the score of a bundle can be defined as number of prefixes that are shared by all of the strings in this bundle. Thus if a prefix is shared by all strings in Y bundles, then it will contribute Y to the total sum of scores.

Now instead of finding the total score, we find the contribution of each prefix in the total score. So for maximising the total score, we would want to maximize the contribution of each prefix in the total score. Let the contribution of each prefix PRE be contibution(PRE). We want to maximize ∑ contribution(PRE) where PRE comprises all possible prefixes of the given strings.

Let us say a prefix Pi is a prefix of S strings. The maximum number of bundles of size K formed by S strings is ⌊ S / K ⌋. In each of these ⌊ S / K ⌋ bundles, prefix Pi will add to their scores. Thus maximum value of contribution(Pi) can be ⌊ S / K ⌋. So a prefix Pi which occurs as a prefix of S strings will contribute ⌊ S / K ⌋ to the answer.

Let us see if we can achieve this maximum value for all the prefixes. Consider a prefix P of length L. It occurs as a prefix in CNT number of strings. Now consider there are C prefixes of length L + 1 which contain the prefix P as a prefix (P1, P2, ....,PC). And we have stored the number of strings these prefixes are part of as (CNT1, CNT2, ....,CNTC).

Let us say we divided the strings which have prefix Pi into ⌊ (CNTi / K) ⌋ bundles. Now we have CNTi%K strings remaining for each prefix that we need to arrange so that they make a bundle. For each of these remaining strings we cannot have a bundle of size K which would have a common prefix of length L + 1 because we have CNTi%K remaining strings for each Pi. So, we can make bundles in any order using the remanining strings. Those bundles will still have a prefix of length L shared among them. Thus we would be left with CNT%K number of strings which are not in any bundle when we consider prefix P. We can continue this procedure till we are left with prefix of length 0. We would be able to bundle all the strings at this point because we would have N % K strings remaining, and as specified in the problem, N is divisible by K.

The problem is now reduced to finding number of times each prefix occurs in the given strings. Let this number be COUNT. We just need to add ⌊ COUNT / K ⌋ to the answer for each prefix.

Test set 1
The length of each string is at most 5. Thus we have total number of prefixes as N * 5 and each prefix can be of size at most 5. Store each prefix in a hashmap and increase the count for each prefix. In the end, we just need to add ⌊ (count(i) / K) ⌋ for each prefix i. The complexity of the solution would be O(N * 5 * 5).

Test set 2
Let the sum of length of all strings over all the test cases be SUM which is 106. For the large test set, the length of the string can be very large. So, we can't store all the prefixes in a hashmap. We need to store all the prefixes in an efficient manner along with the number of times they occur in given strings. We can use a data structure trie. The insertion cost would be equal to sum of length of strings over the test cases which is O(SUM). Then finally we just need to traverse the trie and for each prefix, add its contribution to the answer. Time complexity of the solution would be O(SUM).
'''
