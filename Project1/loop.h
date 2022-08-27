#pragma once
#include "game.h"
/*
* GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP 
* GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP 
*/
void main_loop() {
	//call setup
	
	m_setup();
	ALLEGRO_COLOR blue ={ 255.f,255.f,255.f,0.f };

	al_start_timer(timer);
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	bool _exit = false;
	while (_exit == false) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {

			printf("you closed the window!\n");
			exit(0);

		}
		if (al_is_event_queue_empty(event_queue)) {
			al_clear_to_color(al_map_rgb(0, 0, 0));//clears screen

			al_draw_line(0.5, 0, 0.5, 6, blue, 1);

			al_flip_display();//actuall draws stuff
			
		}
		

	}
	//destroy all stuff funciton



}


