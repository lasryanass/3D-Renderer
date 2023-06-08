SYSCONF_LINK = g++
CPPFLAGS     =
LDFLAGS      =
LIBS         = -lm

DESTDIR = ./
TARGET  = rasterize

EXTERNAL_DIR = ../lib

CPPFLAGS += -I$(EXTERNAL_DIR)/imageformat
CPPFLAGS += -I$(EXTERNAL_DIR)/model
CPPFLAGS += -I$(EXTERNAL_DIR)/geometry
CPPFLAGS += -I$(EXTERNAL_DIR)/lineImplementation
CPPFLAGS += -I$(EXTERNAL_DIR)/triangleImplementation

OBJECTS := $(patsubst %.cpp,%.o,$(wildcard $(EXTERNAL_DIR)/*/*.cpp)) main.o

all: $(DESTDIR)$(TARGET)

$(DESTDIR)$(TARGET): $(OBJECTS)
	$(SYSCONF_LINK) -Wall $(LDFLAGS) -o $(DESTDIR)$(TARGET) $(OBJECTS) $(LIBS)

$(OBJECTS): %.o: %.cpp
	$(SYSCONF_LINK) -Wall $(CPPFLAGS) -c $(CFLAGS) $< -o $@

main.o: main.cpp
	$(SYSCONF_LINK) -Wall $(CPPFLAGS) -c $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f $(TARGET)
	-rm -f *.tga
