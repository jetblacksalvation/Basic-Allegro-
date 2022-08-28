#pragma once
#include "game.h"
/*
* GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP 
* GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP * GAMELOOP 
*/
void main_loop() {
	//call setup	
	m_setup();
	bool _exit = false;
	bool keys[6] = {false,false,false,false,false,false};
	while (_exit == false) {
		input(keys);

		dist = distance(player, object);
		projection =  temp_ret(player, object);//assign the values of shape to projection 

		//drawing section 
		if (al_is_event_queue_empty(event_queue)) {
			al_clear_to_color(al_map_rgb(0, 0, 0));//clears screen

			al_draw_filled_rectangle(projection.x, projection.y, 100+projection.x, 100+projection.y, red);

			al_flip_display();//actuall draws stuff
			
		}
		

	}
	//destroy all stuff funciton



}


