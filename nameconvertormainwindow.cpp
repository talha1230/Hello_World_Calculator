#include "nameconvertormainwindow.h"
#include "ui_nameconvertormainwindow.h"

nameconvertorMainWindow::nameconvertorMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nameconvertorMainWindow)
{
    ui->setupUi(this);

    // Connect the signal to the slot for textChanged
    connect(ui->lineEdit_name, &QLineEdit::textChanged, this, &nameconvertorMainWindow::onConvertNameToASCII);
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
    QString finalMessage = "Your Name in ASCII is : " + asciiResult.trimmed();

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