TARGET=colourpicker

CFLAGS=-Wall -pedantic -Wmissing-prototypes
GTK=$(shell pkg-config --cflags --libs gtk+-2.0)

all: $(TARGET)

$(TARGET):  colourpicker.c colourpicker.h
	gcc -o $(TARGET) colourpicker.c $(WFLAGS) $(GTK)

install: all
	sudo cp $(TARGET) /usr/local/bin/
	sudo cp colourpicker.desktop /usr/share/applications/
	sudo cp colourpicker.png /usr/share/icons/
clean:
	rm -f $(TARGET)
