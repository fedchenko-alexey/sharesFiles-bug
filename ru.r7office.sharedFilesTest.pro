TARGET = ru.r7office.sharedFilesTest

CONFIG += \
    auroraapp

PKGCONFIG += \

SOURCES += \
    src/main.cpp \

HEADERS += \
    src/fsutils.h

DISTFILES += \
    rpm/ru.r7office.sharedFilesTest.spec \

AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n

TRANSLATIONS += \
    translations/ru.r7office.sharedFilesTest.ts \
    translations/ru.r7office.sharedFilesTest-ru.ts \
