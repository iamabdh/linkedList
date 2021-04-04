#include <iostream>
#include <string>
using namespace std;
bool isListEmpty();
bool isItemInList(int);
void display();
void insertNode(int);
void deleteSelectedItem(int);
void getLength();
struct Node {
    int data;
    Node* link;
};
struct Node* list = NULL;
struct Node* last = NULL;
void insertNode(int n) {   /**insert begining**/
    if (isListEmpty()) {
        struct Node* newNode = new Node;
        newNode->data = n;
        newNode->link = last;
        last = newNode;
        list = last;
    }
    else {
        struct Node* newNode = new Node;
        newNode->data = n;
        newNode->link = list;
        list = newNode;
    }
    last->link = list;
}
void display() { /** display lists **/
    if (isListEmpty()) {
        cout << "the list is empty" << endl;
    }
    else {
        struct Node* temp = list;
        while (temp != NULL) {
            if (temp == last) {
                cout << temp->data << " ";
                temp = NULL;
            }
            else {
                cout << temp->data << " ";
                temp = temp->link;
            }
        }
    }
    cout << "\n";
}

void deleteSelectedItem(int selectedItem = list->data) { /**delete selected item from the list by defulat it's delete first element**/
    if (isListEmpty()) {
        cout << "the list is empty" << endl;
    }
    else {
        bool confirmation = false;
        if (isItemInList(selectedItem)) {
            struct Node* temp = list;
            struct Node* prevLast=NULL;
            if (selectedItem == list->data) { /** delete first item if it's in the first**/
                cout << list->data << ": deleted from list" << endl;
                struct Node* temp = list;
                if (list == last) {
                    list = NULL;
                }
                else {
                    list = list->link;
                    last->link = list;
                    delete temp;
                }
            }
            else if (selectedItem == last->data) {  /** delete last item, if it's in the last **/
                while (temp != NULL) {
                    if (temp != last) {
                        prevLast = temp;
                        temp = temp->link;
                    }
                    else {
                        cout << temp->data << ": deleted from list" << endl;
                        delete last;
                        last = prevLast;
                        last->link = list;
                        temp = NULL;
                    }
                }
            }
            else {        /** delete item in between **/
                while (!confirmation) { /**confirmation it's used if the middle item deleted**/
                    if (temp->data != selectedItem) {
                        prevLast = temp;
                        temp = temp->link;

                    }
                    else {
                        cout << temp->data << ": deleted from list" << endl;
                        prevLast->link = temp->link;
                        delete temp;
                        confirmation = true;
                    }
                }
            }
        }
        else {
            cout << "the given item is not in the list to delete" << endl;
        }
    }
}
bool isItemInList(int data) {       /**usefull function to ckecks if the items in lists**/
    bool found = false;
    if (isListEmpty()) {
        cout << "the list is empty" << endl;
    }
    else {
        struct Node* temp = list;
        while (temp != NULL && !found) {
            if (temp != last) {
                if (temp->data != data) {
                    temp = temp->link;
                }
                else {
                    found = true;
                }
            }
            if (temp == last) {
                if (temp->data == data) {
                    found = true;
                }
                temp = NULL;
            }
        }

    }
    return found;
}
void serachItem(int data) {    /**serach item from selected item from the list**/
    if (isItemInList(data)) {
        cout << data << ": found." << endl;
    }
    else {
        cout << data << ": not found." << endl;
    }
}
void getLength() {      /**find the length of list**/
    int length = 0;
    if (isListEmpty()) {
        cout << "length: " << length << endl;
    }
    else {
        struct Node* temp = list;
        while (temp != NULL) {
            if (temp == last) {
                temp = NULL;
            }
            else {
                temp = temp->link;
            }
            length += 1;
        }
        cout << "length: " << length << endl;
    }
}
bool isListEmpty() {        /**check if the list is empty**/
    return (list == NULL) ? true : false;
}
int main() {
    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(4);
    insertNode(5);
    display();
    getLength();
    deleteSelectedItem();
    display();
    serachItem(2);
    serachItem(5);
    deleteSelectedItem(2);
    deleteSelectedItem(0);
    display();
    deleteSelectedItem(4);
    display();
    getLength();
    cout << list->link->link->link->link->data << endl;
}
