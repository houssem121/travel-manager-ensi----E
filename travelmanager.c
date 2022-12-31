#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

typedef struct DATE // Structure de date
{
    int JOUR;
    int MOIS;
    int ANNEE;
    int HEURE;
    int MINUTES;
} date;

typedef struct VOYAGE // Une structure qui contient tous les informations à propos un voyage
{
    int num;
    char DESTINATION[100];
    char DEPART[100];
    date D;
    int nb_jour;
    char HOTEL[10];
    int PRIX;
} voyage;
typedef struct cellule // Structure de cellule d'une liste chainée
{
    struct cellule *suivant;
    voyage val;
} cellule;
void red()
{
    printf("\033[1;31m");
}
void green()
{
    printf("\033[0;32m"); // Les couleurs
}
void reset()
{
    printf("\033[0;34m");
}
int main()
{
    struct cellule *tete;
    tete = NULL;
    voyage v;
    char ch[10];
    char chw[10];
    int a, cho;

    int n, x, choix = 0;
    struct cellule *Q;
    struct cellule *Z;
    printf("\033[0;32m");
    printf(R"(
------------------------------------------------------------------------------------------
 /$$$$$$$$ /$$$$$$$   /$$$$$$  /$$    /$$ /$$$$$$$$ /$$
|__  $$__/| $$__  $$ /$$__  $$| $$   | $$| $$_____/| $$
   | $$   | $$  \ $$| $$  \ $$| $$   | $$| $$      | $$
   | $$   | $$$$$$$/| $$$$$$$$|  $$ / $$/| $$$$$   | $$
   | $$   | $$__  $$| $$__  $$ \  $$ $$/ | $$__/   | $$
   | $$   | $$  \ $$| $$  | $$  \  $$$/  | $$      | $$
   | $$   | $$  | $$| $$  | $$   \  $/   | $$$$$$$$| $$$$$$$$
   |__/   |__/  |__/|__/  |__/    \_/    |________/|________/|

 /$$      /$$  /$$$$$$  /$$   /$$  /$$$$$$   /$$$$$$  /$$$$$$$$ /$$$$$$$
| $$$    /$$$ /$$__  $$| $$$ | $$ /$$__  $$ /$$__  $$| $$_____/| $$__  $$
| $$$$  /$$$$| $$  \ $$| $$$$| $$| $$  \ $$| $$  \__/| $$      | $$  \ $$
| $$ $$/$$ $$| $$$$$$$$| $$ $$ $$| $$$$$$$$| $$ /$$$$| $$$$$   | $$$$$$$/
| $$  $$$| $$| $$__  $$| $$  $$$$| $$__  $$| $$|_  $$| $$__/   | $$__  $$
| $$\  $ | $$| $$  | $$| $$\  $$$| $$  | $$| $$  \ $$| $$      | $$  \ $$
| $$ \/  | $$| $$  | $$| $$ \  $$| $$  | $$|  $$$$$$/| $$$$$$$$| $$  | $$
|__/     |__/|__/  |__/|__/  \__/|__/  |__/ \______/ |________/|__/  |__/
|
                                       |
                                       |
                                     .-'-.
                                    ' _ '
                          ---------'  .-.  '---------
          _________________'  '-'  '_________________
           ''''''-|---|--/    \==][^',_m_,'^][==/    \--|---|-''''''
                         \    /  ||/   H   \||  \    /
                          '--'   OO   O|O   OO   '--'
                                                                      by:ensi-students ||E
------------------------------------------------------------------------------------------
)");
    reset();
    while (choix != 6)
    {
        printf("\n* 1 \tAjouter un voyage");
        printf("\n 2 \tAfficher la description d'un voyage");
        printf("\n 3 \tSupprimer un voyage");
        printf("\n 4 \tModifier un voyage");
        printf("\n 5 \tRecherche des voyages disponibles selon des dates precises.");
        printf("\n 6 *\tQuitter le programme");
        printf("\n\nSaisissez votre choix : ");
        do
        {
            
            scanf("%d",&choix);
            getchar();
            
            
        } while ((choix < 1) || (choix > 6));
        switch (choix)
        {
        case 1: // Pour ajouter un voyage à la liste
        {
            if (tete == NULL)
            {                                           // L'ajout dans le cas d'une liste vide
                printf("Saisir le numero  du voyage:"); // La saisie du numéro unique d'un voyage
                scanf("%d", &v.num);
                printf("Saisir la destination:"); // La saisie de la destination
                scanf("%s", &v.DESTINATION);

                do
                {
                    printf("Saisir le depart:"); // La saisie du départ
                    scanf("%s", &v.DEPART);
                } while (strcmp(v.DEPART, v.DESTINATION) == 0); // Pour ne pas avoir meme destination et départ

                do
                {
                    printf("Saisir la date du voyage:(JOUR/MOIS/ANNEE),(HEURE:MINUTES)"); // La saisie de la date sous forme jj/mm/aaaa,hh:mm
                    scanf("%d/%d/%d,%d:%d", &v.D.JOUR, &v.D.MOIS, &v.D.ANNEE, &v.D.HEURE, &v.D.MINUTES);
                } while ((v.D.JOUR > 31 || v.D.JOUR <= 0) || (v.D.MOIS > 12 || v.D.MOIS <= 0) || (v.D.ANNEE < 2022 || v.D.ANNEE <= 0) || (v.D.HEURE > 23 || v.D.HEURE < 0) || (v.D.MINUTES > 59 || v.D.MINUTES < 0));
                do
                {
                    printf("donner le prix du voyage: "); // La saisie du prix de voyage
                    scanf("%d", &v.PRIX);
                } while (v.PRIX <= 0);
                do
                {
                    printf("donner le nombre de jours : "); // La saisie de nombre de jours
                    scanf("%d", &v.nb_jour);
                } while ((v.nb_jour <= 0));

                printf("saisir le nom d'hotel  : "); // La saisie du nom d'hotel
                scanf("%s", &v.HOTEL);

                tete = (struct cellule *)malloc(sizeof(cellule)); // Une allocation dynamique de la mémoire
                tete->suivant = NULL;                             // L'ajout se fait à la tete de la liste
                tete->val = v;
            }
            else
            {
                struct cellule *t = tete; // L'ajout dans le cas d'une liste déjà remplie
                x = 0;
                while (x == 0)
                {
                    printf("Saisir le numero  du voyage:");
                    scanf("%d", &v.num);
                    t = tete;
                    a = 0;
                    while (a == 0 && t)
                    { // Le numéro de voyage doit etre unique
                        if (t->val.num == v.num)
                        {
                            a = 1;
                            red();
                            printf("Veuillez choisir un autre numero\n");
                        }
                        t = t->suivant;
                    }
                    reset();
                    if (!a)
                    {
                        x = 1;
                    }
                }
                printf("Saisir la destination:");
                scanf("%s", &v.DESTINATION);
                do
                {
                    printf("Saisir le depart:");
                    scanf("%s", &v.DEPART);
                } while (strcmp(v.DEPART, v.DESTINATION) == 0);
                x = 0;
                do
                {
                    printf("Saisir la date du voyage:(JOUR/MOIS/ANNEE),(HEURE:MINUTES)");
                    scanf("%d/%d/%d,%d:%d", &v.D.JOUR, &v.D.MOIS, &v.D.ANNEE, &v.D.HEURE, &v.D.MINUTES);
                } while ((v.D.JOUR > 31 || v.D.JOUR <= 0) || (v.D.MOIS > 12 || v.D.MOIS <= 0) || (v.D.ANNEE < 2023 || v.D.ANNEE <= 0) || (v.D.HEURE > 23 || v.D.HEURE < 0) || (v.D.MINUTES > 59 || v.D.MINUTES < 0));
                do
                {
                    printf("donner le prix du voyage: ");
                    scanf("%d", &v.PRIX);
                } while (v.PRIX <= 0);
                do
                {
                    printf("donner le nombre de jours : ");
                    scanf("%d", &v.nb_jour);
                } while ((v.nb_jour <= 0));

                printf("saisir le nom d'hotel  : ");
                scanf("%s", &v.HOTEL);

                struct cellule *p;
                p = (struct cellule *)malloc(sizeof(cellule));
                p->suivant = tete;
                p->val = v;
                tete = p;
            }
            break;
        }

        case 2: // L'affichage d'un voyage en donnant son numéro unique
        {
            a = 0;
            printf("Donner le numero  du voyage:");
            scanf("%d", &n);
            Q = tete;
            while (Q != NULL && a == 0)
            {
                x = Q->val.num;
                if (x == n)
                {
                    green();
                    printf("-----------------------------------------------------------------------------------------------------------------------\n");
                    printf("\nNUM       |DESTINATION            |DEPART                 |DATE DE VOYAGE       |HOTEL     |NOMBRE DE JOURS |PRIX      ");
                    printf("\n----------+-----------------------+-----------------------+---------------------+----------+----------------+----------\n");
                    printf("%-10d|%-23s|%-23s|%2d/%2d/%4d,%2d:%2d     |%-10s|%-16d|%-10d\n", Q->val.num, Q->val.DESTINATION, Q->val.DEPART, Q->val.D.JOUR, Q->val.D.MOIS, Q->val.D.ANNEE, Q->val.D.HEURE, Q->val.D.MINUTES, Q->val.HOTEL, Q->val.nb_jour, Q->val.PRIX);
                    printf("%s\n", "-----------------------------------------------------------------------------------------------------------------------\n");
                    a = 1;
                    reset();
                }
                Q = Q->suivant;
            }
            if (a == 0)
            {
                red();
                printf("\n AUCUN VOYAGE TROUVE"); // Si on n'a pas trouvé le voyage on affiche aucun voyage touvé
                reset();
            }
            break;
        }
        case 3: // La suppression d'un voyage en donnant son numéro unique
        {
            printf("Donner le numero  du voyage:");
            scanf("%d", &n);
            Q = tete;
            a = 0;
            if (Q)
            {
                x = Q->val.num;
                if (x == n)
                { // Dans le cas ou le voyage se trouve au début de la liste
                    tete = tete->suivant;
                    free(Q);
                    a = 1;
                    green();
                    printf("VOYAGE BIEN SUPPRIME !");
                    reset();
                }
                else
                { // Dans le cas ou le voyage se trouve au milieu ou à la fin de la liste
                    Z = Q;
                    Q = Q->suivant;

                    while (Q && (a == 0))
                    {
                        x = Q->val.num;
                        if (x == n)
                        {
                            Z->suivant = Q->suivant;
                            free(Q);
                            a = 1;
                            green();
                            printf("VOYAGE BIEN SUPPRIME !");
                            reset();
                        }
                        Z = Z->suivant;
                        Q = Q->suivant;
                    }
                }
            }
            if (!Q)
            { // Dans le cas ou la liste est vide ou on n'a pas trouvé le voyage à supprimer
                red();
                printf("\n CE VOYAGE N'EXISTE PAS !");
                reset();
            }
            break;
        }
        case 4: // La modification des informations d'un voyage en donnant son numéro unique
        {
            cho = 0;
            int getout = 0;
            a = 0;
            printf("Donner le numero  du voyage:");
            scanf("%d", &n);
            Q = tete;
            while (Q != NULL && a == 0)
            { // On cherche la position du voyage à modifier
                x = Q->val.num;
                if (x == n)
                {
                    a = 1;
                    break;
                }
                Q = Q->suivant;
            }
            if (a == 0)
            { // Dans le cas ou on ne trouve pas le voyage
                red();
                printf("\n CE VOYAGE N'EXISTE PAS !");
                reset();
            }
            else
            { // Si on trouve le voyage

                while (cho != 7 || getout == 0)
                { // On donne toutes les possibilités pour modifier tous les informations à propos un voyage
                    printf("\n* 1 \tModifier la destination");
                    printf("\n 2 \tModifier le depart");
                    printf("\n 3 \tModifier la date du voyage");
                    printf("\n 4 \tModifier le nombre de jour du voyage");
                    printf("\n 5 \tModifier le nom d'hotel ");
                    printf("\n 6 \tModifier le prix du voyage ");
                    printf("\n 7 *\tFinir les modifications");
                    printf("\n\nSaisissez votre choix : ");
                    do
                    {
                        scanf("%d",&cho);
                        getchar();
                    } while ((cho < 0) || (cho > 7));
                    switch (cho)
                    {
                    case 1: // Modifiction de la destination
                    {

                        printf("Saisir la destination:");
                        scanf("%s", &v.DESTINATION);

                        strcpy(Q->val.DESTINATION, v.DESTINATION);
                        break;
                    }
                    case 2: // Modification de la départ
                    {

                        printf("Saisir le depart:");
                        scanf("%s", &v.DEPART);

                        strcpy(Q->val.DEPART, v.DEPART);
                        break;
                    }
                    case 3: // Modification de la date
                    {
                        do
                        {
                            printf("Saisir la date du voyage:(JOUR/MOIS/ANNEE),(HEURE:MINUTES):");
                            scanf("%d/%d/%d,%d:%d", &v.D.JOUR, &v.D.MOIS, &v.D.ANNEE, &v.D.HEURE, &v.D.MINUTES);
                        } while ((v.D.JOUR > 31 || v.D.JOUR <= 0) || (v.D.MOIS > 12 || v.D.MOIS <= 0) || (v.D.ANNEE < 2022 || v.D.ANNEE <= 0) || (v.D.HEURE > 23 || v.D.HEURE < 0) || (v.D.MINUTES > 59 || v.D.MINUTES < 0));
                        Q->val.D.ANNEE = v.D.ANNEE;
                        Q->val.D.MOIS = v.D.MOIS;
                        Q->val.D.JOUR = v.D.JOUR;
                        Q->val.D.HEURE = v.D.HEURE;
                        Q->val.D.MINUTES = v.D.MINUTES;
                        break;
                    }
                    case 4: // Modification de nombre de jours
                    {
                        do
                        {
                            printf("Saisir le nombre de jour: ");
                            scanf("%d ", &v.nb_jour);
                        } while (v.nb_jour < 1);
                        Q->val.nb_jour = v.nb_jour;
                        break;
                    }

                    case 5: // Modification du nom d'hotel
                    {
                        printf("Donner le nom de l'hotel :");
                        scanf("hotel %s ", &v.HOTEL);
                        strcpy(Q->val.HOTEL, v.HOTEL);
                        break;
                    }
                    case 6: // Modification du prix
                    {
                        do
                        {
                            printf("Donner le prix du voyage:");
                            scanf("%d", &v.PRIX);
                        } while (v.PRIX <= 0);
                        Q->val.PRIX = v.PRIX;
                        break;
                    }

                    case 7: // Dans le cas ou la destination et le départ sont identiques aprés la modification alors on demande à l'utilisateur de changer l'une des deux
                    {
                        getout = strcmp(v.DEPART, Q->val.DESTINATION);
                        red();
                        if (getout == 0)
                        {
                            printf("la destination et le depart sont identiques!!!");
                        }
                        reset();
                        break;
                    }
                    }
                }
                // cho=0;
            }
            break;
        }
        case 5: // La recherche et l'affichage d'un voyage en donnat une date précise
        {
            Q = tete;
            int ii = 0;
            do
            {
                printf("Saisir la date du voyage:");
                scanf("%d/%d/%d,%d:%d", &v.D.JOUR, &v.D.MOIS, &v.D.ANNEE, &v.D.HEURE, &v.D.MINUTES);
            } while ((v.D.JOUR > 31 || v.D.JOUR <= 0) || (v.D.MOIS > 12 || v.D.MOIS <= 0) || (v.D.ANNEE < 2022 || v.D.ANNEE <= 0) || (v.D.HEURE > 23 || v.D.HEURE < 0) || (v.D.MINUTES > 59 || v.D.MINUTES < 0));
            while (Q)
            {
                if ((Q->val.D.ANNEE == v.D.ANNEE) && (Q->val.D.HEURE == v.D.HEURE) && (Q->val.D.JOUR == v.D.JOUR) && (Q->val.D.MINUTES == v.D.MINUTES) && (Q->val.D.MOIS == v.D.MOIS))
                {
                    green();
                    if (ii == 0)
                    {
                        green();
                        printf("-----------------------------------------------------------------------------------------------------------------------\n");
                        printf("\nNUM       |DESTINATION            |DEPART                 |DATE DE VOYAGE       |HOTEL     |NOMBRE DE JOURS |PRIX      ");
                        printf("\n----------+-----------------------+-----------------------+---------------------+----------+----------------+----------\n");
                        printf("%-10d|%-23s|%-23s|%2d/%2d/%4d,%2d:%2d     |%-10s|%-16d|%-10d\n", Q->val.num, Q->val.DESTINATION, Q->val.DEPART, Q->val.D.JOUR, Q->val.D.MOIS, Q->val.D.ANNEE, Q->val.D.HEURE, Q->val.D.MINUTES, Q->val.HOTEL, Q->val.nb_jour, Q->val.PRIX);
                        printf("%s\n", "-----------------------------------------------------------------------------------------------------------------------\n");

                        reset();
                        ii++;
                    }
                    else
                    {
                        printf("%-10d|%-23s|%-23s|%2d/%2d/%4d,%2d:%2d     |%-10s|%-16d|%-10d\n", Q->val.num, Q->val.DESTINATION, Q->val.DEPART, Q->val.D.JOUR, Q->val.D.MOIS, Q->val.D.ANNEE, Q->val.D.HEURE, Q->val.D.MINUTES, Q->val.HOTEL, Q->val.nb_jour, Q->val.PRIX);
                        printf("%s\n", "-----------------------------------------------------------------------------------------------------------------------\n");
                    }
                }
                Q = Q->suivant;
                reset();
            }
            if (ii == 0) // Si on ne trouve pas le voyage
            {
                red();
                printf("AUCUN VOYAGE DISPONIBLE !");
                reset();
            }

            break;
        }
        }
    }
    return 0;
}
