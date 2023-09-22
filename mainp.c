
#include<stdio.h>
#include<string.h>
#include <time.h> 
////////////////////////////////////////////////////
int size = 0;





typedef struct deaedline
{
    int j;
    int m;
    int a;
}deaedline;

typedef struct tache
    {
        int id;
        char titre[20];
        char desc[20];
        deaedline d;
        int status; //(1 : à réaliser, 2 : en cours de réalisation, 3 : finalisée)
    }tache;

tache t[100];
//fonction menu
void menu(){
    
    {
    printf("\n\n-------------- Gestion de Taches ToDo --------------\n\n");
    printf("*********************************************************\n* \t 1 : Ajouter une tache                          *\n*\t 2 : Afficher la liste de toutes les taches     *\n*\t 3 : Supprimer une tache par identifiant        *\n*\t 4 : Rechercher les Taches                      *\n*********************************************************\n");
}

}

//ajout 
void ajout(){
    
    
    t[size].id = size + 1;
    printf("veuillez saisir les information du tache N %d \n",size+1);
    printf("\t Titre : ");
    scanf("%s",t[size].titre);
    printf("\t Description : ");
    getchar();
    gets(t[size].desc);
    printf("\t Deadline (JJ/MM/AAAA)* : ");
    scanf("%d/%d/%d",&t[size].d.j,&t[size].d.m,&t[size].d.a);
    printf("\t Status \n(Tapez 1 pour a realiser  2 pour en cours de realisation  3 pour finalisee :) ");
    scanf("%d",&t[size].status);
    size++;
    }


//ajout N
void ajoutN(){
    printf("Combien de tache vous voullez saisir");
    int c;
    scanf("%d",&c);

    int start = size;
    size = size + c;

    
    
    for (int i = start; i < size; i++)
    {
        t[i].id = i + 1;
        printf("veuillez saisir les information du tache N %d \n",i+1);
        printf("\t Titre : ");
        scanf("%s",t[i].titre);
        printf("\t Description : ");
        getchar();
        gets(t[i].desc);
        printf("\t Deadline (JJ/MM/AAAA)* : ");
        scanf("%d/%d/%d",&t[i].d.j,&t[i].d.m,&t[i].d.a);
        printf("\t Status \n(Tapez 1 pour a realiser  2 pour en cours de realisation  3 pour finalisee :) ");
        scanf("%d",&t[i].status);
    }
    
    
    }


//affichage---------------------------------------------------------------------------------


void affichage(){
    char s[13] = "a realiser";
    char s1[29] = "en cours de realisation";
    char s2[13] = "finalisee";
    char sf[29];

     printf("--------------------------------------------------------------\nId\tTitre\tDesc\t\tdeadline\tStatus\n--------------------------------------------------------------");
    for (int i = 0; i < size; i++)
    {
        switch (t[i].status)
        {
        case 1:
            strcpy(sf,s);
            break;
        case 2:
            strcpy(sf,s1);
            break;
        case 3:
            strcpy(sf,s2);
            break;
        
        default:
            break;
        }

        printf("\n%d\t%s\t%s\t\t%d/%d/%d\t%s\n--------------------------------------------------------------"
        ,t[i].id,t[i].titre,t[i].desc,t[i].d.j,t[i].d.m,t[i].d.a,sf);
    }
    
}

//tri alphabet---------------------------------------------------------------------------------

void tri_alpha(){
     for (int j = 0; j < size; j++)
    {
       for (int i = 0; i < size -1 ; i++)
       {
        int dif = strcmp(t[i].titre,t[i + 1].titre);
        if (dif > 0)
        {
            tache per = t[i];
            t[i] = t[i+1];
            t[i+1] = per;
        }        
       }       
    }    
}

//tri par deadline-------------------------------------------------------------------------------


void tri_dead() {
    tache temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (t[j].d.a > t[j + 1].d.a) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            } else if (t[j].d.a == t[j + 1].d.a &&
                       t[j].d.m > t[j + 1].d.m) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            } else if (t[j].d.a == t[j + 1].d.a &&
                       t[j].d.m == t[j + 1].d.m &&
                       t[j].d.j > t[j + 1].d.j) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}


