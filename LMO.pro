QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AcademicJournal.cpp \
    AcademicJournalParser.cpp \
    Account.cpp \
    Basic.cpp \
    Book.cpp \
    BookParser.cpp \
    Content.cpp \
    ContentData.cpp \
    DBAccess.cpp \
    Database.cpp \
    DateTime.cpp \
    LibMS.cpp \
    MemberShip.cpp \
    Premium.cpp \
    Reading.cpp \
    Reservation.cpp \
    ReservationData.cpp \
    ReservationFilter.cpp \
    SearchingFilter.cpp \
    Staff.cpp \
    StaffParser.cpp \
    Student.cpp \
    StudentParser.cpp \
    User.cpp \
    UserData.cpp \
    Utils.cpp \
    bookwidgetitem.cpp \
    borroweditemwidget.cpp \
    borrowedwidget.cpp \
    contentdetailsdialog.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    modifycontentwidget.cpp \
    modifyuserwidget.cpp \
    regulationwidget.cpp \
    searchingwidget.cpp \
    signupwindow.cpp \
    thewidgetitem.cpp \
    userinfowidget.cpp

HEADERS += \
    AcademicJournal.h \
    AcademicJournalParser.h \
    Account.h \
    Basic.h \
    Book.h \
    BookParser.h \
    Content.h \
    ContentData.h \
    ContentParser.h \
    DBAccess.h \
    Database.h \
    DateTime.h \
    LibMS.h \
    MemberShip.h \
    Premium.h \
    Reading.h \
    Reservation.h \
    ReservationData.h \
    ReservationFilter.h \
    SearchingFilter.h \
    Staff.h \
    StaffParser.h \
    Student.h \
    StudentParser.h \
    TabProxy.h \
    UniversityEnum.h \
    User.h \
    UserData.h \
    UserParser.h \
    UserTypeEnum.h \
    Utils.h \
    bookwidgetitem.h \
    borroweditemwidget.h \
    borrowedwidget.h \
    contentdetailsdialog.h \
    logindialog.h \
    mainwindow.h \
    modifycontentwidget.h \
    modifyuserwidget.h \
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
