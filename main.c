#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    unsigned temps;
    char *type_course;
    char *termine;
} score;

typedef struct 
{
    unsigned code;
    char *nom;
    score competition;
} athlete;

void remplir(athlete *ta, int na)
{
    athlete *p;
    char ch[100];

    for (p = ta; p < ta + na; p++)
    {
        printf("Athlete %d\n", p - ta + 1);
        
        // Code
        printf("Code: ");
        scanf("%u", &p->code);
        getchar();

        // Nom 
        printf("Nom et prenom: ");
        gets(ch);
        p->nom = (char *)malloc(strlen(ch) + 1);
        strcpy(p->nom, ch);

        // Temps
        printf("Temps en seconde: ");
        scanf("%u", &p->competition.temps);
        getchar();

        // Type de course
        printf("Type de course (400m/300m): ");
        scanf("%s", ch);
        p->competition.type_course = (char *)malloc(strlen(ch) + 1);
        strcpy(p->competition.type_course, ch);

        // Termine
        printf("Il termine la course? ");
        scanf("%s", ch);
        p->competition.termine = (char *)malloc(strlen(ch) + 1);
        strcpy(p->competition.termine, ch);
    }
}

void afficher(athlete *ta, int na)
{
    athlete *p;
    for (p = ta; p < ta + na; p++)
    {
        printf("\nAthlete %d\n", p - ta + 1);
        printf("Code: %u\n", p->code);
        printf("Nom: %s\n", p->nom);
        printf("Temps: %u secondes\n", p->competition.temps);
        printf("Type de course: %s\n", p->competition.type_course);
        printf("A termine: %s\n", p->competition.termine);
    }
}

void classifier(athlete *ta,int na,athlete *ta1,int *nb1,athlete *ta2,int *nb2)
{
    athlete *p;
    for (p = ta; p < ta + na; p++)
    {
        if (strcmp(p->competition.termine, "oui") == 0)
        {
            if (strcmp(p->competition.type_course, "400m") == 0)
            {
                ta1[*nb1] = *p;
                (*nb1)++;            
            }
            else if (strcmp(p->competition.type_course, "300m") == 0)
            {
                ta2[*nb2] = *p;  
                (*nb2)++;            
            }
        }
    }
}

void tri(athlete *ta,int na)
{
    athlete *p,*q,temp;
    for(p=ta;p<ta+na-1;p++)
    {
        for(q=p+1;q<ta+na;q++)
        {
            if((p->competition.temps)>(q->competition.temps))
            {
                temp=*p;
                *p=*q;
                *q=temp;
            }
        }

    }
}

void liberer(athlete *ta, int na,athlete *ta1, athlete *ta2)
{
    athlete *p;
    for (p = ta; p < ta + na; p++)
    {
        free(p->nom);
        free(p->competition.type_course);
        free(p->competition.termine);
    }
    free(ta);
    free(ta1);
    free(ta2);
}

int main()
{
    int na,nb1=0,nb2=0;
    printf("Donnez le nombre d'athletes: ");
    scanf("%d", &na);
    getchar();

    // Allocation dynamique pour l'array d'athlètes
    athlete *ta = (athlete *)malloc(na * sizeof(athlete));
    
    if (ta == NULL)
    {
        printf("Erreur d'allocation memoire\n");
        return 1;
    }

    remplir(ta, na);

    athlete *ta2 = (athlete *)malloc(na * sizeof(athlete));
    athlete *ta1 = (athlete *)malloc(na * sizeof(athlete));
    classifier(ta,na,ta1,&nb1,ta2,&nb2);

    tri(ta1,nb1);
    tri(ta2,nb2);

    afficher(ta1,nb1);
    afficher(ta2,nb2);

    // Libération de la mémoire
    liberer(ta, na,ta1,ta2);

    return 0;
}
