TARGET=colourpicker

CFLAGS=-Wall -pedantic -Wmissing-prototypes
GTK=$(shell pkg-config --cflags --libs gtk+-2.0)

all: $(TARGET)

$(TARGET):  colourpicker.c colourpicker.h
	gcc -o $(TARGET) colourpicker.c $(WFLAGS) $(GTK)

install: all
	cp ColourPicker /usr/local/bin/

clean:
	rm -f $(TARGET)
