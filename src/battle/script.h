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

#include "SDL2/SDL.h"

#include "../defs.h"
#include "../structs.h"
#include "../json/cJSON.h"

extern void completeMission(void);
extern void failMission(void);
extern void retreatEnemies(void);
extern void retreatAllies(void);
extern void addHudMessage(SDL_Color c, char *format, ...);
extern void addMessageBox(int time, char *title, char *format, ...);
extern void activateEntities(char *name);
extern void activateEntityGroup(char *groupName);
extern void activateObjective(int num);

extern Battle battle;
extern Colors colors;