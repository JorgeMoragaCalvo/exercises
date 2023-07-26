def digits(num):
    count = 0
    while num != 0:
        num = num // 10
        count += 1 
    return count

def isArmstrong(num):
    if num < 10: return True
    else:
        sum = 0
        aux = num
        d = digits(num)
        i = d - 1
        while i >= 0:
            a = num // (pow(10, i))
            sum += pow(a, d)
            num = num % (pow(10, i))
            i -= 1
        
        if sum == aux: return True
        else: return False



num = int(input("Enter a number: "))
if isArmstrong(num):
    print("The number is Armstrong")
else:
    print("The number is not Armstrong")
    


