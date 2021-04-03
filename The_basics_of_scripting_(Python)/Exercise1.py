#   Exercise description:
#
#   "Napisz funkcję, która znajdzie i zapisze do pliku wszystkie liczby z zadanego
#   przez użytkownika przedziału, których suma cyfr jest liczbą pierwszą."
#
##################################################################################

# Functions
def sumOfDigits(number):
    sum = 0
    while(number > 0):
        sum = sum + number % 10
        number /= 10
        number = int(number)
    return sum

def isPrimeNumber(number):
    sum = sumOfDigits(number)

    #   Check conditions
    if(sum > 2):
        for devider in range(2, sum):
            if((sum%devider) == 0):
                return False
    elif(sum == 1 or sum == 2):
        return True
    else:
        return False
    return True

#   MAIN
try:
    x1 = int(input("Beginning:"))
    x2 = int(input("End:"))

    f = open("prime_number_list.txt", "w");
    f.write("Your list:\n")
    for number in range(x1, x2+1):
        if(isPrimeNumber(number)):
            f.write(str(number)+"\n")
            print(number)
    f.close()
except:
    print("Wrong input")