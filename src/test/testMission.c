/*
Copyright (C) 2015 Parallel Realities

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "testMission.h"

static Mission mission;

void loadTestMission(char *filename)
{
	memset(&mission, 0, sizeof(Mission));
	
	STRNCPY(mission.filename, filename, MAX_DESCRIPTION_LENGTH);
	
	game.currentMission = &mission;
	
	initBattle();
	
	loadMission(filename);
}