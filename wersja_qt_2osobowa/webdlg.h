#ifndef WEBDLG_H
#define WEBDLG_H

#include <QDialog>

namespace Ui {
class WebDlg;
}

class WebDlg : public QDialog
{
    Q_OBJECT

public:
    explicit WebDlg(QWidget *parent = 0);
    ~WebDlg();
    void set_data(QString m_ip,int m_port);
    QString get_ip();
    int get_port();
private:
    QString ip;
    int port;
    Ui::WebDlg *ui;
};

#endif // WEBDLG_H
