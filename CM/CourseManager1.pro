QT += core gui sql
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CourseManager1
TEMPLATE = app

SOURCES += \
    CourseManagerV1/CellEnter.cpp \
    CourseManagerV1/CourseChoice.cpp \
    CourseManagerV1/educationmanager.cpp \
    CourseManagerV1/LoginWindow.cpp \
    CourseManagerV1/main.cpp \
    CourseManagerV1/ManagerWin.cpp \
    CourseManagerV1/RegisterWin.cpp \
    CourseManagerV1/TeacherWin.cpp \
    CourseManagerV1/qrc_educationmanager.cpp \
    CourseManagerV1/CellChoose.cpp

HEADERS += \
    CourseManagerV1/CellEnter.h \
    CourseManagerV1/CourseChoice.h \
    CourseManagerV1/educationmanager.h \
    CourseManagerV1/LoginWindow.h \
    CourseManagerV1/ManagerWin.h \
    CourseManagerV1/RegisterWin.h \
    CourseManagerV1/TeacherWin.h \
    CourseManagerV1/ui_CellEnter.h \
    CourseManagerV1/ui_CourseChoice.h \
    CourseManagerV1/ui_educationmanager.h \
    CourseManagerV1/ui_LoginWindow.h \
    CourseManagerV1/ui_ManagerWin.h \
    CourseManagerV1/ui_RegisterWin.h \
    CourseManagerV1/ui_TeacherWin.h \
    CourseManagerV1/connection.h \
    CourseManagerV1/cskernel.h \
    CourseManagerV1/login.h \
    CourseManagerV1/myquery.h \
    CourseManagerV1/CellChoose.h \
    CourseManagerV1/ui_CellChoose.h \
    CourseManagerV1/myupdate.h \
    CourseManagerV1/myinsert.h \
    CourseManagerV1/mydelete.h

RESOURCES += \
    CourseManagerV1/educationmanager.qrc

FORMS += \
    CourseManagerV1/TeacherWin.ui \
    CourseManagerV1/RegisterWin.ui \
    CourseManagerV1/ManagerWin.ui \
    CourseManagerV1/LoginWindow.ui \
    CourseManagerV1/educationmanager.ui \
    CourseManagerV1/CourseChoice.ui \
    CourseManagerV1/CellEnter.ui \
    CourseManagerV1/CellChoose.ui

UI_DIR += \
