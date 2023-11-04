#include <iostream>
#include <string>

using namespace std;

struct Song {
    string title;
    string artist;
    Song* next;
    Song* prev;

    Song(string _title, string _artist) : title(_title), artist(_artist), next(nullptr), prev(nullptr) {}
};

class Playlist {
private:
    Song* head;
    Song* tail;

public:
    Playlist() : head(nullptr), tail(nullptr) {}

    void addSong(string title, string artist) {
        Song* newSong = new Song(title, artist);
        if (head == nullptr) {
            head = newSong;
            tail = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }

    void displayPlaylist() {
        Song* current = head;
        while (current != nullptr) {
            cout << "Title: " << current->title << ", Artist: " << current->artist << endl;
            current = current->next;
        }
    }
};

int main() {
    Playlist myPlaylist;

    myPlaylist.addSong("Song 1", "Artist 1");
    myPlaylist.addSong("Song 2", "Artist 2");
    myPlaylist.addSong("Song 3", "Artist 3");

    cout << "Mi Playlist:" << endl;
    myPlaylist.displayPlaylist();

    return 0;
}
