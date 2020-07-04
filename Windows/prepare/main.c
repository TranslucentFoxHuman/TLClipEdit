/*
 * main.c
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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int strwrite(char *writingmode,char *filename,char *filedata) {

	FILE* thisfilepointer;
	if((thisfilepointer = fopen(filename,writingmode)) == NULL) {
		return 1;
	}
	fputs(filedata,thisfilepointer);
	fclose(thisfilepointer);
	return 0;
}

int main(void) {
	printf("prepare.exe\nCopyright (C) 2020 TranslucentFoxHuman\n\nTLClipEdit is free software: you can redistribute it and/or modify it\nunder the terms of the GNU General Public License as published by the\nFree Software Foundation, either version 3 of the License, or\n(at your option) any later version.\n\nTLClipEdit is distributed in the hope that it will be useful, but\nWITHOUT ANY WARRANTY; without even the implied warranty of\nMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\nSee the GNU General Public License for more details.\n\nYou should have received a copy of the GNU General Public License along\nwith this program.  If not, see <http://www.gnu.org/licenses/>.");
	char *pwd = getcwd(NULL,NULL);
	char commandline[2048] = "";
	snprintf(commandline,2047,"cd %s\\bin\r\nstart tlclipedit.exe",pwd);
	strwrite("w","run_tlclipedit.bat",commandline);
	return 0;
}
