#include <QDesktopServices>
#include <QFileDialog>
#include <QUrl>
#include <QLabel>
#include <QMessageBox>
#include <QProcess>
#include <opencv4/opencv2/opencv.hpp>
#include <QDebug>
#include <QCoreApplication>
#include <QPixmap>

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // создаем экземпляр QLabel для отображения изображения
    imageLabel = new QLabel(this);
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);


    // добавляем QLabel в centralwidget
    setCentralWidget(imageLabel);
}

MainWindow::~MainWindow()
{
    delete imageLabel;
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    // открываем диалоговое окно выбора файла
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("*.png *.xpm *.jpg"));

    // загружаем изображение из выбранного файла
    QImage image(fileName);
    if (image.isNull()) {
        QMessageBox::warning(this, tr("Image Viewer"),
                             tr("Cannot load %1.").arg(QDir::toNativeSeparators(fileName)));
        return;
    }

    // отображаем изображение на QLabel
    imageLabel->setPixmap(QPixmap::fromImage(image));
    imageLabel->adjustSize();
}


void MainWindow::on_actionAbout_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/MrSteelRat/Phobeus", QUrl::TolerantMode));
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionStableDiffsion_AI_triggered()
{

}
