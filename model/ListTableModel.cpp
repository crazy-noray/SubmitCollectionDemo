#include "ListTableModel.h"
#include "infoState.h"
#include <QDebug>
ListTableModel::ListTableModel(InfoState &data)
    : m_infoData(&data)
{
    initModel();
    this->setHeaderData(0, Qt::Horizontal, "姓名");
    this->setHeaderData(1, Qt::Horizontal, "是否提交");
}

void ListTableModel::onStateChanged(const QModelIndex &index)
{
    if (index.column() != 1) {
        return;
    }
    if (index.row() < 0 || index.row() > m_infoData->getInfoList().size()) {
        return;
    }
    if (m_infoData->getInfoState().value(m_infoData->getInfoList().value(index.row())) == submitted) {
        m_infoData->onStateChanged(m_infoData->getInfoList().value(index.row()), State::unsubmitted);
    } else {
        m_infoData->onStateChanged(m_infoData->getInfoList().value(index.row()), State::submitted);
    }

}

void ListTableModel::initModel()
{
    int index = 0;
    auto studentsState = m_infoData->getInfoState();
    for (auto student : studentsState.keys()) {
        initNameItem(index, student);
        initCheckStateItem(index, studentsState.value(student));
        index ++;
    }
}

void ListTableModel::initNameItem(int index, QString name)
{
    QStandardItem *item = new QStandardItem();
    item->setCheckable(false);
    item->setEditable(false);
    item->setText(name);
    this->setItem(index, 0, item);
}

void ListTableModel::initCheckStateItem(int index, bool isChecked)
{
    QStandardItem *item = new QStandardItem();
    item->setCheckable(true);
    item->setCheckState((isChecked ? Qt::Checked : Qt::Unchecked));
    item->setEditable(false);
    this->setItem(index, 1, item);
}

QVariant ListTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return m_infoData->getInfoList().value(index.row());
        } else if (index.column() == 1) {
            if (m_infoData->getInfoState().value(m_infoData->getInfoList().value(index.row())) == submitted)
                return "已提交";
            else
                return "未提交";
        }
    }
    return QVariant();
}

