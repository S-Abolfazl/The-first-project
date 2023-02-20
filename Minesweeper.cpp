#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <string.h>
#include "clui.h"
#include "rang.h"
using namespace std;


  struct user{
  char name[100];
  int emtiaz;
  double time;}bazicon;
  struct point {
  int x;
  int y;};
  struct save{
    int lazem[4];     //    x     y       min    flagshomar
    bool** check;
    int** zamin_bazi1;
    char** zamin_bazi2;
    char** prevv;
    user bazicon;
    bool flag=false;
}saved;
bool just_new_game;
  int i12;

  bool** check;
  int** zamin_bazi1;
  char** zamin_bazi2;
  char** prevv;
  int flagshomar,end;
  bool avalkali;


  save arrsave[10];
  int shomarandeh;


  void sort() {
    save temp;
    for (int i = 0; i < shomarandeh-1; i++)
      for (int j = 0; j < shomarandeh-1-i;j++)
        if (arrsave[j+1].bazicon.emtiaz < arrsave[j].bazicon.emtiaz){
            temp=arrsave[j];
            arrsave[j]=arrsave[j+1];
            arrsave[j+1]=temp;
        }
  }



void bombcalculator(int xb,int yb,int x,int y){
  int i,j;
  int sum=0;

  for(i=xb-1;i<=xb+1;i++)
    for(j=yb-1;j<=yb+1;j++)
      if(i>=0 && j>=0 && i<x && j<y)
        if(zamin_bazi1[i][j]==-1){
          check[xb][yb]=false;
          sum++;}

    if(sum>0){zamin_bazi2[xb][yb]='0'+sum,prevv[xb][yb]='0'+sum;return;}

    else{
      if(zamin_bazi2[xb][yb]=='f' || prevv[xb][yb]=='f'){flagshomar--;}
     zamin_bazi2[xb][yb]=' ',prevv[xb][yb]=' ';

     for(i=xb-1;i<=xb+1;i++)
       for(j=yb-1;j<=yb+1;j++)
         if(i>=0 && j>=0 && i<x && j<y)
           if(zamin_bazi1[i][j]==0 && check[i][j]==true){
                check[i][j]=false;
                bombcalculator(i,j,x,y);}
                  }
                }
point gozine(int x,int y,int min){
  point a;
  a.x=rand()%x;
  a.y=rand()%y;
  return a;
}
void peyqam(){
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
  setTextColor(AQUA);
  printf("save:O    ");
  setTextColor(WHITE);
  printf("Exit:Q\n\n");
  setTextColor(YELLOW);
  printf("Selected:#\n\n" );
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
}
void  payambakht(){
  setTextColor(LIGHT_RED);
  printf("\t\t\t    Boom\n\n\n\n\n" );
  setTextColor(GREEN);
printf("$$$$$$$$$$$$$$$$$$$$$$$  Game Over  $$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n\n");
}



