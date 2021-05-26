#   Exercise description:
#
#   "Napisz funkcję, która w podanym przez użytkownika tekście znajdzie poprawny numer telefonu
#   (cyfry mogą być oddzielone spacjami bądź znakiem -,
#   numer może być poprzedzony znakiem +).Należy wziąć pod uwagę
#   wszystkie „normalnie” używane formaty numerów stacjonarnych i komórkowych."
#
#################################################################################################
import re
x1 = input("Random text input with included number: ")

phone = re.findall(r'[+[\s]?\d{1,3}[\s-]?]?\d{3}[\s-]?\d{3}[\s-]?\d{3}', x1)

try:
    print("Phone number: " + str(phone[0]))
except:
    print("There is no phone number detected")
