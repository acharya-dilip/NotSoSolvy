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
}maker;

void openMaker() {

    //Window for the mcqMaker
    maker.window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(maker.window),"MCQ Maker");
    gtk_window_set_default_size(GTK_WINDOW(maker.window),800,800);
    gtk_window_present(GTK_WINDOW(maker.window));

    //Init for a grid
    GtkWidget *gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(maker.window),gridParent);

    //Text view for entering the question
    maker.textviewQuestion = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(maker.textviewQuestion),TRUE);

}