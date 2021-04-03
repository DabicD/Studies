#   Exercise description:
#
#   "Napisz program zwracający listę unikalnych nazw plików w danym katalogu (oczywiście z podkatalogami)."
#
#################################################################################################
import os


#   Functions
def uniqueFilesInDir(path):
    if(path == ''):
        path = '.'
    try:
        unique = []
        for x in os.walk('.'):
            for y in x[2]:
                try:
                    unique.index(y)
                except:
                    unique.append(y)
        return unique
    except:
        return "Wrong Path"

#   MAIN

x1 = input("In directory(skip = this directory): ")
print(uniqueFilesInDir(x1))