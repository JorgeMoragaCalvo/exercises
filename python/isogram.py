
def is_isogram(str):
    size = len(str)
    while(size > 0):
        for i in range(size - 2):
            if((str[size - 1] == str[i]) and (str[size - 1] != '-' and str[size - 1] != ' ')): return False
            i -= 1
        size -= 1
    
    return True


text1 = "Dermatoglyphics"
text2 = "six-years-old"
print(is_isogram(text1))
print(is_isogram(text2))