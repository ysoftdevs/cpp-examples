/**
 * Example 01 - Allegro 5
 * Display image
 *
 * Juraj Michalek - http://georgik.sinusgear.com
 */

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>


int main()
{
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_DISPLAY *display;
    
    ALLEGRO_EVENT event;
    ALLEGRO_BITMAP *image;

    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    display = al_create_display(640, 480);
    if (!display)
    {
        fprintf(stderr, "failed to create display!\n");
        return 2;
    }

    al_install_keyboard();
    al_init_image_addon();
    
    // Create Event queue
        event_queue = al_create_event_queue();

    // Register Keyboard to queue
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));

    // Clear screen
    al_clear_to_color(al_map_rgb_f(1.0, 1.0, 1.0));
    
    // Load and display image
    image = al_load_bitmap("smajlik.png");
    if (image != NULL)
    {
        al_draw_bitmap(image, 10, 10, 0);
    } else {
        printf("No bitmap.\n");
        return 1;
    }
    al_flip_display();

    // Wait until some key is pressed
    al_wait_for_event(event_queue, &event);

    // Release
    al_destroy_bitmap(image);
    al_uninstall_keyboard();
    al_uninstall_system();
    return 0;
}

