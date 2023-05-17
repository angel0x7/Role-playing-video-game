#include <allegro.h>
#include <stdio.h>
#include <time.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 720
void tirage (int offset1, BITMAP*Symbole, BITMAP*Symbole2, BITMAP*Symbole3, BITMAP*buffer,BITMAP*Machine,BITMAP*Machine2,BITMAP*MachineBas,BITMAP*MachineBas2,BITMAP *MachineJ, BITMAP *MachineJA, BITMAP *MachineJAC,BITMAP *MachineJACK,BITMAP *MachineJACKP,BITMAP *MachineJACKPO,BITMAP *MachineJACKPOT,BITMAP *MachineJ2, BITMAP *MachineJA2, BITMAP *MachineJAC2,BITMAP *MachineJACK2,BITMAP *MachineJACKP2,BITMAP *MachineJACKPO2,BITMAP *MachineJACKPOT2, int player);

typedef struct {
    int NBticket;
}Player;

int main() {


    //on et pzieugfpeziu

    srand(time(NULL));
    int player=1;
    int offset1=0;
    allegro_init();
    install_keyboard();
    install_mouse();


    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    BITMAP *buffer = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);
    BITMAP *Machine = load_bitmap("../machine P ALG.bmp", NULL);
    BITMAP *Machine2 = load_bitmap("../machine P2.bmp", NULL);
    BITMAP *MachineBas = load_bitmap("../machine P ALG bas.bmp", NULL);
    BITMAP *MachineBas2 = load_bitmap("../machine bas P2.bmp", NULL);
    BITMAP *MachineJ = load_bitmap("../machine victoire J.bmp", NULL);
    BITMAP *MachineJA = load_bitmap("../machine victoire JA.bmp", NULL);
    BITMAP *MachineJAC = load_bitmap("../machine victoire JAC.bmp", NULL);
    BITMAP *MachineJACK = load_bitmap("../machine victoire JACK.bmp", NULL);
    BITMAP *MachineJACKP = load_bitmap("../machine victoire JACKP.bmp", NULL);
    BITMAP *MachineJACKPO = load_bitmap("../machine victoire JACKPO.bmp", NULL);
    BITMAP *MachineJACKPOT = load_bitmap("../machine victoireJACKPOT.bmp", NULL);
    BITMAP *MachineJ2 = load_bitmap("../machine victoire J P2.bmp", NULL);
    BITMAP *MachineJA2 = load_bitmap("../machine victoire JA P2.bmp", NULL);
    BITMAP *MachineJAC2 = load_bitmap("../machine victoire JAC P2.bmp", NULL);
    BITMAP *MachineJACK2 = load_bitmap("../machine victoire JACK P2.bmp", NULL);
    BITMAP *MachineJACKP2 = load_bitmap("../machine victoire JACKP P2.bmp", NULL);
    BITMAP *MachineJACKPO2 = load_bitmap("../machine victoire JACKPO P2.bmp", NULL);
    BITMAP *MachineJACKPOT2 = load_bitmap("../machine victoireJACKPOT P2.bmp", NULL);

    BITMAP *Symbole= load_bitmap("../symbole.bmp",NULL);
    BITMAP *Symbole2= load_bitmap("../symbole2.bmp",NULL);
    BITMAP *Symbole3= load_bitmap("../symbole3.bmp",NULL);
    if (!Symbole) {
        allegro_message("Erreur lors du chargement de 'symbole ALG.bmp'\n");
        return 1;}
    stretch_blit(Symbole, buffer, 0, (Symbole->h) - (Symbole->h / 40) - offset1, Symbole->w, Symbole->h / 40,248,212, 93, 150);
    stretch_blit(Symbole2, buffer, 0, (Symbole2->h) - (Symbole2->h / 50) - offset1, Symbole2->w,Symbole2->h / 50,347, 212, 93, 150);
    stretch_blit(Symbole3, buffer, 0, (Symbole3->h) - (Symbole3->h / 60) - offset1, Symbole3->w,Symbole3->h / 60,445, 212, 93, 150);
    masked_blit(Machine, buffer, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    show_mouse(screen);
    while (!key[KEY_ESC]){
        if (mouse_b & 1)
        {
            if (mouse_x >= 182 && mouse_x <= 324 && mouse_y >= 457 && mouse_y <= 499){
                player =1;
                masked_blit(Machine, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            }
            if (mouse_x >= 182 && mouse_x <= 324 && mouse_y >= 525 && mouse_y <= 563){
                player =2;
                masked_blit(Machine2, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            }

            if (mouse_x >= 617 && mouse_x <= 697 && mouse_y >= 92 && mouse_y <= 179){
                tirage(offset1,Symbole,Symbole2,Symbole3,buffer,Machine,Machine2,MachineBas,MachineBas2,MachineJ, MachineJA, MachineJAC, MachineJACK,MachineJACKP,MachineJACKPO,MachineJACKPOT,MachineJ2, MachineJA2, MachineJAC2, MachineJACK2,MachineJACKP2,MachineJACKPO2,MachineJACKPOT2,player);}}
    }
    allegro_exit();
    return 0;
}END_OF_MAIN()

        void tirage (int offset1, BITMAP*Symbole, BITMAP*Symbole2, BITMAP*Symbole3, BITMAP*buffer,BITMAP*Machine,BITMAP*Machine2,BITMAP*MachineBas,BITMAP*MachineBas2,BITMAP *MachineJ, BITMAP *MachineJA, BITMAP *MachineJAC,BITMAP *MachineJACK,BITMAP *MachineJACKP,BITMAP *MachineJACKPO,BITMAP *MachineJACKPOT,BITMAP *MachineJ2, BITMAP *MachineJA2, BITMAP *MachineJAC2,BITMAP *MachineJACK2,BITMAP *MachineJACKP2,BITMAP *MachineJACKPO2,BITMAP *MachineJACKPOT2, int player){
    int tabS1[5]={560, 420, 280, 140, 0};
    int tabS2[5]={560, 140, 280, 0, 420};
    int tabS3[5]={140, 420, 560, 0, 280};
    int S1=0;//rand()%(4-0+1)+0;
    int S2=0;//rand()%(4-0+1)+0;
    int S3=0;//rand()%(4-0+1)+0;
    for (int i =0;i<2800;i++) {
        masked_blit(Machine, buffer, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        int speed = 3;
        offset1 = (offset1 + speed);
        long a = (Symbole->h) - (Symbole->h / 40) - offset1;
        long b = (Symbole2->h) - (Symbole2->h / 50) - offset1;
        long c = (Symbole3->h) - (Symbole3->h / 60) - offset1;
        if (a > tabS1[S1]) {
            stretch_blit(Symbole, buffer, 0, (Symbole->h) - (Symbole->h / 40) - offset1, Symbole->w, Symbole->h / 40,248,212, 93, 150);
        }
        if (b > tabS2[S2]) {
            stretch_blit(Symbole2, buffer, 0, (Symbole2->h) - (Symbole2->h / 50) - offset1, Symbole2->w,Symbole2->h / 50,347, 212, 93, 150);
        }
        if (c > tabS3[S3]) {
            stretch_blit(Symbole3, buffer, 0, (Symbole3->h) - (Symbole3->h / 60) - offset1, Symbole3->w,Symbole3->h / 60,445, 212, 93, 150);
        }
        if(player==1)
            masked_blit(MachineBas, buffer, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        if(player==2)
            masked_blit(MachineBas2, buffer, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    }
    if (S1==S2 && S2==S3){
        for (int x=0;x<3;x++){
            for (int k=0;k<40;k++) {
                if (player == 2)
                    masked_blit(MachineJ2, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                if (player == 1)
                    masked_blit(MachineJ, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            }
            for (int k=0;k<40;k++) {
                if (player == 2)
                    masked_blit(MachineJA2, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                if (player == 1)
                    masked_blit(MachineJA, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
            for (int k=0;k<40;k++) {
                if (player == 1)
                    masked_blit(MachineJAC, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                if (player == 2)
                    masked_blit(MachineJAC2, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
            for (int k=0;k<40;k++) {
                if (player == 2)
                    masked_blit(MachineJACK2, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                if (player == 1)
                    masked_blit(MachineJACK, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
            for (int k=0;k<40;k++){
                if (player == 2)
                    masked_blit(MachineJACKP2, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                if (player == 1)
                    masked_blit(MachineJACKP, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
            for (int k=0;k<40;k++) {
                if (player == 2)
                    masked_blit(MachineJACKPO2, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                if (player == 1)
                    masked_blit(MachineJACKPO, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
            for (int k=0;k<40;k++){
                if (player == 2)
                    masked_blit(MachineJACKPOT2, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                if (player == 1)
                    masked_blit(MachineJACKPOT, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
        }}
    if (player == 2)
        masked_blit(Machine2, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    if (player == 1)
        masked_blit(Machine, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

}
