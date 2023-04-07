#include <iostream>
#include <libadwaita-1/adwaita.h>
#include <gtk/gtk.h>

static void activate(GtkApplication* application, gpointer data)
{
    (void)data;
    GtkWidget* window = adw_application_window_new(application);
    gtk_window_set_title(GTK_WINDOW(window), "Gtk + libAdwaita + cmake");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget* headerBar = adw_header_bar_new();

    gtk_box_append(GTK_BOX(box), headerBar);

    adw_application_window_set_content(ADW_APPLICATION_WINDOW(window), box);
    gtk_widget_set_visible(window, true);
}

int main(int argc, char** argv)
{
    GApplication * app = G_APPLICATION(adw_application_new("my.application.id", G_APPLICATION_DEFAULT_FLAGS));
    g_signal_connect(app, "activate", G_CALLBACK(activate), nullptr);
    return g_application_run(app, argc, argv);
}
