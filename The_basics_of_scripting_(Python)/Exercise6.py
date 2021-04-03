#   Exercise description:
#
#   "Napisz funkcję, która dostaje dwie daty postaci dd.mm.rrrri sprawdza,
#   ile dni mija od pierwszej do drugiej z nich.  Można pominąć istnienie lat przestępnych."
#
#################################################################################################

import datetime

print("How many days are betwenn... [data format: dd.mm.yyyy]")
try:
    x1 = input("Date 1: ")
    x2 = input("Date 2: ")

    #   Calculations
    date1 = datetime.datetime.strptime(x1, '%d.%m.%Y')
    date2 = datetime.datetime.strptime(x2, '%d.%m.%Y')
    result = date2 - date1

    #   Printing data
    print(str(abs(result.days)) + " days difference")

except:
    print("Wrong input")