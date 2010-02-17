import sys
from PyQt4 import QtCore, QtGui

from test_ui import Ui_Translate


class MyForm(QtGui.QMainWindow):
	def __init__(self, parent=None):
		QtGui.QWidget.__init__(self, parent)
		self.ui = Ui_Translate()
		self.ui.setupUi(self)
		QtCore.QObject.connect(self.ui.addButton,QtCore.SIGNAL('clicked()'), self.add)
	
	def add(self):
		text = self.ui.textLine.text
		self.ui.textLine.setText(text + text)


if __name__ == '__main__':
	app = QtGui.QApplication(sys.argv)
	myapp = MyForm()
	myapp.show()
	sys.exit(app.exec_())


