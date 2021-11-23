#include <stdio.h>
#include <string.h>

int max=1000;

struct compte_bancaire{
    char nom[20];
    char prenom[20];
    char cin[20];
    double montant;
};
struct compte_bancaire compte[1000];

int recherche_cin()
{
    int i,index;
    char cin[20];
    printf("entrer le cin : ");
    scanf("%s",cin);

    for (i=0; i<sizeof(1000); i++) {
        if (strcmp(cin, compte[i].cin) == 0)
            index = i;
    }
    return index;
}

void inserer_compte(int i)
{
        printf("entrer le nom : ");
        scanf("%s",compte[i].nom);
        printf("entrer le prenom : ");
        scanf("%s",compte[i].prenom);
        printf("entrer le CIN : ");
        scanf("%s",compte[i].cin);
        printf("entrer le montant : ");
        scanf("%lf",&compte[i].montant);
}

void affiche_menu(){
        printf("\t\t\t\tMENU PRINCIPALE\n");
        printf(" Pour ajouter un nouveau compte, inserer 1\n");
        printf(" Pour ajouter plusieurs nouveaux comptes, inserer 2\n");
        printf(" Pour faire des operations sur compte, inserer 3\n");
        printf(" Pour afficher les comptes, inserer 4\n");
        printf(" Pour fidelisation, inserer 5 \n");
        printf(" Pour quitter, inserer 6 \n");
}

int main(){
     int i=0;
    int choix;
    int choix2;
    int choix3;
    double montantEntree;
    int total = 0;

    int ind_cin;

    //char rech_cin[12];

    affiche_menu();
    scanf("%d",&choix);

    while(choix!=6){
       switch(choix){
        case 1 :
                 inserer_compte(i);

                 i++;
				// limite a ete depasse
				if (i > max - 1)
				{
					i = 0;
					printf("le stockage est saturé les anciennes informations seront supprimées!");
				}

				// total des comptes qui sont insere
				// 100
				total++; // 101
				if (total > max)
					total = max; // ex max = 100

                 break;
        case 2 :
                 inserer_compte(i);

                 i++;
				if (i > max - 1)
				{
					i = 0;
					printf("le stockage est saturé les anciennes informations seront supprimées!");
				}

				total++;
				if (total > max)
					total = max;

                 printf("entrer 1 pour saisir autre personne ou 2 pour retourner au menu principale :");
                 scanf("%d",&choix2);

                 while(choix2 != 2){

                     if(choix2 == 1){

                         inserer_compte(i);

                         i++;
				if (i > max - 1)
				{
					i = 0;
					printf("le stockage est saturé les anciennes informations seront supprimées!");
				}

				total++;
				if (total > max)
					total = max;
                       }

                     else {
                            printf("L'option n'existe pas \n");
                          }
                           printf("entrer 1 pour saisir autre personne ou 2 pour retourner menu principale :");
                           scanf("%d",&choix2);
                     }
                 break;
        case 3 :
                    printf("Entrer 1 pour Retrait ou 2 pour Depot ou 3 pour retourner menu principale :");
                    scanf("%d", &choix3);

                    while (choix3 == 1)
				       {

                          ind_cin = recherche_cin();

                             if (ind_cin != 0){
                                printf("Le cin n'existe pas \n");
                              }
                             else
                                 {
                                    printf("Entrer le montant :");
                                    scanf("%lf", &montantEntree);

                                    if(montantEntree > compte[ind_cin].montant)
                                        printf("Montant invalide!\n");

                                    else{
                                            compte[ind_cin].montant -= montantEntree;
                                            printf("montant globale : %.2lf\n",compte[ind_cin].montant);
                                        }

                                }
                                printf("Entrer 1 pour Retrait ou 2 pour Depot ou 3 pour retourner menu principale :");
                             scanf("%d", &choix3);
                        }

                    break;


				// Depot
				/*else if (choix3 == 2)
                  {
                                ind_cin = recherche_cin();

                                // cas erreur // non trouve
                                if (ind_cin == -1)
                                {
                                    printf("Le cin n'existe pas \n");
                                }

                                // cas vrai // cin trouve
                                else
                                {
                                    // montant a depose
                                    printf("Entrer le montant :");
                                    scanf("%f", &montantEntree);
                                    compte[ind_cin].montant += montantEntree;
                                    break;
                                }
                            }

                            else
                            {
                                printf("L'option n'existe pas \n");
                                printf("Entrer 1 pour Retrait ou 2 pour Depot ou 3 pour annuler :");
                                //
                                scanf("%d", &choix3);
                            }
                            break;*/


                       // montant



                       // cas erreur // non trouve

                     //  }
                     // }
                     // Depot


       // case 4 : printf("");
       // case 5 : printf("");
       // case 6 : printf("");
       default :printf("L'option n'existe pas \n");
                    break;
        }

 affiche_menu();
     scanf("%d", &choix);
    }


}
