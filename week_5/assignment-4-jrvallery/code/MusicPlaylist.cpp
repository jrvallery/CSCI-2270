
#include "MusicPlaylist.hpp"

MusicPlaylist::MusicPlaylist()
{
    // No changes needed
}

/*
 * Purpose: Has to detect if a loop is present in the linkedlist pointed by head
 * @param none
 * @return integer length of loop if one exists. If loop not present return -1
 */
int MusicPlaylist::findLoopInPlaylist(){

    // TODO START =============================================
    Song *fast = head;
    Song *slow = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            Song *temp = slow->next;
            int count = 1;
            while(temp != slow){
                temp = temp->next;
                count++;
            }
            return count;
        }
    }
    return -1;
    // TODO END ==================================================
}

/*
 * Purpose: Has to remove all the Song nodes from [start, end] inclusive.
 * Has to print appropriate messages on cout like below if the linkedlist is empty
 * or if the values of start/ end are improper
 * follow the same order for couts in the writeup - check empty list first, then check wrong start/end values
 * @param integers start and end (1 based indexing not 0 based)
 * @return none
 */
void MusicPlaylist::removeSongs(int start, int end){

    // TODO START ===================================================

    if(head == nullptr){
        cout << "Playlist is Empty" << endl;
        return;
    }
    if(start < 1 || start > end){
        cout << "Invalid start or end values" << endl;
        return;
    }
    Song *temp = head;
    int count = 1;
    while(temp != nullptr && count < end){
        count++;
        temp = temp->next;
    }

    if(temp == nullptr){
        cout << "Invalid start or end values" << endl;
        return;
    }


    temp = head;
    count = 1;
    if(temp->next == nullptr){
        delete temp;
        head = nullptr; 
        return;
    }

    Song *prev = nullptr;
    while(temp != nullptr){
        if(count == start){
            break;
        }
        prev = temp;
        temp = temp->next;
        count++;
    }
    
    Song *current = temp;
    while(current != nullptr && count <= end){
        Song *nodeToDelete = current;
        current = current->next;
        delete nodeToDelete;
        count++;
    }

    if(prev == nullptr){
        head = current;
    }
    else{
        prev->next = current;
    }
    // TODO END ===================================================
}


/*
 * Purpose: Interweave the webpages alternatively into a new linkedlist 
 * starting with the first webpage in the list one
 * Assign the head of the new interweaved list to the head of this BrowserHistory
 * DO NOT create new nodes and copy the data, just use the same nodes from one and two and change pointers
 * If one of them runs out of length append the remaining of the other one at end
 * @param two linkedlist heads one and two
 * @return none
 */
void MusicPlaylist::mergeTwoPlaylists(Song *headOne, Song * headTwo){

    // TODO START =============================================

    if(headOne == nullptr){head = headTwo; return;}
    if(headTwo == nullptr){head = headOne; return;}
    Song *temp = headOne;
    int headOneSize = 0;
    while(temp != nullptr){
        temp = temp->next;
        headOneSize++;
    }
    temp = headTwo;
    int headTwoSize = 0;
    while(temp != nullptr){
        temp = temp->next;
        headTwoSize++;
    }
    // cout << "headOneSize: " << headOneSize << endl;
    // cout << "headTwoSize: " << headTwoSize << endl;

    Song *mergedHead = nullptr;
    Song *current = nullptr;
    bool headOneisLarger = (headOneSize >= headTwoSize);
    int count;
    if(headOneisLarger){
        mergedHead = headOne;
        current = headOne;
        headOne = headOne->next;
        count = 0;
    }
    else{
        mergedHead = headTwo;
        current = headTwo;
        headTwo = headTwo->next;
        count = 1;
    }

    
    while(headOne != nullptr && headTwo != nullptr){
        Song *chosen = nullptr;
        if(count % 2 == 0){
            chosen = headTwo;
            headTwo = headTwo->next;
        }
        else{
            chosen = headOne;
            headOne = headOne->next;
        }
        
        current->next = chosen;
        current = current->next;
         count++;
    }
    if(headOne != nullptr){
            current->next = headOne;
        }
    if(headTwo != nullptr){
        current->next = headTwo;
    }
    head = mergedHead;
    // TODO END ==================================================
}