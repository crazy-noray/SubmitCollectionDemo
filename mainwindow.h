#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class ListTableModel;
class SubmitModel;
class UnsubmitModel;
class InfoState;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    InfoState *m_infoState = nullptr;
    ListTableModel *m_Tablemodel = nullptr;
    SubmitModel *m_submitModel = nullptr;
    UnsubmitModel *m_unsubmitModel = nullptr;


};

#endif // MAINWINDOW_H
