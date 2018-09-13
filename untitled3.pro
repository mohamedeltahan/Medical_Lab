#-------------------------------------------------
#
# Project created by QtCreator 2018-06-25T17:50:21
#
#-------------------------------------------------

QT       += core gui
QT += sql
DEFINES *= QT_USE_QSTRINGBUILDER

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled3
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
        mainwindow.cpp \
    Deliver_Doctor.cpp \
    Doctor.cpp \
    MedicalLab.cpp \
    Order.cpp \
    Patient.cpp \
    Receptionist.cpp \
    Staff.cpp \
    Test.cpp \
    databasemodel.cpp \
    dialog.cpp \
    form.cpp \
    testform.cpp \
    patientform.cpp \
    labform.cpp \
    logindialog.cpp \
    orderform.cpp \
    staffform.cpp \
    alltest.cpp \
    allpatient.cpp

HEADERS += \
        mainwindow.h \
    Deliver_Doctor.h \
    Doctor.h \
    MedicalLab.h \
    Order.h \
    Patient.h \
    Receptionist.h \
    Staff.h \
    Test.h \
    databasemodel.h \
    dialog.h \
    form.h \
    testform.h \
    patientform.h \
    labform.h \
    logindialog.h \
    orderform.h \
    staffform.h \
    alltest.h \
    allpatient.h

FORMS += \
        mainwindow.ui \
    form.ui \
    testform.ui \
    patientform.ui \
    labform.ui \
    logindialog.ui \
    orderform.ui \
    staffform.ui \
    alltest.ui \
    allpatient.ui

RESOURCES += \
    res.qrc
