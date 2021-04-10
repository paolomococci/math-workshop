/*
 * gtk_template.c
 *
 * Copyright (C) 2021 paolo mococci
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <gtk/gtk.h>

static void hello(
		GtkWidget *widget,
		gpointer data_gpointer
		) {
	g_print("\tExample of GNOME application.\n");
}

static void activate(
		GtkApplication* gtk_app,
		gpointer user_gpointer
		) {
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *button_box;

	window = gtk_application_window_new(gtk_app);
	gtk_window_set_title(GTK_WINDOW(window), "Welcome from GNOME example app");
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 150);

	button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_container_add(GTK_CONTAINER(window), button_box);

	button = gtk_button_new_with_label("hello");
	g_signal_connect(button, "clicked", G_CALLBACK (hello), NULL);
	g_signal_connect_swapped(
			button,
			"clicked",
			G_CALLBACK(gtk_widget_destroy),
			window
			);
	gtk_container_add(GTK_CONTAINER(button_box), button);

	gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
	GtkApplication *gtk_app;
	int status;
	gtk_app = gtk_application_new(NULL, G_APPLICATION_FLAGS_NONE);
	g_signal_connect(gtk_app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(gtk_app), argc, argv);
	g_object_unref(gtk_app);
	return status;
}
