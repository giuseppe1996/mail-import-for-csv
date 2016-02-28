#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

const int DIM = 50;
typedef char stringa [DIM];

bool controllo1(const stringa);
bool controllo2(const stringa);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	ifstream leggi;
	ofstream scrivi;
	stringa mail;
	char end;
	stringa temp;
	
	cout <<"Creatore di Mail-List\n\nProgramma di Giuseppe Ferrara\n\n\n";
	do{
		cout << "Digitare l'indirizzo mail del cliente e premere invio o premere Q per chiudere"<<endl;
		cin >> mail;
		cout << endl << endl;
		if(controllo1(mail)&&controllo2(mail)){
		if(strlen(mail)>1 && mail[0] != 'Q'){
			
		/*	leggi.open("mail.txt"); //devo lavorare ancora su questa funzione
			while(!leggi.eof())
			{
				leggi.getline(char,50,',')>>temp;
				if(mail==leggi){
					cout << "indirizzo mail già inserito!";
					leggi.close();
					break;
				}
			} leggi.close(); */
			
			scrivi.open("mail.txt",ios::app);
			if(scrivi.fail()){
				cout << "Errore nell'apertura del file, chiudere e riaprire il programma, se il problema persiste contattare lo sviluppatore\n\n";
			}
			scrivi << mail;
			scrivi <<endl;
			scrivi.close(); //essendo i file su un server di rete per sarlvare ho bisogno ogni volta di chiudere e riaprire il file...
	}
		} else cout << "Attenzione! inserisci di nuovo l'indirizzo mail correttamente!\n\n";
		
	}while(mail[0] !='Q');
	
	
	cout << "Chiusura programma in corso...\n\npremere un tasto per chiudere  ";
	
	return 0;
}



bool controllo1(const stringa mail){
	bool feedback = false;
	for(int i=0;i<strlen(mail);i++){
			if(mail[i]=='@'){
				return true;
			}
			
		}
		
		return feedback;
}

bool controllo2(const stringa mail){
	bool feedback = false;
	for(int i=0;i<strlen(mail);i++){
			if (mail[i]=='.'){
				return true;
			}
		}
		
		return feedback;
}