void newgame(int x,int y,int min) {
  int i,j,x1,y1;
  point bomb;

  zamin_bazi1=new int*[y];
  zamin_bazi2=new char*[y];
  prevv=new char*[y];
  check=new bool*[y];

  for(i=0;i<y;i++)
    zamin_bazi1[i]=new int[x];

  for(i=0;i<y;i++)
    zamin_bazi2[i]=new char[x];


  for(i=0;i<y;i++)
    prevv[i]=new char[x];

  for(i=0;i<y;i++)
    check[i]=new bool[x];

  for(i=0;i<x;i++)
    for(j=0;j<y;j++)
      check[i][j]=true;

  for(i=0;i<x;i++)
    for(j=0;j<y;j++){
      zamin_bazi2[i][j]='X';
    }
    zamin_bazi2[0][0]='#';

  for(i=0;i<x;i++)
        for(j=0;j<y;j++)
          prevv[i][j]='X';


  for(i=0;i<x;i++)
    for(j=0;j<y;j++)
      zamin_bazi1[i][j]=0;

  for(i=0;i<min;i++){
  bomb=gozine(x,y,min);
  if(zamin_bazi1[bomb.x][bomb.y]==-1){i--;continue;}
  zamin_bazi1[bomb.x][bomb.y]=-1;
}


  bool q=true;
  float dif;
  time_t start,end;
  char t,t1='X';
  int xa=0,ya=0,xb=0,yb=0,v=0,finish=0;


  init_clui();                    //Bakhsh chap0
  peyqam();
  setTextColor(YELLOW);
  for(i=0;i<y;i++) {
    printf(" _ " );}
  printf("\n");
  for(i=0;i<x;i++){
    for(j=0;j<y;j++){
      if(v==0){printf("|#|");v=1;j++;}
      printf("|X|");}
      printf("\n");
      if(i==x-1)for(i=0;i<y;i++)printf(" _ " );
      printf("\n");}



  do{
    do{

    t=getch();
    if(q){time (&start);q=false;}

    if(t==32)
      if(prevv[xb][yb]!='X'){
        while (t==32) {
          setTextColor(LIGHT_RED);
          printf("\t\t\t\tChoose another place\n");
          t=getch();}
        }


    if(t=='f'){
      if(prevv[xb][yb]==' ' || zamin_bazi2[xb][yb]==' '|| (prevv[xb][yb]>'1' && prevv[xb][yb]<'9')||(zamin_bazi2[xb][yb]>'1' && zamin_bazi2[xb][yb]<'9')){
        while (t=='f') {
          setTextColor(LIGHT_RED);
          printf("\t\t\t\t !!!!!!!!!\n");
          t=getch();}
          }

    if(flagshomar==min){
      while(t=='f') {
        setTextColor(LIGHT_RED);
        printf("\t\t\t\tMaximum of flags is %d\n",min);
        t=getch();}
        }
      }


    if(t=='w'){xb--;}
    else if(t=='a'){yb--;}
    else if(t=='s'){xb++;}
    else if(t=='d'){yb++;}

    if(xb<=-1 || xb>=x || yb<=-1 || yb>=y){
      if(xb<=-1){xb=0;}
      if(xb>=x){xb=x-1;}
      if(yb<=-1){yb=0;}
      if(yb>=y){yb=y-1;}
      continue;}


    zamin_bazi2[xb][yb]='#';
    zamin_bazi2[xa][ya]=prevv[xa][ya];
    xa=xb;ya=yb;

    init_clui();
    peyqam();
    for(i=0;i<y;i++) {  //chap Asli
      printf(" _ " );}

    printf("\n");
    for(i=0;i<x;i++){
      for(j=0;j<y;j++){
        printf("|%c|",zamin_bazi2[i][j]);}

      printf("\n");
      if(i==x-1)for(i=0;i<y;i++)printf(" _ " );
      printf("\n");}


    if(t=='q'){exit(0);}
    if(t=='o'){

      time (&end);
      dif = difftime (end,start);
      bazicon.time=dif;

      saved.lazem[0]=x;
      saved.lazem[1]=y;
      saved.lazem[2]=min;
      saved.lazem[3]=flagshomar;



      saved.zamin_bazi1=new int*[y];
      saved.zamin_bazi2=new char*[y];
      saved.prevv=new char*[y];
      saved.check=new bool*[y];


      for(i=0;i<y;i++)
        saved.zamin_bazi1[i]=new int[x];

      for(i=0;i<y;i++)
        saved.zamin_bazi2[i]=new char[x];


      for(i=0;i<y;i++)
        saved.prevv[i]=new char[x];

      for(i=0;i<y;i++)
        saved.check[i]=new bool[x];


      for(i=0;i<x;i++){
        for(j=0;j<y;j++){
          saved.zamin_bazi1[i][j]=zamin_bazi1[i][j];
        }
      }

      for(i=0;i<x;i++){
        for(j=0;j<y;j++){
           saved.zamin_bazi2[i][j]=zamin_bazi2[i][j];
        }
      }

      for(i=0;i<x;i++){
        for(j=0;j<y;j++){
           saved.check[i][j]=check[i][j];
            }
          }

      for(i=0;i<x;i++){
        for(j=0;j<y;j++){
           saved.prevv[i][j]=prevv[i][j];
            }
          }

          strcpy(saved.bazicon.name,bazicon.name);

          if(just_new_game==false){
              saved.bazicon.emtiaz+=arrsave[i12].bazicon.emtiaz;
              saved.bazicon.time=arrsave[i12].bazicon.time;
            /*arrsave[i12]=saved;*/}

          else{
            saved.bazicon.emtiaz=bazicon.emtiaz;
            saved.bazicon.time=bazicon.time;
            saved.flag=true;
            arrsave[shomarandeh]=saved;
            shomarandeh++;}

              return;}

  }while(t!=32 && t!='f');                  //payan halqe aval


    init_clui();
    peyqam();
    if(t==32){
      if(zamin_bazi1[xb][yb]==-1){
      play_beep();

      for(i=0;i<x;i++)
        for(j=0;j<y;j++)
          if(zamin_bazi1[i][j]==-1){zamin_bazi2[i][j]='*';};

      for(i=0;i<y;i++) {  //chap Asli
        printf(" _ " );}

        printf("\n");
      for(i=0;i<x;i++){
        for(j=0;j<y;j++){
          printf("|%c|",zamin_bazi2[i][j]);}

          printf("\n");
          if(i==x-1)for(i=0;i<y;i++)printf(" _ " );
          printf("\n");}
          finish=1;
        payambakht();
        exit(0);}


        else {
          bazicon.emtiaz++;
          bombcalculator(xb,yb,x,y);
          init_clui();
          peyqam();

          for(i=0;i<y;i++) {  //chap Asli
            printf(" _ " );}

            printf("\n");
          for(i=0;i<x;i++){
            for(j=0;j<y;j++){//cout<<"i:"<<i<<"  "<<"j:"<<j<<endl;
              printf("|%c|",zamin_bazi2[i][j]);}//cout<<"khat 280"<<endl;

              printf("\n");//cout<<"khat 282"<<endl;
              if(i==x-1)for(int i1=0;i1<y;i1++)printf(" _ " );//cout<<"khat 283"<<endl;
              printf("\n");}


          for(i=0;i<x;i++)
            for(j=0;j<y;j++)
            prevv[i][j]=zamin_bazi2[i][j];

        }
      }


    else if(t=='f'){
      bazicon.emtiaz+=2;
      if(zamin_bazi2[xb][yb]=='f' || prevv[xb][yb]=='f'){
        zamin_bazi2[xb][yb]='X';
        prevv[xb][yb]='X';
        flagshomar--;}

      else {
        zamin_bazi2[xb][yb]='f';
        prevv[xb][yb]='f';
        flagshomar++;}
      init_clui();
      peyqam();
      for(i=0;i<y;i++) {  //chap Asli
        printf(" _ " );}

        printf("\n");
      for(i=0;i<x;i++){
        for(j=0;j<y;j++){
          printf("|%c|",zamin_bazi2[i][j]);}

          printf("\n");
          if(i==x-1)for(i=0;i<y;i++)printf(" _ " );
          printf("\n");}

          v=0;
          for(i=0;i<x;i++)
            for(j=0;j<y;j++)
              if(zamin_bazi1[i][j]==-1 && zamin_bazi2[i][j]=='f'){v++;}

          if(v==min){

            printf("\n\n\n");
              for(v=0;v<3;v++){play_beep();flush();}

          payampirozi();exit(0);
          }
        }
      }while(finish!=1);

    }


