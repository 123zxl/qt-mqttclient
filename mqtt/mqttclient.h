#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

#include <QMainWindow>
#include"mqtt/qmqtt.h"
namespace Ui {
class MqttClient;
}

class MqttClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit MqttClient(QWidget *parent = 0);
    ~MqttClient();
    QMQTT::Client *client;
private slots:
    void on_link_clicked();
    void on_sub_clicked();
    void on_pub_clicked();
    void onReceived(const QMQTT::Message& message);
private:
    Ui::MqttClient *ui;
    bool linkflag=false;
};

#endif // MQTTCLIENT_H
