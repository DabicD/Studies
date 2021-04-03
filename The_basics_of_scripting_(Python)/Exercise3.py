#   Exercise description:
#
#   "Napisz funkcję sprawdzającą, które znaki w podanym przez użytkownika
#   zdaniupowtarzają się i uporządkuj je w kolejności od najczęściej do najrzadziej występującego."
#
####################################################################################################
try:
    x1 = input("Your text: ")
    alphabet = []
    count = []

    #   Freq-Counter
    for i in x1:
        try:
            index = alphabet.index(i)
            count[index] = count[index] + 1
        except:
            alphabet.append(i)
            count.append(1)

    #   Sorting data max-min (freq)
    arr = []
    for i in range(0, len(alphabet)):
        arr.append((alphabet[i], str(count[i])))
    arr.sort(key=lambda tup: tup[1])
    arr.reverse()

    #   Showing the result
    for i in range(0, len(arr)):
        print(arr[i][0] + ": " + arr[i][1])

except:
    print("Wrong input")