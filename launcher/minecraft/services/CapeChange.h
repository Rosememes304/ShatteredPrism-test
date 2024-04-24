#pragma once

#include <minecraft/auth/MinecraftAccount.h>
#include <QFile>
#include <QtNetwork/QtNetwork>
#include <memory>
#include "QObjectPtr.h"
#include "tasks/Task.h"

class CapeChange : public Task {
    Q_OBJECT
   public:
    CapeChange(QObject* parent, MinecraftAccountPtr m_account, QString capeId);
    virtual ~CapeChange() {}

   private:
    void setCape(QString& cape);
    void clearCape();

   private:
    QString m_capeId;
    MinecraftAccountPtr m_account;
    shared_qobject_ptr<QNetworkReply> m_reply;

   protected:
    virtual void executeTask();

   public slots:
    void downloadError(QNetworkReply::NetworkError);
    void sslErrors(const QList<QSslError>& errors);
    void downloadFinished();
};
