#include <stdio.h>
#include <string.h>

char titres[100][50], auteurs[100][50], prix[100][50];
int quantites[100];
int nombre_de_livre = 0;

void ajouter_un_livre()
{
    printf("titre:\n");
    scanf("%s", titres[nombre_de_livre]);
    printf("auteur:\n");
    scanf("%s", auteurs[nombre_de_livre]);
    printf("prix:\n");
    scanf("%s", prix[nombre_de_livre]);
    printf("quantité:\n");
    scanf("%i", &quantites[nombre_de_livre]);
    nombre_de_livre++;
}

void afficher_les_livres()
{
    if (nombre_de_livre == 0)
    {
        return printf("il y'a aucun livre\n");
    }

    for (int i = 0; i < nombre_de_livre; i++)
    {
        printf("book %i\n", i + 1);
        printf("titre: %s\n", titres[i]);
        printf("auteur: %s\n", auteurs[i]);
        printf("prix: %s\n", prix[i]);
        printf("quantite: %i\n", quantites[i]);
    }
}

int rechercher(char titre[])
{
    for (int i = 0; i < nombre_de_livre; i++)
    {
        if (strcmp(titre, titres[i]) == 0)
        {
            return i;
        }
    }
    printf("ce livre n'existe pas!\n");
    return -1;
}

void mettre_a_jour_quantite()
{
    char titre[50];
    printf("entrer le titre de livre: \n");
    scanf("%s", titre);
    int index = rechercher(titre);
    int quantite;
    printf("entrer la nouvelle quantite: \n");
    scanf("%i", &quantite);
    quantites[index] = quantite;
}

void supprimer_un_livre()
{
    char titre[50];
    printf("entrer le titre du livre: \n");
    scanf("%s", titre);
    int index = rechercher(titre);
    printf("%i\n", index);

    if (index == -1)
    {
        return;
    };

    for (int i = index; i < nombre_de_livre; i++)
    {
        strcpy(titres[i], titres[i + 1]);
        strcpy(auteurs[i], auteurs[i + 1]);
        strcpy(prix[i], prix[i + 1]);
        quantites[i] = quantites[i + 1];
    }
    nombre_de_livre--;
}

void afficher_nombre_total()
{
    printf("nombre de livres: %d\n", nombre_de_livre);
}

int main()
{
    while (1)
    {
        int choix;
        printf("\nEntrer le numero d'operation:\n");
        printf("1. Ajouter un Livre au Stock\n");
        printf("2. Afficher Tous les Livres Disponibles\n");
        printf("3. Mettre à Jour la Quantité d'un Livre\n");
        printf("4. Supprimer un Livre du Stock\n");
        printf("5. Afficher le Nombre Total de Livres en Stock\n\n");
        scanf("%i", &choix);
        switch (choix)
        {
        case 1:
            ajouter_un_livre();
            break;
        case 2:
            afficher_les_livres();
            break;
        case 3:
            mettre_a_jour_quantite();
            break;
        case 4:
            supprimer_un_livre();
            break;
        case 5:
            afficher_nombre_total();
        default:
            break;
        }
    }
    return 0;
}
