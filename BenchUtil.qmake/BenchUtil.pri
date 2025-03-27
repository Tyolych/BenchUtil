# Не работает - надо -O0  а у меня -O2
# Поредактировать и проверить на ошибки, а собирать через оригинальный Makefile

CONFIG -= qt gui widgets
QMAKE_CXXFLAGS -= -O2
QMAKE_CXXFLAGS += -Wno-overflow -pthread -O0
QMAKE_LFLAGS += -O0
LIBS += -lpthread 

TEMPLATE = app
INCLUDEPATH += $$PWD/.. "./  -O0"
DEPENDPATH += $$PWD/..
HEADERS = $$PWD/../BenchUtil.h 
SOURCES = $$PWD/../$$TARGET".cpp"




