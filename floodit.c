#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define COULEURS 6
#define TAILLE 12

void initialiser(int tab[TAILLE][TAILLE])
{   
    srand(time(NULL));
    for (int i=0; i<TAILLE ;i++)
    {
        for (int j=0; j<TAILLE; j++)
        {
            tab[i][j]=rand()%(COULEURS)+1 ;

        }
    }

}
void affichergrille(int tab[TAILLE][TAILLE])
{   
    for (int i=0; i<TAILLE ;i++)
    {
        for (int j=0; j<TAILLE; j++)
        {
            
            printf("%d ",tab[i][j]);
            if (j==11)
            { 
                printf("\n");
            }

        }
    }
}

int fin(int tab [TAILLE][TAILLE])
{
    int r=1;
    for (int i=0; i<TAILLE ;i++)
    {
        for (int j=0; j<TAILLE; j++)
        {
            if(tab[i][j] != tab[0][0])
            {
                r=0;
            }
            
        }
    }
    return r;
}

void remplir(int tab[TAILLE][TAILLE],int cavant,int cnouv,int i,int j)
{   
    
    if (i>0 && j>0 && i<TAILLE && j<TAILLE)
    {   
        if(tab[i][j]==cavant)
        {
            tab[i][j]=cnouv;
            remplir(tab, cavant, cnouv , i-1,j);
            remplir(tab, cavant, cnouv , i+1,j);
            remplir(tab, cavant, cnouv , i,j-1);
            remplir(tab, cavant, cnouv , i,j+1);
        }
        
    }
}
