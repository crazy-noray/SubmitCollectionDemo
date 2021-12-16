#ifndef LISTTABLEMODEL_H
#define LISTTABLEMODEL_H

#include <QObject>
#include <QStandardItemModel>
class InfoState;
class ListTableModel : public QStandardItemModel
{
    Q_OBJECT
public:
    ListTableModel(InfoState &data);
public slots:
    void onStateChanged(const QModelIndex &index);


private:
    void initModel();
    void initNameItem(int index, QString name);
    void initCheckStateItem(int index, bool isChecked);
protected:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    InfoState *m_infoData;
};

#endif // LISTTABLEMODEL_H
