#include "infoState.h"
#include "QFile"
const QString filePath = "filePath.txt";
InfoState::InfoState()
{
    getList();
    init();
}

void InfoState::onStateChanged(QString name, State state)
{
    if (m_infoState.contains(name)) {
        m_infoState[name] = state;
    }
}

void InfoState::clearState()
{
    for (auto info : m_infoState.keys()) {
        m_infoState[info] = State::unsubmitted;
    }
}

void InfoState::init()
{
    for (auto info : m_infoList) {
        m_infoState.insert(info, State::unsubmitted);
    }
}

void InfoState::getList()
{
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    if (file.isOpen()) {
        while (!file.atEnd()) {
            QByteArray name = file.readLine();
            name = name.replace("\n", "");
            m_infoList.append(name);
        }
    }
}

QList<QString> InfoState::getInfoList() const
{
    return m_infoList;
}

QMap<QString, State> InfoState::getInfoState() const
{
    return m_infoState;
}

QList<QString> InfoState::getUnSubmit()
{
    QList<QString> unsubmit;
    for (auto info : m_infoState.keys()) {

        if (m_infoState.value(info) == State::unsubmitted) {
            unsubmit.append(info);
        }
    }
    return unsubmit;
}

QList<QString> InfoState::getSubmit()
{
    QList<QString> submit;
    for (auto info : m_infoState.keys()) {
        if (m_infoState.value(info) == State::submitted) {
            submit.append(info);
        }
    }
    return submit;
}


