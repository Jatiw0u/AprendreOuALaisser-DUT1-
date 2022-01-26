#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int NB=25;

int T[NB]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25}; //Tableau montré aux joueurs lors de la partie avec les prix découverts dans les boîtes par la suite//
int tabprix[NB]={0,30,35,40,50,75,100,250,500,750,1000,1500,2000,3000,4000,5000,7500,10000,15000,20000,30000,50000,100000,500000,1000000}; //tableau regroupant les différents prix//
int comptval[NB]; //tableau regroupant les différentes valeurs prises par le joueur//
int tab[NB]; //Tableaux regroupant les prix au place des boîtes indiqués//
int tabexprix[NB]; //Tableaux des prix qui se mettent à jour//

int* inittab(){
int i,nb_alea;

for (i=0;i<=NB-1;i++) {
nb_alea = (rand() %25)+1 ;
while (tab[nb_alea-1]!=0) {   //Fonction permettant d'initaliser le tableau tab pour mettre les valeurs des prix à différents endroits aléatoires//
nb_alea = (rand() %25)+1 ;
}
tab[nb_alea-1]=tabprix[i];
}
 for (i=0;i<=NB-1;i++) {
    comptval[i]=-1;
          }
for (i=0;i<=NB-1;i++) {
tabexprix[i]=tabprix[i];
         }
return tab;
    }

int montrevalise () {
int i;
for (i=0;i<=NB-1;i++) {                //Fonction permettant de montrer les valises au tout début lorsque aucune valise n'a été ouverte//
cout<<"[ "<<T[i]<< " ]";
if ((i+1)%5==0) {
    cout<<endl;
         }
   }
cout<<"***********************************"<<endl;
}

int montrevalise2 (int nb) {
int i;
for (i=0;i<=NB-1;i++) {
        if (i==nb-1) {
                cout<<"      ";
          }
else {                                //Fonction permettant de montrer les valises tout au long du jeu avec une place en moins montrant la place de la valise prise vide//
cout<<"[ "<<T[i]<< " ]";
     }
if ((i+1)%5==0) {
    cout<<endl;
        }
    }
cout<<"***********************************"<<endl;
}

int montreprix (int elm) {
int i,comptprix;
comptprix=-1;
for (i=0;i<=NB-1;i++) {
if (comptval[i]!=-1) {
 comptprix=comptprix+1;
}
}
if (comptprix==-1) {
comptprix=0;
}
cout<<"***********************************"<<endl;
for (i=0;i<=NB-1-comptprix;i++) {
cout<<" [ "<<tabexprix[i]<<" ] ";         //Procédure qui montre la liste des différents prix à gagner//
if ((i+1)%5==0) {
cout<<endl;
}
}
cout<<endl;
}

int verifprix (int elm) {
int i,j;



for (i=0;i<=NB-1;i++) {
if (tabexprix[i]==T[elm-1]) {
for (j=i;j<=NB-1;j++) {
tabexprix[j]=tabexprix[j+1];
}

}
                            //Procédure qui va supprimer une valeur du tableau de la liste des prix//
}


}

int valise (int nb) {
int elm,i,j;
bool ver;
cout<<"Voici les differents prix existants qui sont encore dans la partie:"<<endl;
 montreprix(elm);
cout<<"***********************************"<<endl;
comptval[nb-1]=nb-1;                                                 //La ligne 60 va mettre dans le tableau le rang de la boîte choisi de base//
    ver=true;
    cout<<"Maintenant quel valise allez-vous elimine?"<<endl;
    cout<<"***********************************"<<endl;
    montrevalise2(nb);
    cin>>elm;
    while (elm<=0 || elm>25) {
         cout<<"Veuillez resaisir votre numero de valise"<<endl;   //Fonction permettant de choisir la valise a éliminé//
    cout<<"***********************************"<<endl;
    cin>>elm;
    }
    for (i=0;i<=NB-1;i++) {
            ver=true;
        while (elm-1==comptval[i] || ver==false || (elm<=0 || elm>25)) {
        cout<<"Veuillez resaisir votre numero de valise"<<endl; //Ici on va bien vérifier que la valeur n'existe pas dans le tableau comptval qui répertorie toutes les valeurs prises//
        cout<<"***********************************"<<endl;      //Tout en demandant à nouveau un numéro de valise si le numéro avait déjà été donner//
        cin>>elm;
        ver=true;
           for (j=0;j<=NB-1;j++) {
              if (elm-1==comptval[j] || (elm<=0 || elm>25)) {
                ver=false;
              }
           }
        }
    }
    comptval[elm-1]=elm-1;                 //Ici on va compter la valeur prise par le joueur dans un tableau//
    T[elm-1]=tab[elm-1];
    verifprix(elm);
    montrevalise2(nb);
    cout<<"Vous avez pris la valise "<<elm<<" elle contenait "<<tab[elm-1] <<" euros"<<endl;
    if (tab[elm-1]>=10000) {
        cout<<"Houla, que de desespoir dans vos yeux, une grosse valeur vient de partir"<<endl;
    }

}


