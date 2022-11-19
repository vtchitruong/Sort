def selectionSort(myList):
    n = len(myList)

    for i in range(n):
        m = i
        for j in range(i + 1, n):
            if myList[j] < myList[m]:
                m = j
        myList[i], myList[m] = myList[m], myList[i]
        
arr = [10, 70, 40, 0, 90, 40, 80]
selectionSort(arr)
print ("Sorted list")
for i in range(len(arr)):
    print(f'{arr[i]}', end=' ')