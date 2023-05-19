
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 720

#define Taille_h 91
#define Taille_w 124
#define NUM_HORSES 5
int partie_gagnee_joueur1=0;
int partie_gagnee_joueur2=0;
int partie_gagnee_joueur1_=0;
int partie_gagnee_joueur2_=0;
typedef struct horse
{
    BITMAP* sprites[NUM_HORSES];
    int x[NUM_HORSES];
    int speed;
    int paris[2];
    int victoire;
    int num_joueur;
}t_horse;

void draw_pari(t_horse* horse, BITMAP* buffer);
void pari(t_horse* horse, BITMAP* buffer);
void Separer_bitmap_cheval(t_horse* horse, BITMAP* bitmap);
void draw_cheval(t_horse* horse, BITMAP* buffer);
void init_cheval(t_horse* horse);
void arriver(t_horse* horse, BITMAP* buffer);

void course_hipi()
{
    //allegro_init();
    srand(time(NULL));
    set_color_depth(32);
    //install_keyboard();
    //install_mouse();
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,SCREEN_WIDTH,SCREEN_HEIGHT,0,0))!=0){
        allegro_message("Pb de mode graphique") ;
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *buffer = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);
    clear_bitmap(buffer);
    BITMAP *background = load_bitmap("../background.bmp", NULL);
    if (!background) {
        allegro_message("Erreur lors du chargement de 'Cheval.bmp'\n");

    }
    BITMAP *cheval= load_bitmap("../Cheval.bmp",NULL);
    if (!cheval) {
        allegro_message("Erreur lors du chargement de 'Cheval.bmp'\n");

    }


    t_horse horse;
    Separer_bitmap_cheval(&horse, cheval);
    init_cheval(&horse);

    while (!key[KEY_ENTER]) {
        horse.num_joueur=1;
        pari(&horse, buffer);
        textout_ex(buffer, font, "Appuyer sur la touche d'entré pour sauvegarder votre pari",SCREEN_WIDTH-500,SCREEN_HEIGHT-50,
                   makecol(255,255,255),1);
        blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
        rest(20);
    }
    while (!key[KEY_SPACE]) {
        horse.num_joueur=2;
        pari(&horse, buffer);
        textout_ex(buffer, font, "Appuyer sur la touche d'espace pour sauvegarder votre pari",SCREEN_WIDTH-500,SCREEN_HEIGHT-50,
                   makecol(255,255,255),1);
        blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
        rest(20);
    }
    while (horse.victoire==0){
        clear_bitmap(buffer);
        blit(background, buffer,0,0,0,0, background->w, background->h);
        draw_cheval(&horse,buffer);
        blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
        rest(20);
    }
    while (!key[KEY_B]){
        arriver(&horse, buffer);

    }
    if(partie_gagnee_joueur1>partie_gagnee_joueur2){
        partie_gagnee_joueur1_++;

    }
    else{
        partie_gagnee_joueur2_++;
    }
    rest(30);
    destroy_bitmap(buffer);
    destroy_bitmap(background);
    destroy_bitmap(cheval);


}


void Separer_bitmap_cheval(t_horse* horse, BITMAP* bitmap){
    for(int i=0;i<NUM_HORSES; i++){
        horse->sprites[i]=create_sub_bitmap(bitmap, i * Taille_w, 0, Taille_w, Taille_h);
    }
}
void init_cheval(t_horse* horse){
    horse->num_joueur=0;
    horse->victoire=0;
    horse->speed = 0;
    for( int i=0; i<NUM_HORSES;i++ ){
        horse->x[i]= 0;
    }
}


void draw_cheval(t_horse* horse, BITMAP* buffer){
    for(int i=0; i<NUM_HORSES; i++){
        if(horse->x[i]>= 980 - Taille_w){
            horse->victoire=i+1;
        }
        else{
            horse->speed = rand()%8;
            horse->x[i] = horse->x[i]+horse->speed;
            masked_blit(horse->sprites[i], buffer, 0, 0, horse->x[i], 151+i*50, Taille_w, Taille_h);
        }
    }
}

void draw_pari(t_horse* horse, BITMAP* buffer){
    clear_to_color(buffer, makecol(0,0,0));
    textprintf_ex(buffer,font,SCREEN_WIDTH/2-100,30, makecol(255,255,255),1, "Joueur %d : Faites votre pari", horse->num_joueur);
    rect(buffer,130,230,290,270,makecol(255,255,255));
    rect(buffer,130,280,290,320,makecol(255,255,255));
    rect(buffer,130,330,290,370,makecol(255,255,255));
    rect(buffer,130,380,290,420,makecol(255,255,255));
    rect(buffer,130,430,290,470,makecol(255,255,255));
    textout_ex(buffer,font,"a : Cheval bleu",150,250, makecol(64,77,201),1);
    textout_ex(buffer,font,"b : Cheval jaune",150,300, makecol(254,240,53),1);
    textout_ex(buffer,font,"c : Cheval rouge",150,350, makecol(195,47,47),1);
    textout_ex(buffer,font,"d : Cheval vert",150,400, makecol(44,176,81),1);
    textout_ex(buffer,font,"e : Cheval violet",150,450, makecol(162,76,162),1);
}


