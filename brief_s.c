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

int recherche_cin(struct compte_bancaire bank[1000], int size, char rech[12])
{
    int i;
    int index = -1;

    for (i=0; i<size; i++) {
        if (strcmp(rech, bank[i].cin) == 0)
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
    int j=0;
    int t=0;
    int i=0;
    int choix;
    int choix2;
    int choix3;
    int choix4;
    double montantEntree;
    int total = 0;

   struct compte_bancaire aux;

    int ind_cin;

    char rech_cin[12];




    affiche_menu();
    scanf("%d",&choix);

    while(choix!=6){
       switch(choix){

        case 1 :
                 inserer_compte(i);

                 i++;

				if (i > max - 1)
                    {
                        i = 0;
                        printf("le stockage est satur� les anciennes informations seront supprim�es!\n");
                    }

                 total++;
				if (total > max)
					total = max;

                 break;

        case 2 :
                 inserer_compte(i);

                 i++;
				if (i > max - 1)
				{
					i = 0;
					printf("le stockage est satur� les anciennes informations seront supprim�es!\n");
				}

				total++;
				if (total > max)
					total = max;

                 printf("entrer 1 pour saisir autre personne ou 2 pour retourner menu principale :");
                 scanf("%d",&choix2);

                 while(choix2 != 2){

                     if(choix2 == 1){

                         inserer_compte(i);

                         i++;
				if (i > max - 1)
				{
					i = 0;
					printf("le stockage est satur� les anciennes informations seront supprim�es!\n");
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

				           if(choix3 == 1){
                          printf("Entrer cin : ");
                          scanf("%s", rech_cin);

                          ind_cin = recherche_cin(compte, total , rech_cin);

                             if (ind_cin == -1){
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
                                            break;
                                        }
                                 }
                            }

				else if(choix3 == 2){
					printf("Entrer cin : ");
					scanf("%s", rech_cin);

					ind_cin = recherche_cin(compte, total, rech_cin);

					if (ind_cin == -1)
					{
						printf("Le cin n'existe pas \n");
					}

					else
					{
						printf("Entrer le montant :");
						scanf("%lf", &montantEntree);
						compte[ind_cin].montant += montantEntree;
						 printf("montant globale : %.2lf\n",compte[ind_cin].montant);
						break;
					}
				}
                 else{
					printf("L'option n'existe pas \n");
					printf("Entrer 1 pour Retrait ou 2 pour Depot ou 3 pour annuler :");

					scanf("%d", &choix3);
				}
				break;



            case 4 : printf("1 pour ordre ascendant\n");
                     printf("2 pour ordre descendant\n");
                     printf("3 pour ordre ascendant et superieur a un chiffre\n");
                     printf("4 pour ordre descendant et superieur a un chiffre\n");
                     printf("5 pour rechercher avec cin\n");

				     scanf("%d", &choix4);

             if(choix4==1){
                for(i=0;i<total;i++){
                    for(j=i+1;j<total;j++){
                        if(compte[i].montant> compte[j].montant){
                                 aux=compte[i];
                                 compte[i]=compte[j];
                                 compte[j]=aux;
                            }
                    }
                }
                for(i=0;i<total;i++){
                    printf("nom : %s\t",compte[i].nom);
                    printf("prenom : %s\t",compte[i].prenom);
                    printf("cin : %s\t",compte[i].cin);
                    printf("montant : %.2lf\t",compte[i].montant);
                    printf("\n");
                    }
             }


            else if(choix4==2){

                    for(i=0;i<total;i++){
                        for(j=i+1;j<total;j++){
                            if(compte[i].montant < compte[j].montant)
                                   {
                                     aux=compte[i];
                                     compte[i]=compte[j];
                                     compte[j]=aux;
                                   }

                                }

                            }
                        for(i=0;i<total;i++){
                            printf("nom : %s\t",compte[i].nom);
                            printf("prenom : %s\t",compte[i].prenom);
                            printf("cin : %s\t",compte[i].cin);
                            printf("montant : %.2lf\t",compte[i].montant);
                            printf("\n");
                            }
                }


             else if(choix4==3){

                for(i=0;i<total;i++){
                        for(j=i+1;j<total;j++){
                            if(compte[i].montant < compte[j].montant){
                                     aux=compte[i];
                                     compte[i]=compte[j];
                                     compte[j]=aux;
                                   }
                                }
                            }

                            printf("entrer le montant : ");
                            scanf("%lf",&montantEntree);

                            for(i=0;i<total;i++){

                            if(compte[i].montant<montantEntree){

                                printf("nom : %s\t",compte[i].nom);
                                printf("prenom : %s\t",compte[i].prenom);
                                printf("cin : %s\t",compte[i].cin);
                                printf("montant : %.2lf\t",compte[i].montant);
                                printf("\n");

                                }

                            }

                   }




              else if(choix4==4){

                  for(i=0;i<total;i++){
                        for(j=i+1;j<total;j++){
                            if(compte[i].montant > compte[j].montant){
                                     aux=compte[i];
                                     compte[i]=compte[j];
                                     compte[j]=aux;
                                   }
                                }
                            }

                            printf("entrer le montant : ");
                            scanf("%lf",&montantEntree);

                            for(i=0;i<total;i++){

                            if(compte[i].montant > montantEntree){

                                printf("nom : %s\t",compte[i].nom);
                                printf("prenom : %s\t",compte[i].prenom);
                                printf("cin : %s\t",compte[i].cin);
                                printf("montant : %.2lf\t",compte[i].montant);
                                printf("\n");

                               }

                          }

                  }


                  else if (choix4 == 5)
                     {
					printf("Entrer cin : ");
					scanf("%s", rech_cin);

					ind_cin = recherche_cin(compte, total, rech_cin);

					if (ind_cin == -1) {
						printf("Le cin n'existe pas \n");
					     }
					      else {
					            printf("nom : %s\t\n",compte[ind_cin].nom);
                                printf("prenom : %s\t\n",compte[ind_cin].prenom);
                                printf("cin : %s\t\n",compte[ind_cin].cin);
                                printf("montant : %.2lf\t\n",compte[ind_cin].montant);
                                printf("\n");

					         }
				      }

				else
				   {
					printf("L'option n'existe pas \n");
				  }

            break;

       // case 5 : printf("");

       default :printf("L'option n'existe pas \n");
                    break;
        }

     affiche_menu();
     scanf("%d", &choix);
    }


}
