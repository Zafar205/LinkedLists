arr = [1, 2, 3, 4, 5]

l = 0
r = len(arr)-1
val = 6
while l <= r:
    m = (l+r)//2

    if arr[m] == val:
        print("found")
        break
    elif arr[m] <= val:
        l = m + 1
    else:
        r = m - 1

print("Not found")        
