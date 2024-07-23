nums_size = int(input())
nums = []
for i in range(0,nums_size):
    nums.append(int(input()))
nums.sort()
j = 0
MEX = 0
ind  = 0
for i in range(0,len(nums)):
    if(nums[i]==j-1):
        continue
    if(nums[i]==j):
        j+=1
        continue
    else:
        MEX = j
        ind = i;
        break;
if(nums[-1]==j-1):
    MEX = j
    print(len(nums))
    exit(0)


if(MEX==0):
    print("-2")
    exit(0)
count = 0

for i in range(0,ind+1):
    if(nums[i]!=MEX):
        count+=1
        break

print(count)