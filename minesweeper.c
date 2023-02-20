#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "clui.h"
#include "rang.h"
char prev[5][5]={{'X','X','X','X','X'},{'X','X','X','X','X'},{'X','X','X','X','X'},{'X','X','X','X','X'},{'X','X','X','X','X'}};//آرایه ای که مقادیر قبلی را حفظ میکند
char c[5][5]={{'#','X','X','X','X'},{'X','X','X','X','X'},{'X','X','X','X','X'},{'X','X','X','X','X'},{'X','X','X','X','X'}};//آرایه اصلی بازی که دایم تغییر میکنند
int a[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};//برای نشان دادن خانه های بمب دار
bool check[5][5]={{true,true,true,true,true},{true,true,true,true,true},{true,true,true,true,true},{true,true,true,true,true},{true,true,true,true,true}};//برای نشان دادن خانه های بمب دار
int flagshomar=0;

int tol1,arz1,tol2,arz2,tol3,arz3,tol4,arz4,tol5,arz5,tol6,arz6;    //طول و عرض 6خانه بمب دار


void bombcalculator(int xb,int yb){       //بمب شمار،xb & yb مختصات نقطه در حال بررسی
  int i,j;
  int sum=0;
  for(i=xb-1;i<=xb+1;i++)
    for(j=yb-1;j<=yb+1;j++)
      if(i>=0 && j>=0 && i<5 && j<5)    //باید در محدوده زمین بازی باشد
        if(a[i][j]==-1){                  //-1==بمب دار
          check[xb][yb]=false;            //وقتی چک شد باید فالس کرد یعنی چک شده
          sum++;}

    if(sum>0){c[xb][yb]='0'+sum,prev[xb][yb]='0'+sum;return;}

    else{                                 //if(sum==0)=> خونه خالیه
      if(c[xb][yb]=='f' || prev[xb][yb]=='f'){flagshomar--;}  //حالت بسیار خاص
     c[xb][yb]=' ',prev[xb][yb]=' ';    //خونه خالی
     for(i=xb-1;i<=xb+1;i++){
       for(j=yb-1;j<=yb+1;j++){
         if(i>=0 && j>=0 && i<5 && j<5)
           if(a[i][j]==0 && check[i][j]==true){   //اطراف خانه خالی باید چک شود و در شرایط صدق کند
                check[i][j]=false;
                bombcalculator(i,j);
                  }
                }
              }
          }

}



void gozine(){            //انتخاب رندوم مختصات نقاط بمب
    for(;;){
  tol1=rand()%5;
  tol2=rand()%5;
  tol3=rand()%5;
  tol4=rand()%5;
  tol5=rand()%5;
  tol6=rand()%5;
  arz1=rand()%5;
  arz2=rand()%5;
  arz3=rand()%5;
  arz4=rand()%5;
  arz5=rand()%5;
  arz6=rand()%5;
  if((tol1==tol2 && arz1==arz2)||(tol1==tol3 && arz1==arz3)||(tol1==tol4 && arz1==arz4)||(tol1==tol5 && arz1==arz5)||(tol1==tol6&&arz1==arz6)){continue;}
  if((tol2==tol3 && arz2==arz3)||(tol2==tol4 && arz2==arz4)||(tol2==tol5 && arz2==arz5)||(tol2==tol6&&arz2==arz6)){continue;}
  if((tol3==tol4 && arz3==arz4)||(tol3==tol5 && arz3==arz5)||(tol3==tol6&&arz3==arz6)){continue;}
  if((tol4==tol5 && arz4==arz5)||(tol4==tol6&&arz4==arz6)){continue;}
  if(tol5==tol6&&arz5==arz6){continue;}
  break;}   //دو خانه نباید دقیقا مختصات یکسانی بگیرند
}