void loadgame(int wanted){
  int i,j,x1,y1;
  point bomb;

 saved=arrsave[wanted];

 int x=saved.lazem[0];
 int y=saved.lazem[1];
 int min=saved.lazem[2];
 flagshomar=saved.lazem[3];

  zamin_bazi1=new int*[y];
  zamin_bazi2=new char*[y];
  prevv=new char*[y];
  check=new bool*[y];

  for(i=0;i<y;i++)
    zamin_bazi1[i]=new int[x];

  for(i=0;i<y;i++)
    zamin_bazi2[i]=new char[x];


  for(i=0;i<y;i++)
    prevv[i]=new char[x];

  for(i=0;i<y;i++)
    check[i]=new bool[x];



      for(i=0;i<x;i++){                             //Load game
        for(j=0;j<y;j++){
           zamin_bazi1[i][j] = saved.zamin_bazi1[i][j];
        }

      }


      for(i=0;i<x;i++){
        for(j=0;j<y;j++){
          zamin_bazi2[i][j] = saved.zamin_bazi2[i][j];
          }

        }



    for(i=0;i<x;i++){
      for(j=0;j<y;j++){
          check[i][j] = saved.check[i][j];
      }
    }


    for(i=0;i<x;i++){
      for(j=0;j<y;j++){
        prevv[i][j] = saved.prevv[i][j];
        }
      }

      bazicon.time=saved.bazicon.time;
      bazicon.emtiaz=saved.bazicon.emtiaz;

      float dif;
      time_t start,end;
      char t,t1='X';
      int xa=0,ya=0,xb=0,yb=0,finish=0;
      bool q=true;

      init_clui();
      peyqam();
      setTextColor(YELLOW);
      for(i=0;i<y;i++) {
        printf(" _ " );}

      printf("\n");
      for(i=0;i<x;i++){
        for(j=0;j<y;j++){
          printf("|%c|",zamin_bazi2[i][j]);}

        printf("\n");
        if(i==x-1)for(i=0;i<y;i++)printf(" _ " );
        printf("\n");}



      do{
        do{

        t=getch();
        if(q){time (&start);q=false;}

        if(t==32)
          if(prevv[xb][yb]!='X'){
            while (t==32) {
              setTextColor(LIGHT_RED);
              printf("\t\t\t\tChoose another place\n");
              t=getch();}
            }


        if(t=='f'){
          if(prevv[xb][yb]==' ' || zamin_bazi2[xb][yb]==' '|| (prevv[xb][yb]>'1' && prevv[xb][yb]<'9')||(zamin_bazi2[xb][yb]>'1' && zamin_bazi2[xb][yb]<'9')){
            while (t=='f') {
              setTextColor(LIGHT_RED);
              printf("\t\t\t\t !!!!!!!!!\n");
              t=getch();}
              }

        if(flagshomar==min){
          while(t=='f') {
            setTextColor(LIGHT_RED);
            printf("\t\t\t\tMaximum of flags is %d\n",min);
            t=getch();}
            }
          }


        if(t=='w'){xb--;}
        else if(t=='a'){yb--;}
        else if(t=='s'){xb++;}
        else if(t=='d'){yb++;}

        if(xb<=-1 || xb>=x || yb<=-1 || yb>=y){
          if(xb<=-1){xb=0;}
          if(xb>=x){xb=x-1;}
          if(yb<=-1){yb=0;}
          if(yb>=y){yb=y-1;}
          continue;}


        zamin_bazi2[xb][yb]='#';
        zamin_bazi2[xa][ya]=prevv[xa][ya];
        xa=xb;ya=yb;

        init_clui();
        peyqam();
        for(i=0;i<y;i++) {
          printf(" _ " );}

        printf("\n");
        for(i=0;i<x;i++){
          for(j=0;j<y;j++){
            printf("|%c|",zamin_bazi2[i][j]);}

          printf("\n");
          if(i==x-1)for(i=0;i<y;i++)printf(" _ " );
          printf("\n");}


        if(t=='q'){exit(0);}
        if(t=='o'){
          time (&end);
          dif = difftime (end,start);
          bazicon.time=dif;

          saved.lazem[0]=x;
          saved.lazem[1]=y;
          saved.lazem[2]=min;
          saved.lazem[3]=flagshomar;



          saved.zamin_bazi1=new int*[y];
          saved.zamin_bazi2=new char*[y];
          saved.prevv=new char*[y];
          saved.check=new bool*[y];


          for(i=0;i<y;i++)
            saved.zamin_bazi1[i]=new int[x];

          for(i=0;i<y;i++)
            saved.zamin_bazi2[i]=new char[x];


          for(i=0;i<y;i++)
            saved.prevv[i]=new char[x];

          for(i=0;i<y;i++)
            saved.check[i]=new bool[x];


          for(i=0;i<x;i++){
            for(j=0;j<y;j++){
              saved.zamin_bazi1[i][j]=zamin_bazi1[i][j];
            }
          }

          for(i=0;i<x;i++){
            for(j=0;j<y;j++){
               saved.zamin_bazi2[i][j]=zamin_bazi2[i][j];
            }
          }

          for(i=0;i<x;i++){
            for(j=0;j<y;j++){
               saved.check[i][j]=check[i][j];
                }
              }

          for(i=0;i<x;i++){
            for(j=0;j<y;j++){
               saved.prevv[i][j]=prevv[i][j];
                }
              }

              strcpy(saved.bazicon.name,bazicon.name);

              saved.bazicon.emtiaz+=arrsave[wanted].bazicon.emtiaz;
              saved.bazicon.time+=arrsave[wanted].bazicon.time;

                arrsave[wanted]=saved;
                  return;
        }

            }while(t!=32 && t!='f');                  //payan halqe aval


        init_clui();
        peyqam();
        if(t==32){
          if(zamin_bazi1[xb][yb]==-1){
          play_beep();

          for(i=0;i<x;i++)
            for(j=0;j<y;j++)
              if(zamin_bazi1[i][j]==-1){zamin_bazi2[i][j]='*';};

          for(i=0;i<y;i++) {  //chap Asli
            printf(" _ " );}

            printf("\n");
          for(i=0;i<x;i++){
            for(j=0;j<y;j++){
              printf("|%c|",zamin_bazi2[i][j]);}

              printf("\n");
              if(i==x-1)for(i=0;i<y;i++)printf(" _ " );
              printf("\n");}
              finish=1;
            payambakht();
            exit(0);}


            else {
              bazicon.emtiaz++;
              bombcalculator(xb,yb,x,y);
              init_clui();
              peyqam();

              for(i=0;i<y;i++) {
                printf(" _ " );}

                printf("\n");
              for(i=0;i<x;i++){
                for(j=0;j<y;j++){
                  printf("|%c|",zamin_bazi2[i][j]);}

                  printf("\n");
                  if(i==x-1)for(int i1=0;i1<y;i1++)printf(" _ " );
                  printf("\n");}


              for(i=0;i<x;i++)
                for(j=0;j<y;j++)
                prevv[i][j]=zamin_bazi2[i][j];

            }
          }


        else if(t=='f'){
          bazicon.emtiaz+=2;
          if(zamin_bazi2[xb][yb]=='f' || prevv[xb][yb]=='f'){
            zamin_bazi2[xb][yb]='X';
            prevv[xb][yb]='X';
            flagshomar--;}

          else {
            zamin_bazi2[xb][yb]='f';
            prevv[xb][yb]='f';
            flagshomar++;}
          init_clui();
          peyqam();
          for(i=0;i<y;i++) {
            printf(" _ " );}

            printf("\n");
          for(i=0;i<x;i++){
            for(j=0;j<y;j++){
              printf("|%c|",zamin_bazi2[i][j]);}

              printf("\n");
              if(i==x-1)for(i=0;i<y;i++)printf(" _ " );
              printf("\n");}

            int v=0;
              for(i=0;i<x;i++)
                for(j=0;j<y;j++)
                  if(zamin_bazi1[i][j]==-1 && zamin_bazi2[i][j]=='f'){v++;}

              if(v==min){

                printf("\n\n\n");
                  for(v=0;v<3;v++){play_beep();flush();}

              payampirozi();exit(0);
              }
            }
          }while(finish!=1);

        }

