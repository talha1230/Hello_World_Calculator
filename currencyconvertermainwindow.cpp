#include "currencyconvertermainwindow.h"
#include "ui_currencyconvertermainwindow.h"
#include <QNetworkRequest> // Include necessary header for integrating API
#include <QNetworkReply>
#include <QJsonDocument>  // Include necessary header for JSON parsing
#include <QMessageBox>
#include <QJsonObject>

void CurrencyConverterMainWindow::onManagerFinished(QNetworkReply* reply)
{
    // Handle network request completion
    if (reply->error()) {
        qDebug() << reply->errorString();
        QMessageBox::critical(this, "Error", "There was an issue with the currency conversion API: " + reply->errorString());
        return;
    }

    // Read and parse the API response
    QString answer = reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());

    if (!jsonResponse.isObject()) {
        qDebug() << "Invalid JSON response";
        QMessageBox::critical(this, "Error", "Invalid JSON response from the currency conversion API.");
        return;
    }

    // Extract conversion rates from JSON
    QJsonObject jsonObject = jsonResponse.object();

    if (!jsonObject.contains("conversion_rates") || !jsonObject["conversion_rates"].isObject()) {
        qDebug() << "Conversion rates not found in JSON response";
        QMessageBox::critical(this, "Error", "Conversion rates not found in the JSON response from the currency conversion API.");
        return;
    }

    QJsonObject conversionRates = jsonObject["conversion_rates"].toObject();
    conversionRate = conversionRates["MYR"].toDouble();  // Assuming MYR is the target currency
}

CurrencyConverterMainWindow::CurrencyConverterMainWindow(QWidget *parent)  :
   QMainWindow(parent),
     ui(new Ui::CurrencyConverterMainWindow)
{
    // Initialize the main window
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &CurrencyConverterMainWindow::onManagerFinished);

    // Connect button click signal to currency conversion function
    connect(ui->currencyButton, &QPushButton::clicked, this, &CurrencyConverterMainWindow::convertCurrency);
    manager->get(QNetworkRequest(QUrl("https://v6.exchangerate-api.com/v6/9ef329ffdad401628eca2190/latest/USD"))); // Replace with your API URL

    // Set the background color of the main window
    setStyleSheet("QMainWindow { background-color: #2c3e50;  }");

    // Set the background color and text color of QTextEdit widgets
    ui->uservalue->setStyleSheet("QTextEdit {"
                                 "background-color: #34495e;"  
                                 "border: 1px solid #ccc;"        
                                 "border-radius: 5px;"            
                                 "padding: 5px;"                  
                                 "color: #f0f0f0;"                   
                                 "}");
    ui->useroutput->setStyleSheet("QTextEdit {"
                                  "background-color: #34495e;"  
                                  "border: 1px solid #ccc;"        
                                  "border-radius: 5px;"            
                                  "padding: 5px;"                 
                                  "color: #f0f0f0;"                   
                                  "}");

    // Set the background color and text color of QPushButton
    ui->currencyButton->setStyleSheet("QPushButton { background-color: #3498db; color: white; padding: 5px; border-radius: 5px; }"
                                      "QPushButton:hover { background-color: #2980b9; }"
                                      "QPushButton:pressed { background-color: #1a5276; }");
}

void CurrencyConverterMainWindow::convertCurrency()
{
    // Perform currency conversion
    double input = ui->uservalue->toPlainText().toDouble();
    double output = input * conversionRate;
    ui->useroutput->setText(QString::number(output));
    QMessageBox::information(this, "Success", "The currency conversion has taken place successfully.");
}

CurrencyConverterMainWindow::~CurrencyConverterMainWindow()
{
    // Destructor to clean up resources
    delete ui;
}
