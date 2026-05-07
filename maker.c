//
// Created by g4sker on 5/7/26.
//

#include "maker.h"
#include <stdio.h>
#include <gtk/gtk.h>

struct windowMaker {
    GtkWidget *window;
    GtkWidget *textviewQuestion;
    struct option {
        GtkWidget *A;
        GtkWidget *B;
        GtkWidget *C;
        GtkWidget *D;
    }textviewOption;
    int answer;
}maker;

struct radioCheck {
    GtkWidget *A;
    GtkWidget *B;
    GtkWidget *C;
    GtkWidget *D;
}radio;

void filepathPrompt() {
    //Window for a thing that prompts you to type out a filename and choose a filepath
    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Create Test");
    gtk_window_present(GTK_WINDOW(window));

    //parent grid for the filepath window
    GtkWidget *gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window),gridParent);



}

void openMaker() {

    //Window for the mcqMaker
    maker.window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(maker.window),"MCQ Maker");
    gtk_window_present(GTK_WINDOW(maker.window));

    //Init for a grid
    GtkWidget *gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(maker.window),gridParent);
    //Margins for the parent grid
    gtk_widget_set_margin_top(gridParent,10);
    gtk_widget_set_margin_bottom(gridParent,10);
    gtk_widget_set_margin_start(gridParent,10);
    gtk_widget_set_margin_end(gridParent,10);

    //Text view for entering the question
    maker.textviewQuestion = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(maker.textviewQuestion), GTK_WRAP_WORD);
    gtk_grid_attach(GTK_GRID(gridParent),maker.textviewQuestion,0,0,12,4);
    gtk_widget_set_size_request(maker.textviewQuestion,780,260);
    gtk_widget_set_margin_bottom(maker.textviewQuestion,10);

    //text views for entering options

    maker.textviewOption.A = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(maker.textviewQuestion),GTK_WRAP_WORD);
    gtk_grid_attach(GTK_GRID(gridParent),maker.textviewOption.A,0,5,6,4);
    gtk_widget_set_size_request(maker.textviewOption.A,385,120);
    gtk_widget_set_margin_bottom(maker.textviewOption.A,10);
    gtk_widget_set_margin_end(maker.textviewOption.A,10);

    maker.textviewOption.B = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(maker.textviewQuestion),GTK_WRAP_WORD);
    gtk_grid_attach(GTK_GRID(gridParent),maker.textviewOption.B,6,5,6,4);
    gtk_widget_set_size_request(maker.textviewOption.B,385,120);
    gtk_widget_set_margin_bottom(maker.textviewOption.B,10);


    maker.textviewOption.C = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(maker.textviewQuestion),GTK_WRAP_WORD);
    gtk_grid_attach(GTK_GRID(gridParent),maker.textviewOption.C,0,10,6,4);
    gtk_widget_set_size_request(maker.textviewOption.C,385,120);
    gtk_widget_set_margin_end(maker.textviewOption.C,10);

    maker.textviewOption.D = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(maker.textviewQuestion),GTK_WRAP_WORD);
    gtk_grid_attach(GTK_GRID(gridParent),maker.textviewOption.D,6,10,6,4);
    gtk_widget_set_size_request(maker.textviewOption.D,385,120);


    //The Buttons to choose the answer
    radio.A = gtk_check_button_new();
    gtk_grid_attach(GTK_GRID(gridParent),radio.A,0,5,1,1);

    radio.B = gtk_check_button_new();
    gtk_check_button_set_group(GTK_CHECK_BUTTON(radio.B),GTK_CHECK_BUTTON(radio.A));
    gtk_grid_attach(GTK_GRID(gridParent),radio.B,6,5,1,1);


    radio.C = gtk_check_button_new();
    gtk_check_button_set_group(GTK_CHECK_BUTTON(radio.C),GTK_CHECK_BUTTON(radio.A));
    gtk_grid_attach(GTK_GRID(gridParent),radio.C,0,10,1,1);


    radio.D = gtk_check_button_new();
    gtk_check_button_set_group(GTK_CHECK_BUTTON(radio.D),GTK_CHECK_BUTTON(radio.A));
    gtk_grid_attach(GTK_GRID(gridParent),radio.D,6,10,1,1);

    //The Submit button to submit the MCQ and go on to the next one
    GtkWidget *buttonSubmit = gtk_button_new_with_label("Submit");
    gtk_grid_attach(GTK_GRID(gridParent),buttonSubmit,0,14,12,1);
    gtk_widget_set_size_request(buttonSubmit,780,50);
    gtk_widget_set_margin_top(buttonSubmit,10);

}