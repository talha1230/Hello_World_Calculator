#include <QtTest>
#include "nameconvertormainwindow.h"

class NameConvertorMainWindowTest : public QObject
{
    Q_OBJECT

private slots:
    void testConvertNameToASCII_data();
    void testConvertNameToASCII();

};

void NameConvertorMainWindowTest::testConvertNameToASCII_data()
{
    QTest::addColumn<QString>("inputName");
    QTest::addColumn<QString>("expectedResult");

    QTest::newRow("Empty Name") << "" << "";
    QTest::newRow("Single Character Name") << "A" << "65 ";
    QTest::newRow("Multiple Character Name") << "John" << "74 111 104 110 ";
}

void NameConvertorMainWindowTest::testConvertNameToASCII()
{
    QFETCH(QString, inputName);
    QFETCH(QString, expectedResult);

    nameconvertorMainWindow mainWindow;
    mainWindow.ui->lineEdit_name->setText(inputName);
    mainWindow.onConvertNameToASCII();

    QCOMPARE(mainWindow.ui->label_ASCIIResult->toPlainText(), "Your Name in ASCII is : " + expectedResult);
}

QTEST_APPLESS_MAIN(NameConvertorMainWindowTest)

#include "nameconvertormainwindow_test.moc"