#ifndef UNSUBMITMODEL_H
#define UNSUBMITMODEL_H

#include <QStandardItemModel>
class InfoState;
class UnsubmitModel : public QStandardItemModel
{
public:
    UnsubmitModel(InfoState &data);

protected:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    void initModel();
private:
    InfoState *m_infoData;
};

#endif // UNSUBMITMODEL_H