// Modifier la description d'une tache----------------------------------------------------------

void modif_desc(){
    printf("\nVeuillez saisir ID de la tache que vous voullez modifier");
    int idd;
    scanf("%d", &idd);
    printf("Veuillez saisir la nouvelle description");
    char ndesc[30];
    int check = 0;
    getchar();
    gets(ndesc);


    for (int i = 0; i < size; i++)
    {
        if(t[i].id == idd){
            strcpy(t[i].desc,ndesc);
            check = 1;
        }
    }
    if (check == 0)
    {
        printf("id que vous avez saisie n existe pas");
    }
    else{
        printf("La modification est faite");
    }
}

//modif status---------------------------------------------------------------------------------

void modifStatus(){
    printf("\nVeuillez saisir ID de la tache que vous voullez modifier");
    int idMs;
    scanf("%d", &idMs);
    printf("\nVeuillez choisir le nouveau status\n (Tapez 1 pour a realiser  2 pour en cours de realisation  3 pour finalisee :)");
    int newstatus;
    scanf("%d",&newstatus);
    for (int i = 0; i < size; i++)
    {
        if(t[i].id == idMs){
           t[i].status = newstatus ;
            
        }
    }

}

//modif deadline---------------------------------------------------------------------------------

void modifDead(){
    printf("\nVeuillez saisir ID de la tache que vous voullez modifier");
    int idMd;
    scanf("%d", &idMd);
    printf("\nVeuillez choisir le nouveau deadline (JJ/MM/AAAA)");
    int JJ,MM,AAAA;
    scanf("%d/%d/%d",&JJ,&MM,&AAAA);
    for (int i = 0; i < size; i++)
    {
        if(t[i].id == idMd){
           t[i].d.j = JJ ;
           t[i].d.m = MM ;
           t[i].d.a = AAAA ;
            
        }
    }

}

//Suprimer une tache
void suprimer(){
    printf("\nVeuillez saisir ID de la tache que vous voullez suprimer\n");

    int idS,check = 0;
    int j;
    scanf("%d", &idS);
    printf("\nVous comfirmer la Suppression (1 : Oui / 2 : Non)\n");
    int supverif;
    scanf("%d",&supverif);
    switch (supverif)
    {
    case 1:
        
        for (int i = 0; i < size; i++)
        {
            if(t[i].id == idS){
                int j = i;
                //check = 1;
                for (int k = j; k < size - 1; k++){
                t[i] = t[k+1];
                i++;
            }
            size--;            
        }
        }
        break;
    case 2:
        printf("\nSuppression annulee");
        break;
    default:
        break;
    }
   


}


//Recherche par Id

void rechId(){
    printf("\nVeuillez saisir ID de la tache que vous voullez afficher");
    int vid,check = 0;
    scanf("%d",&vid);
    for (int i = 0; i < size; i++){
            char s[13] = "a realiser";
            char s1[29] = "en cours de realisation";
            char s2[13] = "finalisee";
            char sf[29];
            if (t[i].id == vid)
            {
                check = 1;    
                switch (t[i].status)
                {
                    case 1:
                        strcpy(sf,s);
                        break;
                    case 2:
                        strcpy(sf,s1);
                        break;
                    case 3:
                        strcpy(sf,s2);
                        break;
        
                    default:
                        break;
                }
                printf("--------------------------------------------------------------\nId\tTitre\tDesc\t\tdeadline\tStatus\n--------------------------------------------------------------");
                printf("\n%d\t%s\t%s\t\t%d/%d/%d\t%s\n--------------------------------------------------------------"
                ,t[i].id,t[i].titre,t[i].desc,t[i].d.j,t[i].d.m,t[i].d.a,sf);
            }            
        }
        if(check == 0){
            printf("\n Id que vous avez saisir n'existe pas\n");
        }
}


// recherch par titre---------------------------------------------------------------------------

