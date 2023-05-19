#include <allegro.h>
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "snake_jeu.h"
#include "course_hipi.h"
#define LARGO 1000
#define ANCHO 720
typedef struct personnage
{
    BITMAP* bas[3];
    BITMAP* gauche[3];
    BITMAP* droite[3];
    BITMAP* haut[3];
    int x, y;
    int direction;
    int frame;
    int en_deplacement;
}t_personnage;

void separer_bitmap_personnage(t_personnage* personnage, BITMAP* bitmap)
{
    int taille_w = 48;
    int taille_h = 48;

    for (int j = 0; j < 3; j++) {
        personnage->bas[j] = create_sub_bitmap(bitmap, j * taille_w, 0 * taille_h, taille_w, taille_h);
        personnage->gauche[j] = create_sub_bitmap(bitmap, j * taille_w, 1 * taille_h, taille_w, taille_h);
        personnage->droite[j] = create_sub_bitmap(bitmap, j * taille_w, 2 * taille_h, taille_w, taille_h);
        personnage->haut[j] = create_sub_bitmap(bitmap, j * taille_w, 3 * taille_h, taille_w, taille_h);
    }
}

void dessiner_personnage(t_personnage* personnage, BITMAP* buffer)
{
    BITMAP* frame;
    switch (personnage->direction) {
        case 0:
            frame = personnage->bas[personnage->frame];
            break;
        case 1:
            frame = personnage->gauche[personnage->frame];
            break;
        case 2:
            frame = personnage->droite[personnage->frame];
            break;
        case 3:
            frame = personnage->haut[personnage->frame];
            break;
    }
    masked_blit(frame, buffer, 0, 0, personnage->x, personnage->y, frame->w, frame->h);
}


