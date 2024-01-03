#include "currencyconvertermainwindow.h"
#include "ui_currencyconvertermainwindow.h"
#include <QNetworkRequest> // New Line added for intergating API
#include <QNetworkReply>
#include <QJsonDocument>  // Add this line
#include <QMessageBox>
#include <QJsonObject>

void CurrencyConverterMainWindow::onManagerFinished(QNetworkReply* reply)
{
    if (reply->error()) {
        qDebug() << reply->errorString();
        QMessageBox::critical(this, "Error", "There was an issue with the currency conversion API: " + reply->errorString());
        return;
    }

    QString answer = reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());

    if (!jsonResponse.isObject()) {
        qDebug() << "Invalid JSON response";
        QMessageBox::critical(this, "Error", "Invalid JSON response from the currency conversion API.");
        return;
    }

    QJsonObject jsonObject = jsonResponse.object();

    if (!jsonObject.contains("conversion_rates") || !jsonObject["conversion_rates"].isObject()) {
        qDebug() << "Conversion rates not found in JSON response";
        QMessageBox::critical(this, "Error", "Conversion rates not found in the JSON response from the currency conversion API.");
        return;
    }

    QJsonObject conversionRates = jsonObject["conversion_rates"].toObject();
    conversionRate = conversionRates["PKR"].toDouble();
}

CurrencyConverterMainWindow::CurrencyConverterMainWindow(QWidget *parent)  :
   QMainWindow(parent),
     ui(new Ui::CurrencyConverterMainWindow)
{

    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &CurrencyConverterMainWindow::onManagerFinished);
    connect(ui->currencyButton, &QPushButton::clicked, this, &CurrencyConverterMainWindow::convertCurrency);
    manager->get(QNetworkRequest(QUrl("https://v6.exchangerate-api.com/v6/9ef329ffdad401628eca2190/latest/USD"))); // Replace with your API URL
    // In your constructor or initialization code
    setStyleSheet("QPushButton { background-color: #3498db; color: white; }");

}
void CurrencyConverterMainWindow::convertCurrency()
{
    double input = ui->myr->toPlainText().toDouble(); // Replace "inputLabel" with "myr"
    double output = input * conversionRate;
    ui->pkr->setText(QString::number(output)); // Replace "outputLabel" with "pkr"
    QMessageBox::information(this, "Success", "The currency conversion has taken place successfully.");

}


CurrencyConverterMainWindow::~CurrencyConverterMainWindow()
{
    delete ui;
}
