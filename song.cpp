// ***********************************************************************
// Title: song.cpp
// Course: CPET 321
// Developer: Ava Teegarden
// Description: hahaaa
// ***********************************************************************
#include <string>
#include <iostream>
#include "song.h"

using namespace std;

//constructors----------------------------------------
Song::Song() {
   name = "";
   artist = "";
   URL = "";
}

Song::Song(string n, string a, string u) {
	name = n;
	artist = a;
	URL = u;

}

//displayer and play--------------------------------
void Song::DisplaySongInfo() {

	cout << name << " by " << artist << endl;

}
void Song::PlaySong(){

	string command;//a fun surprise tool for later

	cout << "Playing : " << name;
	cout << " by " << artist << endl;

	//create command line & call it
	command = "start chrome --window-size=250,675 " + URL;
	const char* system_command = command.c_str();
	system(system_command);


}