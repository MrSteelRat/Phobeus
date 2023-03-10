#include <QDesktopServices>
#include <QFileDialog>
#include <QUrl>

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.png *.xpm *.jpg)"));
}

void MainWindow::on_actionAbout_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/MrSteelRat/Phobeus", QUrl::TolerantMode));
}

void MainWindow::on_actionExit_triggered()
{
    close();
}
