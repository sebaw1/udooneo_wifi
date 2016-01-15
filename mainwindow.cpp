#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QtNetwork/QNetworkInterface>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    sName = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                QStandardPaths::writableLocation(QStandardPaths::TempLocation),
                "Binary Files (*.bin)");

    ui->lineEdit->setText(sName);
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Select directory!", QMessageBox::Ok);

        return;
    }
    if(ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Select IP!", QMessageBox::Ok);

        return;
    }

    char chFormat[250];
    sprintf(chFormat, "C:\\Users\\Dom\\AppData\\Roaming\\Arduino15\\packages\\UDOO\\tools\\udooclient\\1.0\\udooclient.exe %s:5152 %s", ui->lineEdit_2->text().toStdString().c_str(), sName.toStdString().c_str());

    system(chFormat);

    qDebug() << chFormat;
}
