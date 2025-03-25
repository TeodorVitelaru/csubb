import heapq

def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    
    return merge(left, right)

def merge(left, right):
    sorted_arr = []
    i = j = 0
    
    while i<len(left) and j< len(right):
        if left[i] < right[j]:
            sorted_arr.append(right[j])
            j += 1
        else:
            sorted_arr.append(left[i])
            i += 1
    
    sorted_arr.extend(left[i:])
    sorted_arr.extend(right[j:])
    
    return sorted_arr

#O(n*log(n))-timp, O(n)-memorie
def pr7(k, arr):
    #sortare sir
    arr = merge_sort(arr)
    return arr[k-1]

#O(nlog(k))-timo, O(k)--memorie
def pr7_ai(k, arr):
    # Folosim un heap minim pentru a păstra cele mai mari k elemente
    return heapq.nlargest(k, arr)[-1]
    
print(pr7(2, [7,4,6,3,9,1]))
print(pr7_ai(2, [7,4,6,3,9,1]))