void rechT(){
    printf("\nVeuillez saisir le titre de la tache que vous voullez afficher");
    char vt[20];
    int check = 0,rslt;

    scanf("%s",&vt);

    for (int i = 0; i < size; i++){
            rslt = strcmp(t[i].titre,vt);
            char s[13] = "a realiser";
            char s1[29] = "en cours de realisation";
            char s2[13] = "finalisee";
            char sf[29];
            if (rslt == 0)
            {
                check = 1;    
                switch (t[i].status)
                {
                    case 1:
                        strcpy(sf,s);
                        break;
                    case 2:
                        strcpy(sf,s1);
                        break;
                    case 3:
                        strcpy(sf,s2);
                        break;
        
                    default:
                        break;
                }
                printf("--------------------------------------------------------------\nId\tTitre\tDesc\t\tdeadline\tStatus\n--------------------------------------------------------------\n");
                printf("\n%d\t%s\t%s\t\t%d/%d/%d\t%s\n--------------------------------------------------------------"
                ,t[i].id,t[i].titre,t[i].desc,t[i].d.j,t[i].d.m,t[i].d.a,sf);
            }            
        }
        if(check == 0){
            printf("\n le titre que vous avez saisir n'existe pas\n");
        }
}

//Statistique----------------------------------------------------------------------------------------------

void totalTache(){
    printf("\nle nombre total des taches est : %d\n",size);

}

void competomcop(){
    int com = 0,incom = 0;
    for (int i = 0; i < size; i++)
    {
        if (t[i].status == 3)
        {
            com++;
        }
        if (t[i].status == 1 || t[i].status == 2)
        {
            incom++;
        }        
    }
    printf("le nombre de taches completes est %d\n",com);
    printf("le nombre de taches incompletes est %d\n",incom);

}

void deadline_diff(){

}



//Fontion menu-------------------------------------------------------------------------------------------------------------
void ajoutm(){
        int choixAjout;
        printf("\n\t1 : Ajouter une seule tache\n\t2 : Ajouter plusieurs taches\n\t0 : Retour\n\n");
        printf("Vous souhaitez : ");
        scanf("%d",&choixAjout);
        switch (choixAjout){
            case 1:
                ajout();
                break;
            case 2:
                ajoutN();
                break;
            default:
               
                break;
        }
}

//Affichage menu-----------------------------------------------------------------------------------------------------------------

void affichem(){
        int choixAff;
        printf("\n\t1 : Afficher les taches Trier par ordre alphabétique \n\t2 : Afficher les taches Trier par deadline \n\t3 : Afficher les tches dont le deadline est dans 3 jours ou moins\n\t0 : Retour\n\n");
        printf("Vous souhaitez : ");
        scanf("%d",&choixAff);
        switch (choixAff){
            case 1:
                tri_alpha();
                affichage();
                break;
            case 2:
                tri_dead();
                affichage();
                break;
            case 3:
                deadline_3();
            default:
                
                break;
        }
}

//MODIF-MENU

void modifm(){
    int choixModif;
    printf("\n\t1 : Modifier la description d une tache \n\t2 : Modifier le statut d une tache \n\t3 : Modifier le deadline d une tache\n\t0 : Retour\n\n");
    printf("Vous souhaitez : ");
    scanf("%d",&choixModif);
    switch (choixModif)
    {
    case 1:
        modif_desc();
        affichage();
        break;
    case 2 :
        modifStatus();
        affichage();
        break;
    case 3:
        modifDead();
        affichage();
        break;
    
    default:
        break;
    }
    
}

//menu-recherche

void rechMenu(){
     int choixRech;
    printf("\n\t1 :Rechercher une tache par son Identifiant \n\t2 : Rechercher une tache par son Titre \n\t0 : Retour\n\n");
    printf("Vous souhaitez : ");
    scanf("%d",&choixRech);
    switch (choixRech)
    {
    case 1:
        rechId();
        break;
    case 2:
        rechT();
        break;
    
    default:
        break;
    }

}


//stattistique-MENU

void statistique_menu(){
    int choixstat;
    printf("\n\t1 : Afficher le nombre total des taches\n\t2 : Afficher le nombre de taches completes et incompletes \n\t3 : Afficher le nombre de jours restants jusqu'au delai de chaque tache\n\t0 : Retour\n\n");
    printf("Vous souhaitez : ");
    scanf("%d",&choixstat);
    switch (choixstat)
    {
    case 1:
        totalTache();
        
        break;
    case 2 :
        competomcop();
        break;
    case 3:
        deadline_jours_restant();
        break;
    
    default:
        break;
    }
    
}


