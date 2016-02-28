CXX           = g++
CXXFLAGS      = -Wall
INCPATH       = -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I.
LINK          = g++
LIBS          = -lQtGui -lQtCore -lpthread 
RM            = rm
####### Files

SOURCES       = src/main.cpp src/moc_view.cpp src/moc_engine.cpp
OBJECTS       = objects/main.o objects/moc_view.o objects/moc_engine.o
TARGET        = tp1

####### Build rules

all: $(TARGET)
	@echo "Building $@"
$(TARGET):  $(OBJECTS)
	@echo "Linking"  
	$(LINK) -o $(TARGET) $(OBJECTS) $(LIBS)

src/moc_view.cpp: src/view.hpp
	@echo "Meta object compiling"
	moc $(INCPATH) src/view.hpp -o src/moc_view.cpp

src/moc_engine.cpp: src/engine.hpp
	@echo "Meta object compiling"
	moc $(INCPATH) src/engine.hpp -o src/moc_engine.cpp


####### Compile

objects/main.o: src/main.cpp src/view.hpp src/engine.hpp src/translator.hpp
	@echo "Compiling"
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/main.o src/main.cpp

objects/moc_view.o: src/moc_view.cpp 
	@echo "Compiling"
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/moc_view.o src/moc_view.cpp

objects/moc_engine.o: src/moc_engine.cpp 
	@echo "Compiling"
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/moc_engine.o src/moc_engine.cpp

####### Clean

clean: main.o moc_view.o moc_engine.o
	@echo "Cleaning"
	$(RM) $(OBJECTS) 
