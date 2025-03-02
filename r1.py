arr = [1, 2, 555]

def sum1(arr):
    if len(arr) <= 1:
        return arr[0]
    else:
        return arr[0] + sum1(arr[1:])
# print(sum1(arr))



def count(arr):
    if len(arr) <= 1:
        return 1
    else:
        return 1 + count(arr[1:])
    
# print(count(arr))


def maxi(arr, m = arr[0]):
    if len(arr) < 1:
        return m
    else:
        if arr[0] > m:
            m = arr[0]
            return maxi(arr[1:], m) 
        else:
            return maxi(arr[1:], m)   
        

def improved_max(arr, m = arr[0]):
    if len(arr) < 1:
        return m
    else:
        if arr[0] > m:
            m = arr[0]
        return maxi(arr[1:], m) 

# print(maxi(arr))            



def binary_search(e, arr, l=0, r=len(arr) - 1):
    if r is None:
        r = len(arr) - 1

    if l > r:
        return "not found"

    m = (l + r) // 2

    if arr[m] == e:
        return f'found at index {m}'
    elif arr[m] < e:
        return binary_search(e, arr, m + 1, r)
    else:
        return binary_search(e, arr, l, m - 1)

print(binary_search(3, [1, 2, 3, 4]))  # Output: found at index 2


# Returns index of x in arr if present, else -1
def binarySearch(arr, low, high, x):

    # Check base case
    if high >= low:

        mid = low + (high - low) // 2

        # If element is present at the middle itself
        if arr[mid] == x:
            return mid

        # If element is smaller than mid, then it
        # can only be present in left subarray
        elif arr[mid] > x:
            return binarySearch(arr, low, mid-1, x)

        # Else the element can only be present
        # in right subarray
        else:
            return binarySearch(arr, mid + 1, high, x)

    # Element is not present in the array
    else:
        return -1
print(binarySearch(arr, 0, len(arr)-1, 3))    