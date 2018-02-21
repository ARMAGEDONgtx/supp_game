#include "webdlg.h"
#include "ui_webdlg.h"

WebDlg::WebDlg(QWidget *parent) :
    QDialog(parent), ip(""),port(0),
    ui(new Ui::WebDlg)
{
    ui->setupUi(this);
}

WebDlg::~WebDlg()
{
    delete ui;
}

void WebDlg::set_data(QString m_ip, int m_port)
{
    ui->label_ip->setText(m_ip);
    ui->label_port->setText(QString::number(m_port));
}

QString WebDlg::get_ip()
{
    return ui->label_ip->text();
}

int WebDlg::get_port()
{
    return ui->label_port->text().toInt();
}
