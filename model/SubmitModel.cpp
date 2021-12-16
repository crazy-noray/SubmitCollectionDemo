#include "SubmitModel.h"
#include "infoState.h"
#include <QDebug>
SubmitModel::SubmitModel(InfoState &data)
    : m_infoData(&data)
{
    initModel();
}

QVariant SubmitModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return m_infoData->getSubmit().value(index.row());
    }
    return QVariant();
}

void SubmitModel::initModel()
{
    auto studentList = m_infoData->getUnSubmit();
    int size = studentList.size();
    for (auto index = 0; index < size; ++index) {
        QStandardItem *item = new QStandardItem();
        item->setCheckable(false);
        item->setEditable(false);
        item->setText(studentList.value(index));
        this->setItem(index, 0, item);
    }
}
