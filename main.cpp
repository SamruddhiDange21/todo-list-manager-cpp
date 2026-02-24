#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string task;
    Node* next;

    Node(string t) {  // Constructor
        task = t;
        next = NULL;
    }
};

class ToDoList {
    Node* head;

public:
    ToDoList() { head = NULL; }

    // Add at beginning
    void addAtBeginning(string t) {
        Node* newNode = new Node(t);
        newNode->next = head;
        head = newNode;
    }

    // Add at end
    void addAtEnd(string t) {
        Node* newNode = new Node(t);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Add at a specific position
    void addAtPosition(string t, int pos) {
        if (pos <= 1) {
            addAtBeginning(t);
            return;
        }
        Node* newNode = new Node(t);
        Node* temp = head;
        for (int i = 1; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            addAtEnd(t);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Display all tasks
    void displayTasks() {
        if (head == NULL) {
            cout << "No tasks in the list.\n";
            return;
        }
        Node* temp = head;
        int i = 1;
        while (temp != NULL) {
            cout << i++ << ". " << temp->task << endl;
            temp = temp->next;
        }
    }

    // Delete first task
    void deleteFirstTask() {
        if (head == NULL) {
            cout << "No task to delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete last task
    void deleteLastTask() {
        if (head == NULL) {
            cout << "No task to delete.\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // Delete task by position
    void deleteTaskByPosition(int pos) {
        if (head == NULL) {
            cout << "No task to delete.\n";
            return;
        }
        if (pos == 1) {
            deleteFirstTask();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Invalid position.\n";
            return;
            
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    // Search for a task
    void searchTask(string t) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->task == t) {
                cout << "Task found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Task not found.\n";
    }

    // Count number of tasks
    void countTasks() {
        Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "Total tasks: " << count << endl;
    }
};

int main() {
    ToDoList list;
    int choice, pos;
    string task;

    do {
        cout << "\n--- TO-DO LIST MANAGER ---\n";
        cout << "1. Add at Beginning\n2. Add at End\n3. Add at Position\n";
        cout << "4. Display Tasks\n5. Delete First Task\n6. Delete Last Task\n";
        cout << "7. Delete Task by Position\n8. Search Task\n9. Count Tasks\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                list.addAtBeginning(task);
                break;
            case 2:
                cout << "Enter task: ";
                getline(cin, task);
                list.addAtEnd(task);
                break;
            case 3:
                cout << "Enter position: ";
                cin >> pos;
                cin.ignore();
                cout << "Enter task: ";
                getline(cin, task);
                list.addAtPosition(task, pos);
                break;
            case 4:
                list.displayTasks();
                break;
            case 5:
                list.deleteFirstTask();
                break;
            case 6:
                list.deleteLastTask();
                break;
            case 7:
                cout << "Enter position to delete: ";
                cin >> pos;
                list.deleteTaskByPosition(pos);
                break;
            case 8:
                cout << "Enter task to search: ";
                getline(cin, task);
                list.searchTask(task);
                break;
            case 9:
                list.countTasks();
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 10);

    return 0;
}