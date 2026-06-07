/*************************************************************/
/*                MusicPlaylist Definition                   */
/*************************************************************/
/* TODO: Implement the member functions of a MusicPLaylist   */
/*     This class uses a linked-list of Song structs to      */
/*     represent a playlist structure                        */
/*************************************************************/

#include "musicPlaylist.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
MusicPlaylist::MusicPlaylist() {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
}

MusicPlaylist::MusicPlaylist(Song* song) {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = song;
}

Song* MusicPlaylist::getFirstSong(){
    //DO NOT MODIFY THIS
    return this->head;
}
/*======================== ALL FUNCTIONS BELOW ARE #TODO ======================= */

/**
 * Display the song object
 * 
 * @param song The song object to display
 * @return No output returned. Should write to cout
 */
void Song::displaySong(){
    // TODO
    cout << "[ " << this->songName << ", " << this->artistNames << ", ";
    if(this->liked){
        cout << "<3 ]";
    }
    else{
         cout << "</3 ]";
    }
}

/**
 * Checks whether the music playlist is empty or not
 * 
 * @return True/False if the playlist is empty or not
 */
bool MusicPlaylist::isEmpty(){
    //TODO
    if(this->head == nullptr){
        return true;
    }
    return false;
}


/**
 * Walk through all songs in a playlist and display each one based on readme specs.
 * 
 * @return No output returned. Should write to cout using displaySong
 */
void MusicPlaylist::displayPlaylist(){
    // TODO
    if(head == nullptr){
        cout << "Displaying songs\n==================\nNULL\n==================\n";
        return;
    }
    Song *temp = head;
    cout << "Displaying songs\n==================\n";
    while(temp != nullptr){
        temp->displaySong();
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> " << "NULL\n==================\n";
}


/**
 * Adds a song to the playlist after the passed song. 
 * @param previousSong The song object to which the newSong should be added to.
 * @param newSong The newSong to be added to the playlist. It should be added after the previousSong (if previousSong is nullptr, song gets added to the beginning)
 * @return No output returned. Should modify the MusicPlaylist 
 */
void MusicPlaylist::addSong(Song* previousSong, Song* newSong){
    // TODO
    if(previousSong == nullptr){
        newSong->next = head; //Sets the previous head to the newSong.next 
        head = newSong; //Replaces head with new song
        return;
    }
    Song *temp = head;
    while(temp != nullptr){
        if(temp == previousSong){
            newSong->next = temp->next; //Sets the song after previous Song to newsong.next
            temp->next = newSong; //previousSong.next = new Song 
            return;
        }
        temp = temp->next;
    }
}

/**
 * Search through the music playlist until you find the song by name.
 * 
 * @param name The name of the song being looked for
 * @return Should return a song object. If no song is found, should return nullptr.
 */
Song* MusicPlaylist::searchSongByName(std::string name){
    // TODO
    Song *temp = head;
    while(temp != nullptr){
        if(temp->songName == name){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

/**
 * Like the song. Change the boolean (*liked*) from false->true or true->false
 * 
 * @param name The name of the song to like
 * @return No output returned. Should modify the Song and print according to readme specifications.
 */
void MusicPlaylist::likeSong(std::string name){
    // TODO
    Song *temp = head;
    while(temp != nullptr){
        if(temp->songName == name){
            temp->liked = !(temp->liked);
            cout << "Song: " << temp->songName << " liked!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Song not found." << endl;
}

/**
 * Traverse the playlist and display all songs that match the given artistName
 * 
 * @param name The name of the artist that we should search for
 * @return No output returned. Should write to cout each song that matches the artist.
 */  
void MusicPlaylist::displayAllSongsbyArtist(std::string name){
    // TODO
    Song *temp = head;
    bool found = false;
    while(temp != nullptr){
        if(temp->artistNames == name){
            temp->displaySong();
            cout << "\n";
            found = true;
        }
        temp = temp->next;
    }
    if(!found){
        cout << "No songs found.\n";
    }
}