void liderboard(){
          init_clui();
          int i;
          setTextColor(LIGHT_YELLOW);
          cout<<"Name    "<<"Score    "<<"Time";
          cout<<"\n\n\n";
          setTextColor(LIGHT_BLUE);
          sort();
          for(i=0;i<shomarandeh;i++) {
            if(strcmp(arrsave[i].bazicon.name,arrsave[i+1].bazicon.name)==0){continue;}
          cout<<arrsave[i].bazicon.name<<"      "<<arrsave[i].bazicon.emtiaz<<"      "<<arrsave[i].bazicon.time<<"\n\n";
            }
            cout<<"Press any key to exit...";
            getch();
            return;
        }

int main() {
  srand(time(NULL));
  int test,end=0,j;
  bazicon.emtiaz=0;
  char esm[100];
    int i,i1,x,y,wanted;

  init_clui();
  setTextColor(LIGHT_YELLOW);
  cout<<"\n\t  Hello & Wellcome\n\n\t\tPlease enter your name:\n";
  cin>>bazicon.name;

  ifstream inputFile("bazicon.txt", ios::in);
  if (!inputFile)
 {cerr << "some thing wrong during opening file!" << endl;exit(1);}
  inputFile>>shomarandeh;
  if(shomarandeh==0){just_new_game=true;}

  else{
   for(i1=0;i1<shomarandeh;i1++){
     inputFile>>saved.lazem[0];
     int x=saved.lazem[0];
     inputFile>>saved.lazem[1];
     int y=saved.lazem[1];
     inputFile>>saved.lazem[2];
     int min=saved.lazem[2];
     inputFile>>saved.lazem[3];
     flagshomar=saved.lazem[3];


     zamin_bazi1=new int*[y];
     zamin_bazi2=new char*[y];
     prevv=new char*[y];
     check=new bool*[y];
     for(i=0;i<y;i++)
       zamin_bazi1[i]=new int[x];
     for(i=0;i<y;i++)
       zamin_bazi2[i]=new char[x];
     for(i=0;i<y;i++)
       prevv[i]=new char[x];
     for(i=0;i<y;i++)
       check[i]=new bool[x];

       saved.zamin_bazi1=new int*[y];
       saved.zamin_bazi2=new char*[y];
       saved.prevv=new char*[y];
       saved.check=new bool*[y];

       for(i=0;i<y;i++)
         saved.zamin_bazi1[i]=new int[x];

       for(i=0;i<y;i++)
         saved.zamin_bazi2[i]=new char[x];


       for(i=0;i<y;i++)
         saved.prevv[i]=new char[x];

       for(i=0;i<y;i++)
         saved.check[i]=new bool[x];

       for(i=0;i<x;i++){
         for(j=0;j<y;j++){
           inputFile>>saved.zamin_bazi1[i][j];
           zamin_bazi1[i][j]=saved.zamin_bazi1[i][j];
         }
       }

           for(i=0;i<x;i++){
             for(j=0;j<y;j++){
               inputFile>>saved.zamin_bazi2[i][j];
               if(saved.zamin_bazi2[i][j]=='?'){saved.zamin_bazi2[i][j]=' ';}
               zamin_bazi2[i][j]=saved.zamin_bazi2[i][j];
             }
           }

           for(i=0;i<x;i++){
             for(j=0;j<y;j++){
               inputFile>>saved.check[i][j];
               check[i][j]=saved.check[i][j];
             }
           }

           for(i=0;i<x;i++){
             for(j=0;j<y;j++){
               inputFile>>saved.prevv[i][j];
               if(saved.prevv[i][j]=='?'){saved.prevv[i][j]=' ';}
               prevv[i][j]=saved.prevv[i][j];
             }
           }

          inputFile>>saved.bazicon.name>>saved.bazicon.emtiaz>>saved.bazicon.time;
          inputFile>>saved.flag;
          arrsave[i1]=saved;

          }
        }

    for(i12=0;i12<shomarandeh;i12++){
        if(strcmp(arrsave[i12].bazicon.name,bazicon.name)==0){just_new_game=false;break;}
         if(i12+1==shomarandeh){just_new_game=true;}
        }


  do{                 //halqe menu Asli
  init_clui();
  setTextColor(PURPLE);

  cout<<endl<<"    1.New Game"<<endl<<endl<<"    2.Load Game"<<endl<<endl<<"    3.Change Name"<<endl<<endl<<"    4.Leaderbord"<<endl<<endl<<"    5.Quit"<<endl;

      test=getch();
        while (test<'1' || test>'5') {
          setTextColor(LIGHT_RED);
          cout<<"!!!!!!!"<<endl;
          test=getch();
            }

        if(just_new_game==true && test=='2') {
          setTextColor(LIGHT_RED);
          cout<<"There are no saved games"<<endl;
          delay(2000);
          continue;}

if(test=='1'){
      setTextColor(LIGHT_GREEN);
      cout<<endl<<endl<<endl<<"    1.Easy:5x5\n"<<endl<<"    2.Average:12x12"<<endl<<endl<<"    3.Hard:20x20"<<endl<<endl<<"    4.Another ..."<<endl;

      test=getch();
        while (test<'1' || test>'4') {
        setTextColor(LIGHT_RED);
        cout<<"!!!!!!!"<<endl;
        test=getch();}

          if(test=='1'){newgame(5,5,6);}
          else if(test=='2'){newgame(12,12,28);}
          else if(test=='3'){newgame(20,20,96);}
          else{
            int col,row,min;
            cout<<"Please enter your favorite game:"<<endl;
            while(true){
            cout<<"row:"<<endl;
            cin>>row;
            cout<<endl<<"col:"<<endl;
            cin>>col;

            if(row<=2 || row>20 || col<=2 || col>20){
                setTextColor(LIGHT_RED);
                cout<<"Max of col & row is 20 & the min of them is 3"<<endl;
                continue;
                }

            cout<<endl<<"Number of mines:"<<endl;cin>>min;

            if(min>=col*row || min==0){
              setTextColor(LIGHT_RED);
              cout<<"Number of mines is Immoral"<<endl;
              continue;
              }
              break;
            }
            newgame(row,col,min);
          }
        }

if(test=='2'){
        init_clui();
        setTextColor(LIGHT_GREEN);
        cout<<"Name   "<<"Score   "<<"Time";
        cout<<"\n\n\n";
        setTextColor(LIGHT_BLUE);
        for(i=0;i<shomarandeh;i++) {
        cout<<arrsave[i].bazicon.name<<"      "<<arrsave[i].bazicon.emtiaz<<"      "<<arrsave[i].bazicon.time<<"\n\n";
      }cout<<"\n\n\nWhich one do you want to load?"<<endl;
      cin>>wanted;

        loadgame(wanted-1);
      }

if(test=='3'){
            init_clui();
            setTextColor(LIGHT_GREEN);
            for(i=0;i<shomarandeh;i++){
              saved=arrsave[i];
                cout<<saved.bazicon.name<<endl;
                  }
            cout<<"Which one do you want to change?\n\nEnter its Number:"<<endl;
            int esm_n;cin>>esm_n;
            cout<<"Enter your desired name:\n\n";
            cin>>esm;
            strcpy(arrsave[esm_n-1].bazicon.name,esm);}

if(test=='4'){liderboard();}

    }while(test!='5');

        ofstream outputFile("bazicon.txt", ios::out);
        if (!outputFile)
        {cerr << "some thing wrong during opening file!" << endl;exit(1);}
        outputFile<<shomarandeh<<"  ";
        sort();
        for(i1=0;i1<shomarandeh;i1++){//zakhire sazy
      saved=arrsave[i1];

      x=saved.lazem[0];
      y=saved.lazem[1];

      outputFile<<saved.lazem[0]<<" ";
      outputFile<<saved.lazem[1]<<" ";
      outputFile<<saved.lazem[2]<<" ";
      outputFile<<saved.lazem[3]<<" ";


      outputFile<<"  ";
        for(i=0;i<x;i++){
          for(j=0;j<y;j++){
            outputFile<<saved.zamin_bazi1[i][j]<<" ";
          }
        }
          outputFile<<"  ";
            for(i=0;i<x;i++){
              for(j=0;j<y;j++){
                if(saved.zamin_bazi2[i][j]==' '){saved.zamin_bazi2[i][j]='?';}
                outputFile<<saved.zamin_bazi2[i][j]<<" ";
              }
            }
              outputFile<<"  ";
            for(i=0;i<x;i++){
              for(j=0;j<y;j++){
                outputFile<<saved.check[i][j]<<" ";
              }
            }
              outputFile<<"  ";
            for(i=0;i<x;i++){
              for(j=0;j<y;j++){
                if(saved.prevv[i][j]==' '){saved.prevv[i][j]='?';}
                outputFile<<saved.prevv[i][j]<<" ";
              }
            }
            //cout<<saved.bazicon.name;delay(8000);
           outputFile<<"    "<<saved.bazicon.name<<" "<<saved.bazicon.emtiaz<<" "<<saved.bazicon.time<<"  ";
           outputFile<<saved.flag<<endl<<endl;

           outputFile<<"\n\n\n";
           }

        return 0;
}
