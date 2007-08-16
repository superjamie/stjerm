/*
 * main.c
 * This file is part of Stjerm
 *
 * Copyright (C) 2007 - Stjepan Glavina
 * Copyright (C) 2007 - Markus Groß
 * 
 * Stjerm is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Stjerm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Stjerm; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */

#include <gtk/gtk.h>
#include "stjerm.h"

int sargc;
char **sargv;

void print_help(void);

void print_help(void) {
	printf("stjerm version %s\n"
           "Usage: %s "
           "[--help] "
		   "[--toggle] "
           "[-k KEY] "
           "[-m MOD] "
           "[-fn FONT] "
           "[-bg COLOR] "
           "[-fg COLOR]\n       "
           "[-b TYPE] "
           "[-o OPACITY] "
           "[-w WIDTH] "
           "[-h HEIGHT] "
           "[-p POSITION]\n       "
           "[-s POSITION] "
           "[-sh SHELL] "
           "[-bl LINES] "
           "[-showtabs VAL] "
           "[-tabpos POSITION]\n       "
           "[-tablabel NAME] "
		   "[-c0 COLOR] "
		   "[-c1 COLOR] "
		   "... "
		   "[-c15 COLOR]\n\n"
           "Options:\n"
           "  --help            Display this menu\n"
		   "  --info            Display .Xdefaults options\n"
		   "  --toggle          Show/Hide the current stjerm instance\n"
           "  -k KEY            Shortcut key\n"
           "  -m MOD            Mod key used in combination with shortcut key: shift,\n"
           "                    control, alt, windows, none\n"
           "  -fn FONT          Terminal font\n"
           "  -bg COLOR         Background color\n"
           "  -fg COLOR         Foreground color\n"
           "  -b TYPE           Border type: thin, thick, none\n"
           "  -o OPACITY        Opacity (range: 10 - 100)\n"
           "  -w WIDTH          Window width\n"
           "  -h HEIGHT         Window height\n"
           "  -p POSITION       Window position: top, bottom, left, right\n"
           "  -s POSITION       Scrollbar position: left, right, none\n"
           "  -sh SHELL         Shell (if not set: the user's default shell)\n"
           "  -bl LINES         Scrollback lines (default: 1000; 0 to disable scrollback)\n"
           "  -showtab VAL      Valid values: never, one, always.\n"
           "                    To show the tab bar if one tab is opened, or never or always.\n"
           "  -tabpos POSITION  Tab bar position: top, bottom, left, right\n"
           "  -tablabel NAME    Label of the tab buttons\n"
		   "  -c0 COLOR         Specify color 0 of the terminals color palette.\n"
		   "  -c1 COLOR         Specify color 1 of the terminals color palette.\n"
		   "     ...            You may specify no palette, or a complete one with 16 total colors.\n"
		   "     ...            For this you have to use -c0, -c1, ..., -c15.\n"
           "  -c15 COLOR        Specify color 15 of the terminals color palette.\n\n"
		   "Note:     any colors in hex codes are entered without the leading '#'.\n\n"
		   "Examples: %s -fn \"Bitstream Vera Sans Mono 12\" -bg white -k F12 -sh /bin/bash\n"
           "          %s -bg black -fg green -w 800 -h 405 -s right -m alt -k f -bl 10000\n"
           "          %s -b thick -w 500 -p left -t best -o 90 -m shift -k tab -sh /bin/zsh\n",
           STJERM_VERSION, sargv[0], sargv[0], sargv[0], sargv[0]);
}

int main(int argc, char *argv[]) {
	sargc = argc;
	sargv = argv;

	if (!g_thread_supported())
		g_thread_init(NULL);
	gdk_threads_init();
	gtk_init(&argc, &argv);

	conf_init();
	build_mainwindow();

	gdk_threads_enter();
	gtk_main();
	gdk_threads_leave();

	return 0;
}
