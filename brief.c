#include <stdio.h>
int i;
i=0;
struct compte_bancaire{
    char nom[20];
    char prenom[20];
    char cin[20];
    double montant;
};
struct compte_bancaire compte[2];

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

    int choix;
    int choix2;
    int choix3;

    affiche_menu();

    scanf("%d",&choix);
    while(choix!=6){
       switch(choix){
        case 1 : printf("entrer le nom : ");
                 scanf("%s",compte[i].nom);
                 printf("entrer le prenom : ");
                 scanf("%s",compte[i].prenom);
                 printf("entrer le CIN : ");
                 scanf("%s",compte[i].cin);
                 printf("entrer le montant : ");
                 scanf("%f",&compte[i].montant);
                 break;
        case 2 :
                 printf("entrer le nom : ");
                 scanf("%s",compte[i].nom);
                 printf("entrer le prenom : ");
                 scanf("%s",compte[i].prenom);
                 printf("entrer le CIN : ");
                 scanf("%s",compte[i].cin);
                 printf("entrer le montant : ");
                 scanf("%f",&compte[i].montant);

                 printf("entrer 1 pour saisir autre personne ou 2 pour retourner au menu principale :");
                 scanf("%d",&choix2);

                 while(choix2 != 2){

                    if(choix2 == 1){
                         printf("entrer le nom : ");
                         scanf("%s",compte[i].nom);
                         printf("entrer le prenom : ");
                         scanf("%s",compte[i].prenom);
                         printf("entrer le CIN : ");
                         scanf("%s",compte[i].cin);
                         printf("entrer le montant : ");
                         scanf("%f",&compte[i].montant);
                       }

                     else {
                            printf("L'option n'existe pas \n");
                          }
                           printf("entrer 1 pour saisir autre personne ou 2 pour retourner au menu principale :");
                           scanf("%d",&choix2);
                     }
                 break;
        case 3 :
              //  printf("Entrer 1 pour Retrait ou 2 pour Depot ou 3 pour annuler :");
                //scanf("%d", &choix3);
                   // while (choix3 != 3){
                       // Retrait
                     //  if (choix3 == 1) {
                        //    printf("Entrer cin : ");
                        //    scanf("" );
                     //  }
                       // montant



                       // cas erreur // non trouve

                     //  }
                     // }
                     // Depot


        case 4 : printf("");
        case 5 : printf("");
        case 6 : printf("");
       default :printf("L'option n'existe pas \n");
                    break;
        }

 affiche_menu();
     scanf("%d", &choix);
    }


}
