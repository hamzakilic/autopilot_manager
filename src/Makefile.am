AUTOMAKE_OPTIONS = subdir-objects
bin_PROGRAMS=autopilot_manager
autopilot_manager_SOURCES=autopilot_manager.cpp  common/AtpmException.cpp common/AtpmLog.cpp  ui/BaseWindow.cpp ui/MainWindow.cpp ui/BaseElement.cpp ui/RectangleElement.cpp ui/LogsElement.cpp ui/Color.cpp
AM_CFLAGS=`sdl2-config --cflags`
AM_LDFLAGS=`sdl2-config --libs`
LIBS=`sdl2-config --libs` -lSDL2_ttf

