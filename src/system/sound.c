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

#include "sound.h"

static void loadSounds(void);

static Mix_Chunk *sounds[SND_MAX];
static Mix_Music *music;

static int lastPlayerX;
static int lastPlayerY;

void initSounds(void)
{
	memset(sounds, 0, sizeof(Mix_Chunk*) * SND_MAX);
	
	music = NULL;
	
	loadSounds();
}

void playMusic(char *filename)
{
	if (music != NULL)
	{
		Mix_HaltMusic();
		Mix_FreeMusic(music);
		music = NULL;
	}
	
	music = Mix_LoadMUS(getFileLocation(filename));
	
    Mix_PlayMusic(music, -1);
}

void stopMusic(void)
{
	Mix_HaltMusic();
}

void playSound(int id)
{
	Mix_PlayChannel(-1, sounds[id], 0);
}

void playBattleSound(int id, int x, int y)
{
	float distance;
	int channel;
	float vol;
	
	if (player != NULL)
	{
		lastPlayerX = player->x;
		lastPlayerY = player->y;
	}
	
	distance = getDistance(lastPlayerX, lastPlayerY, x, y);
	
	if (distance <= MAX_BATTLE_SOUND_DISTANCE)
	{
		channel = Mix_PlayChannel(-1, sounds[id], 0);
		if (channel != -1)
		{
			vol = 255;
			vol /= MAX_BATTLE_SOUND_DISTANCE;
			vol *= distance;
			
			Mix_SetDistance(channel, vol);
		}
	}
}

static void loadSounds(void)
{
	sounds[SND_ARMOUR_HIT] = Mix_LoadWAV(getFileLocation("sound/275151__bird-man__gun-shot.ogg"));
	sounds[SND_SHIELD_HIT] = Mix_LoadWAV(getFileLocation("sound/49678__ejfortin__energy-short-sword-7.ogg"));
	sounds[SND_PLASMA] = Mix_LoadWAV(getFileLocation("sound/268344__julien-matthey__jm-noiz-laser-01.ogg"));
	sounds[SND_LASER] = Mix_LoadWAV(getFileLocation("sound/18382__inferno__hvylas.ogg"));
	sounds[SND_MAG] = Mix_LoadWAV(getFileLocation("sound/146725__fins__laser.ogg"));
	sounds[SND_SHIELD_BREAK] = Mix_LoadWAV(getFileLocation("sound/322603__clippysounds__glass-break.ogg"));
	sounds[SND_PARTICLE] = Mix_LoadWAV(getFileLocation("sound/77087__supraliminal__laser-short.ogg"));
	sounds[SND_MISSILE] = Mix_LoadWAV(getFileLocation("sound/65787__iwilldstroyu__laserrocket.ogg"));
	sounds[SND_BOOST] = Mix_LoadWAV(getFileLocation("sound/18380__inferno__hvrl.ogg"));
	sounds[SND_RADIO] = Mix_LoadWAV(getFileLocation("sound/321906__bruce965__walkie-talkie-roger-beep.ogg"));
	sounds[SND_INCOMING] = Mix_LoadWAV(getFileLocation("sound/242856__plasterbrain__nuclear-alarm.ogg"));
	sounds[SND_GET_ITEM] = Mix_LoadWAV(getFileLocation("sound/88275__s-dij__gbc-reload-06.ogg"));
	sounds[SND_EXPLOSION_1] = Mix_LoadWAV(getFileLocation("sound/162265__qubodup__explosive.ogg"));
	sounds[SND_EXPLOSION_2] = Mix_LoadWAV(getFileLocation("sound/207322__animationisaac__short-explosion.ogg"));
	sounds[SND_EXPLOSION_3] = Mix_LoadWAV(getFileLocation("sound/254071__tb0y298__firework-explosion.ogg"));
	sounds[SND_EXPLOSION_4] = Mix_LoadWAV(getFileLocation("sound/47252__nthompson__bad-explosion.ogg"));
	sounds[SND_JUMP] = Mix_LoadWAV(getFileLocation("sound/276912__pauldihor__transform.ogg"));
	sounds[SND_ECM] = Mix_LoadWAV(getFileLocation("sound/251431__onlytheghosts__fusion-gun-flash0-by-onlytheghosts.ogg"));
	sounds[SND_MAG_HIT] = Mix_LoadWAV(getFileLocation("sound/172591__timbre__zapitydooda.ogg"));
	sounds[SND_POWER_DOWN] = Mix_LoadWAV(getFileLocation("sound/39030__wildweasel__d1clsstf.ogg"));
	sounds[SND_SELECT_WEAPON] = Mix_LoadWAV(getFileLocation("sound/329359__bassoonrckr__reed-guillotine.ogg"));
	
	sounds[SND_GUI_CLICK] = Mix_LoadWAV(getFileLocation("sound/257786__xtrgamr__mouse-click.ogg"));
	sounds[SND_GUI_SELECT] = Mix_LoadWAV(getFileLocation("sound/321104__nsstudios__blip2.ogg"));
	sounds[SND_GUI_CLOSE] = Mix_LoadWAV(getFileLocation("sound/178064__jorickhoofd__slam-door-shut.ogg"));
	sounds[SND_GUI_DENIED] = Mix_LoadWAV(getFileLocation("sound/249300__suntemple__access-denied.ogg"));
}

void destroySounds(void)
{
	int i;
	
	for (i = 0 ; i < SND_MAX ; i++)
	{
		if (sounds[i])
		{
			Mix_FreeChunk(sounds[i]);
		}
	}
	
	if (music != NULL)
	{
		Mix_FreeMusic(music);
	}
}
