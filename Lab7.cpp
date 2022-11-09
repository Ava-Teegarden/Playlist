// ***********************************************************************
// Title: Lab7.cpp
// Course: CPET 321
// Developer: Ava Teegarden
// Description: choose a neat tune to play, it will spawn a chrome 
//     youtube window for you
// ***********************************************************************
#include <string>
#include <iostream>
#include <fstream>
#include "song.h"
#include <list>

using namespace std;

//funtion: display a song menu of your options------------------------------
   void ScreenDisplay(list<Song> these_tunes){
   cout << "Song Menu :" << endl;

   int i = 1;//to display numbered songs
   for (auto songtemp : these_tunes) {
	   cout << i << ") ";
	   songtemp.DisplaySongInfo();
	   i++;
   }

   cout << "-1) QUIT" << endl;//quit option
   cout << "Select=>  ";

}



int main() {
	//file business
	ifstream playlist;

	//open playlist file
	playlist.open("my_playlist.txt");
	//if no worky, print error message
	if (playlist.fail()) {
		cout << "Oopsies, error: the playlist file could not open" << endl;
		return(-1);

	}
	

		//create list stuff and temp variables
		list<Song> tunes;
		string n, a, u; //these will input to datamembers of song after read in

	   //ok populate a list of Songs from the text file-----------------------------
	   //while not end of file, read in names and such
		while (!playlist.eof()) {
			//read in first three values
			getline(playlist, n);
			getline(playlist, a);
			getline(playlist, u);

			

			tunes.push_back(Song(n, a, u));//put new values into a song and push back

		}//while
        
		//once done reading the file close it
		playlist.close();

	   //read in a value X and iterate X number times to get to that song-------------

		int x = 0; //assign initial value
		list<Song>::iterator iter = tunes.begin();//create iter for tunes, set initial value

		while (x != -1) {

			//refresh screen etc
			ScreenDisplay(tunes);
			iter = tunes.begin();
			cin >> x;//first thing read in x

			if (x == -1) {
				cout << "thanks for listening !!" << endl;
				break;
			}



			//if it's an unused value let user know
			if ((x < 1) || (x > tunes.size())) {
				cout << "Oopsies... not a number option :/" << endl;
				system("pause");
				system("cls");
				continue;//pops back up to cin >> x
			}

			//for x times, iter++ until you get to requested place
			for (int j = 0; j < (x - 1); j++) {
				iter++;
			}
			iter->PlaySong();
			system("pause");
			system("cls");//clear screen
			


		}//while



	   //play the song at that place--------------------------------------------------



	return 0;

}//main