#include "UnsubmitModel.h"
#include "infoState.h"
UnsubmitModel::UnsubmitModel(InfoState &data)
    : m_infoData(&data)
{
    initModel();
}

QVariant UnsubmitModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return m_infoData->getUnSubmit().value(index.row());
    }
    return QVariant();
}

void UnsubmitModel::initModel()
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
