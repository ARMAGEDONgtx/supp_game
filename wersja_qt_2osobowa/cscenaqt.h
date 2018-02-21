#ifndef CSCENAQT_H
#define CSCENAQT_H

#include <QWidget>
#include <QGLWidget>
#include "gameclient.h"
#include "SOIL.h"
class cScenaQt : public QGLWidget
{
    Q_OBJECT        // must include this if you use Qt signals/slots

public:
    cScenaQt(QWidget *parent);

protected:

    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();
    void mouseMoveEvent(QMouseEvent * event);
    void keyPressEvent(QKeyEvent* e);
    void keyReleaseEvent(QKeyEvent* e);
    void timerEvent(QTimerEvent *event);
public slots:
    //void newData(graczz player);
private:
    QString ip;
    int port;
    gameClient *client;
    float m_x,m_y;
    int m_timer_id;
    int m_timer_id2;
};

#endif // CSCENAQT_H
