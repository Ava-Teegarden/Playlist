// ***********************************************************************
// Title: song.h
// Course: CPET 321
// Developer: Ava Teegarden
// Description: header file for the song class
// ***********************************************************************
#pragma once
#include<iostream>
#include<string>

using namespace std;

class Song {

private:

	string name;
	string artist;
	string URL;

public:
	Song();
	Song(string, string, string);
	void DisplaySongInfo();
	void PlaySong();
};