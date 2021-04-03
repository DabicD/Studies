#   Exercise description:
#
#   "Napisz program drukujący na ekranie kalendarz na zadany miesiąc dowolnego roku
#   (użytkownik wprowadza informację postaci: czerwiec 1997–nazwa miesiąca w języku polskim)."
#
##############################################################################################
import locale
locale.setlocale(locale.LC_ALL, 'pl')
import calendar

polishMonths = {
    "styczen": 1,
    "luty": 2,
    "marzec": 3,
    "kwiecien": 4,
    "maj":5,
    "czerwiec":6,
    "lipiec":7,
    "sierpien":8,
    "wrzesien":9,
    "pazdziernik":10,
    "listopad":11,
    "grudzien":12
}

try:
    x1 = int(input("Year:"))
    x2 = input("Month:")

    cal = calendar.TextCalendar(calendar.MONDAY)
    text = cal.formatmonth(x1, polishMonths[x2])
    print(text)
except:
    print("Wrong input")
