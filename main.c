#include <stdio.h>
#include<gtk/gtk.h>

#include "maker.h"

struct windowSolver {
    GtkWidget *window;
    GtkWidget *textviewQuestion;
    struct option {
        GtkWidget *A;
        GtkWidget *B;
        GtkWidget *C;
        GtkWidget *D;
    }option;
}solver;

char *filePath;
struct mcqData {
    char question[256];
    struct mcqoption {
        char A[128];
        char B[128];
        char C[128];
        char D[128];
    }option;
    int answer;
}mcq[100];

int totalMcq;
int activeMcq=-1;

void loadMcq() {
    //This keeps track of the questions
    activeMcq++;

    GtkTextBuffer *temp;
if (activeMcq<=totalMcq) {

    //loads mcq question
    temp = gtk_text_view_get_buffer(GTK_TEXT_VIEW(solver.textviewQuestion));
    gtk_text_buffer_set_text(temp,mcq[activeMcq].question,-1);
    //loads option A
    temp = gtk_text_view_get_buffer(GTK_TEXT_VIEW(solver.option.A));
    gtk_text_buffer_set_text(temp,mcq[activeMcq].option.A,-1);
    //loads option B
    temp = gtk_text_view_get_buffer(GTK_TEXT_VIEW(solver.option.B));
    gtk_text_buffer_set_text(temp,mcq[activeMcq].option.B,-1);
    //loads option C
    temp = gtk_text_view_get_buffer(GTK_TEXT_VIEW(solver.option.C));
    gtk_text_buffer_set_text(temp,mcq[activeMcq].option.C,-1);
    //loads option D
    temp = gtk_text_view_get_buffer(GTK_TEXT_VIEW(solver.option.D));
    gtk_text_buffer_set_text(temp,mcq[activeMcq].option.D,-1);

}





}



void readData() {
    FILE *file = fopen(filePath,"r");
    int i = 0;
    while (fread(&mcq[i],sizeof(mcq[i]),1,file)==1) {
        i++;
        totalMcq++;
    }
    fclose(file);
}



void on_file_selected(GObject *source, GAsyncResult *res, gpointer user_data) {
    GtkFileDialog *dialog = GTK_FILE_DIALOG(source);
    GFile *file = gtk_file_dialog_open_finish(dialog, res, NULL);
    filePath = g_file_get_path(file);
    //printf("FilePath = %s ",filePath);
    readData();
    loadMcq(0);
}

void dialogNavToTest() {

        GtkFileDialog *dialog = gtk_file_dialog_new();
        gtk_file_dialog_open(dialog, NULL, NULL, on_file_selected, NULL);

}



static void activate (GtkApplication *app,gpointer user_data) {
    // The window for the solver
    solver.window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(solver.window),"NotSoSolvy");
        gtk_window_set_default_size(GTK_WINDOW(solver.window),800,800);
    gtk_window_present(GTK_WINDOW(solver.window));

    //Header bar for the buttons and stuff
    GtkWidget *headerbar = gtk_header_bar_new();
    gtk_window_set_titlebar(GTK_WINDOW(solver.window),headerbar);

    //Button to open the maker window (windowMaker)
    GtkWidget *buttonMaker = gtk_button_new_with_label("📄");
    gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar),buttonMaker);
    g_signal_connect(buttonMaker,"clicked",G_CALLBACK(openMaker),NULL);

    //Button to open the dialogbox to choose test file
    GtkWidget *buttonBrowse = gtk_button_new_with_label("📂");
    gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar),buttonBrowse);
    g_signal_connect(buttonBrowse,"clicked",G_CALLBACK(dialogNavToTest),NULL);

    //parent grid for the solver window
    GtkWidget *gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(solver.window),gridParent);
    gtk_widget_set_margin_top(gridParent,10);
    gtk_widget_set_margin_bottom(gridParent,10);
    gtk_widget_set_margin_start(gridParent,10);
    gtk_widget_set_margin_end(gridParent,10);

    //Text view for entering the question
    solver.textviewQuestion = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(solver.textviewQuestion), GTK_WRAP_WORD);
    gtk_grid_attach(GTK_GRID(gridParent),solver.textviewQuestion,0,0,12,4);
    gtk_widget_set_size_request(solver.textviewQuestion,780,260);
    gtk_widget_set_margin_bottom(solver.textviewQuestion,10);

    //text views for entering options

    solver.option.A = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(solver.textviewQuestion),GTK_WRAP_WORD);
    gtk_grid_attach(GTK_GRID(gridParent),solver.option.A,0,5,6,4);
    gtk_widget_set_size_request(solver.option.A,385,120);
    gtk_widget_set_margin_bottom(solver.option.A,10);
    gtk_widget_set_margin_end(solver.option.A,10);

    solver.option.B = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(solver.textviewQuestion),GTK_WRAP_WORD);
    gtk_grid_attach(GTK_GRID(gridParent),solver.option.B,6,5,6,4);
    gtk_widget_set_size_request(solver.option.B,385,120);
    gtk_widget_set_margin_bottom(solver.option.B,10);


    solver.option.C = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(solver.textviewQuestion),GTK_WRAP_WORD);
    gtk_grid_attach(GTK_GRID(gridParent),solver.option.C,0,10,6,4);
    gtk_widget_set_size_request(solver.option.C,385,120);
    gtk_widget_set_margin_end(solver.option.C,10);

    solver.option.D = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(solver.textviewQuestion),GTK_WRAP_WORD);
    gtk_grid_attach(GTK_GRID(gridParent),solver.option.D,6,10,6,4);
    gtk_widget_set_size_request(solver.option.D,385,120);


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