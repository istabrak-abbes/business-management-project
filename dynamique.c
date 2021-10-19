#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dynamique.h"
#define maxtaille 64
int bissecstile(date date1)
{
    int c;
    if (date1.annee%4!=0)
        c=0; //on a 28 jours dans le mois du février
    else
        c=1; //ona 29 jours dans le mois du février
    return c;
}
personnel* saisie(personnel *elt)
{
    printf("Identifiant : ");
    scanf("%s",(*elt).id);
    fflush(stdin);
    do
    {
        printf("Numero de la CIN : ");
        scanf("%s",(*elt).NCIN);
    }while(strlen((*elt).NCIN)!=8);
    printf("Nom du personnel : ");
    scanf("%s",(*elt).nom);
    printf("Prenom du personnel : ");
    scanf("%s",(*elt).prenom);
    do
    {
        fflush(stdin);
        printf("Sexe  (M ou F) : ");
        scanf("%s",(*elt).sexe);
        fflush(stdin);
    }while(strcmp((*elt).sexe,"M")!=0 && strcmp((*elt).sexe,"F")!=0);
    printf("Date de naissance:\n");
     do
    {
        printf("Annee : ");
        scanf("%d",&((*elt).datepersonnel.annee));
    }while(((*elt).datepersonnel.annee<1950)||((*elt).datepersonnel.annee>2020));
    do
    {

        printf("mois :  ");
        scanf("%d",&((*elt).datepersonnel.mois));

    }while ((*elt).datepersonnel.mois<1||(*elt).datepersonnel.mois>12);

    if ((*elt).datepersonnel.mois==2&&bissecstile((*elt).datepersonnel)==0)
    {
        do
        {
            printf("jour :  ");
            scanf("%d",&((*elt).datepersonnel.jour));
        }while ((*elt).datepersonnel.jour<1||(*elt).datepersonnel.jour>28);
    }
    else
        if((*elt).datepersonnel.mois==2&&bissecstile((*elt).datepersonnel)!=0)
    {

        do
        {
            printf("mois:  ");
            scanf("%d",&((*elt).datepersonnel.mois));
        }while ((*elt).datepersonnel.mois<1||(*elt).datepersonnel.mois>29);
    }

   else
    {
        do
        {

            printf("Jour : ");
            scanf("%d",&((*elt).datepersonnel.jour));

        }while(((*elt).datepersonnel.jour<1)||((*elt).datepersonnel.jour>31));
   }

    printf("Adresse :\n");
    printf("Ville : ");
    scanf("%s",(*elt).adressepersonnel.ville);
    printf("Rue : ");
    scanf("%s",(*elt).adressepersonnel.rue);
    printf("Code postal : ");
    scanf("%s",(*elt).adressepersonnel.codepostal);
     do
    {
    printf("Numero de telephone : ");
    scanf("%s",(*elt).tel);
    }while(strlen((*elt).tel)!=8);
    do
    {
        printf("Etat civil : mariee ou celibataire : ");
        scanf("%s",(*elt).etatcivil);
    }while((strcmp((*elt).etatcivil,"mariee"))&&(strcmp((*elt).etatcivil,"celibataire")));
    printf("Nombre d'enfants : ");
    scanf("%d",&((*elt).nbrenfants));
	return elt;
}


void afficher(personnel prs)
{

    printf("  Identifiant : %s \n",prs.id);
    printf("  Numero de la CIN : %s \n",prs.NCIN);
    printf("  Nom : %s\n ",prs.nom);
    printf("  Prenom : %s\n",prs.prenom);
    printf("  Date de naissance : %d-%d-%d\n",prs.datepersonnel.jour,prs.datepersonnel.mois,prs.datepersonnel.annee);
    printf("  Adresse : %s,%s,%s\n",prs.adressepersonnel.ville,prs.adressepersonnel.rue,prs.adressepersonnel.codepostal);
    printf("  Numero de telephone : %s \n",prs.tel);
    printf("  Etat civil : %s \n",prs.etatcivil);
    printf("  Nombre d'enfants : %d \n \t \t ***************** \n ",(prs.nbrenfants));

}

void affich_list(liste *lst)

{
    liste *courant;
    courant=lst ;
    if (!lst)
        printf("la liste n'existe pas ");
    else
    {
        while (courant)
        {
            afficher(courant->elt);
            courant=courant->succ;
        }
    }
}

int recherche(liste *lst,char id[maxtaille])
{
    liste *courant;
    int cmp=0;
    courant=lst;
    while(courant)
    {
        if(strcmp(courant->elt.id,id)==0)
        {
            return cmp;
            break;
        }
        courant=courant->succ;
        cmp++;
    }
    return -1;



}

liste* supprimer(liste *lst,char id1[])
{
    liste *courant,*pred;
    courant=lst;
    pred=NULL;
    while (courant)
    {
        if (strcmp(courant->elt.id,id1)==0)
            break;
        pred=courant;
        courant=courant->succ;
    }
   if (courant)
    {
        if(pred)
			pred->succ=courant->succ;
		else
			lst=lst->succ;
		free(courant);
    }

    else
        printf("Ce personnel n'existe pas\n");
    return lst;
}





void modifier_nbr_enfants(liste *lst,char id[maxtaille],int nbrenfants)
{
    int s=recherche(lst,id);
    liste *courant;
    courant=lst;
    if (s==-1)
    {
        printf("On ne peut pas modifier le nombre d'enfants d'un personnel qui n'existe pas \n");
    }
    else
    {
        while(courant)
        {
            if(strcmp(courant->elt.id,id)==0)
                break;
            courant=courant->succ;
        }
        courant->elt.nbrenfants=nbrenfants;
    }
}


void modifier_etatcivil(liste *lst,char id[maxtaille],char etat[maxtaille])
{
    int s=recherche(lst,id);
    liste *courant;
    courant=lst;
    if (s==-1)
    {
        printf("On ne peut pas modifier l'etat civil d'un personnel qui n'existe pas \n");
    }
    else
    {
        while(courant)
        {
            if(strcmp(courant->elt.id,id)==0)
                break;
            courant=courant->succ;
        }
        courant->elt.etatcivil[maxtaille]='\0';
        strcpy((courant->elt.etatcivil[maxtaille]),etat);
    }
}


void modifier_adresse(liste *lst,char id[maxtaille],char ville[maxtaille],char rue[maxtaille],char code[maxtaille])
{
    int s=recherche(lst,id);
    liste *courant;
    courant=lst;
    if (s==-1)
    {
        printf("On ne peut pas modifier l'adresse d'un personnel qui n'existe pas \n");
    }
    else
    {
        while(courant)
        {
            if(strcmp(courant->elt.id,id)==0)
                break;
            courant=courant->succ;
        }

        courant->elt.adressepersonnel.ville[maxtaille]='\0';
        strcpy(courant->elt.adressepersonnel.ville,ville);
        courant->elt.adressepersonnel.rue[maxtaille]='\0';
        strcpy(courant->elt.adressepersonnel.rue,rue);
        courant->elt.adressepersonnel.codepostal[maxtaille]='\0';
        strcpy(courant->elt.adressepersonnel.codepostal,code);

    }
}


