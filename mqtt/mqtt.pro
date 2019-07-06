#-------------------------------------------------
#
# Project created by QtCreator 2019-07-02T19:20:03
#
#-------------------------------------------------

QT       += core gui
QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mqtt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mqttclient.cpp

HEADERS += \
        mqttclient.h\
    mqtt/qmqtt.h \
    mqtt/include/qmqtt/qmqttDepends

FORMS += \
        mqttclient.ui

RC_ICONS = favicon.ico

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../MqttClient/lib/ -lqmqtt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../MqttClient/lib/ -lqmqttd

INCLUDEPATH += $$PWD/../../MqttClient
DEPENDPATH += $$PWD/../../MqttClient

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../MqttClient/lib/libqmqtt.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../MqttClient/lib/libqmqttd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../MqttClient/lib/qmqtt.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../MqttClient/lib/qmqttd.lib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../MqttClient/lib/ -lqmqtt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../MqttClient/lib/ -lqmqttd

INCLUDEPATH += $$PWD/../../MqttClient
DEPENDPATH += $$PWD/../../MqttClient

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../MqttClient/lib/libqmqtt.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../MqttClient/lib/libqmqttd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../MqttClient/lib/qmqtt.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../MqttClient/lib/qmqttd.lib

