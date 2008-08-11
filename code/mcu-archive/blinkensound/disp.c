/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <stdio.h>
#include "disp.h"
#include "values.h"

void disp_paint (void) {
        int x, y;

        /* clear screen */ 
        printf ("\033[2J\033[H"); 

        for (y=0; y<=25; y++) {
                for (x=0; x<WIDTH; x++) {
                        printf (" %c", (audio_vals[x][0] > (25-y)*10)?'A':' ');
                }

		printf (" | ");
		for (x=0; x<WIDTH; x++) {
                        printf (" %c", (audio_vals[x][1] > (25-y)*10)?'A':' ');
                }

                printf (" |\n");
        }

        for (x=0; x<WIDTH*2; x++)
                printf ("--");

        printf ("---\n");

}

