#include <gtk/gtk.h>
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
	gtk_window_set_icon_name(GTK_WINDOW(window), GTK_STOCK_SELECT_COLOR);
	
	picker = gtk_color_selection_new();
	gtk_container_add (GTK_CONTAINER (window), picker);
	
	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}