void maj_personnage(t_personnage* personnage)
{
    int vitesse = 3;
    personnage->en_deplacement = 0;
    if (key[KEY_UP]) {
        personnage->y -= vitesse;
        personnage->direction = 3;
        personnage->en_deplacement = 1;
    }
    if (key[KEY_DOWN]) {
        personnage->y += vitesse;
        personnage->direction = 0;
        personnage->en_deplacement = 1;
    }
    if (key[KEY_LEFT]) {
        personnage->x -= vitesse;
        personnage->direction = 1;
        personnage->en_deplacement = 1;
    }
    if (key[KEY_RIGHT]) {
        personnage->x += vitesse;
        personnage->direction = 2;
        personnage->en_deplacement = 1;
    }
}
void menu();
void nom_des_perso();
void personnage() {
    int ticket1=5,ticket2=5;


    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1000, 720, 0, 0);

    BITMAP *buffer = create_bitmap(1000, 720);

    BITMAP *background = load_bitmap("../Map.bmp", NULL);
    if (!background) {
        allegro_message("Erreur lors du chargement de 'background.bmp'\n");

    }

    BITMAP *sprite = load_bitmap("../sprite.bmp", NULL);
    BITMAP *ticket = load_bitmap("../ticket.bmp", NULL);
    BITMAP *parchemin = load_bitmap("../parchemin.bmp", NULL);
    BITMAP *back = load_bitmap("../Back.bmp", NULL);
    if (!sprite) {
        allegro_message("Erreur lors du chargement de 'sprite.bmp'\n");
        destroy_bitmap(background);
        destroy_bitmap(buffer);

    }

    t_personnage personnage;
    personnage.direction = 0;
    personnage.frame = 0;
    personnage.x = SCREEN_W/2;
    personnage.y = SCREEN_H/2;

    separer_bitmap_personnage(&personnage, sprite);

    int frame_counter = 0;

    while (!key[KEY_ESC]) {

        maj_personnage(&personnage);
        show_mouse( screen);

        stretch_blit(background, buffer, 0, 0, background->w, background->h, 0, 0, buffer->w, buffer->h);

        dessiner_personnage(&personnage, buffer);

        blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
        textprintf_ex(screen,font,(SCREEN_W/2)+100,SCREEN_H-(SCREEN_H-100),0xFFFFFF,-1,"x: %d  y: %d ",personnage.x,personnage.y);

        frame_counter++;
        if (frame_counter >= 10) {
            if (personnage.en_deplacement) {
                personnage.frame = (personnage.frame + 1) % 3;
            } else {
                personnage.frame = 0;
            }
            frame_counter = 0;
        }

        if(key[KEY_T]){
            rest(10);
            clear(screen);

            while (!key[KEY_B]){
                blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
                masked_blit(parchemin,buffer,0,0,100,0,parchemin->w,parchemin->h);
                masked_blit(back,buffer,0,0,450,100,back->w,back->h);
                textprintf_ex(buffer,font,300,200, makecol(0, 0, 0),-1,"Angel         Mederic");
                textprintf_ex(buffer,font,300,300, makecol(0, 0, 0),-1,"%d            %d           Points",PUNTOS1,PUNTOS2);//on doit remplir
                textprintf_ex(buffer,font,300,400, makecol(0, 0, 0),-1,"%d            %d          Victoires",partie_gagnee_joueur1_,partie_gagnee_joueur2_);//on doit remplir
                textprintf_ex(buffer,font,300,500, makecol(0, 0, 0),-1,"Angel         Mederic");//on doit remplir
                //masked_blit(ticket,buffer,0,0,100,0,ticket->w,ticket->h);

                //blit(parchemin, buffer, 0, 0, 100, 0, parchemin->w, parchemin->h);
               // stretch_blit(tableau, buffer, 0, 0, tableau->w, tableau->h, 0, 0, buffer->w, buffer->h);

            }


            }
        else if(key[KEY_O]){
            rest(10);
            clear(screen);
            while (!key[KEY_B]){
                blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);

                masked_blit(ticket,buffer,0,0,650,0,ticket->w,ticket->h);
                masked_blit(back,buffer,0,0,650,100,back->w,back->h);
                textprintf_ex(buffer,font,675,25, makecol(0, 0, 0),-1,"ticket: J1:%d  J2: %d ",ticket1,ticket2);

                //blit(parchemin, buffer, 0, 0, 100, 0, parchemin->w, parchemin->h);
                // stretch_blit(tableau, buffer, 0, 0, tableau->w, tableau->h, 0, 0, buffer->w, buffer->h);

            }


        }
        else if(key[KEY_S]){
            snake_game();
            if(PUNTOS1>PUNTOS2){
                ticket1++;
                ticket2--;
            }
            else{
                ticket2++;
                ticket1--;
            }
        }
        else if(key[KEY_C]){

            course_hipi();
            if(partie_gagnee_joueur1_>partie_gagnee_joueur2_){
                ticket1++;
                ticket2--;
            }
            else if(partie_gagnee_joueur1_<partie_gagnee_joueur2_){
                ticket2++;
                ticket1--;
            }
        }


        rest(10);
    }
    menu();


}
void nom_des_perso(){

    char joueur1[256] = {0};
    int index = 0;
    char joueur2[256] = {0};
    int index1 = 0;
    BITMAP *tableau = load_bitmap("../tableau_map.bmp", NULL);




    while (!key[KEY_ESC]) {

        clear_to_color(screen, makecol(255, 255, 255));
        //blit(tableau, screen, 0, 0, 0, 0, tableau->w, tableau->h);
        stretch_blit(tableau, screen, 0, 0, tableau->w, tableau->h, 0, 0, screen->w, screen->h);


        textout_centre_ex(screen, font, joueur1, SCREEN_W / 2, SCREEN_H / 2, makecol(0, 0, 0), -1);


        if (keypressed()) {
            int key = readkey();
            char ascii = key & 0xff;

            if (ascii >= 32 && ascii <= 126 && index < 255) {
                joueur1[index++] = ascii;
                joueur1[index] = '\0';
            }
        }
        vsync();


    }
    while (!key[KEY_ENTER]) {

        clear_to_color(screen, makecol(255, 255, 255));
        stretch_blit(tableau, screen, 0, 0, tableau->w, tableau->h, 0, 0, screen->w, screen->h);

        textout_ex(screen, font, joueur1, SCREEN_W / 2, SCREEN_H / 2, makecol(0, 0, 0), -1);


        textout_centre_ex(screen, font, joueur2, SCREEN_W/2 , (SCREEN_H/2) -100, makecol(0, 0, 0), -1);


        if (keypressed()) {
            int key = readkey();
            char ascii = key & 0xff;

            if (ascii >= 32 && ascii <= 126 && index < 255) {
                joueur2[index1++] = ascii;
                joueur2[index1] = '\0';
            }
        }


        vsync();

    }
    rest(10);

}
void menu(){
    BITMAP *buffer= create_bitmap(LARGO,ANCHO);
    BITMAP *fondo1= load_bitmap("../fond1.bmp",NULL);
    BITMAP *fondo2= load_bitmap("../fond2.bmp",NULL);
    BITMAP *fondo3= load_bitmap("../fond3.bmp",NULL);
    bool sortie = false;

    while (!sortie){
        if(mouse_x>445 && mouse_x<557 && mouse_y>318 && mouse_y<384){
            //blit(fondo2,buffer,0,0,0,0,LARGO,ANCHO);
            stretch_blit(fondo2,buffer,0,0,fondo1->w,fondo1->h,0,0,LARGO,ANCHO);
            if(mouse_b&1){
                nom_des_perso();
                personnage();
                break;

            }
        }else if (mouse_x>445 && mouse_x<557 && mouse_y>401 && mouse_y<485){
            stretch_blit(fondo3,buffer,0,0,fondo1->w,fondo1->h,0,0,LARGO,ANCHO);
            //blit(fondo3,buffer,0,0,0,0,LARGO,ANCHO);
            if(mouse_b&1){
                sortie = true;// como un exit 0
            }
        }else{//stretch_blit(game, screen, 0, 0, game->w, game->h,0, 0, LARGO, ANCHO);
            stretch_blit(fondo1,buffer,0,0,fondo1->w,fondo1->h,0,0,LARGO,ANCHO);
            //blit(fondo1,buffer,0,0,0,0,LARGO,ANCHO);
        }
        show_mouse(buffer);

        blit(buffer,screen,0,0,0,0,LARGO,ANCHO);

    }
    destroy_bitmap(buffer);
}




int main(){
    allegro_init();
    install_mouse();
    install_keyboard();

    set_gfx_mode(GFX_AUTODETECT_WINDOWED,LARGO,ANCHO,0,0);
    //snake_game();
    menu();

    return 0;
}END_OF_MAIN();