void peyqam(){              //راهنمای بازی که همیشه باید در بالای صفحه قرار داشته باشد
  setTextColor(GRAY);
  printf("The keys:\n\n" );
  setTextColor(LIGHT_BLUE);
printf("up:W    ");
setTextColor(RED);
  printf("left:A    ");
  setTextColor(LIGHT_GREEN);
  printf("down:S    ");
setTextColor(LIGHT_AQUA);
  printf("right:D    ");
  setTextColor(LIGHT_YELLOW);
  printf("flag:F    ");
  setTextColor(WHITE);
  printf("Exit:esc\n\n");
  setTextColor(GREEN);
  printf("Your time in the game is 45 seconds\n\n");
  setTextColor(YELLOW);
  printf("Selected:#\n\n---------\n" );
}

void payampirozi(){
  setTextColor(LIGHT_YELLOW);
  printf("***     ***"),printf("   ***    "),printf(" ***     *** "),printf(" ***                *** "),printf(" *** "),printf(" *****       ***\n");
  printf(" ***   *** "),printf("  ** **   "),printf(" ***     *** "),printf(" ***       ***      *** "),printf(" *** "),printf(" ******      ***\n");
  printf("  *** ***  "),printf(" **   **  "),printf(" ***     *** "),printf(" ***       ***      *** "),printf(" *** "),printf(" *** ***     ***\n");
  printf("   *****   "),printf("**     ** "),printf(" ***     *** "),printf(" ***       ***      *** "),printf(" *** "),printf(" ***  ***    ***\n");
  printf("    ***    "),printf("**     ** "),printf(" ***     *** "),printf("  ***      ***     ***  "),printf(" *** "),printf(" ***   ***   ***\n");
  printf("    ***    "),printf("**     ** "),printf(" ***     *** "),printf("   ***     ***    ***   "),printf(" *** "),printf(" ***    ***  ***\n");
  printf("    ***    "),printf(" **   **  "),printf(" ***     *** "),printf("     ***   ***   ***    "),printf(" *** "),printf(" ***     *** ***\n");
  printf("    ***    "),printf("  ** **   "),printf("  ***   ***  "),printf("      **** *** ****     "),printf(" *** "),printf(" ***      ******\n");
  printf("    ***    "),printf("   ***    "),printf("   ******    "),printf("       ***********      "),printf(" *** "),printf(" ***       *****\n");
  printf("\n\n\n\n\n");
  setTextColor(GREEN);
  printf("\tDo you want to play again?\n");
  printf("\t    y or n?\n" );
  printf("        y:yes  &  n:no\n");
}

void  payambakht(){
  setTextColor(LIGHT_RED);
  printf("\t\t\t    Boom\n\n\n\n\n" );
  setTextColor(GREEN);
printf("$$$$$$$$$$$$$$$$$$$$$$$  Game Over  $$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n\n");
setTextColor(AQUA);
printf("\tDo you want to play again?\n");
printf("\t   y or n?\n");
printf("        y:yes  &  n:no\n" );

}

