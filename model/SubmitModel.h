#ifndef STATELISTMODEL_H
#define STATELISTMODEL_H

#include <QObject>
#include <QStandardItemModel>

class InfoState;

class SubmitModel : public QStandardItemModel
{
    Q_OBJECT
public:
    SubmitModel(InfoState &data);

protected:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    void initModel();
private:
    InfoState *m_infoData;
};

#endif // STATELISTMODEL_H
