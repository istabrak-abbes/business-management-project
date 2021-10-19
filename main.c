#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "dynamique.h"
#define maxtaille 64

int main()

{
    liste *lst,*lst1,*pred,*pred2;
    personnel *prs;
    int n=0,choix,p,i,plus,choice,nbrenfants;
    char id1[maxtaille];
    char id[maxtaille],rue[maxtaille],ville[maxtaille],codepostal[maxtaille],etat[maxtaille];
    FILE* fiche;
    fiche=fopen("liste.txt","rt");
    if (fiche==NULL)
        printf("le fichier n'existe pas ! \n");
    else
    {
        i=0;
        lst=(struct liste*)malloc(sizeof(liste));
        lst1=lst;
        while (!feof(fiche))

        {

        fscanf(fiche,"%s",lst1->elt.id);
        fscanf(fiche,"%s",lst1->elt.NCIN);
        fscanf(fiche,"%s",lst1->elt.sexe);
        fscanf(fiche,"%s",lst1->elt.nom);
        fflush(stdin);
        fscanf(fiche,"%s",lst1->elt.prenom);
        fflush(stdin);
        fscanf(fiche,"%d",&lst1->elt.datepersonnel.jour);
        fscanf(fiche,"%d",&lst1->elt.datepersonnel.mois);
        fscanf(fiche,"%d",&lst1->elt.datepersonnel.annee);
        fflush(stdin);
        fscanf(fiche,"%s",lst1->elt.adressepersonnel.rue);
        fscanf(fiche,"%s",lst1->elt.adressepersonnel.ville);
        fscanf(fiche,"%s",lst1->elt.adressepersonnel.codepostal);
        fflush(stdin);
        fscanf(fiche,"%s",lst1->elt.tel);
        fscanf(fiche,"%s",lst1->elt.etatcivil);
        fscanf(fiche,"%d",&lst1->elt.nbrenfants);
        pred=lst1;
        lst1->succ=malloc(sizeof(liste));
        lst1=lst1->succ;
        }
        free(pred->succ);
        pred->succ=NULL;
    }
    fclose(fiche);
       lst1=lst;


    while(lst1->succ)
    {
        pred2=lst1;
        pred=lst1->succ;
        lst1=lst1->succ;
    }
    free(pred2->succ);
    pred2->succ=NULL;
     while (1)
    {
    printf("\t \t ****MENU**** \n tapez \n 1 pour saisir \n 2 pour afficher \n 3 pour chercher \n 4 pour modifier les donnees d'un personnel \n 5 pour supprimer \n o pour quitter \n  \n");
    scanf("%d",&choix);
    switch (choix)
    {
        case 0:
        {
            fiche=fopen("liste.txt","wt");
            lst1=lst;
            while(lst1)
                {
                    fprintf(fiche,"%s ",lst1->elt.id);
                    fprintf(fiche,"%s ",lst1->elt.NCIN);
                    fprintf(fiche,"%s ",lst1->elt.sexe);
                    fprintf(fiche,"%s ",lst1->elt.nom);
                    fprintf(fiche,"%s ",lst1->elt.prenom);
                    fprintf(fiche,"%d ",lst1->elt.datepersonnel.jour);
                    fprintf(fiche,"%d ",lst1->elt.datepersonnel.mois);
                    fprintf(fiche,"%d ",lst1->elt.datepersonnel.annee);
                    fprintf(fiche,"%s ",lst1->elt.adressepersonnel.rue);
                    fprintf(fiche,"%s ",lst1->elt.adressepersonnel.ville);
                    fprintf(fiche,"%s ",lst1->elt.adressepersonnel.codepostal);
                    fprintf(fiche,"%s ",lst1->elt.tel);
                    fprintf(fiche,"%s ",lst1->elt.etatcivil);
                    fprintf(fiche,"%d \n",lst1->elt.nbrenfants);
                    lst1=lst1->succ;
                }
            fclose(fiche);
            exit(0);
            break;
        }


        case 1:
        {
            do
            {

                prs=malloc(sizeof(liste));
                prs=saisie(prs);
                lst1->elt=*prs;
                lst1->succ=lst;
                lst=lst1;
                printf("nouvelle personel ? 0 oui 1 non \t");
                scanf("%d",&plus);
                n++;
            }while(plus==0);
         break;
        }

        case 2:
        {
            affich_list(lst);
            break;
        }
        case 3:
        {
            printf("donner l'identifiant du personnel cherche \n");
            scanf("%s",id1);

            p=recherche(lst,id1);
            if (p!=-1)
                printf("la position du personnel a chercher est %d \n",p);
            else
                printf("ce personnel n'existe pas \n ");
            break;
        }

        case 4:
        {
            printf("donner l'identifiant du personnel a modifier  ");
            scanf("%s",id);
            printf("tapez \n 1 pour modifier l'adresse \n 2 pour modifier l'etat civil \n 3 pour modifier le nombre d'enfants  ");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1 :
                {

                printf("nouvelle ville :  ");
                scanf("%s",ville);
                printf("nouvelle rue :  ");
                scanf("%s",rue);
                printf("nouveau code postal :  ");
                scanf("%s",codepostal);
                modifier_adresse(lst,id1,ville,rue,codepostal);
                break;
                }
            case 2 :
                {
                    do
                    {
                        printf("nouvelle etat civil :   ");
                        scanf("%s",etat);
                    }while((strcmp(etat,"marie"))&&(strcmp(etat,"celibataire")));
                    modifier_etatcivil(lst,id1,etat);
                    break;

                }
            case 3 :
                {
                    printf("le nouveau nombre d'enfants  ");
                    scanf("%d",&nbrenfants);
                    modifier_nbr_enfants(lst,id,nbrenfants);
                    break;
                }
            }
        break;
        }
         case 5:
        {
            printf("donner l'identifiant du personnel a supprimer");
            scanf("%s",id1);
            lst=supprimer(lst,id1);
            break;
        }

        default :
        {
            printf("merci ! Au revoir ");
            break ;
        }
    }
    }

return 0;
}
