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
};

struct windowMaker {
    GtkWidget *window;
    GtkWidget *textviewQuestion;
    struct entryOption {
        GtkWidget *A;
        GtkWidget *B;
        GtkWidget *C;
        GtkWidget *D;
    }entryOption;
}windowMaker;

static void activate (GtkApplication *app,gpointer user_data) {



}


int main(int argc, char **argv) {
    GtkApplication *app;
    int status;
    app= gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}