int banquier (int compt) {
int somme,total,total2,i;
total=0;
total2=0;
for (i=0;i<=NB;i++) {
   total=tabprix[i]+total;                  //Fonction qui permet de calculer la somme que le banquier pourra donner lors de l'appel//
   total2=T[i]+total2;
}
somme=(total+325)-total2;
somme=somme/(NB-compt);

return somme;
}

int repbanquier (int somme) {
string verit,OUI,NON;
bool ver;
     cout<<"Le banquier vous propose de repartir avec "<<somme<<" euros"<<endl;
     cout<<"Acceptez-vous son offre? (OUI ou NON)"<<endl;
     cin>>verit;
     while (verit!="OUI" && verit!="NON") {
     cout<<"***********************************"<<endl;
     cout<<"Veuillez resaisir la reponse de l'offre du banquier (OUI ou NON)"<<endl;  //Fonction qui retourne si oui ou non, on accepte la demande du banquier//
     cin>>verit;
     }
     if (verit =="OUI") {
        ver=true;
     }
     else if (verit =="NON") {
        ver=false;
     }
     return ver;
}

int continu () {

cout<<"Vous avez decide de continuer l'aventure"<<endl;
cout<<"Esperons que ce soit le bon choix"<<endl;                 //procédure qui affiche cela si on continue l'aventure après avoir dit non au banquier//
cout<<"***********************************"<<endl;
}

int boite26 () {
int mult;
mult = (rand() %3) ;             //fonction qui va sélectionner une valeur entre 0 et 2 pour avoir une valeur pour la boîte 26//
return mult;
}

int lastboite (int nb) {
    int i,rang;
for (i=0;i<=NB-1;i++) {          //Fonction qui va trouver le numéro de la dernière boîte non ouverte//
 if (comptval[i]!=i) {
rang=i;
 }
}
return rang;
}

int exchange (int nb) {  //Fonction permettant l'échange entre 2 boîtes, celle choisi par le joueur avec une des boîtes restantes//
int otre,i;
bool ver;
string verex,OUI,NON;
ver=true;
cout<<"Voulez-vous echanger votre boite contre une autre (OUI ou NON)"<<endl;
cin>>verex;
while (verex!="OUI" && verex!="NON") {
cout<<"veuillez resaisir la reponse (OUI OU NON)"<<endl;
cin>>verex;
}
if (verex=="OUI") {
cout<<"Quel valise voulez-vous echange avec celle que vous avez en votre possession?"<<endl;
cout<<"***********************************"<<endl;
    montrevalise2(nb);
cin>>otre;
ver=false;
while (ver==false) {
ver=true;
 for (i=0;i<=NB-1;i++) {
if(otre-1==comptval[i] || (otre<1 || otre>25) || otre==nb) {
cout<<"Veuillez resaisir le numero de la valise que vous voulez choisir"<<endl;
cout<<"***********************************"<<endl;
cin>>otre;
ver=false;
   }
 }
}
comptval[otre-1]=otre-1;
comptval[nb-1]=0;
return otre;
}
if (verex=="NON") {
cout<<"Tres bien, c'est votre choix et je le considere"<<endl;
cout<<endl;
return nb;
}
}

