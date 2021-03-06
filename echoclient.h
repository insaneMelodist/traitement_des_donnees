#ifndef ECHOCLIENT_H
#define ECHOCLIENT_H

#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>
#include <iostream>
//#include <Qtcore/QDebug>
#include <string>
using namespace std;

class EchoClient : public QObject
{
    Q_OBJECT
public:
    explicit EchoClient(const QUrl &url, bool debug = false, QObject *parent = Q_NULLPTR);
	void traitement(QString message);
Q_SIGNALS:
    void closed();

private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);

private:
    QWebSocket m_webSocket;
    QUrl m_url;
    bool m_debug;
};

#endif // ECHOCLIENT_H
