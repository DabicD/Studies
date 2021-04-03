#   Exercise description:
#
#   "Napisz funkcję, która dopisze 10 najczęściej występujących słów wraz z liczbą
#   ich wystąpieńna końcu każdego pliku tekstowego podanegojako parametr (dowolna liczba parametrów)."
#
#################################################################################################

import sys
leng = len(sys.argv)

try:
    while(leng>1):

        #   Words from file to array
        f = open(sys.argv[leng-1])
        allTextStr = f.read()
        f.close()
        word = ""
        allWords = []
        for i in allTextStr:
            if(i != '\n' and i != ' '):
                word += i
            else:
                allWords.append(word)
                word = ""
        allWords.append(word)

        #   Freq-Counter
        words = []
        count = []
        for i in allWords:
            try:
                index = words.index(i)
                count[index] = count[index] + 1
            except:
                words.append(i)
                count.append(1)

        #   Sorting data max-min (freq)
        arr = []
        for i in range(0, len(words)):
            arr.append((words[i], str(count[i])))
        arr.sort(key=lambda tup: tup[1])
        arr.reverse()

        #   Adding analyst to file
        f = open(sys.argv[leng-1], 'a')
        f.writelines("\nMost popular words in this file:")
        toTen = 0
        for i in range(0, len(arr)):
            if(toTen<10):
                f.writelines("\n" + str(arr[i][0]) + ": " + str(arr[i][1]))
            toTen += 1
        f.close()
        leng -= 1
except:
    print("Something went wrong")
