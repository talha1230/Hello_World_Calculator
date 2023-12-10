// do not try to play with comments
#include "unitconvertormainwindow.h"
#include "ui_unitconvertormainwindow.h"
#include<QPushButton>
#include<QDebug>
#include<QMessageBox>

UnitConvertorMainWindow::UnitConvertorMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UnitConvertorMainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    QStringList strList;
    strList << "Length" << "Temperature" << "Speed" << "Area" << "Fuel" <<"Angle" << "Volume" << "Weight" << "Preasure";

//    for(int i = 0; i<strList.size(); i++){
//        QListWidgetItem *pItem = new QListWidgetItem();
//        pItem->setSizeHint(QSize(50,50));
//        pItem->setTextAlignment(Qt::AlignCenter);
//        pItem->setText(strList.at(i));
//        ui->listWidget->insertItem(i,pItem);
//    } TESTING FOR SET AS TEXT

//    connect(ui->listWidget,&QListWidget::currentRowChanged,[=](int index)
//    {
//        qDebug()<<"index ="<<index;
//    }); DEBUG OF SEE THE VALUE (THE VALUE RETURN WIHT CORRECT VALUE, GOOD JOB TEAM)

    QIcon icon0(":/Images/Angle.png");
    QListWidgetItem * pItem0 = new QListWidgetItem(icon0,"");
    ui->listWidget->insertItem(0,pItem0);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon1(":/Images/Length.png");
    QListWidgetItem * pItem1 = new QListWidgetItem(icon1,"");
    ui->listWidget->insertItem(1,pItem1);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon2(":/Images/Fuel.png");
    QListWidgetItem * pItem2 = new QListWidgetItem(icon2,"");
    ui->listWidget->insertItem(2,pItem2);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon3(":/Images/Area.png");
    QListWidgetItem * pItem3 = new QListWidgetItem(icon3,"");
    ui->listWidget->insertItem(3,pItem3);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon4(":/Images/Pressure.png");
    QListWidgetItem * pItem4 = new QListWidgetItem(icon4,"");
    ui->listWidget->insertItem(4,pItem4);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon5(":/Images/Speed.png");
    QListWidgetItem * pItem5 = new QListWidgetItem(icon5,"");
    ui->listWidget->insertItem(5,pItem5);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon6(":/Images/Temperature.png");
    QListWidgetItem * pItem6 = new QListWidgetItem(icon6,"");
    ui->listWidget->insertItem(6,pItem6);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon7(":/Images/Volume.png");
    QListWidgetItem * pItem7 = new QListWidgetItem(icon7,"");
    ui->listWidget->insertItem(7,pItem7);
    ui->listWidget->setIconSize(QSize(50,50));

    QIcon icon8(":/Images/Weight.png");
    QListWidgetItem * pItem8 = new QListWidgetItem(icon8,"");
    ui->listWidget->insertItem(8,pItem8);
    ui->listWidget->setIconSize(QSize(50,50));

    connect(ui->listWidget,&QListWidget::currentRowChanged,[=](int index)
    {
        ui->stackedWidget->setCurrentIndex(index);
    });

    plainTextEdit_2 = ui->plainTextEdit_2;
    // Connect the signal textChanged to a custom slot
    connect(plainTextEdit_2, &QPlainTextEdit::textChanged, this, &UnitConvertorMainWindow::onPlainTextEditTextChangedLength);

    plainTextEdit_4 = ui->plainTextEdit_4;
    // Connect the signal textChanged to a custom slot
    connect(plainTextEdit_4, &QPlainTextEdit::textChanged, this, &UnitConvertorMainWindow::onPlainTextEditTextChangedArea);


    connect(ui->back,&QPushButton::clicked,[=](){
        emit this->back();
    });
}

    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_14;
    QLabel *label_17;
    QLabel *label_16;


void UnitConvertorMainWindow::onPlainTextEditTextChangedLength() {
    // Get the input value from plainTextEdit_2
    QString inputValue = plainTextEdit_2->toPlainText();

    // Check if the input is a valid number
    bool isNumber;
    double value = inputValue.toDouble(&isNumber);

    if (!isNumber) {
        QMessageBox::critical(this, "Error", "Please enter a valid number");
    }

    // Convert the input to different units
    double valueInMeter = value / 100.0;         // Centimeter to Meter
    double valueInKilometer = value / 100000.0;  // Centimeter to Kilometer
    double valueInMillimeter = value * 10.0;     // Centimeter to Millimeter
    double valueInInch = value * 0.393701;       // Centimeter to Inch
    double valueInFoot = value * 0.0328084;      // Centimeter to Foot
    double valueInYard = value * 0.0109361;      // Centimeter to Yard

    // Update the labels with the converted values
    ui->label_12->setText(QString::number(valueInMeter) + " m");
    ui->label_13->setText(QString::number(valueInKilometer) + " km");
    ui->label_15->setText(QString::number(valueInMillimeter) + " mm");
    ui->label_14->setText(QString::number(valueInInch) + " in");
    ui->label_17->setText(QString::number(valueInFoot) + " ft");
    ui->label_16->setText(QString::number(valueInYard) + " yd");
}

    QPlainTextEdit *plainTextEdit_4;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_27;
    QLabel *label_26;
    QLabel *label_29;
    QLabel *label_28;

void UnitConvertorMainWindow::onPlainTextEditTextChangedArea() {
    // Get the input value from plainTextEdit_2
    QString inputValue = plainTextEdit_4->toPlainText();

    // Check if the input is a valid number
    bool isNumber;
    double value = inputValue.toDouble(&isNumber);

    if (!isNumber) {
        // Show an error message
        QMessageBox::critical(this, "Error", "Please enter a valid number");
        return;
    }

    // Convert the input to various square units
    double valueInSquareKilometer = value * 1.0e-10;         // Square Centimeter to Square Kilometer
    double valueInSquareFoot = value * 0.00107639;            // Square Centimeter to Square Foot
    double valueInSquareMeter = value * 0.0001;               // Square Centimeter to Square Meter
    double valueInHectare = value * 0.00000001;               // Square Centimeter to Hectare
    double valueInAcre = value * 2.47105e-08;                 // Square Centimeter to Acre
    double valueInSquareMillimeter = value * 100.0;           // Square Centimeter to Square Millimeter

    // Update the labels with the converted values
    ui->label_24->setText(QString::number(valueInSquareKilometer) + " km²");
    ui->label_25->setText(QString::number(valueInSquareFoot) + " ft²");
    ui->label_27->setText(QString::number(valueInSquareMeter) + " m²");
    ui->label_26->setText(QString::number(valueInHectare) + " ha");
    ui->label_29->setText(QString::number(valueInAcre) + " acres");
    ui->label_28->setText(QString::number(valueInSquareMillimeter) + " mm²");
}

UnitConvertorMainWindow::~UnitConvertorMainWindow()
{
    delete ui;
}


