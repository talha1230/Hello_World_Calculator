#ifndef CURRENCYCONVERTERMAINWINDOW_H
#define CURRENCYCONVERTERMAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager> // New Line added for intergating API

namespace Ui {
class CurrencyConverterMainWindow;
}

class CurrencyConverterMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CurrencyConverterMainWindow(QWidget *parent = nullptr);
    ~CurrencyConverterMainWindow();

private:
    Ui::CurrencyConverterMainWindow *ui;
    QNetworkAccessManager* manager; // New Line added for intergating API
    double conversionRate;  // Declare 'conversionRate' as a member variable

public slots:
    void onManagerFinished(QNetworkReply *reply);
    void convertCurrency();
    void onCurrencySelectionChanged();


};

#endif // CURRENCYCONVERTERMAINWINDOW_H
