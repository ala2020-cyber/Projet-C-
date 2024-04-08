#include <iostream>
#include "models.hpp"
#include "withdrawal.hpp"

using namespace std;
#include <string>


// Système de banking
// réaliser par: Ala Hani DEBBABI



int main() {


    int choice;
    int cardChoice;
    int matricule;
    string nom, prenom, tel, motDePasse, pass;
    string address, city, country, postalCode;
    double amount,montant;
    string cardType;
    Card* card;


    // Les principales fonctionnalités du système:
    // Ajout du client.
    // Création du compte bancaire.
    // Depot d'argent par carte.
    // Retrait d'argent par carte.
    // Consulter le Solde du compte créer.



    cout << "Bienvenue dans la banque interactive Realiser par Ala Hani DEBBABI M1IA !" << endl;

    cout<< "********Ajouter un client********" << endl;

    cout << "Entrez le matricule du client : " << endl;
    cin >> matricule;
    cout << "Entrez le nom du client : " << endl;
    cin.ignore();
    getline(cin,nom);
    cout << "Entrez le prenom du client : " << endl;
    cin.ignore();
    getline(cin,prenom);
    cout << "Entrez le numero de telephone du client : " << endl;
    cin.ignore();
    getline(cin,tel);
    cout << "Entrez le mot de passe du client : " << endl;
    cin>>motDePasse;
    cout << "Entrez l'adresse du client : " << endl;
    cin.ignore();
    getline(cin,address);
    cout << "Entrez la ville du client : " << endl;
    cin.ignore();
    getline(cin,city);
    cout << "Entrez le pays du client : " << endl;
    cin.ignore();
    getline(cin,country);
    cout << "Entrez le code postal du client : " << endl;
    cin.ignore();
    getline(cin,postalCode);

    Location clientLocation(address, city, country, postalCode);


    cout << "Quel type de carte vous voulais: (GoldCard, PlatiniumCard, BlackCard)? (1,2,3)"  << endl;
    cin >> cardChoice;

    cout << "Entrez le montant initial du compte en €: ";
    cin >> amount;


    if(cardChoice == 1){
        card= new GoldCard();
    }
    else if(cardChoice == 2){
        card= new PlatiniumCard();
    }
    else if(cardChoice == 3){
        card= new BlackCard();
    } else {
        cout << "Type de carte invalide." << endl;

    }

    Client client(matricule,nom,prenom, tel, motDePasse,clientLocation,0);


    cout << "Les informations du client (MATRICULE:" << client.get_matricule() << ") " << client.get_name() << " " << client.get_prenom() << " ont ete bien enregistrees." << endl<< endl;
    cout << "Pour la carte bancaire votre plafond est "<<card->max_credit()<<" €"<< "et votre max retrait "<< card->max_withdrawal()<<" €"<<endl;

    // ajputer compte
    Account account(client.get_matricule(),*card,amount);
    cout << "Le compte du client a ete cree avec succes !" << endl <<" Creation du compte bancaire de M/Mme "<< client.get_name()<< " "<< client.get_prenom()<< ":" <<endl;





    cout<< "********Deposer l'argent du carte********" << endl;
    cout << "Donne moi le code du compte pour deposer d'argent: "<<endl;
    cin>> pass;

    while(pass!=client.get_motDePasse()){
    cout << "S'authentifier avec une mot de passe pour faire des opérations sur le compte(Matricule:"<< client.get_matricule() <<"): "<<endl;
    cin>> pass;
    };
    cout << "Mot de passe correct ! Vous pouvez maintenant proceder au depot d'argent." << endl<< endl;


    cout<< ">> Votre solde a ce jour la est: "<<account.get_amount()<<" €"<<endl;
    cout<< "Tapez le montant a deposer:"<<endl;
    cin >> montant;

    account.set_amount(account.get_amount()+montant);


    cout<< ">> Votre solde apres depot d'argent est: "<<account.get_amount()<<endl;

    cout<< "********Retirer de l'argent du carte********" << endl;
    cout<< "Tapez le montant a retirer:"<<endl;
    cin >> montant;


    if(montant< account.get_amount() && montant <card->max_withdrawal()){
            account.set_amount(account.get_amount()- montant);
            cout<< montant<<endl;
    cout<< ">> Votre solde apres retrer d'argent: "<<account.get_amount()<<endl;
    }else{
        cout<< "Solde Insuiffusant"<<endl;
    }

     cout<< "********Consulter Solde du compte créer********" << endl;
     cout<< ">> Votre solde a ce jour la est: "<<account.get_amount()<<endl<<endl;


    cout << "Merci de utilise notre banque interactive. Au revoir !" << endl;

}
