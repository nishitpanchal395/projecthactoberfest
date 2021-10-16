#GUI Calculator in Python

import sys
from PyQt4.QtGui import *
#from PyQt4 import QtGui
 
app = QApplication(sys.argv)
widget = QWidget()
label = QLabel("", widget)
 
btnAdd = QPushButton("Add", widget)
btnSub = QPushButton("Subtract", widget)
btnDiv = QPushButton("Divide", widget)
btnMul = QPushButton("Multiply", widget)
 
txtArea1 = QLineEdit("", widget)
txtArea2 = QLineEdit("", widget)
 
def init():
 
    widget.resize(300, 300)
    widget.move(300, 300)
    widget.setWindowTitle('Calculator')
    widget.show()
 
    txtArea1.move(20,10)
    txtArea1.show()
    txtArea2.move(20,60)
    txtArea2.show()
 
    label.setText("")
    label.move(20,110)
    label.show()
 
    btnAdd.setToolTip('Addition')
    btnAdd.move(20,160)
    btnAdd.clicked.connect(addition)
    btnAdd.show()
 
    btnSub.setToolTip('Subtraction')
    btnSub.move(110,160)
    btnSub.clicked.connect(subtraction)
    btnSub.show()
 
    btnDiv.setToolTip('Division')
    btnDiv.move(20,210)
    btnDiv.clicked.connect(division)
    btnDiv.show()
 
    btnMul.setToolTip('Multiplication')
    btnMul.move(110,210)
    btnMul.clicked.connect(multiplication)
    btnMul.show()
 
 
def addition():
    num1 = int(txtArea1.text())
    num2 = int(txtArea2.text())
    label.setFixedWidth(200)
    label.setText("Addition: "+str(num1 + num2))
 
def subtraction():
    num1 = int(txtArea1.text())
    num2 = int(txtArea2.text())
    label.setFixedWidth(200)
    label.setText("Subtraction: "+str(num1 - num2))
 
def multiplication():
    num1 = int(txtArea1.text())
    num2 = int(txtArea2.text())
    label.setFixedWidth(200)
    label.setText("Multiplication: "+str(num1 * num2))
 
def division():
    num1 = int(txtArea1.text())
    num2 = int(txtArea2.text())
    label.setFixedWidth(200)
    label.setText("Division: "+str(num1 / num2))
 
if __name__ == "__main__":
     init()
 
app.exec_()
