#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QTimerEvent>

struct sRamka
{
   int ID_transakcji;
   int rozmiar;
   char text[100];
};
struct graczz
{
    int id;
    float wsp_x;
    float wsp_y;
};

class gameClient : public QObject
{
   Q_OBJECT

public:
   explicit gameClient(QString IP="", int port=0, QObject *parent = 0);

   int getPort() { return m_port; }
   QString getIP() { return m_IP; }
   void setPort(int port) { m_port=port; }
   void setIP(QString ip) { m_IP=ip; }
   graczz gracz_client;
   graczz gracz_coop;
   void wlaczTimer();
   void aktualizuj_dane(float w_x,float w_y);
   bool connect2Server();
protected:
   void timerEvent(QTimerEvent *event);
public slots:
   void swapData();
signals:
   void newMessageReceived(graczz);
private:


   QTcpSocket m_socket;
   QString m_IP;
   int m_port;
   int m_timerID;
   int m_receivedCounter;
};

#endif // GAMECLIENT_H
