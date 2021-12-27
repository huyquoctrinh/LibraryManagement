QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bookwidgetitem.cpp \
    borroweditemwidget.cpp \
    borrowedwidget.cpp \
    content.cpp \
    contentdetailsdialog.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    modifycontentwidget.cpp \
    modifyuserwidget.cpp \
    reading.cpp \
    regulationwidget.cpp \
    searchingwidget.cpp \
    signupwindow.cpp \
    thewidgetitem.cpp \
    userinfowidget.cpp

HEADERS += \
    TabProxy.h \
    bookwidgetitem.h \
    borroweditemwidget.h \
    borrowedwidget.h \
    content.h \
    contentdetailsdialog.h \
    logindialog.h \
    mainwindow.h \
    modifycontentwidget.h \
    modifyuserwidget.h \
    reading.h \
    regulationwidget.h \
    searchingwidget.h \
    signupwindow.h \
    thewidgetitem.h \
    userinfowidget.h

FORMS += \
    bookwidgetitem.ui \
    borroweditemwidget.ui \
    borrowedwidget.ui \
    contentdetailsdialog.ui \
    logindialog.ui \
    mainwindow.ui \
    modifycontentwidget.ui \
    modifyuserwidget.ui \
    regulationwidget.ui \
    searchingwidget.ui \
    signupwindow.ui \
    thewidgetitem.ui \
    userinfowidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    res/icon/search_lense.png

RESOURCES += \
    res.qrc