int main() {
  srand(time(NULL));
    gozine();         //مختصات رندوم نقاط بمب همینجا مشخص میشود
    bool q=true;      //شروع زمان فقط بعد از زدن اولین کلید
    float dif;        //متغیر شمارش زمان
    time_t start,end;
    char t,t1='X';
    a[tol1][arz1]=-1;a[tol2][arz2]=-1;a[tol3][arz3]=-1;a[tol4][arz4]=-1;a[tol5][arz5]=-1;a[tol6][arz6]=-1;//مختصات بمب -1 میباشد
    int xa=0,ya=0,xb=0,yb=0,i,j,v;//xa,ya اولیه و ثانویه
    init_clui();peyqam();setTextColor(YELLOW);
    for(i=0;i<5;i++){
      for(j=0;j<5;j++){printf("%c ",c[i][j] );} //چاپ زمین بازی در آغاز بازی
      printf("|\n");}printf("---------" );
    do{   //حلقه اصلی بازی
      do{
      t=getch();
      if(q){time (&start);q=false;} //شروع زمان
      dif = difftime (end,start);
      if(dif>=45){setTextColor(LIGHT_YELLOW);printf("\n\n\t\t\t\tYour time is finished :(");return 0;}
      if(t==13)
        if(prev[xb][yb]!='X'){  //جای غیر مجاز enter
          while (t==13) {
            setTextColor(LIGHT_RED);
            printf("\t\t\t\tChoose another place\n");delay(200);
            t=getch();}}
            if(t=='f')    //flag غیر مجاز
              if(prev[xb][yb]==' ' || c[xb][yb]==' '){
                while (t=='f') {setTextColor(LIGHT_RED);printf("\t\t\t\t !!!!!!!!!\n");t=getch();}}
        if(t=='f')
        if(flagshomar==6){
          while (t=='f') {
            setTextColor(LIGHT_RED);
            printf("\t\t\t\tMaximum of flags is 6\n");
            t=getch();}}
      if(t=='w'){xb--;}       //کلید های جهت نما
      else if(t=='a'){yb--;}
      else if(t=='s'){xb++;}
      else if(t=='d'){yb++;}
      if(xb<=-1 || xb>=5 || yb<=-1 || yb>=5){//کنترل کلید های جهت نما
        if(xb<=-1){xb=0;}
        if(xb>=5){xb=4;}
        if(yb<=-1){yb=0;}
        if(yb>=5){yb=4;}continue;}
      c[xb][yb]='#';
      c[xa][ya]=prev[xa][ya];
      xa=xb,ya=yb;
      init_clui();
      peyqam();
      for(i=0;i<5;i++){
        for(j=0;j<5;j++){
          printf("%c ",c[i][j] );}printf("|\n");}printf("---------");
      if(t==27){printf("\n\n");printf("\t\t\t  Are you sure?\n");printf("\t\t\t    y or n?\n");
        char t=getch();
        if(t=='y'){exit(0);}
      else{init_clui();peyqam();
        for(i=0;i<5;i++){
          for(j=0;j<5;j++){printf("%c ",c[i][j] );}printf("|\n");}printf("---------");t=='#';}}
      time (&end);dif = difftime (end,start);
      if(dif>=45){setTextColor(LIGHT_YELLOW);printf("\n\n\t\t\t\tYour time is finished :(");return 0;}
    }while(t!=13 && t!='f');
      init_clui();
      if(t==13){if((xb==tol1&&yb==arz1)||(xb==tol2&&yb==arz2)||(xb==tol3&&yb==arz3)||(xb==tol4&&yb==arz4)||(xb==tol5&&yb==arz5)||(xb==tol6&&yb==arz6)){
        play_beep();
        c[tol1][arz1]='*';c[tol2][arz2]='*';c[tol3][arz3]='*';c[tol4][arz4]='*';c[tol5][arz5]='*';c[tol6][arz6]='*';
          for(i=0;i<5;i++){
            for(j=0;j<5;j++){printf("%c ",c[i][j] );}printf("|\n");}printf("----------\n\n\n" );
          payambakht();
          t=getch();
          if(t=='n'){return 0;}
          else{system("Minesweeper.exe");exit(0);}}
      else {bombcalculator(xb,yb);
      peyqam();
      for(i=0;i<5;i++){
        for(j=0;j<5;j++){
          printf("%c ",c[i][j] );}printf("|\n");}printf("---------\n");
          prev[i][j]=c[i][j];}}
      else if(t=='f'){
        if(c[xb][yb]=='f' || prev[xb][yb]=='f'){c[xb][yb]='X';prev[xb][yb]='X';flagshomar--;}
        else {c[xb][yb]='f';prev[xb][yb]='f';flagshomar++;}
        peyqam();
        for(i=0;i<5;i++){
          for(j=0;j<5;j++){
            printf("%c ",c[i][j] );}printf("|\n");}printf("---------\n");}
            if((prev[tol1][arz1]=='f')&&(prev[tol2][arz2]=='f')&&(prev[tol3][arz3]=='f')&&(prev[tol4][arz4]=='f')&&(prev[tol5][arz5]=='f')&&(prev[tol6][arz6]=='f')){printf("\n\n\n");
    for(v=0;v<3;v++){play_beep();flush();}
      payampirozi();
      char u=getch();
      if(u=='n'){return 0;}else{system("Minesweeper.exe");exit(0);}}
    time (&end);
    dif = difftime (end,start);
    if(dif>=45){setTextColor(LIGHT_YELLOW);printf("\n\n\t\t\t\tYour time is finished :(");return 0;}
  }while(t!=27);
  return 0;}
