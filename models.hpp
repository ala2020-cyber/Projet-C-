#include <iostream>
#include <string>
#include <vector>
#include "./withdrawal.hpp"

using namespace std;

class Location {
    private:
        string address;
        string city;
        string country;
        string postalCode;

    public:
        Location(string address, string city, string country, string postalCode)
            : address(address), city(city), country(country), postalCode(postalCode){}

        // Getters
        string get_address();
        string get_city();
        string get_country(); 
        string get_postalCode(); 

        // Setters
        void set_address(string address) {this->address = address;};
        void set_city(string city) {this->city = city;};
        void set_country(string country) {this->country = country;};
        void set_postalCode(string postalCode) {this->postalCode = postalCode;};



};




class User {
    private:
        int matricule;
        string nom;
        string prenom;
        string tel;
        string motDePasse;
        Location location;
        // Card* card;


    public:
        // Constructeur
        User(int matricule,string nom, string prenom, string tel, string motDePasse
        ,Location location)
        : matricule(matricule),nom(nom),prenom(prenom),tel(tel),motDePasse(motDePasse),location(location)
        {}

        // Getters
        int get_matricule(){return matricule;};
        string get_name() {return nom;};
        string get_prenom() {return prenom;};
        string get_tel() {return tel;};
        string get_motDePasse() {return motDePasse;};
        Location get_location() {return location;};




        // Setters
        void set_matricule(int matricule) {this->matricule = matricule;}
        void get_name(string nom) {this->nom = nom;}
        void get_prenom(string prenom) {this->prenom = prenom;}
        void get_tel(string tel) {this->tel = tel;}
        void getmotDePasse(string motDePasse) {this->motDePasse = motDePasse;}
        void get_location(Location location) {this->location = location;}
    

};





class Client: public User {
    private:
        double cash;
    public:
    // Constructor for Client
    Client(int matricule, string nom, string prenom, string tel, string motDePasse, Location location, double cash)
        : User(matricule, nom, prenom, tel, motDePasse, location), cash(cash) {}

    // Getter for cash
    double get_cash() { return cash; }

    // Setter for cash
    void set_cash(double cash) { this->cash = cash; }
};






class Account {
    private:
        int matricule;
        double amount;
        Card &card;
    public:
        Account(int matricule,Card &card,double amount):
        amount(amount),card(card),matricule(matricule)
        {}

        double get_amount() {return amount;};
        void set_amount(double amount) {this->amount = amount; }
        Card* get_card() const { return &card; }


};








