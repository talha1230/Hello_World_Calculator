#include "nameconvertormainwindow.h"
#include "ui_nameconvertormainwindow.h"

nameconvertorMainWindow::nameconvertorMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nameconvertorMainWindow)
{
    ui->setupUi(this);

    // Apply the style sheet to the QMainWindow
    QString mainStyle = "QMainWindow {"
                        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #87CEEB, stop:1 #f0f0f0);"
                        "    border: 1px solid #87CEEB;"
                        "}";

    this->setStyleSheet(mainStyle);

    // Apply the style sheet to the QPushButton
    QString buttonStyle = "QPushButton {"
                          "    background-color: #4CAF50;"
                          "    color: white;"
                          "    padding: 10px 20px;"
                          "    border: none;"
                          "    border-radius: 5px;"
                          "}"
                          "QPushButton:hover {"
                          "    background-color: #45A049;"
                          "}"
                          "QPushButton:focus {"
                          "    outline: none;"
                          "}";

    ui->convertButton->setStyleSheet(buttonStyle);

    // Apply the style sheet to the QLabel
    QString labelStyle = "QLabel#label_ASCIIResult {"
                         "    background-color: #ffffff;"
                         "    color: #333333;"
                         "    padding: 10px;"
                         "    border: 1px solid #4CAF50;"
                         "    border-radius: 5px;"
                         "}";

    ui->label_ASCIIResult->setStyleSheet(labelStyle);

    // Connect signals and slots
    connect(ui->lineEdit_name, &QLineEdit::textChanged, this, &nameconvertorMainWindow::onConvertNameToASCII);
    connect(ui->convertButton, &QPushButton::clicked, this, &nameconvertorMainWindow::onConvertButtonClicked);
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
