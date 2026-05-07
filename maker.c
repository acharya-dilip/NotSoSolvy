//
// Created by g4sker on 5/7/26.
//

#include "maker.h"
#include <stdio.h>
#include <gtk/gtk.h>

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

void openMaker() {

    //Window for the mcqMaker
    windowMaker.window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(windowMaker.window),"MCQ Maker");
    gtk_window_set_default_size(GTK_WINDOW(windowMaker.window),800,800);
    gtk_window_present(GTK_WINDOW(windowMaker.window));


}