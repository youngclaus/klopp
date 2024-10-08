//EE553 Final Project : MP3/Wav File Player
//Christopher Kruger, Mark Tuhacek, Christopher Youngclaus
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <iomanip>
#include <ios>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <random>

#pragma comment(lib, "Winmm.lib") //necessary for universal usage, no need to add linker file

using namespace std;

/*
In order for program to be able to compile, you need to use
Multi-Byte char instead of Wide char.
Project Properties -> Advanced
	-> Character Set option to Use Multi-Byte Character Set
Also to use filesystem, make sure compiler is using at least C++ Version 17
Project Properties -> General -> C++ Language Standard
*/

// used with mciSendString
string base = "";
LPCSTR command = ""; //necessary for future usage to pass a variable as an input for the mciSendString function

// default path
string DEFAULT = "songs";

int choice, track;
string songChoice, PATH;

class Playlist { //handles taking in every song within a folder
private:
	int error, NowPlaying;
	bool Paused;

	void fillwav() {		// fills wav vector with files in directory
		for (const auto& entry : filesystem::directory_iterator(PATH)) {
			wav.push_back(entry.path().string());
		}
	}

public:
	vector<string> wav;

	Playlist() {				// add songs in predetermined directory to vector
		PATH = DEFAULT;
		fillwav();
	}

	Playlist(string userpath) {		// add songs in user defined directory to vector
		PATH = userpath;
		fillwav();
	}

	void setFolder(string userpath) {	// change PATH after initialization
		wav.clear();
		PATH = userpath;
		fillwav();
	}

	void Close() {					// closes active media file
		mciSendString("close MediaFile", 0, 0, 0);
	}

	bool Open(string fileName) {			// opens media file for use
		base = "";
		command = "";

		base = "open " + fileName + " type waveaudio alias MediaFile"; //used for mciSendString function, but the function doesn't allow strings

		command = base.c_str(); //converted string to LPCSTR
		error = mciSendString(command, 0, 0, 0); //now compatible for mciSendString function

		if (error != 0) {
			base = "open " + fileName + " alias MediaFile";
			command = base.c_str();
			error = mciSendString(command, 0, 0, 0);

			if (error == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return true;
		}
	}

	bool Play() {						//	play song
		if (Open(wav[track])) {
			command = "play MediaFile";
			error = mciSendString(command, 0, 0, 0);

			if (error == 0) {
				NowPlaying = track;
				currentSong();
				return true;
			}
			else {
				Close();
				return false;
			}
		}
		else {
			return false;
		}
	}

	void Pause() {					// pauses active file
		if (Paused) {
			command = "resume MediaFile";
			error = mciSendString(command, 0, 0, 0);

			Paused = false;
		}
		else {
			command = "pause MediaFile";
			error = mciSendString(command, 0, 0, 0);
			Paused = true;
		}
	}

	void Stop() {							// stops song and any active function
		command = "stop MediaFile";
		error = mciSendString(command, 0, 0, 0);
		Paused = false;
		Close();
	}

	void Quit() {							// quits out of queue
		Stop();
		track = 0;
		Paused = false;
	}

	void Skip() {							// skips song
		Stop();
		track = track + 1;					//next in the vector

		if (track == wav.size()) {			//check if end of playlist
			cout << "Playlist End" << endl;
			Quit();
		}
		else {
			Play();
		}
	}

	void Prev() {					// restarts song
		Stop();
		Play();
	}

	void displayFolder() {			// see whats being written to wav vector
		for (int i = 0; i < wav.size(); i++) {
			cout << wav[i] << endl;
		}
	}
	void currentSong() {			//displays the currently playing song
		cout << "Now playing: " << wav[track] << endl;
	}
};

// would be used for playing a single wav file without initializing a playlist, have not made yet due to time constraint
class Song : public Playlist {

};

void Queue(Playlist p) {						// plays folder in order
	for (int i = 0; i < p.wav.size(); i++) {
		p.Play();
	}
}

void introGUI() {								//basic text GUI for playback controls
	cout << "**********" << endl;
	cout << "Welcome to our project!" << endl;;
	cout << "Reading from the 'songs' folder: " << endl;
	cout << left << setfill('.') << setw(30) << "1 for" << right << setfill('.') << setw(20) << "Changing playlists" << endl;
	cout << left << setfill('.') << setw(30) << "2 for" << right << setfill('.') << setw(20) << "Displaying the current playlist" << endl;
	cout << left << setfill('.') << setw(30) << "3 for" << right << setfill('.') << setw(20) << "Playing the playlist in order" << endl;
	cout << "**********" << endl;
	cout << "For playback controls: " << endl;
	cout << left << setfill('.') << setw(30) << "4 for" << right << setfill('.') << setw(20) << "Pausing the currently playing song" << endl;
	cout << left << setfill('.') << setw(30) << "5 for" << right << setfill('.') << setw(20) << "Resuming the currently playing song" << endl;
	cout << left << setfill('.') << setw(30) << "6 for" << right << setfill('.') << setw(20) << "Skipping to the next song" << endl;
	cout << left << setfill('.') << setw(30) << "7 for" << right << setfill('.') << setw(20) << "Restarting the currently playing song" << endl;
	cout << left << setfill('.') << setw(30) << "8 for" << right << setfill('.') << setw(20) << "Ending the current queue" << endl;
}

int main() {
	Playlist p("songs");	// default playlist program uses

	bool loop = true;
	introGUI();
	while (loop) {				//loops through for the user's control
		cout << "\nChoice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Insert a valid directory path" << endl;
			cin >> PATH;
			try {
				p.setFolder(PATH);
			}
			catch (exception e) {
				cout << "Directory does not contain music." << endl;
				PATH = DEFAULT;
			}
			break;
		case 2:
			cout << "Displaying the songs within the folder: " << endl;
			p.displayFolder();
			break;
		case 3:
			cout << "Playing the queue in order! " << endl;
			Queue(p);
			break;
		case 4:
			cout << "Pausing the current playing song! " << endl;
			p.Pause();
			break;
		case 5:
			cout << "Resuming the current playing song! " << endl;
			p.Pause();
			break;
		case 6:
			cout << "Skipping to the next song! " << endl;
			p.Skip();
			break;
		case 7:
			cout << "Restarting the current playing song! " << endl;
			p.Prev();
			break;
		case 8:
			cout << "Ending the queue." << endl;
			p.Quit();
			break;
		default:
			cin.clear();
			cin.ignore(99, '\n');
			cout << "Bad choice! Please try again: " << endl;
			break;
		}

	}

}