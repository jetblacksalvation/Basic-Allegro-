#pragma once
/* 
* GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS *
* GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS *

*/
#include <allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

ALLEGRO_DISPLAY* display;
ALLEGRO_EVENT_QUEUE* event_queue;
ALLEGRO_TIMER* timer;

void m_setup() {
	al_init();
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_image_addon();
	
	//set up game screen, event queue, and timer
	 display = al_create_display(1000, 1000);
	 event_queue = al_create_event_queue();
	 timer = al_create_timer(1.0 / 60.0);

	 
}
/*
*  COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * 
*/


