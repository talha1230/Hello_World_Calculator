#include "nameconvertormainwindow.h"
#include "ui_nameconvertormainwindow.h"

nameconvertorMainWindow::nameconvertorMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nameconvertorMainWindow)
{
    ui->setupUi(this);

    // Apply the style sheet to the QMainWindow
    QString mainStyle = "QMainWindow {"
                        "    background-color: #2c3e50;" // Dark blue background
                        "}";

    this->setStyleSheet(mainStyle);

    // Apply the style sheet to the QPushButton
    QString buttonStyle = "QPushButton {"
                          "    background-color: #3498db;" // Bright blue background
                          "    color: white;" // White text
                          "    border: none;" // No border
                          "    border-radius: 5px;" // Rounded corners
                          "    padding: 5px 10px;" // Some padding
                          "}"
                          "QPushButton:hover {"
                          "    background-color: #2980b9;" // Slightly darker blue when hovered over
                          "}"
                          "QPushButton:pressed {"
                          "    background-color: #1a5276;" // Even darker when pressed
                          "}";

    ui->convertButton->setStyleSheet(buttonStyle);

    // Apply the style sheet to the QLineEdit
    QString lineEditStyle = "QLineEdit {"
                            "    background-color: #ecf0f1;" // Light gray background
                            "    color: ##2c3e50;" // Dark blue text
                            "    border: none;" // No border
                            "    border-radius: 5px;" // Rounded corners
                            "    padding: 5px;" // Some padding
                            "}";

    ui->lineEdit_name->setStyleSheet(lineEditStyle);

    // Apply the style sheet to the QLabel
    QString labelStyle = "QLabel {"
                         "    background-color: #ecf0f1;" // Light gray background
                         "    color: ##2c3e50;" // Dark blue text
                         "    border: none;" // No border
                         "    border-radius: 5px;" // Rounded corners
                         "    padding: 5px;" // Some padding
                         "}";


    ui->label_ASCIIResult->setStyleSheet(labelStyle);



    // Connect signals and slots
    connect(ui->lineEdit_name, &QLineEdit::returnPressed, this, &nameconvertorMainWindow::onConvertButtonClicked);
    connect(ui->convertButton, &QPushButton::clicked, this, &nameconvertorMainWindow::onConvertButtonClicked);
}

void nameconvertorMainWindow::onPlainTextEditTextChangedLength() {
    // Your implementation here
}

void nameconvertorMainWindow::onConvertNameToASCII() {
    // Get the input value from the QLineEdit
    QString name = ui->lineEdit_name->text();

    // Convert the name to ASCII
    QString asciiResult;
    for (QChar character : name) {
        asciiResult += QString::number(character.toLatin1()) + " ";
    }

    // Prepare the final message to display
    QString finalMessage = "" + asciiResult.trimmed();

    // Clear the label and set the new text
    ui->label_ASCIIResult->clear();
    ui->label_ASCIIResult->setPlainText(finalMessage);
}

void nameconvertorMainWindow::onConvertButtonClicked() {
    // Trigger the conversion when the button is clicked
    onConvertNameToASCII();
}

nameconvertorMainWindow::~nameconvertorMainWindow()
{
    delete ui;
}
