#include <gtk/gtk.h>
#include <stdio.h>
#include "colourpicker.h"

void destroy(void)
{
	gtk_main_quit();
}

int main (int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *picker;
	
	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_signal_connect(GTK_OBJECT (window), "destroy", GTK_SIGNAL_FUNC (destroy), NULL);
	
	gtk_window_set_title(GTK_WINDOW(window), "ColourPicker");
	gtk_container_border_width(GTK_CONTAINER(window), 10);
	gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("/usr/share/icons/colourpicker.png"));
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	
	
	picker = gtk_color_selection_new();
	gtk_container_add(GTK_CONTAINER (window), picker);
	
	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}

GdkPixbuf *create_pixbuf(const gchar * filename)
{
	GdkPixbuf *pixbuf;
	GError *error = NULL;
	pixbuf = gdk_pixbuf_new_from_file(filename, &error);
	if(!pixbuf) {
		fprintf(stderr, "%s\n", error->message);
		g_error_free(error);
	}
	
	return pixbuf;
}
