#include "gameclient.h"

 gameClient::gameClient(QString IP, int port, QObject *parent): m_IP(IP),m_port(port),QObject(parent),m_receivedCounter(0)
{
    //m_timerID=startTimer(1000);
     gracz_client.id = 1;
     gracz_client.wsp_x = 0;
     gracz_client.wsp_y = 0;

     gracz_coop.id = 2;
     gracz_coop.wsp_x = 11;
     gracz_coop.wsp_y = 123;

}

void gameClient::wlaczTimer()
{
    m_timerID=startTimer(100);
}

void gameClient::aktualizuj_dane(float w_x, float w_y)
{
    gracz_client.wsp_x = w_x;
    gracz_client.wsp_y = w_y;
}

bool gameClient::connect2Server()
{
    m_socket.connectToHost(m_IP,m_port);

    if(m_socket.waitForConnected())
    {

        return true;
    }
    return false;

}


void gameClient::swapData()
{

    if(connect2Server())
    {

        m_socket.write((char*)&gracz_client,sizeof(graczz));
        if(m_socket.waitForBytesWritten())
        {
            if(m_socket.waitForReadyRead())
            {
                m_socket.read((char*)&gracz_coop,sizeof(graczz));

                //emit newMessageReceived(gracz_coop);
                //emit newMessageReceived(gracz_client);
                m_socket.disconnectFromHost();
            }
        }
    }
}




void gameClient::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==m_timerID)
    {
        swapData();

    }
}
