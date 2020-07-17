# Problem Description
# You are a teacher in reputed school. During Celebration Day you 
# were assigned a task to distribute Cadbury such that maximum 
# children get the chocolate. You have a box full of Cadbury with 
# different width and height. You can only distribute largest square 
# shape Cadbury. So if you have a Cadbury of length 10 and width 5, 
# then you need to break Cadbury in 5X5 square and distribute to 
# first child and then remaining 5X5 to next in queue

# Constraints
# 0<P<Q<1501

# 0<R<S<1501

# Input Format
# First line contains an integer P that denotes minimum length of 
# Cadbury in the box
# Second line contains an integer Q that denotes maximum length of 
# Cadbury in the box
# Third line contains an integer R that denotes minimum width of 
# Cadbury in the box
# Fourth line contains an integer S that denotes maximum width of 
# Cadbury in the box

# Output
# Print total number of children who will get chocolate.
# Timeout
# 1
# Explanation

# Example 1
# Input
# 5
# 7
# 3
# 4
# Output
# 24
# Explanation
# Length is in between 5 to 7 and width is in between 3 to 4.
# So we have 5X3,5X4,6X3,6X4,7X3,7X4 type of Cadbury in the box.
# If we take 5X3 :
# First, we can give 3X3 square Cadbury to 1st child .Then we are 
# left with 3X2. Now largest square is 2X2 which will be given to 
# next child. Next, we are left with two  1X1 part of Cadbury which 
# will be given to another two children.
# And so on

LH  = int(input().strip())
UH  = int(input().strip())
LW  = int(input().strip())
UW  = int(input().strip())

dct = {}
max_len = 0
count = 0

def f(x,y):
  global count, max_len
  count += 1
  if x<y:
    x, y = y,x
  if x==0 or y==0:
    return 0
  if x==y:
    return 1
  else:
    #return 1+f(x-y,y)
    #'''
    if (x,y) not in dct:
      dct[(x,y)] = 1+f(x-y,y)
      if len(dct)>max_len: max_len = len(dct)
      if ((x-y,y) in dct): del dct[(x-y,y)]
    return dct[(x,y)]
    #'''

res = 0
for i in range(LH,UH+1):
  for j in range(LW,UW+1):
    res += f(i,j)

print(res)
