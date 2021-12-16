#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ListTableModel.h"
#include "SubmitModel.h"
#include "UnsubmitModel.h"
#include "infoState.h"

#include <QStandardItem>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_infoState(new InfoState),
    m_Tablemodel(new ListTableModel(*m_infoState)),
    m_submitModel(new SubmitModel(*m_infoState)),
    m_unsubmitModel(new UnsubmitModel(*m_infoState))
{

    ui->setupUi(this);
    ui->tableView->setModel(m_Tablemodel);
    ui->listView->setModel(m_submitModel);
    ui->listView_2->setModel(m_unsubmitModel);
    connect(ui->tableView, &QTableView::doubleClicked, m_Tablemodel, &ListTableModel::onStateChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}
