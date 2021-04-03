#   Exercise description:
#
#   "Napisz funkcję, która przekształci wprowadzoną liczbę dziesiętną
#   na liczbę rzymską (funkcja powinna obsługiwać liczby max pięciocyfrowe)."
#
#################################################################################################

num = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000]
sym = ["I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"]

def decimalToRoman(number):
    str = ""
    i = len(num)-1

    while(i != -1):
        division = number/num[i]
        while(division >= 1):
            str += sym[i]
            division -= 1

        number %= num[i]
        i -= 1
    return str

#   MAIN
print(str(decimalToRoman(4123)))