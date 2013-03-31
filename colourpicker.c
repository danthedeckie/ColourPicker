#include <gtk/gtk.h>
#include <stdio.h>
#include "colourpicker.h"

/////////////////////////////////
// Return Values:
// 0 - User selected new color, here it is!
// 1 - User didn't bother with selecting a new color.  Here's what you sent me.
// 2 - User didn't bother with a new color, and you didn't bother giving me one.
#define NEWCOLOR 0
#define NONEWCOLOR 1
#define NONEWOROLD 2

void select_color(GdkColor *color)
{

    GtkResponseType result;
    GtkColorSelection *colorsel;

    GtkWidget *dialog = gtk_color_selection_dialog_new("colorpicker");

    colorsel = GTK_COLOR_SELECTION(
        GTK_COLOR_SELECTION_DIALOG(dialog)->colorsel);

    gtk_color_selection_set_current_color(colorsel, color);
    gtk_color_selection_set_previous_color(colorsel, color);

    result = gtk_dialog_run(GTK_DIALOG(dialog));
    if (result == GTK_RESPONSE_OK)
    {
        gtk_color_selection_get_current_color(colorsel, color);
    }

    gtk_widget_destroy(dialog);
}


int main( int argc, char *argv[])
{
    // Do this first or fear the wrath of SegFault.
    gtk_init(&argc, &argv);

    GdkVisual *visual;
    GdkColormap *colormap;
    GdkColor *color, *initial_color;

    visual = gdk_visual_get_best();
    colormap = gdk_colormap_new(visual, TRUE);
    gdk_colormap_alloc_color(colormap, color, TRUE, TRUE);

    if ((argc != 2) || (!gdk_color_parse(argv[1], color)))
    {
        gdk_color_parse("black", color);
    }

    initial_color = gdk_color_copy(color);

    select_color(color);

    // if the color is the same as we started with, output the original
    // string.  Thus 'red' stays as 'red' and doesn't become #ff0000.
    if (gdk_color_equal(initial_color, color)){
        if (argc == 2) {
            printf("%s",argv[1]);
        }
    } else {
        printf("#%.2x%.2x%.2x", color->red>>8, color->green>>8, color->blue>>8);
    }

    // Possibly superfluous since we're quitting anyway...
    gdk_colormap_free_colors(colormap, color, 1);
    gdk_color_free(initial_color);
    g_object_unref(colormap);
    g_object_unref(visual);

    return 0;
}
