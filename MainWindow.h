#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QUrl>
#include <QMainWindow>
#include <QDesktopServices>

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
    void on_actionAbout_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;

    void CreateActions();
    void createMenus();

    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuTool;
    QMenu *menuInfo;
};
#endif // MAINWINDOW_H
