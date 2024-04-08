#include "models.hpp"

using namespace std;

Location::Location( string address,  string city,  string country,  string postalCode)
    : address(address), city(city), country(country), postalCode(postalCode) {}

 string Location::get_address() { return address; };

 string Location::get_city() { return city; }

 string Location::get_country() { return country; }



// Implementation des fonctions de User

User::User(int matricule,  string nom,  string prenom,  string tel,  string motDePasse, Location location)
    : matricule(matricule), nom(nom), prenom(prenom), tel(tel), motDePasse(motDePasse), location(location) {}

int User::get_matricule() { return matricule; }

 string User::get_name() { return nom; }

 string User::get_prenom() { return prenom; }

 string User::get_tel() { return tel; }

 string User::get_motDePasse() { return motDePasse; }

Location User::get_location() { return location; }


// Implementation des fonctions de Client

Client::Client(int matricule,  string nom,  string prenom,  string tel,  string motDePasse, Location location, double cash)
    : User(matricule, nom, prenom, tel, motDePasse, location), cash(cash) {}

double Client::get_cash() { return cash; }


// Implementation de la fonction d'Account

Account::Account(int matricule, Card& card, double amount) : amount(amount), card(card), matricule(matricule) {}

double Account::get_amount() { return amount; }

void Account::set_amount(double amount) { this->amount = amount; }

Card* Account::get_card() const { return &card; }








