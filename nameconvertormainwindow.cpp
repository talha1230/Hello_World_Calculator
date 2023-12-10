// do not try to play with comments
#include "nameconvertormainwindow.h"
#include "ui_nameconvertormainwindow.h"


// nameconvertormainwindow.cpp



nameconvertorMainWindow::nameconvertorMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nameconvertorMainWindow)
{
    ui->setupUi(this);

    // Connect the signal to the slot for textChanged
   // connect(ui->text_form, &QPlainTextEdit::textChanged, this, &nameconvertorMainWindow::onPlainTextEditTextChangedLength);
    connect(ui->lineEdit_name, &QLineEdit::textChanged, this, &nameconvertorMainWindow::onConvertNameToASCII);
    connect(ui->convertButton, &QPushButton::clicked, this, &nameconvertorMainWindow::onConvertButtonClicked);

    // Other setup code
}

void nameconvertorMainWindow::onPlainTextEditTextChangedLength() {
    // Your implementation here
}

// Rest of your implementation
void nameconvertorMainWindow::onConvertButtonClicked() {
    // Your implementation here
   // QString inputValue = ui->text_form->toPlainText();
  //  QString asciiOutput;
  //  for (QChar character : inputValue) {
 //       asciiOutput += QString::number(character.toLatin1()) + " ";
 //   }
}
//
void nameconvertorMainWindow::onConvertNameToASCII() {
    // Get the input value from the QLineEdit
    QString name = ui->lineEdit_name->text();

    // Convert the name to ASCII
    QString asciiResult;
    for (QChar character : name) {
        asciiResult += QString::number(character.toLatin1()) + " ";
    }

    // Update the label with the ASCII result
    ui->label_ASCIIResult->clear();  // Clear previous text
    ui->label_ASCIIResult->setPlainText(asciiResult);  // Use setPlainText here

    ui->label_ASCIIResult->setPlainText("Your Name in ASCII is : " + asciiResult);
}
nameconvertorMainWindow::~nameconvertorMainWindow()
{
    delete ui;
}
