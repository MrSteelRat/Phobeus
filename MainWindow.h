#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDesktopServices>
#include <QFileDialog>
#include <QUrl>
#include <QLabel>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>
#include <QCoreApplication>
#include <QPixmap>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionOpen_triggered();

    void on_actionAbout_triggered();

    void on_actionExit_triggered();

    void on_actionStableDiffsion_AI_triggered();

private:
    Ui::MainWindow *ui;
    QLabel* imageLabel;
};
#endif // MAINWINDOW_H
