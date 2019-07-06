#include "mqttclient.h"
#include <QApplication>
//#include"mqtt/qmqtt.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MqttClient w;
     QIcon icon(":/rc/mqtt.ico");
     w.setWindowIcon(icon);
    w.setWindowTitle("MqttClient");
    w.show();

    return a.exec();
}


//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);


//    QMQTT::Client *client = new QMQTT::Client(QHostAddress("192.168.1.15"), 1883);
//  // QMQTT::Client *client =new QMQTT::Client(QHostAddress::LocalHost, 1883);

//    client->setClientId("clientId");
//    client->setUsername("user");
//    client->setPassword("password");
//    client->connectToHost();
//    return a.exec();
//}
