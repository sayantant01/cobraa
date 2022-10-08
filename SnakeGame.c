#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<mmsystem.h>

int height=20,width=50,x,y,x_food,y_food,score=0,gameOver=0,flag=0;

int tailX[100],tailY[100];
int countTail=0;

void frame(){
    system ("cls");
    int i, j, k;
    for (i = 0; i <height; i++)
    {
        for (j = 0; j <width; j++)
        {
            if (i == 0 || i == height-1  ||  j == 0 || j == width-1 )
                printf ("#");
            else{
                if (i == x && j == y)
                    printf ("S");
                else if (i == x_food && j == y_food)
                    printf("F");
                else{
                        int ch=0;
                        for(k=0;k<countTail;++k){
                            if(i==tailX[k]&&j==tailY[k]){
                                printf("s");
                                ch=1;
                            }
                        }
                        if(ch==0)
                            printf(" ");
                    }
                }
        }
        printf("\n");
    }
    printf("####################\n");
    printf("###   WELCOME  #####\n");
    printf("#### SCORE : %d ####\n",score);
    printf("####################\n");
    printf("####################\n");
}

void setup(){
    x=height/2;
    y=width/2;

    z1: x_food=rand()%height;
    if(x_food==0)
        goto z1;
    z2: y_food=rand()%width;
    if(y_food==0)
        goto z2;
}

void input(){
    if(kbhit()){
        switch(getch()){
        case 'w':
            flag=1;
            break;
        case 's':
            flag=2;
            break;
        case 'd':
            flag=3;
            break;
        case 'a':
            flag=4;
            break;
        case 'x':
            gameOver=1;
            break;
        default:
            break;
        }
    }
}

void logic(){
    int i,prevX=tailX[0],prevY=tailY[0];
    tailX[0]=x;
    tailY[0]=y;
    int prev2X,prev2Y;

    for(int i=1;i<countTail;i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    switch(flag){
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        y--;
        break;
    default:
        break;
    }
    if(x<0||x>height||y<0||y>width)
        gameOver=1;
    for(i=0;i<countTail;++i){
        if(x==tailX[i]&&y==tailY[i])
            gameOver=1;
    }
    if(x==x_food&&y==y_food){
        z3: x_food=rand()%height;
        if(x_food==0)
            goto z3;
        z4: y_food=rand()%width;
        if(y_food==0)
            goto z4;

        score+=10;
        countTail++;
    }
}

int main(){
    system ("color 3c");
    printf("Game Instructions:\n");
    printf("1. Press 'w' to go upwards\n\n\
           2. Press 's' to go downwards\n\n\
           3. Press 'd' to go to right\n\n\
           4. Press 'a' to go to left\n");
    getch();
    system("cls");
    setup();
    while(!gameOver){
        frame();
        input();
        logic();
        for(int m=1;m<=1000;++m)
            for(int n=1;n<=10000;++n);
    }
    system("cls");
    printf("You lost the game\n");
    printf("Your Score is->%d\n",score);
    printf("Press any key to exit\n");
    getch();
    return 0;
}
