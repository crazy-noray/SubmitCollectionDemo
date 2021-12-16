#ifndef DATA_H
#define DATA_H
#include <QObject>
#include <QMap>
enum State {
    unsubmitted,
    submitted,
};

class InfoState : public QObject
{
public:
    InfoState();
    void clearState();

    QList<QString> getUnSubmit();
    QList<QString> getSubmit();
    QMap<QString, State> getInfoState() const;
    QList<QString> getInfoList() const;
    void onStateChanged(QString name, State state);

private:
    void init();
    void getList();
private:
    QMap<QString, State> m_infoState;
    QStringList m_infoList;
};

#endif // DATA_H
