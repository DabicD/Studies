############################################
# IMPORTS
##########
import sys
import time
import requests
import threading
import keyboard
import pyautogui
import pymysql
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QDialog, QFileDialog
from PyQt5.QtWidgets import QMessageBox, QProgressBar, QMainWindow
from PyQt5.QtCore import QTimer


############################################
# FUNCTIONS
###########

############################################
# CLASSES
###########

class MainApplication(QMainWindow):
    def __init__(self):
        super().__init__()
        self.fileName = ''

        self.tablica_bindow2 = ["", "", "", "", ""]
        self.tablica_dostepu2 = [True, True, True, True, True]

        self.clickedSpam = False

        self.lolStarted = False
        self.lolObiectExist = False

        print("constructor- mainApp")
        self.setupUi()
        self.show()

    def setupUi(self):
        self.setObjectName("MainWindow")
        self.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(self)
        self.centralwidget.setObjectName("centralwidget")
        self.tabWidget = QtWidgets.QTabWidget(self.centralwidget)
        self.tabWidget.setGeometry(QtCore.QRect(0, 8, 800, 601))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI Light")
        font.setPointSize(12)
        self.tabWidget.setFont(font)
        self.tabWidget.setAutoFillBackground(False)
        self.tabWidget.setObjectName("tabWidget")
        self.pianoBot = QtWidgets.QWidget()
        self.pianoBot.setObjectName("pianoBot")
        self.label = QtWidgets.QLabel(self.pianoBot)
        self.label.setGeometry(QtCore.QRect(20, 10, 751, 51))
        font = QtGui.QFont()
        font.setFamily("Papyrus")
        font.setPointSize(31)
        self.label.setFont(font)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.tabWidget.addTab(self.pianoBot, "")
        self.spamBot = QtWidgets.QWidget()
        self.spamBot.setObjectName("spamBot")
        self.label_2 = QtWidgets.QLabel(self.spamBot)
        self.label_2.setGeometry(QtCore.QRect(20, 10, 751, 51))
        font = QtGui.QFont()
        font.setFamily("Papyrus")
        font.setPointSize(31)
        self.label_2.setFont(font)
        self.label_2.setAlignment(QtCore.Qt.AlignCenter)
        self.label_2.setObjectName("label_2")
        self.label_12 = QtWidgets.QLabel(self.spamBot)
        self.label_12.setGeometry(QtCore.QRect(180, 100, 231, 91))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI Light")
        font.setPointSize(17)
        self.label_12.setFont(font)
        self.label_12.setAlignment(QtCore.Qt.AlignCenter)
        self.label_12.setObjectName("label_12")
        self.label_13 = QtWidgets.QLabel(self.spamBot)
        self.label_13.setGeometry(QtCore.QRect(190, 220, 311, 41))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI Light")
        font.setPointSize(17)
        self.label_13.setFont(font)
        self.label_13.setAlignment(QtCore.Qt.AlignCenter)
        self.label_13.setObjectName("label_13")
        self.label_14 = QtWidgets.QLabel(self.spamBot)
        self.label_14.setGeometry(QtCore.QRect(170, 340, 301, 81))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI Light")
        font.setPointSize(17)
        self.label_14.setFont(font)
        self.label_14.setAlignment(QtCore.Qt.AlignCenter)
        self.label_14.setObjectName("label_14")
        self.comboBox_2 = QtWidgets.QComboBox(self.spamBot)
        self.comboBox_2.setGeometry(QtCore.QRect(420, 130, 181, 31))
        self.comboBox_2.setObjectName("comboBox_2")
        self.doubleSpinBox = QtWidgets.QDoubleSpinBox(self.spamBot)
        self.doubleSpinBox.setGeometry(QtCore.QRect(520, 230, 81, 51))
        self.doubleSpinBox.setObjectName("doubleSpinBox")
        self.pushButton_2 = QtWidgets.QPushButton(self.spamBot)
        self.pushButton_2.setGeometry(QtCore.QRect(470, 360, 131, 41))
        self.pushButton_2.setObjectName("pushButton_2")
        self.label_15 = QtWidgets.QLabel(self.spamBot)
        self.label_15.setGeometry(QtCore.QRect(200, 250, 301, 31))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI Light")
        font.setPointSize(17)
        self.label_15.setFont(font)
        self.label_15.setObjectName("label_15")
        self.pushButton_3 = QtWidgets.QPushButton(self.spamBot)
        self.pushButton_3.setGeometry(QtCore.QRect(320, 450, 171, 71))
        font = QtGui.QFont()
        font.setPointSize(19)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_3.setFont(font)
        self.pushButton_3.setObjectName("pushButton_3")
        self.tabWidget.addTab(self.spamBot, "")
        self.lolBot = QtWidgets.QWidget()
        self.lolBot.setObjectName("lolBot")
        self.label_3 = QtWidgets.QLabel(self.lolBot)
        self.label_3.setGeometry(QtCore.QRect(20, 10, 751, 51))
        font = QtGui.QFont()
        font.setFamily("Papyrus")
        font.setPointSize(31)
        self.label_3.setFont(font)
        self.label_3.setAlignment(QtCore.Qt.AlignCenter)
        self.label_3.setObjectName("label_3")
        self.pushButton = QtWidgets.QPushButton(self.lolBot)
        self.pushButton.setGeometry(QtCore.QRect(510, 260, 171, 61))
        self.pushButton.setObjectName("pushButton")
        self.listWidget = QtWidgets.QListWidget(self.lolBot)
        self.listWidget.setGeometry(QtCore.QRect(10, 300, 371, 181))
        self.listWidget.setObjectName("listWidget")
        self.text_bind = QtWidgets.QLineEdit(self.lolBot)
        self.text_bind.setGeometry(QtCore.QRect(80, 190, 241, 31))
        self.text_bind.setObjectName("text_bind")
        self.label_4 = QtWidgets.QLabel(self.lolBot)
        self.label_4.setGeometry(QtCore.QRect(70, 120, 171, 41))
        self.label_4.setAlignment(QtCore.Qt.AlignCenter)
        self.label_4.setObjectName("label_4")
        self.label_5 = QtWidgets.QLabel(self.lolBot)
        self.label_5.setGeometry(QtCore.QRect(140, 170, 121, 21))
        self.label_5.setAlignment(QtCore.Qt.AlignCenter)
        self.label_5.setObjectName("label_5")
        self.label_6 = QtWidgets.QLabel(self.lolBot)
        self.label_6.setGeometry(QtCore.QRect(60, 60, 281, 51))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI Light")
        font.setPointSize(15)
        font.setBold(True)
        font.setWeight(75)
        self.label_6.setFont(font)
        self.label_6.setAlignment(QtCore.Qt.AlignCenter)
        self.label_6.setObjectName("label_6")
        self.label_7 = QtWidgets.QLabel(self.lolBot)
        self.label_7.setGeometry(QtCore.QRect(330, 70, 71, 471))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI Light")
        font.setPointSize(500)
        self.label_7.setFont(font)
        self.label_7.setObjectName("label_7")
        self.button_zbinduj = QtWidgets.QPushButton(self.lolBot)
        self.button_zbinduj.setGeometry(QtCore.QRect(140, 240, 131, 41))
        self.button_zbinduj.setObjectName("button_zbinduj")
        self.button_usunbind = QtWidgets.QPushButton(self.lolBot)
        self.button_usunbind.setGeometry(QtCore.QRect(144, 500, 131, 41))
        self.button_usunbind.setObjectName("button_usunbind")
        self.comboBoxKlawisz = QtWidgets.QComboBox(self.lolBot)
        self.comboBoxKlawisz.setGeometry(QtCore.QRect(250, 130, 71, 22))
        self.comboBoxKlawisz.setObjectName("comboBoxKlawisz")
        self.label_8 = QtWidgets.QLabel(self.lolBot)
        self.label_8.setGeometry(QtCore.QRect(456, 59, 271, 51))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI Light")
        font.setPointSize(15)
        font.setBold(True)
        font.setWeight(75)
        self.label_8.setFont(font)
        self.label_8.setAlignment(QtCore.Qt.AlignCenter)
        self.label_8.setObjectName("label_8")
        self.label_9 = QtWidgets.QLabel(self.lolBot)
        self.label_9.setGeometry(QtCore.QRect(490, 140, 211, 20))
        self.label_9.setAlignment(QtCore.Qt.AlignCenter)
        self.label_9.setObjectName("label_9")
        self.comboBox = QtWidgets.QComboBox(self.lolBot)
        self.comboBox.setGeometry(QtCore.QRect(510, 180, 171, 31))
        self.comboBox.setObjectName("comboBox")
        self.label_10 = QtWidgets.QLabel(self.lolBot)
        self.label_10.setGeometry(QtCore.QRect(510, 380, 171, 31))
        self.label_10.setAlignment(QtCore.Qt.AlignCenter)
        self.label_10.setObjectName("label_10")
        self.label_11 = QtWidgets.QLabel(self.lolBot)
        self.label_11.setGeometry(QtCore.QRect(510, 422, 171, 101))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI Light")
        font.setPointSize(49)
        self.label_11.setFont(font)
        self.label_11.setFrameShape(QtWidgets.QFrame.Panel)
        self.label_11.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.label_11.setAlignment(QtCore.Qt.AlignCenter)
        self.label_11.setObjectName("label_11")
        self.tabWidget.addTab(self.lolBot, "")
        self.setCentralWidget(self.centralwidget)

        self.comboBox_2.addItems(['F8', 'F9', 'F10', 'F11', 'F12'])
        self.doubleSpinBox.setSingleStep(0.1)
        self.doubleSpinBox.setRange(0, 5)
        self.pushButton_2.clicked.connect(self.openFile)
        self.pushButton_3.clicked.connect(self.startSpam)

        self.button_zbinduj.clicked.connect(self.zbindujKlawisz)
        self.button_usunbind.clicked.connect(self.usunBind)

        # LOL BOT
        self.comboBox.addItems(['q', '1', '2', '3', 'c', 'x', 'v', 'z'])
        self.pushButton.clicked.connect(self.startLolBot)
        self.comboBoxKlawisz.addItems(['f8', 'f9', 'f10', 'f11', 'f12'])

        self.retranslateUi(self)
        self.tabWidget.setCurrentIndex(1)
        QtCore.QMetaObject.connectSlotsByName(self)

    def zbindujKlawisz(self):

        if (self.comboBoxKlawisz.currentText() == 'f8'):
            self.ustawTablice(0)

        if (self.comboBoxKlawisz.currentText() == 'f9'):
            self.ustawTablice(1)

        if (self.comboBoxKlawisz.currentText() == 'f10'):
            self.ustawTablice(2)

        if (self.comboBoxKlawisz.currentText() == 'f11'):
            self.ustawTablice(3)

        if (self.comboBoxKlawisz.currentText() == 'f12'):
            self.ustawTablice(4)

    def ustawTablice(self, number):
        if self.tablica_dostepu2[number] == True:
            self.tablica_bindow2[number] = self.text_bind.text()
            self.tablica_dostepu2[number] = False
            self.listWidget.addItem(
                f'PRZYCISK: {self.comboBoxKlawisz.currentText()} --- TEKST: {self.text_bind.text()}')
        else:
            choice = QMessageBox.critical(self, 'INFORMACJA', 'Podano przycisk jest juz zajety', QMessageBox.Ok,
                                          QMessageBox.Ok)

    def usunBind(self):
        self.listWidget.clear()
        if (self.tablica_dostepu2[0] == False):
            self.tablica_dostepu2[0] = True
            self.tablica_bindow2[0] = ""

        if (self.tablica_dostepu2[1] == False):
            self.tablica_dostepu2[1] = True
            self.tablica_bindow2[1] = ""

        if (self.tablica_dostepu2[2] == False):
            self.tablica_dostepu2[2] = True
            self.tablica_bindow2[2] = ""

        if (self.tablica_dostepu2[3] == False):
            self.tablica_dostepu2[3] = True
            self.tablica_bindow2[3] = ""

        if (self.tablica_dostepu2[4] == False):
            self.tablica_dostepu2[4] = True
            self.tablica_bindow2[4] = ""

        self.lolBOT.cleanTable()

    def startLolBot(self):
        if self.lolObiectExist is False:
            # Create lolObject
            self.lolBOT = Lol_Tool('q')
            self.lolStarted = True
            self.lolBOT.setStarted(True)
            self.pushButton.setText('ZATRZYMAJ BOTA')
            self.label_11.setText('ON')
            self.lolBOT.changeBindedButton(self.comboBox.currentText())
            self.lolObiectExist = True

            if (self.tablica_dostepu2[0] == False):
                self.lolBOT.addBind('f8', self.tablica_bindow2[0])

            if (self.tablica_dostepu2[1] == False):
                self.lolBOT.addBind('f9', self.tablica_bindow2[1])

            if (self.tablica_dostepu2[2] == False):
                self.lolBOT.addBind('f10', self.tablica_bindow2[2])

            if (self.tablica_dostepu2[3] == False):
                self.lolBOT.addBind('f11', self.tablica_bindow2[3])

            if (self.tablica_dostepu2[4] == False):
                self.lolBOT.addBind('f12', self.tablica_bindow2[4])

        else:
            print("elsecostamStartBotLOL")
            if self.lolStarted is False:
                self.lolStarted = True
                self.lolBOT.setStarted(True)
                self.pushButton.setText('ZATRZYMAJ BOTA')
                self.label_11.setText('ON')
                self.lolBOT.changeBindedButton(self.comboBox.currentText())
                if (self.tablica_dostepu2[0] == False):
                    self.lolBOT.addBind('f8', self.tablica_bindow2[0])

                if (self.tablica_dostepu2[1] == False):
                    self.lolBOT.addBind('f9', self.tablica_bindow2[1])

                if (self.tablica_dostepu2[2] == False):
                    self.lolBOT.addBind('f10', self.tablica_bindow2[2])

                if (self.tablica_dostepu2[3] == False):
                    self.lolBOT.addBind('f11', self.tablica_bindow2[3])

                if (self.tablica_dostepu2[4] == False):
                    self.lolBOT.addBind('f12', self.tablica_bindow2[4])

            else:
                self.lolStarted = False
                self.lolBOT.setStarted(False)
                self.pushButton.setText('WYSTARTUJ BOTA')
                self.label_11.setText('OFF')

    def startSpam(self):
        print(self.doubleSpinBox.value())

        if self.clickedSpam is False:
            self.clickedSpam = True
            self.pushButton_3.setText("Stop")
            print("1click")
            ##Tworzenie
            self.spamBotThread = threading.Thread(target=self.spaming)
            self.spamBotThread.start()

        else:
            self.clickedSpam = False
            self.pushButton_3.setText("Start")
            print("2click")
            ##DeamonDestroy

    def spaming(self):
        print("Spambot-started")
        while True:
            while self.clickedSpam:
                self.f = open(self.fileName, 'r')
                if keyboard.is_pressed(self.comboBox_2.currentText()):
                    time.sleep(1)
                    while True:
                        breaked = False
                        for word in self.f:
                            if keyboard.is_pressed(self.comboBox_2.currentText()):
                                breaked = True
                                break
                            pyautogui.typewrite(word)
                            if keyboard.is_pressed(self.comboBox_2.currentText()):
                                breaked = True
                                break
                            time.sleep(self.doubleSpinBox.value())
                            if keyboard.is_pressed(self.comboBox_2.currentText()):
                                breaked = True
                                break
                            pyautogui.press("enter")
                            if keyboard.is_pressed(self.comboBox_2.currentText()):
                                breaked = True
                                break
                        self.f.seek(0)
                        if breaked is True:
                            time.sleep(1)
                            break
                self.f.close()
            print("Spambot-Stoped")
            break

    def openFile(self):
        options = QFileDialog.Options()
        options |= QFileDialog.DontUseNativeDialog
        self.fileName, x = QFileDialog.getOpenFileName(self, 'Open File', 'Test.py', 'Wszystko ();;Tekst (.txt)',
                                                       options=options)
        print(self.fileName)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "Welcome to Piano-tool!"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.pianoBot), _translate("MainWindow", "Magic Piano"))
        self.label_2.setText(_translate("MainWindow", "Welcome to Spam-tool!"))
        self.label_12.setText(_translate("MainWindow", "WYBIERZ PRZYCISK"))
        self.label_13.setText(_translate("MainWindow", "CZAS MIĘDZY WYSYŁANIEM "))
        self.label_14.setText(_translate("MainWindow", "PLIK Z WIADOMOŚCIAMI"))
        self.pushButton_2.setText(_translate("MainWindow", "WYBIERZ PLIK"))
        self.label_15.setText(_translate("MainWindow", "KOLEJNYCH WIADOMOŚCI"))
        self.pushButton_3.setText(_translate("MainWindow", "Start"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.spamBot), _translate("MainWindow", "Spam Bot"))
        self.label_3.setText(_translate("MainWindow", "Welcome to LoL-tool!"))
        self.pushButton.setText(_translate("MainWindow", "WYSTARTUJ BOTA"))
        self.label_4.setText(_translate("MainWindow", "Wybierz klawisz z listy"))
        self.label_5.setText(_translate("MainWindow", "Wpisz tekst"))
        self.label_6.setText(_translate("MainWindow", "BIDNOWANIE KLAWISZA "))
        self.label_7.setText(_translate("MainWindow", "|"))
        self.button_zbinduj.setText(_translate("MainWindow", "ZBINDUJ"))
        self.button_usunbind.setText(_translate("MainWindow", "RESET"))
        self.label_8.setText(_translate("MainWindow", "BINDOWANIE BOTA"))
        self.label_9.setText(_translate("MainWindow", "Wybierz klawisz z listy"))
        self.label_10.setText(_translate("MainWindow", "Status bota "))
        self.label_11.setText(_translate("MainWindow", "OFF"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.lolBot), _translate("MainWindow", "League of Legends"))