void pari(t_horse* horse, BITMAP* buffer){
    draw_pari(horse,buffer);
    if(key[KEY_A]){
        horse->paris[horse->num_joueur-1]=1;
        textprintf_ex(buffer,font,SCREEN_WIDTH/2,SCREEN_HEIGHT/2, makecol(255,255,255),1, "Le paris du joeur %d est le cheval bleu", horse->num_joueur);
    }
    if(key[KEY_B]){
        horse->paris[horse->num_joueur-1]=2;
        textprintf_ex(buffer,font,SCREEN_WIDTH/2,SCREEN_HEIGHT/2, makecol(255,255,255),1, "Le paris du joeur %d est le cheval jaune", horse->num_joueur);
    }if(key[KEY_C]){
        horse->paris[horse->num_joueur-1]=3;
        textprintf_ex(buffer,font,SCREEN_WIDTH/2,SCREEN_HEIGHT/2, makecol(255,255,255),1, "Le paris du joeur %d est le cheval rouge", horse->num_joueur);
    }if(key[KEY_D]){
        horse->paris[horse->num_joueur-1]=4;
        textprintf_ex(buffer,font,SCREEN_WIDTH/2,SCREEN_HEIGHT/2, makecol(255,255,255),1, "Le paris du joeur %d est le cheval vert", horse->num_joueur);
    }if(key[KEY_E]){
        horse->paris[horse->num_joueur-1]=5;
        textprintf_ex(buffer,font,SCREEN_WIDTH/2,SCREEN_HEIGHT/2, makecol(255,255,255),1, "Le paris du joeur %d est le cheval violet", horse->num_joueur);
    }
}
void arriver(t_horse* horse, BITMAP* buffer){

    clear_to_color(buffer, makecol(0,0,0));
    if (horse->victoire==1){
        textout_ex(buffer, font, "Le cheval bleu a gagné",SCREEN_WIDTH/2-100,50,makecol(255,255,255),1);
    }
    if (horse->victoire==2){
        textout_ex(buffer, font, "Le cheval jaune a gagné",SCREEN_WIDTH/2-100,50,makecol(255,255,255),1);
    }if (horse->victoire==3){
        textout_ex(buffer, font, "Le cheval rouge a gagné",SCREEN_WIDTH/2-100,50,makecol(255,255,255),1);
    }if (horse->victoire==4){
        textout_ex(buffer, font, "Le cheval vert a gagné",SCREEN_WIDTH/2-100,50,makecol(255,255,255),1);
    }if (horse->victoire==5){
        textout_ex(buffer, font, "Le cheval violet a gagné",SCREEN_WIDTH/2-100,50,makecol(255,255,255),1);
    }
    if(horse->victoire==horse->paris[0]){
        textout_ex(buffer, font, "Félicitaion Joueur 1,",100,300,makecol(255,255,255),1);
        textout_ex(buffer, font, "vous avez gangné 1 ticket",80,315,makecol(255,255,255),1);
        partie_gagnee_joueur1++;
    }
    if(horse->victoire!=horse->paris[0]){
        textout_ex(buffer, font, "Dommage Joeur 1,",180,300,makecol(255,255,255),1);
        textout_ex(buffer, font, "vous y été presque, vous avez perdu 1 ticket",50,315,makecol(255,255,255),1);
        partie_gagnee_joueur1--;
    }if(horse->victoire==horse->paris[1]){
        textout_ex(buffer, font, "Félicitaion, Joueur 2",600,300,makecol(255,255,255),1);
        textout_ex(buffer, font, "vous avez gangné 1 ticket",580,315,makecol(255,255,255),1);
        partie_gagnee_joueur2++;
    }if(horse->victoire!=horse->paris[1]){
        textout_ex(buffer, font, "Dommage Joueur 2,",680,300,makecol(255,255,255),1);
        textout_ex(buffer, font, "vous y été presque, vous avez perdu 1 ticket",550,315,makecol(255,255,255),1);
        partie_gagnee_joueur2--;
    }
    blit(buffer,screen,0,0,0,0, buffer->w,buffer->h);
    rest(20);
}