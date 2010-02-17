# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'test.ui'
#
# Created: Wed Feb 17 11:39:30 2010
#      by: PyQt4 UI code generator 4.5.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

class Ui_Translate(object):
    def setupUi(self, Translate):
        Translate.setObjectName("Translate")
        Translate.resize(266, 379)
        self.addButton = QtGui.QPushButton(Translate)
        self.addButton.setGeometry(QtCore.QRect(80, 60, 100, 30))
        self.addButton.setObjectName("addButton")
        self.textLine = QtGui.QLineEdit(Translate)
        self.textLine.setGeometry(QtCore.QRect(60, 20, 150, 24))
        self.textLine.setObjectName("textLine")
        self.textField = QtGui.QPlainTextEdit(Translate)
        self.textField.setGeometry(QtCore.QRect(20, 100, 221, 221))
        self.textField.setObjectName("textField")
        self.cleanButton = QtGui.QPushButton(Translate)
        self.cleanButton.setGeometry(QtCore.QRect(150, 340, 91, 27))
        self.cleanButton.setObjectName("cleanButton")
        self.saveButton = QtGui.QPushButton(Translate)
        self.saveButton.setGeometry(QtCore.QRect(20, 340, 91, 27))
        self.saveButton.setObjectName("saveButton")

        self.retranslateUi(Translate)
        QtCore.QMetaObject.connectSlotsByName(Translate)

    def retranslateUi(self, Translate):
        Translate.setWindowTitle(QtGui.QApplication.translate("Translate", "Form", None, QtGui.QApplication.UnicodeUTF8))
        self.addButton.setText(QtGui.QApplication.translate("Translate", "Dodaj", None, QtGui.QApplication.UnicodeUTF8))
        self.cleanButton.setText(QtGui.QApplication.translate("Translate", "Wyczyść", None, QtGui.QApplication.UnicodeUTF8))
        self.saveButton.setText(QtGui.QApplication.translate("Translate", "Zapisz", None, QtGui.QApplication.UnicodeUTF8))

