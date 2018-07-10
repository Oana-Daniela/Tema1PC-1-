#include <stdio.h>

int task6(int ip_temp[5], int ip_2[4]);
void task7(int ip[4]);
void task8(int ip[4]);

int main ()
{
    int task_nr=0,ip_1[5]= {0},ip_2[4]= {0}, masca[4]= {0}, retea[4]= {0}, rest=0, cat=0; //task2
    int masca_c[4]= {0}, broad[4]= {0}; //task3
    int apartine=0;//task4
    int num=0, ip_temp[5]= {0};
    int numbers[1000] = {0}, j= 0, i= 0; //declaram numbers[1000], vom avea maxim 1000 de ip-uri pentru task 6 
    int ip_81[4] = {0}, ip_82[4] = {0};
//------------------citiri-----------------------------
    scanf(" %d", &task_nr);
    scanf(" %d. %d. %d. %d/ %d",&ip_1[0],&ip_1[1],&ip_1[2],&ip_1[3],&ip_1[4]);
    scanf(" %d. %d. %d. %d",&ip_2[0],&ip_2[1],&ip_2[2],&ip_2[3]);
//------------------setup for task6--------------------
    scanf(" %d", &num);
    for(j=0; j<num; j++)
    {                     
        scanf(" %d. %d. %d. %d/ %d", &ip_temp[0], &ip_temp[1], &ip_temp[2], &ip_temp[3], &ip_temp[4]);        
        numbers[j] = task6(ip_temp, ip_2);
    }
//------------------task0------------------------------
      printf(" %d\n", task_nr);
      printf("-0 %d.%d.%d.%d\n",ip_1[0],ip_1[1],ip_1[2],ip_1[3]);



//------------------task1------------------------------


    cat=ip_1[4]/8;
    rest=ip_1[4]%8;
    
    for(i=0; i<cat; i++)
    {
        masca[i]=255;
    }

    masca[cat]=0;

    for(i=0; i<rest; i++)
    {
        masca[cat] |=(1<<(7-i));
    }

    for(i=1; i<=3-cat; i++)  //mai adaug 0 ca sa umplu masca
    {
        masca[cat+i]=0;
    }

    printf("-1 %d.%d.%d.%d \n", masca[0], masca[1], masca[2], masca[3]);

//------------------task2------------------------------

    for(i=0; i<4; i++)
    {
        retea[i]=ip_1[i]&masca[i];
    }

    printf("-2 %d.%d.%d.%d \n", retea[0], retea[1], retea[2], retea[3]);

//------------------task3--------------------------------
    for(i=0; i<4; i++)
    {
        masca_c[i] = ~masca[i]&0x000000FF;
        broad[i] = ip_1[i]|masca_c[i];
    }

    printf("-3 %d.%d.%d.%d \n", broad[0], broad[1], broad[2], broad[3]);

//------------------task4-----------------------------

    for(i=0; i<4; i++)
    {
        if(masca[i]!=255)
        {
            if(ip_2[i]<masca[i])
            {
                apartine=1;
            }
        }
        else
        {
            if(ip_2[i]!=ip_1[i])
            {
                apartine=1;
            }
        }
    }
    if(apartine==0)
        printf("-4 da\n");
    else
        printf("-4 nu\n");

//------------------task5-----------------------------

    printf("-5 %02X.%02X.%02X.%02X %0o.%0o.%0o.%0o \n", ip_1[0], ip_1[1], ip_1[2], ip_1[3], ip_2[0], ip_2[1], ip_2[2], ip_2[3]);


//------------------task6------------------------------

    printf("-6 ");
    if(apartine==0)
    {
        printf("0");
    }
    else
    {
        for(i=0; i<num; i++)
        {
            if (numbers[i]==1)
            {
                printf("%d ", i+1);
            }
        }
    }
    printf("\n");

//---------------------task7------------------------------------------------
    printf("-7 ");
    for(i=0;i<4;i++)// ca sa nu pierdem valorile din ip_1 si ip_2 le memoram in ip_81 si ip_82
    {
      ip_81[i]=ip_1[i];
      ip_82[i]=ip_2[i];
    } 
    task7(ip_1);
    task7(ip_2);
    printf("\n");

//---------------------task8------------------------------------------------
    printf("-8 ");
    task8(ip_81);
    task8(ip_82);
    printf("\n");
}

//--------------------functie task6---------------------------
int task6(int ip_temp[5], int ip_2[4])
{
    int mask[4]= {0}, cat= 0, rest= 0, apartine= 0, i= 0;
//--------------------aflam masca lui ip_temp-----------------
    cat=ip_temp[4]/8;
    rest=ip_temp[4]%8;
    for(i=0; i<cat; i++)
    {
        mask[i]=255;
    }

    mask[cat]=0;

    for(i=0; i<rest; i++)
    {
        mask[cat] |=(1<<(7-i));
    }

    for(i=1; i<=3-cat; i++)
    {
        mask[cat+i]=0;
    }
//---------------------aflam daca ip_2 este in aceeasi retea cu ip_temp---------
    for(i=0; i<4; i++)
    {
        if(mask[i]!=255)
        {
            if(ip_2[i]<mask[i])
            {
                apartine=1;
            }
        }
        else
        {
            if(ip_2[i]!=ip_temp[i])
            {
                apartine=1;
            }
        }
    }
    if(apartine==0)
        return 1;
    else
        return 0;
}

//--------------------functie task7---------------------------
void task7(int ip[4])
{
    int i=0, j=0, bin[8]= {0}, bin01[8]= {0};
 
    for(i=0; i<4; i++)
    {   while (ip[i]!=0)
        {   for(j=0; j<8; j++)
            {
                bin[j]=ip[i]%2;
                ip[i]=ip[i]/2; //pentru 192 obtin in vect bin[j]:00000011
            }
        }

        for(j=0; j<8; j++)
        {   
           bin01[j]=bin[7-j];         //obtin 11000000
        }

        if(i==3) //daca suntem la ultima iteratie nu mai punem ".", punem spatiu
          printf("%d%d%d%d%d%d%d%d ",bin01[0],bin01[1],bin01[2],bin01[3],bin01[4],bin01[5],bin01[6],bin01[7]);
        else
          printf("%d%d%d%d%d%d%d%d.",bin01[0],bin01[1],bin01[2],bin01[3],bin01[4],bin01[5],bin01[6],bin01[7]);
    }

}

//--------------------functie task8---------------------------
void task8(int ip[4])
{   
   int rest=0, i=0;
   char b32[2]={0, 0};
   char numere_b32[32] ={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'};  

   for(i=0; i<4; i++)
    {              
       rest = ip[i] % 32;       
       b32[1] = numere_b32[rest];       
       ip[i]=ip[i]/32;       
       rest = ip[i] % 32;       
       b32[0] = numere_b32[rest];
       if(b32[0]!='0')
         printf("%c%c", b32[0], b32[1]);
       else
         printf("%c", b32[1]);
       if(i!=3)
         printf(".");
       else
         printf(" ");
    }

}
