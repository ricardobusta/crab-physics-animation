#-------------------------------------------------
#
# Project created by QtCreator 2012-08-29T22:28:35
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = QT_ODE
TEMPLATE = app

MOC_DIR = build
DISTFILES = build

DEFINES += \
    SHADERS_ENABLED \
    dSINGLE \
    DEBUG_MODE

SOURCES += \
    main.cpp \
    physics/physics.cpp \    
    interface/glframe.cpp \
    graphics/glwidget.cpp \
    scene/scene.cpp \
    graphics/glprimitive.cpp \
    graphics/material.cpp \
    graphics/camera.cpp \
    math/vector3f.cpp \
    math/matrix4f.cpp \
    scene/object.cpp \
    interface/mainwindow.cpp \
    scene/character.cpp \
    scene/particle.cpp \
    graphics/glutil.cpp \
    scene/particleengine.cpp \
    scene/contact.cpp \
    scene/joint.cpp

HEADERS  += \
    physics/physics.h \
    interface/glframe.h \
    graphics/glwidget.h \
    scene/scene.h \
    graphics/glprimitive.h \
    graphics/material.h \
    graphics/camera.h \
    math/vector3f.h \
    math/matrix4f.h \
    scene/object.h \
    interface/mainwindow.h \
    scene/character.h \
    scene/particle.h \
    graphics/glutil.h \
    scene/particleengine.h \
    scene/contact.h \
    scene/joint.h

FORMS    += \
    interface/mainwindow.ui

OTHER_FILES += \
    shaders/phong.vert \
    shaders/phong.frag \
    shaders/toon.vert \
    shaders/toon.frag

#linux
unix:!macx:!symbian: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -lode
INCLUDEPATH += $$PWD/../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../usr/local/include
unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../../../../../../usr/local/lib/libode.a

#windows
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ode-0.12/lib/DebugSingleDLL/ -lode_single
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ode-0.12/lib/DebugSingleDLL/ -lode_singled
INCLUDEPATH += $$PWD/../ode-0.12/include
DEPENDPATH += $$PWD/../ode-0.12/include

RESOURCES += \
    shaders/shaders.qrc
