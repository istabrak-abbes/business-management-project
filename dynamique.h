#ifndef DYNAMIQUE_H_INCLUDED
#define DYNAMIQUE_H_INCLUDED
#define maxtaille 64



typedef struct
{
    int jour ;
    int mois;
    int annee;
}date;



typedef struct
{
    char ville[maxtaille];
    char rue[maxtaille];
    char codepostal[maxtaille];
}adresse;



typedef struct
{
    char id[maxtaille];
    char NCIN[maxtaille];
    char sexe[3];
    char nom[maxtaille];
    char prenom[maxtaille];
    date datepersonnel;
    adresse adressepersonnel;
    char tel[maxtaille] ;
    char etatcivil[maxtaille];
    int nbrenfants;
}personnel;



typedef struct liste
{
    personnel elt;
    struct liste *succ;
}liste;



int bissecstile(date date1);
personnel* saisie(personnel *elt);
void afficher(personnel prs);
void affich_list(liste *lst);
liste* supprimer(liste *lst,char id[maxtaille]);
int recherche(liste *lst,char id[maxtaille]);
void modifier_nbr_enfants(liste *lst,char id[maxtaille],int nbrenfants);
void modifier_etatcivil(liste *lst,char id[maxtaille],char etat[maxtaille]);
void modifier_adresse(liste *lst,char id[maxtaille],char ville[maxtaille],char rue[maxtaille],char code[maxtaille]);
#endif // DYNAMIQUE_H_INCLUDED
