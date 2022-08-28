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
#include <math.h>


ALLEGRO_DISPLAY* display;
ALLEGRO_EVENT_QUEUE* event_queue;
ALLEGRO_TIMER* timer;
ALLEGRO_TRANSFORM camera_transform;
ALLEGRO_STATE previous_state;

//calculation variables


float dist;//distance var
float angle = 0;//angle of player
float p_angle = 0;
void m_setup() {
	//initialize stuff
	al_init();
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_image_addon();
	
	//set up game screen, event queue, and timer
	 display = al_create_display(1000, 1000);
	 event_queue = al_create_event_queue();
	 timer = al_create_timer(1.0 / 30.0);
	 //register stuff
	 al_start_timer(timer);
	 al_register_event_source(event_queue, al_get_display_event_source(display));
	 al_register_event_source(event_queue, al_get_timer_event_source(timer));
	 al_register_event_source(event_queue, al_get_keyboard_event_source());

	 al_store_state(&previous_state, ALLEGRO_STATE_TRANSFORM);
	 
}
/*
*  COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * 
*/
ALLEGRO_COLOR white = { 255.f,255.f,255.f,0.f };
ALLEGRO_COLOR blue = { 0.f,0.f,255.f,0.f };
ALLEGRO_COLOR green = { 0.f,255.f,0.f,0.f };
ALLEGRO_COLOR red = { 255.f,0.f,0.f,0.f };

//point struct 

struct point{
	float x ,y;
}player = { 500,500 };
struct point object = { 750,750 };

struct point projection;
//distance formula 
float distance(struct point p1, struct point p2) {
	return sqrtf(
		powf(p1.x - p2.x, 2) + powf(p1.y - p2.y, 2)
	);

}
struct point temp_ret(struct point p1, struct point p2) {
	struct point temp;
	//define pangle
	//
	dist = distance(p1, p2);
	p_angle = atan2(
		(p2.y - p1.y), (p2.x - p1.x)
	);
	//if (p2.x > p1.x) {
	//	
		
	//	p_angle = 180;
	//	temp.x = p1.x - (cosf( angle) *dist);
	//	temp.y = p1.y -(sinf( angle) *dist);
	//	return temp;
	//}
	
	
	temp.x = p1.x + (cosf(angle)*dist );
	temp.y = p1.y + (sinf(angle) *dist);
	return temp;
};
//key enums

enum {
	a_left, a_right, w, a, s, d

};

//input function 
void input(bool keys[6]) {
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			printf("you closed the window!\n");
			exit(0);

		}
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_E:
				keys[a_left] = true;
				break;
			case ALLEGRO_KEY_Q:
				keys[a_right] = true;
				break;
			case ALLEGRO_KEY_W:
				keys[w] = true;
				break;
			case ALLEGRO_KEY_A:
				keys[a] = true;
			break; 
			case ALLEGRO_KEY_S:
				keys[s] = true;
				break;
			case ALLEGRO_KEY_D:
				keys[d] = true;
				break;
			
			}
			
		}


		
		if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_E:
				keys[a_left] = false;
				break;
			case ALLEGRO_KEY_Q:
				keys[a_right] = false;
				break;
			case ALLEGRO_KEY_W:
				keys[w] = false;
				break;
			case ALLEGRO_KEY_A:
				keys[a] = false;
				break;
			case ALLEGRO_KEY_S:
				keys[s] = false;
				break;
			case ALLEGRO_KEY_D:
				keys[d] = false;
				break;

			}
		}
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (keys[0] == true)angle-=0.1;
			if (keys[1] == true)angle+=0.1;
			if (keys[w] == true) player.y += 5;
			if (keys[a] == true)player.x -= 5;
			if (keys[s] == true)player.y -= 5;
			if (keys[d] == true)player.x += 5;
			printf("%f is angle \n", angle);
			printf("%f is p_angle\n", p_angle);
			//variable editing 
			al_build_transform(&camera_transform, -player.x + 500, -player.y + 500, 1, 1, 0);
			al_use_transform(&camera_transform);
			if (angle >= 360) {
				angle = 0;
			}
			if (angle < 0) {
				angle = 359;
			}
			if (p_angle >= 360) {
				p_angle = 0;
			}
			if (p_angle < 0) {
				p_angle = 359;
			}
		}


}

// IDEA IDEA IDEA IDEA IDEA IDEA IDEA IDEA IDEA IDEA IDEA IDEA IDEA
/*
I believe that creating something to hold how many "points" i will need and creating a vector like struct that can return how many points it might need to
drw is cool

*/