####################################### L O L ############################################################
class Lol_Tool:
    def __init__(self, bindedButton):
        print("Lol_Tool_init")
        self.bindedButton = bindedButton

        # Class attribute
        self.svaf = 0.14  # Function to namke delamy
        self.keyPressTime = 0.01
        self.tablica_bindow = ["", "", "", "", ""]
        self.tablica_dostepu = [True, True, True, True, True]
        self.started = False
        self.kitingThread = threading.Thread(target=self.kitingWhilePressed)
        self.kitingThread.start()

    def setStarted(self, isStarted):
        self.started = isStarted

    def cleanTable(self):
        self.tablica_bindow = ["", "", "", "", ""]
        self.tablica_dostepu = [True, True, True, True, True]

    def kitingWhilePressed(self):
        while True:
            while self.started is True:
                print("ture")
                if keyboard.is_pressed(self.bindedButton):
                    print("pressed")
                    self.kite()
                if keyboard.is_pressed('f8'):
                    if self.tablica_dostepu[0] == False:
                        self.pokazNapis(0)

                if keyboard.is_pressed('f9'):
                    if self.tablica_dostepu[1] == False:
                        self.pokazNapis(1)

                if keyboard.is_pressed('f10'):
                    if self.tablica_dostepu[2] == False:
                        self.pokazNapis(2)

                if keyboard.is_pressed('f11'):
                    if self.tablica_dostepu[3] == False:
                        self.pokazNapis(3)

                if keyboard.is_pressed('f12'):
                    if self.tablica_dostepu[4] == False:
                        self.pokazNapis(4)
            else:
                print("falsze")

    def pokazNapis(self, index):
        keyboard.press_and_release('\n')
        time.sleep(0.2)
        for char in self.tablica_bindow[index]:
            keyboard.press_and_release(char)
        keyboard.press_and_release('\n')
        time.sleep(3)

    def addBind(self, butt, text):
        if (butt == 'f8'):
            self.tablica_bindow[0] = text
            self.tablica_dostepu[0] = False

        if (butt == 'f9'):
            self.tablica_bindow[1] = text
            self.tablica_dostepu[1] = False

        if (butt == 'f10'):
            self.tablica_bindow[2] = text
            self.tablica_dostepu[2] = False

        if (butt == 'f11'):
            self.tablica_bindow[3] = text
            self.tablica_dostepu[3] = False

        if (butt == 'f12'):
            self.tablica_bindow[4] = text
            self.tablica_dostepu[4] = False

    def atackMove(self):
        keyboard.press('m')
        time.sleep(self.keyPressTime)
        keyboard.release('m')
        print("aa")

    def move(self):
        keyboard.press('n')
        time.sleep(self.keyPressTime)
        keyboard.release('n')
        print("move")

    def kite(self):
        try:
            self.asUpgate()
            self.atackMove()  # keyPressTime time
            time.sleep(svaf)  # svaf time
            self.move()  # keyPressTime time
            # print('pure asDelay ', atackDelay)
            fixeAsDelay = atackDelay - (svaf + 2.0 * self.keyPressTime)
            print('fixe asDelay ', fixeAsDelay)
            time.sleep(fixeAsDelay)
        except:
            print("elo")

    def asUpgate(self):
        global atackSpeed
        global atackDelay
        url = "https://127.0.0.1:2999/liveclientdata/allgamedata"
        reqe = requests.get(url, verify=False, )
        atackSpeed = reqe.json()['activePlayer']['championStats']['attackSpeed']
        print("as: ", atackSpeed)
        atackDelay = 1.0 / atackSpeed
        print("ad: ", atackDelay)
        global svaf
        svaf = 0.35 / atackSpeed
        print("sv: ", svaf)

    def changeBindedButton(self, button):
        self.bindedButton = button


#################################################
# MAIN
########

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    ui = MainApplication()
    sys.exit(app.exec_())