//date fonction--------------------------------------------------------------------------------------
void deadline_3 () { 

    int tempdeadlinejour ,tempdeadlinemonth,tempdeadlineyear;
    int datetoday=22,monthtoday= 9,yeartoday=2023;
    printf("---------------------------------- ----------------------------\nId\tTitre\tDesc\t\tdeadline\tStatus\n--------------------------------------------------------------");

    for(int i=0;i<size;i++){
        tempdeadlinejour = t[i].d.j;
        tempdeadlinemonth = t[i].d.m;
        tempdeadlineyear = t[i].d.a;


        int diff_jour=(tempdeadlineyear-yeartoday)*365 + 
                        (tempdeadlinemonth-monthtoday) *30 + 
                        (tempdeadlinejour-datetoday);

        if (diff_jour<=3 && diff_jour>0){
            char s[13] = "a realiser";
            char s1[29] = "en cours de realisation";
            char s2[13] = "finalisee";
            char sf[29];
            switch (t[i].status)
            {
                case 1:
                    strcpy(sf,s);
                    break;
                case 2:
                    strcpy(sf,s1);
                    break;
                case 3:
                    strcpy(sf,s2);
                    break;
        
                default:
                    break;
        }

        printf("\n%d\t%s\t%s\t\t%d/%d/%d\t%s\n--------------------------------------------------------------"
        ,t[i].id,t[i].titre,t[i].desc,t[i].d.j,t[i].d.m,t[i].d.a,sf);
    }
        }


    }


//jours restatnt
void deadline_jours_restant () { 

    int tempdeadlinejour ,tempdeadlinemonth,tempdeadlineyear;
    int datetoday=22,monthtoday= 9,yeartoday=2023;
    printf("---------------------------------- ----------------------------\nId\tTitre\tDesc\t\tdeadline\tStatus\tJours restant\n--------------------------------------------------------------");

    for(int i=0;i<size;i++){
        tempdeadlinejour = t[i].d.j;
        tempdeadlinemonth = t[i].d.m;
        tempdeadlineyear = t[i].d.a;


        int diff_jour=(tempdeadlineyear-yeartoday)*365 + 
                        (tempdeadlinemonth-monthtoday) *30 + 
                        (tempdeadlinejour-datetoday);

        
            char s[13] = "a realiser";
            char s1[29] = "en cours de realisation";
            char s2[13] = "finalisee";
            char sf[29];
            switch (t[i].status)
            {
                case 1:
                    strcpy(sf,s);
                    break;
                case 2:
                    strcpy(sf,s1);
                    break;
                case 3:
                    strcpy(sf,s2);
                    break;
        
                default:
                    break;
        }

        printf("\n%d\t%s\t%s\t\t%d/%d/%d\t%s\t%d Jours\n--------------------------------------------------------------"
        ,t[i].id,t[i].titre,t[i].desc,t[i].d.j,t[i].d.m,t[i].d.a,sf,diff_jour);
    
        }


    }

    
    
    
    













int main(){
    int choix;
    do{
   printf("\n\n----------Gestion de Taches ToDo----------\n");
    printf("------------------MENU--------------------\n\n");
    printf("\t1 : Ajouter une tache\n\t2 : Afficher la liste de toutes les taches\n\t3 : Modifier une tache\n\t4 : Supprimer une tache par identifiant\n\t5 : Rechercher les Taches\n\t6 : Statistiques\n\t0 : Quitter\n\n");
    printf("Vous souhaitez : ");
    scanf("%d",&choix);
    switch (choix)
    {
    case 1:
        ajoutm();
        break;
    case 2:
        affichem();
        break;
    case 3:
        modifm();
        break;
    case 4:
        suprimer();
        affichage();
        break;
    case 5:
        rechMenu();
        break;
    case 6:
        statistique_menu();
    
    default:
        break;
    }
    }while (choix != 0);    
}
