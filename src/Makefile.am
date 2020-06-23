## Process this file with automake to produce Makefile.in

## Created by Anjuta


uidir = $(pkgdatadir)/ui
ui_DATA = tlclipedit.ui \
	TLClipEditIcon.png


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(TLCLIPEDIT_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = tlclipedit

tlclipedit_SOURCES = \
	main.c \
	tlclipedit.h \
	tlclipedit.c	


tlclipedit_LDFLAGS =

tlclipedit_LDADD = $(TLCLIPEDIT_LIBS)


if PLATFORM_WIN32
tlclipedit_LDFLAGS += -Wl,--export-all-symbols
else
tlclipedit_LDFLAGS += -Wl,--export-dynamic
endif

if NATIVE_WIN32
tlclipedit_LDFLAGS += -mwindows
endif


EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(pkgdatadir)

