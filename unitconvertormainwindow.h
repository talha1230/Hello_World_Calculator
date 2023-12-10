// do not try to play with comments
#ifndef UNITCONVERTORMAINWINDOW_H
#define UNITCONVERTORMAINWINDOW_H

#include <QMainWindow>
#include<convertcm.h>//unit convertor window
#include <QPlainTextEdit>

namespace Ui {
class UnitConvertorMainWindow;
}

class UnitConvertorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UnitConvertorMainWindow(QWidget *parent = nullptr);
    ~UnitConvertorMainWindow();

    convertcm * pconvertcm=NULL;// ADDRESS OF WINDOW UNIT CONVERTOR

signals:
    void back();


private:
    Ui::UnitConvertorMainWindow *ui;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_4;

private slots:
    void onPlainTextEditTextChangedLength();
    void onPlainTextEditTextChangedArea();


};


#endif // UNITCONVERTORMAINWINDOW_H
