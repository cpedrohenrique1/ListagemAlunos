QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aluno.cpp \
    buscaraluno.cpp \
    disciplinaturma.cpp \
    executarmodo.cpp \
    fm_inserircurso.cpp \
    fm_inserirdisciplina.cpp \
    fm_inserirdisciplinaturma.cpp \
    fm_inserirmatricula.cpp \
    inserirmatricula.cpp \
    main.cpp \
    mainwindow.cpp \
    matricula.cpp

HEADERS += \
    aluno.h \
    buscaraluno.h \
    disciplinaturma.h \
    executarmodo.h \
    fm_inserircurso.h \
    fm_inserirdisciplina.h \
    fm_inserirdisciplinaturma.h \
    fm_inserirmatricula.h \
    inserirmatricula.h \
    mainwindow.h \
    matricula.h

FORMS += \
    fm_inserircurso.ui \
    fm_inserirdisciplina.ui \
    fm_inserirdisciplinaturma.ui \
    fm_inserirmatricula.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
