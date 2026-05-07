#include <stdio.h>
#include<gtk/gtk.h>

struct windowSolver {
    GtkWidget *window;
    GtkWidget *textviewQuestion;
    struct buttonOption {
        GtkWidget *A;
        GtkWidget *B;
        GtkWidget *C;
        GtkWidget *D;
    }buttonOption;
}windowSolver;


static void activate (GtkApplication *app,gpointer user_data) {
    // The window for the solver
    windowSolver.window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(windowSolver.window),"NotSoSolvy");
    gtk_window_set_default_size(GTK_WINDOW(windowSolver.window),800,800);
    gtk_window_present(GTK_WINDOW(windowSolver.window));

    //Header bar for the buttons and stuff
    GtkWidget *headerbar = gtk_header_bar_new();
    gtk_window_set_titlebar(GTK_WINDOW(windowSolver.window),headerbar);

    //Button to open the maker window (windowMaker)
    GtkWidget *buttonMaker = gtk_button_new_with_label("📄");
    gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar),buttonMaker);



}

//Tje boilerplate code
int main(int argc, char **argv) {
    GtkApplication *app;
    int status;
    app= gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}