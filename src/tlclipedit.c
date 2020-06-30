/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * tlclipedit.c
 * 
 * 
 * TLClipEdit is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * TLClipEdit is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "tlclipedit.h"
#include <stdio.h>
#include <stdlib.h>

#include <glib/gi18n.h>

/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/ui/tlclipedit.ui" */
#define UI_FILE "src/tlclipedit.ui"
#define TOP_WINDOW "window"

GtkWidget *inputbox1;
GtkWidget *window;
GtkWidget *textview1;
GtkBuilder *builder;

char *versioninfo = "0.1";
char *copyrightstring =" tlclipedit.c\n Copyright (C) 2020 TranslucentFoxHuman\n \n TLClipEdit is free software: you can redistribute it and/or modify it\n under the terms of the GNU General Public License as published by the\n Free Software Foundation, either version 3 of the License, or\n (at your option) any later version.\n \n TLClipEdit is distributed in the hope that it will be useful, but\n WITHOUT ANY WARRANTY; without even the implied warranty of\n MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n See the GNU General Public License for more details.\n \n You should have received a copy of the GNU General Public License along\n with this program.  If not, see <http://www.gnu.org/licenses/>.";

G_MODULE_EXPORT void copybuttonclicked(GtkButton *button, gpointer user_data){
	gtk_clipboard_set_text (gtk_clipboard_get (NULL),gtk_entry_get_text (GTK_ENTRY(inputbox1)),-1);
}

G_MODULE_EXPORT void pastbuttonclicked(GtkButton *button, gpointer user_data){
	gtk_entry_set_text(GTK_ENTRY(inputbox1),gtk_clipboard_wait_for_text(gtk_clipboard_get (NULL)));
}

G_MODULE_EXPORT void aboutclicked(GtkButton *button, gpointer user_data){
	char* auth[] = {"TranslucentFoxHuman (半透明狐人間)",NULL};
	GdkPixbuf *windowicon = gtk_window_get_icon (GTK_WINDOW(window));
	/*auth[0] = "TranslucentFoxHuman (半透明狐人間)";
	auth[1] = NULL;*/
	/*GtkWidget *AboutDiag = gtk_about_dialog_new ();
	//AboutDiag->
	gtk_about_dialog_set_program_name (GTK_ABOUT_DIALOG(AboutDiag),"TLClipEdit");
	gtk_about_dialog_set_version (GTK_ABOUT_DIALOG(AboutDiag),versioninfo);
	gtk_dialog_run(AboutDiag);*/
	gtk_show_about_dialog (NULL,
                       "program-name", "TLClipEdit",
                       "title", "TLClipEditについて",
	                       "comments", "簡単なクリップボードの編集を行うプログラム",
	                       "license" , copyrightstring,
	                       "copyright", "Copyright (C) 2020 TranslucentFoxHuman",
	                       "license-type", GTK_LICENSE_GPL_3_0,
	                       "version" , versioninfo,
	                       "logo", windowicon,
	                       "authors", auth,
                       NULL);
}

G_MODULE_EXPORT void clearinputbox(GtkButton *button, gpointer user_data){
	gtk_entry_set_text(GTK_ENTRY(inputbox1),"");
}

G_MODULE_EXPORT void copytorireki(GtkButton *button, gpointer user_data){
	char texts[102400] = "";
	char printtext[102400] = "";
	int textssize;
	char *entrytext = gtk_entry_get_text(GTK_ENTRY(inputbox1));
	GtkTextBuffer *txtbuf = gtk_text_view_get_buffer (textview1);
	GtkTextIter startiter,enditer;
	gtk_text_buffer_get_start_iter(txtbuf,&startiter);
	gtk_text_buffer_get_end_iter (txtbuf,&enditer);


	strcpy(texts,gtk_text_buffer_get_text (txtbuf,&startiter,&enditer,TRUE));
	textssize = (int)strlen(texts);
	textssize = textssize + (int)strlen(entrytext);

	/*if (textssize >= 10240) {
		//q_errdiag(mainwindow,"履歴がいっぱいです");
		return;
	}*/

	snprintf(printtext,102400,"%s%s\n",texts,entrytext);

	gtk_text_buffer_set_text (txtbuf,printtext,-1);
}

G_DEFINE_TYPE (Tlclipedit, tlclipedit, GTK_TYPE_APPLICATION);

/* ANJUTA: Macro TLCLIPEDIT_APPLICATION gets Tlclipedit - DO NOT REMOVE */
struct _TlclipeditPrivate
{
	/* ANJUTA: Widgets declaration for tlclipedit.ui - DO NOT REMOVE */
};

/* Create a new window loading a file */
void
tlclipedit_new_window (GApplication *app,
                           GFile        *file)
{
	

	
	GError* error = NULL;

	TlclipeditPrivate *priv = TLCLIPEDIT_APPLICATION(app)->priv;

	/* Load UI from file */
	builder = gtk_builder_new ();
	if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
	{
		g_critical ("Couldn't load builder file: %s", error->message);
		g_error_free (error);
	}
	// オブジェクトの取得
	inputbox1 = gtk_builder_get_object(builder,"inputbox1");
	textview1 = gtk_builder_get_object (builder,"textview1");

	/* Auto-connect signal handlers */
	gtk_builder_connect_signals (builder, app);

	/* Get the window object from the ui file */
	window = GTK_WIDGET (gtk_builder_get_object (builder, TOP_WINDOW));
        if (!window)
        {
		g_critical ("Widget \"%s\" is missing in file %s.",
				TOP_WINDOW,
				UI_FILE);
        }

	
	/* ANJUTA: Widgets initialization for tlclipedit.ui - DO NOT REMOVE */

	g_object_unref (builder);
	
	
	gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
	if (file != NULL)
	{
		
		/* TODO: Add code here to open the file in the new window */
	}

	gtk_widget_show_all (GTK_WIDGET (window));
}


/* GApplication implementation */
static void
tlclipedit_activate (GApplication *application)
{
	tlclipedit_new_window (application, NULL);
}

static void
tlclipedit_open (GApplication  *application,
                     GFile        **files,
                     gint           n_files,
                     const gchar   *hint)
{
	gint i;

	for (i = 0; i < n_files; i++)
		tlclipedit_new_window (application, files[i]);
}

static void
tlclipedit_init (Tlclipedit *object)
{
	object->priv = G_TYPE_INSTANCE_GET_PRIVATE (object, TLCLIPEDIT_TYPE_APPLICATION, TlclipeditPrivate);
}

static void
tlclipedit_finalize (GObject *object)
{
	G_OBJECT_CLASS (tlclipedit_parent_class)->finalize (object);
}

static void
tlclipedit_class_init (TlclipeditClass *klass)
{
	G_APPLICATION_CLASS (klass)->activate = tlclipedit_activate;
	G_APPLICATION_CLASS (klass)->open = tlclipedit_open;

	g_type_class_add_private (klass, sizeof (TlclipeditPrivate));

	G_OBJECT_CLASS (klass)->finalize = tlclipedit_finalize;
}

Tlclipedit *
tlclipedit_new (void)
{
	return g_object_new (tlclipedit_get_type (),
	                     "application-id", "org.gnome.tlclipedit",
	                     "flags", G_APPLICATION_HANDLES_OPEN,
	                     NULL);
}

