def remove(num, digit):
    if (num < 10):
        if (num == digit):
            return 0
        else:
            return num 
    last = num % 10
    without_last = num // 10
    
    without_last_remove = remove(without_last, digit)
    if (last == digit):
        return without_last_remove
    return without_last_remove * 10 + last

def remove1(n, digit):
    kept, digits = 1, 0
    while (n > 0):
        n, last = n // 10, n % 10
        if last != digit:
            kept = kept * 10
            digits = kept * last + digits
    return kept

print(remove(234143,3))
print("hello")
