// do not try to play with comments
#ifndef NAMECONVERTORMAINWINDOW_H
#define NAMECONVERTORMAINWINDOW_H

#include "qplaintextedit.h"
#include <QMainWindow>

namespace Ui {
class nameconvertorMainWindow;
}

class nameconvertorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit nameconvertorMainWindow(QWidget *parent = nullptr);
    ~nameconvertorMainWindow();
//signals:
 //   void backButton();

private:
    Ui::nameconvertorMainWindow *ui;
    QPlainTextEdit *plainTextEdit_4;
private slots:
    void onPlainTextEditTextChangedLength();
   // void onPlainTextEditTextChangedArea();
    void onConvertButtonClicked();  // Declaration of the function
    void onConvertNameToASCII();  // Declaration of the function
    //void onBackButtonClicked();


};

#endif // NAMECONVERTORMAINWINDOW_H
