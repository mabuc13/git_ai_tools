#############################################################################
# Makefile for building: ludo
# Generated by qmake (2.01a) (Qt 4.8.7) on: Thu May 10 20:41:35 2018
# Project:  ../ludo/ludo.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile ../ludo/ludo.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -std=c++11 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wunused -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I../ludo -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I. -I../ludo -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ../ludo/main.cpp \
		../ludo/dialog.cpp \
		../ludo/game.cpp \
		../ludo/ludo_player_random.cpp \
		../ludo/smart_ludo_player.cpp \
		../ludo/ludo_player.cpp \
		../ludo/geneticludoevolv.cpp moc_dialog.cpp \
		moc_game.cpp \
		moc_ludo_player_random.cpp \
		moc_smart_ludo_player.cpp \
		moc_ludo_player.cpp
OBJECTS       = main.o \
		dialog.o \
		game.o \
		ludo_player_random.o \
		smart_ludo_player.o \
		ludo_player.o \
		geneticludoevolv.o \
		moc_dialog.o \
		moc_game.o \
		moc_ludo_player_random.o \
		moc_smart_ludo_player.o \
		moc_ludo_player.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		../ludo/ludo.pro
QMAKE_TARGET  = ludo
DESTDIR       = 
TARGET        = ludo

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_dialog.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: ../ludo/ludo.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile ../ludo/ludo.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile ../ludo/ludo.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/ludo1.0.0 || $(MKDIR) .tmp/ludo1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/ludo1.0.0/ && $(COPY_FILE) --parents ../ludo/dialog.h ../ludo/game.h ../ludo/positions_and_dice.h ../ludo/ludo_player_random.h ../ludo/smart_ludo_player.h ../ludo/ludo_player.h ../ludo/geneticludoevolv.h .tmp/ludo1.0.0/ && $(COPY_FILE) --parents ../ludo/main.cpp ../ludo/dialog.cpp ../ludo/game.cpp ../ludo/ludo_player_random.cpp ../ludo/smart_ludo_player.cpp ../ludo/ludo_player.cpp ../ludo/geneticludoevolv.cpp .tmp/ludo1.0.0/ && $(COPY_FILE) --parents ../ludo/dialog.ui .tmp/ludo1.0.0/ && (cd `dirname .tmp/ludo1.0.0` && $(TAR) ludo1.0.0.tar ludo1.0.0 && $(COMPRESS) ludo1.0.0.tar) && $(MOVE) `dirname .tmp/ludo1.0.0`/ludo1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/ludo1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_dialog.cpp moc_game.cpp moc_ludo_player_random.cpp moc_smart_ludo_player.cpp moc_ludo_player.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_dialog.cpp moc_game.cpp moc_ludo_player_random.cpp moc_smart_ludo_player.cpp moc_ludo_player.cpp
moc_dialog.cpp: ../ludo/game.h \
		../ludo/smart_ludo_player.h \
		../ludo/positions_and_dice.h \
		../ludo/geneticludoevolv.h \
		../ludo/dialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) ../ludo/dialog.h -o moc_dialog.cpp

moc_game.cpp: ../ludo/smart_ludo_player.h \
		../ludo/positions_and_dice.h \
		../ludo/geneticludoevolv.h \
		../ludo/game.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) ../ludo/game.h -o moc_game.cpp

moc_ludo_player_random.cpp: ../ludo/positions_and_dice.h \
		../ludo/ludo_player_random.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) ../ludo/ludo_player_random.h -o moc_ludo_player_random.cpp

moc_smart_ludo_player.cpp: ../ludo/positions_and_dice.h \
		../ludo/smart_ludo_player.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) ../ludo/smart_ludo_player.h -o moc_smart_ludo_player.cpp

moc_ludo_player.cpp: ../ludo/positions_and_dice.h \
		../ludo/ludo_player.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) ../ludo/ludo_player.h -o moc_ludo_player.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_dialog.h
compiler_uic_clean:
	-$(DEL_FILE) ui_dialog.h
ui_dialog.h: ../ludo/dialog.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic ../ludo/dialog.ui -o ui_dialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: ../ludo/main.cpp ../ludo/dialog.h \
		../ludo/game.h \
		../ludo/smart_ludo_player.h \
		../ludo/positions_and_dice.h \
		../ludo/geneticludoevolv.h \
		../ludo/ludo_player.h \
		../ludo/ludo_player_random.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o ../ludo/main.cpp

dialog.o: ../ludo/dialog.cpp ../ludo/dialog.h \
		../ludo/game.h \
		../ludo/smart_ludo_player.h \
		../ludo/positions_and_dice.h \
		../ludo/geneticludoevolv.h \
		ui_dialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dialog.o ../ludo/dialog.cpp

game.o: ../ludo/game.cpp ../ludo/game.h \
		../ludo/smart_ludo_player.h \
		../ludo/positions_and_dice.h \
		../ludo/geneticludoevolv.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o game.o ../ludo/game.cpp

ludo_player_random.o: ../ludo/ludo_player_random.cpp ../ludo/ludo_player_random.h \
		../ludo/positions_and_dice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ludo_player_random.o ../ludo/ludo_player_random.cpp

smart_ludo_player.o: ../ludo/smart_ludo_player.cpp ../ludo/smart_ludo_player.h \
		../ludo/positions_and_dice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o smart_ludo_player.o ../ludo/smart_ludo_player.cpp

ludo_player.o: ../ludo/ludo_player.cpp ../ludo/ludo_player.h \
		../ludo/positions_and_dice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ludo_player.o ../ludo/ludo_player.cpp

geneticludoevolv.o: ../ludo/geneticludoevolv.cpp ../ludo/geneticludoevolv.h \
		../ludo/smart_ludo_player.h \
		../ludo/positions_and_dice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o geneticludoevolv.o ../ludo/geneticludoevolv.cpp

moc_dialog.o: moc_dialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_dialog.o moc_dialog.cpp

moc_game.o: moc_game.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_game.o moc_game.cpp

moc_ludo_player_random.o: moc_ludo_player_random.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ludo_player_random.o moc_ludo_player_random.cpp

moc_smart_ludo_player.o: moc_smart_ludo_player.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_smart_ludo_player.o moc_smart_ludo_player.cpp

moc_ludo_player.o: moc_ludo_player.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ludo_player.o moc_ludo_player.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

