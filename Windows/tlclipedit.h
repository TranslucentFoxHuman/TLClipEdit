/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * tlclipedit.h
 * Copyright (C) 2020 TranslucentFoxHuman
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

#ifndef _TLCLIPEDIT_
#define _TLCLIPEDIT_


#include <gtk/gtk.h>

G_BEGIN_DECLS

#define TLCLIPEDIT_TYPE_APPLICATION             (tlclipedit_get_type ())
#define TLCLIPEDIT_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), TLCLIPEDIT_TYPE_APPLICATION, Tlclipedit))
#define TLCLIPEDIT_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), TLCLIPEDIT_TYPE_APPLICATION, TlclipeditClass))
#define TLCLIPEDIT_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TLCLIPEDIT_TYPE_APPLICATION))
#define TLCLIPEDIT_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), TLCLIPEDIT_TYPE_APPLICATION))
#define TLCLIPEDIT_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), TLCLIPEDIT_TYPE_APPLICATION, TlclipeditClass))


typedef struct _TlclipeditClass TlclipeditClass;
typedef struct _Tlclipedit Tlclipedit;
typedef struct _TlclipeditPrivate TlclipeditPrivate;

struct _TlclipeditClass
{
	GtkApplicationClass parent_class;
};

struct _Tlclipedit
{
	GtkApplication parent_instance;

	TlclipeditPrivate *priv;

};

GType tlclipedit_get_type (void) G_GNUC_CONST;
Tlclipedit *tlclipedit_new (void);

/* Callbacks */

G_END_DECLS


#endif /* _APPLICATION_H_ */

