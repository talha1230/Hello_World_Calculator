#include "currencyconvertermainwindow.h"
#include "qjsonobject.h"
#include "ui_currencyconvertermainwindow.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QMessageBox>

CurrencyConverterMainWindow::CurrencyConverterMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CurrencyConverterMainWindow)
{
    // Set up the UI components and connections
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &CurrencyConverterMainWindow::onManagerFinished);

    // Connect button click signal to currency conversion function
    connect(ui->currencyButton, &QPushButton::clicked, this, &CurrencyConverterMainWindow::convertCurrency);

    // Set the background color of the main window
    setStyleSheet("QMainWindow { background-color: #2c3e50; }");

    // Set the background color and text color of QTextEdit widgets
    ui->uservalue->setStyleSheet("QTextEdit {" "background-color: #34495e;" "border: 1px solid #ccc;" "border-radius: 5px;" "padding: 5px;" "color: #f0f0f0;""}");
    ui->useroutput->setStyleSheet("QTextEdit {""background-color: #34495e;" "border: 1px solid #ccc;" "border-radius: 5px;" "padding: 5px;" "color: #f0f0f0;""}");

    // Set the background color and text color of QPushButton
    ui->currencyButton->setStyleSheet("QPushButton { background-color: #3498db; color: white; padding: 5px; border-radius: 5px; }" "QPushButton:hover { background-color: #2980b9; }" "QPushButton:pressed { background-color: #1a5276; }");

    // Initialize and populate the currency combo box
    QStringList currencyList = {"USD", "EUR", "GBP", "JPY"};  // Add more currencies as needed
    QStringList desiredCurrency = {"MYR"};
    ui->currencyComboBox->addItems(currencyList);
    ui->desiredCurrencyComboBox->addItems(desiredCurrency);

    // Connect the combo box selection change signal to the appropriate slot
    connect(ui->currencyComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &CurrencyConverterMainWindow::onCurrencySelectionChanged);
}

void CurrencyConverterMainWindow::onManagerFinished(QNetworkReply* reply)
{
    // Handle the completion of the network request

    if (reply->error()) {
        // Display an error message if the request fails
        qDebug() << "Network Error: " << reply->errorString();
        QMessageBox::critical(this, "Error", "There was an issue with the currency conversion API: " + reply->errorString());
        return;
    }

    // Parse the API response
    QString answer = reply->readAll();
    qDebug() << "API Response: " << answer;  // Print the entire API response

    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());

    if (!jsonResponse.isObject()) {
        // Handle invalid JSON response
        qDebug() << "Invalid JSON response";
        QMessageBox::critical(this, "Error", "Invalid JSON response from the currency conversion API.");
        return;
    }

    QJsonObject jsonObject = jsonResponse.object();

    if (!jsonObject.contains("conversion_rates") || !jsonObject["conversion_rates"].isObject()) {
        // Handle missing or invalid conversion rates in the JSON response
        qDebug() << "Conversion rates not found in JSON response";
        QMessageBox::critical(this, "Error", "Conversion rates not found in the JSON response from the currency conversion API.");
        return;
    }

    // Extract conversion rates for the target currency
    QJsonObject conversionRatesObject = jsonObject["conversion_rates"].toObject();

    if (!conversionRatesObject.contains("MYR")) {
        // Check if the target currency exists in the conversion rates
        qDebug() << "Target currency not found in conversion rates";
        QMessageBox::critical(this, "Error", "Target currency not found in conversion rates.");
        return;
    }

    // Assign the conversion rate for the target currency
    conversionRate = conversionRatesObject["MYR"].toDouble();
}

void CurrencyConverterMainWindow::convertCurrency()
{
    // Perform currency conversion

    // Get the user input
    double input = ui->uservalue->toPlainText().toDouble();

    // Calculate the converted output
    double output = input * conversionRate;

    // Print debug information
    qDebug() << "Input: " << input;
    qDebug() << "Conversion Rate: " << conversionRate;
    qDebug() << "Output: " << output;

    // Ensure conversion rate is valid (not zero)
    if (conversionRate != 0.0) {
        // Display the converted output
        ui->useroutput->setText(QString::number(output));

        // Indicate a successful conversion
        QMessageBox::information(this, "Success", "The currency conversion has taken place successfully.");
    } else {
        // Display an error message for an invalid conversion rate
        QMessageBox::critical(this, "Error", "Invalid conversion rate. Please try again.");
    }
}

// Handle currency selection change
void CurrencyConverterMainWindow::onCurrencySelectionChanged()
{
    // Fetch the conversion rate when the currency selection changes
    manager->get(QNetworkRequest(QUrl("https://v6.exchangerate-api.com/v6/9ef329ffdad401628eca2190/latest/" + ui->currencyComboBox->currentText())));
}

CurrencyConverterMainWindow::~CurrencyConverterMainWindow()
{
    // Destructor to clean up resources
    delete ui;
}
