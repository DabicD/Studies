#   Exercise description:
#
#   "Napisać program, który znajdzie w podanym przez użytkownika katalogu wszystkie pliki,
#   które zawierają w treści (nie w nazwie) zadane słowo."
#
#################################################################################################
import os


#   Functions
def wordsExtractiion(data):
    #   All words from file to array
    word = ""
    words = []
    for i in data:
        if (i != '\n' and i != ' '):
            word += i
        else:
            words.append(word)
            word = ""
    words.append(word)
    return words

def fileToString(path):
    try:
        #   Take the data
        f = open(path, 'r')
        data = f.read()
        f.close()
        return data
    except:
        return "Wrong Path"

def arrayOfFiles(path = '.'):
    if(path == ''):
        path = '.'
    files = []
    for i in os.listdir(path):
        if(os.path.isfile(i)):
            files.append(i)
    return files


def isWordInFile(match, file):
    #   Take the data
    data = fileToString(file)

    #   All words from file to array
    words = wordsExtractiion(data)

    #   Compare
    try:
        words.index(match)
        return True
    except:
        return False

#   MAIN

x1 = input("Search word: ")
x2 = input("In directory(skip = this directory): ")

for i in arrayOfFiles(x2):
    if(isWordInFile(x1, i)):
        print(i)