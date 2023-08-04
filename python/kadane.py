def kadane(arr):
    size = len(arr)
    max_so_far = float('-inf')
    max_ending_here = 0

    for i in range(size):
        max_ending_here += arr[i]
        if(max_so_far < max_ending_here): max_so_far = max_ending_here
        if(max_ending_here < 0): max_ending_here = 0
    
    return max_so_far


arr = []
while(True):
    value = input("Ingrese un numero o escriba 'Fin' para terminar: ")
    if value.lower() == 'fin':
        break
    try:
        num = int(value)
        arr.append(num)
    except ValueError:
        print("Ingrese un numero valido.")


print("Suma maxima: ", kadane(arr))