int montreprix1 () {
int i;
for (i=0;i<=NB-1;i++) {
cout<<" [ "<<tabprix[i]<<" ] ";         //Procédure qui montre la liste des différents prix à gagner//
if ((i+1)%5==0) {
cout<<endl;
}
}
}

int main()                                   //Fonction principale//
{ system("title A Prendre Ou A Laisser");
    int nb,j,compt,somme,gain,b26,rang;
bool ver,verex;
string verboi,OUI,NON;
rang=0;
compt=0;
string verit;
system("color a");
srand(time(0));
cout<<"***********************************"<<endl;
    cout<<"Bonjour, bienvenue a a prendre ou a laisser"<<endl;
    cout<<"***********************************"<<endl;
    cout<<"Voici les differents prix qu'on peut obtenir:"<<endl;
    montreprix1();
    cout<<"***********************************"<<endl;
    cout<<"veuillez choisir votre valise: (nombre entre 1 et 25)"<<endl;
    montrevalise();
    cin>>nb;
    while (nb<=0 || nb>26) {
       cout<<"Veuillez resaisir votre numero de valise"<<endl;
       cin>>nb;
    }
    cout<<"***********************************"<<endl;
    inittab();
    montrevalise2(nb);
    cout<<"ca marche, vous avez pris la valise "<<nb<<" j'espere qu'elle vous portera chance"<<endl;
    cout<<"***********************************"<<endl;
    for (j=1;j<=6;j++) {
    valise(nb);
    compt=compt+1;
     }
     somme=banquier(compt);
     ver=repbanquier(somme);
     if (!ver) {
           continu();
        for (j=1;j<=5;j++) {
    valise(nb);
    compt=compt+1;
     }
     somme=banquier(compt);
     ver=repbanquier(somme);
     if (!ver) {
            continu();
         for (j=1;j<=4;j++) {
          valise(nb);
          compt=compt+1;
          }
          somme=banquier(compt);
          ver=repbanquier(somme);
          if (!ver) {
              continu();
              nb=exchange(nb);
            for (j=1;j<=4;j++) {
            valise(nb);
            compt=compt+1;
          }
           somme=banquier(compt);
          ver=repbanquier(somme);
        if (!ver) {
            continu();
          for (j=1;j<=2;j++) {
            valise(nb);
            compt=compt+1;
          }
           somme=banquier(compt);
          ver=repbanquier(somme);
             if (!ver) {
                continu();
                cout<<"Vous etes sur la derniere ligne droite"<<endl;
                cout<<"***********************************"<<endl;
                cout<<"Bon courage a vous"<<endl;
             valise(nb);
            compt=compt+1;
            cout<<"Le banquier veut vous faire tourner en bourrique"<<endl;
            cout<<"Faites tres attention a vous, choisissez bien"<<endl;
             cout<<"***********************************"<<endl;
           somme=banquier(compt);
          ver=repbanquier(somme);
                 if (!ver) {
                  continu();
                    cout<<"Vous etes maintenant au pile ou face de votre vie"<<endl;
                    cout<<"Un choix important, faire le choix entre 2 boites"<<endl;
                    cout<<"Soyez vigilant dans votre choix"<<endl;
                    cout<<"***********************************"<<endl;
                      valise(nb);
                      compt=compt+1;
                      cout<<"***********************************"<<endl;
                      cout<<"Maintenant que vous avez choisi votre boite"<<endl;
                    cout<<"le banquier va vous donner votre derniere offre"<<endl;
                    somme=banquier(compt);
                    ver=repbanquier(somme);
                    if (!ver) {
                        cout<<"***********************************"<<endl;
                        nb=exchange(nb);
                        cout<<"Vous avez decide de ne pas choisir cette offre"<<endl;
                        cout<<"Est-le meilleur choix?"<<endl;
                        cout<<"Nous allons le voir maintenant avec la boite non choisi"<<endl;
                        rang=lastboite(nb);
                        cout<<"Dans la boite "<<rang+1<<" , il y avait "<<tab[rang]<<" euros"<<endl;
                        cout<<"Dans votre boite se cachait donc "<<tab[nb-1]<<" euros"<<endl;
                        gain=tab[nb-1];
                        if (tab[nb-1]>=10000) {

                            cout<<"***********************************"<<endl;
                            cout<<"C'est une tres belle valeur"<<endl;
                            cout<<"Vus avez ete excellent! BRAVO!"<<endl;
                            cout<<"Vous repartez donc avec "<<tab[nb-1]<<" euros"<<endl;
                        }
                        if (tab[nb-1]<=2000) {
                            cout<<"***********************************"<<endl;
                            cout<<"Quel descente aux enfers, vous avez joue et vous avez perdu"<<endl;
                            cout<<"Vous avez vraiment pas de chance, dommage pour vous"<<endl;
                        }

                      }

                    }
                 }
              }
           }
        }
     }
       if (ver) {
        cout<<"***********************************"<<endl;
        cout<<"Vous avez accepte l'offre du banquier"<<endl;
        cout<<"C'est un choix et c'est votre choix"<<endl;
        cout<<"Vous repartez donc avec "<<somme<<" euros"<<endl;
        gain=somme;
             }
             if (!ver) {
                     if (tab[nb-1]>=10000) {
                            cout<<"***********************************"<<endl;
                            cout<<"C'est une tres belle somme d'argent"<<endl;
                            cout<<"Vous avez ete excellent! BRAVO!"<<endl;
                            cout<<"Felicitations!"<<endl;
                            }
                             if (tab[nb-1]<=2000) {
                            cout<<"***********************************"<<endl;
                            cout<<"Vous avez ete fort et vous avez choisi cette somme"<<endl;
                            cout<<"Le banquier vous a anneanti, vous etes a terre pendant qu'il est aux cieux"<<endl;
                             }
                        }

             cout<<"***********************************"<<endl;
             cout<<"Votre gain= "<<gain<<" euros ";
             cout<<"Mais ce n'est pas finis"<<endl;
             cout<<"Vous pouvez maintenant multiplier votre gain par 2 voir egaliser ou obtenir 0 euros avec la boite 26"<<endl;
             cout<<"[26]"<<endl;
             cout<<"***********************************"<<endl;
             cout<<"Que voulez-vous faire? (OUI ou NON)"<<endl;
             cin>>verboi;
             while (verboi!="OUI" && verboi!="NON") {
             cout<<"Que voulez-vous faire vraiment? (OUI ou NON)"<<endl;
             cout<<"Saisissez a nouveau la reponse"<<endl;
             cin>>verboi;
             }
             cout<<"***********************************"<<endl;
             if (verboi=="OUI") {
                b26=boite26() ;
                cout<<"Dans cette 26eme boite se cachait "<<b26<<endl;
                cout<<"***********************************"<<endl;
                cout<<"[ "<<b26<<" ]"<<endl;
                gain=gain*b26;
                cout<<"Vous obtenez donc la fameuse valeur de "<<gain<<" euros "<<endl;
                if (b26==0) {
                    cout<<"Et ca fait mal, la descente aux enfers qui s'abat sur vous"<<endl;
                    cout<<"Bon courage pour cette nouvelle terrible"<<endl;
                }
                if (b26==2) {
                    cout<<"Que de joie dans vos yeux! Vous multipliez votre gain par 2"<<endl;
                    cout<<"BRAVO et FELICITATION!"<<endl;
                }
             }
             if (verboi=="NON") {
                b26=boite26();
                cout<<"Dans cette 26eme boite se cachait "<<b26<<endl;
                cout<<"***********************************"<<endl;
                cout<<"[ "<<b26<<" ]"<<endl;
             if (b26==0) {
                cout<<"Incroyable, vous avez mis le banquier a terre"<<endl;
                cout<<"Il pensait vous vaincre mais il s'est trompe"<<endl;
                cout<<"BRAVO et FELICITATION!"<<endl;
             }
             if (b26==2) {
                cout<<"Quel dommage, vous auriez pu multiplier votre gain par 2"<<endl;
                cout<<"Neannmoins vous ne perdez rien"<<endl;
             }
             }
             cout<<"Merci d'avoir joue a a prendre ou a laisser, on espere vous revoir tres bientot"<<endl;
}

// Signed Jatiwou
