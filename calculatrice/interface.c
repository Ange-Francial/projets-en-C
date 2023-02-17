#define GTK_DISABLE_DEPRECATED
#define M 15
// #include <stdio.h>
// #include <stdlib.h>

#include <gtk/gtk.h>

// void addition(){  
//     g_print("Addition\n");
//     gtk_entry_set_text(GTK_ENTRY(entrer),"Addition\n");
// }

void destroy(GtkWidget* widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char* argv[])
{      
    GtkWidget   *window;
    GtkWidget   *hbox;
    GtkWidget   *vbox;
    GtkWidget   *entrer;
    GtkWidget   *table;
    GtkWidget   *bouton[M];
    gtk_init(&argc, &argv);
  
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // Arrêt du programme après avoir cliquer sur l'icone de fermeture. 
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    hbox  = gtk_hbox_new( TRUE, 10 );
    vbox  = gtk_vbox_new( TRUE, 10 );
    entrer  = gtk_entry_new();
    bouton[0]  = gtk_button_new_with_label("9");
    bouton[1]  = gtk_button_new_with_label("8");
    bouton[2]  = gtk_button_new_with_label("PGCD");
    bouton[3]  = gtk_button_new_with_label("PPCM");
    bouton[4]  = gtk_button_new_with_label("7");
    bouton[5]  = gtk_button_new_with_label("6");
    bouton[6]  = gtk_button_new_with_label("+");
    bouton[7]  = gtk_button_new_with_label("-");
    bouton[8]  = gtk_button_new_with_label("5");
    bouton[9]  = gtk_button_new_with_label("4");
    bouton[10]  = gtk_button_new_with_label("x");
    bouton[11]  = gtk_button_new_with_label("/");
    bouton[12]  = gtk_button_new_with_label("3");
    bouton[13]  = gtk_button_new_with_label("2");
    bouton[14]  = gtk_button_new_with_label("^");
    bouton[15]  = gtk_button_new_with_label("%");
    bouton[16]  = gtk_button_new_with_label("1");
    bouton[17]  = gtk_button_new_with_label("0");
    bouton[18]  = gtk_button_new_with_label("=");


    // Tout d'abord, on met la GtkHBox dans la GtkWindow :
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window), "CALCULATRICE"); 
    // gtk_signal_connect (GTK_OBJECT (window), "destroy", GTK_SIGNAL_FUNC (gtk_main_quit ), NULL);
    /* Creation et insertion de la table 5 lignes 4 colonnes */
    table=gtk_table_new(6,4,TRUE);
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(table));

        /* Insertion des boutons */
    gtk_table_attach_defaults(GTK_TABLE(table), entrer, 0, 4, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[0], 0, 1, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[1], 1, 2, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[2], 2, 3, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[3], 3, 4, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[4], 0, 1, 2, 3);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[5], 1, 2, 2, 3);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[6], 2, 3, 2, 3);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[7], 3, 4, 2, 3);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[8], 0, 1, 3, 4);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[9], 1, 2, 3, 4);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[10], 2, 3, 3, 4);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[11], 3, 4, 3, 4);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[12], 0, 1, 4, 5);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[13], 1, 2, 4, 5);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[14], 2, 3, 4, 5);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[15], 3, 4, 4, 5);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[16], 0, 1, 5, 6);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[17], 1, 2, 5, 6);
    gtk_table_attach_defaults(GTK_TABLE(table), bouton[18], 2, 4, 5, 6);

    gtk_widget_show_all(window);
  
    gtk_main();
  
//static int counter = 0;
//   void greet(GtkWidget* widget, gpointer data)
// {
//     // printf equivalent in GTK+
//     g_print("Welcome to GTK\n");
//     g_print("%s clicked %d times\n",
//             (char*)data, ++counter);
// }
  
// void destroy(GtkWidget* widget, gpointer data)
// {
//     gtk_main_quit();
// }
    // GtkWidget* window;
    // GtkWidget* button;
    // gtk_init(&argc, &argv);
  
    // window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  
    // g_signal_connect(window, "destroy",
    //                  G_CALLBACK(destroy), NULL);
    // /* Let's set the border width of the window to 20.
    // * You may play with the value and see the
    // * difference. */
    // gtk_container_set_border_width(GTK_CONTAINER(window), 20);
  
    // button = gtk_button_new_with_label("Click Me!");
  
    // g_signal_connect(GTK_OBJECT(button),
    //                  "clicked", G_CALLBACK(greet),
    //                  "button");
  
    // gtk_container_add(GTK_CONTAINER(window), button);
  
    // gtk_widget_show_all(window);
  
    // gtk_main();
  
    return 0;
}