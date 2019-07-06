#include "mqttclient.h"
#include "ui_mqttclient.h"
#include "qdebug.h"
#include <QElapsedTimer>
MqttClient::MqttClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MqttClient)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    QObject::connect(ui->LinkButton,SIGNAL(clicked()), this, SLOT(on_link_clicked()));
    QObject::connect(ui->SubButton,SIGNAL(clicked()), this, SLOT(on_sub_clicked()));
    QObject::connect(ui->pushButton,SIGNAL(clicked()), this, SLOT(on_pub_clicked()));
    ui->pushButton->setEnabled(false);
     ui->SubButton->setEnabled(false);

}

MqttClient::~MqttClient()
{
    delete ui;
}

void MqttClient::on_link_clicked()
{

    if(MqttClient::linkflag==0)
    {
        qDebug()<< ui->IPEdit->text()<<endl;
        qDebug()<< ui->PORTEdit->text()<<endl;
        qDebug()<< ui->ClientidEdit->text()<<endl;
        qDebug()<< ui->UserEdit->text()<<endl;
        qDebug()<< ui->PasswordEdit->text()<<endl;

        client = new QMQTT::Client(QHostAddress( ui->IPEdit->text()), ui->PORTEdit->text().toInt());
        client->setClientId(ui->ClientidEdit->text());
        client->setUsername(ui->UserEdit->text());
        client->setPassword(ui->PasswordEdit->text().toUtf8());
        client->setAutoReconnect(true);
        client-> setCleanSession(true);
        client->connectToHost();


        ui->IPEdit->setEnabled(false);
        ui->PORTEdit->setEnabled(false);
        ui->ClientidEdit->setEnabled(false);
        ui->UserEdit->setEnabled(false);
        ui->PasswordEdit->setEnabled(false);
        ui->pushButton->setEnabled(true);
        ui->SubButton->setEnabled(true);
        ui->LinkButton->setText("关闭");

        QObject::connect(client,&QMQTT::Client::received, this, &MqttClient::onReceived);

        MqttClient::linkflag=true;
    }else{

        client->disconnectFromHost();
        client->deleteLater();
        MqttClient::linkflag=false;
        ui->IPEdit->setEnabled(true);
        ui->PORTEdit->setEnabled(true);
        ui->ClientidEdit->setEnabled(true);
        ui->UserEdit->setEnabled(true);
        ui->PasswordEdit->setEnabled(true);
        ui->LinkButton->setText("连接");
        ui->pushButton->setEnabled(false);
        ui->SubButton->setEnabled(false);

    }


}
void MqttClient::onReceived(const QMQTT::Message& message)
  {
//      qDebug() << "publish received: \"" << QString::fromUtf8(message.payload())
//            << "\"" << endl;
     ui->Repayload->moveCursor(QTextCursor::End);
    ui->Repayload->textCursor().insertText("received:\n");

    ui->Repayload->moveCursor(QTextCursor::End);
    ui->Repayload->textCursor().insertText("Messageid: "+QString::number(message.id())+"\n");

    ui->Repayload->moveCursor(QTextCursor::End);
    ui->Repayload->textCursor().insertText("Qos: "+QString::number(message.qos())+"\n");

    ui->Repayload->moveCursor(QTextCursor::End);
    ui->Repayload->textCursor().insertText("Payload: "+QString::fromUtf8(message.payload()+"\n"));

}
void MqttClient::on_sub_clicked()
{

 int qos=ui->qossubcbox->currentText().toInt();
   client->subscribe(ui->SubEdit->text(),qos);



}
void MqttClient::on_pub_clicked()
{

   int qos=ui->qoscbox->currentText().toInt();
   int id=ui->msgdidEdit->text().toInt();

   QMQTT::Message msg;
    msg.setId(id);
     QByteArray msgpay= ui->Publpayload->toPlainText().toUtf8();
      QString pubtopic=ui->PubEdit->text();
    msg.setQos(qos);
    msg.setTopic(pubtopic);
    msg.setPayload(msgpay);
   client->publish(msg);


}
