#include <iostream>
#include <iostream>

using namespace std;

struct agent {
    int earnings;
    string name;
    agent *next;
};

typedef agent *agentCollection;

void addAgent(agentCollection &ac) {
    int newEarnings;
    string newName;

    cout << "Input new agent earnings\n";
    cin >> newEarnings;
    cout << "Input new agent name\n";
    cin >> newName;

    agent *newAgent = new agent;

    newAgent->earnings = newEarnings;
    newAgent->name = newName;
    newAgent->next = ac;
    ac = newAgent;
}

void displayList(agentCollection ac) {
    while (ac != NULL) {
        cout << "===================\n";
        cout << "NAME: " + ac->name + "\n";
        cout << "EARNINGS: " << ac->earnings << "\n";
        cout << "===================\n";
        ac = ac->next;
    }
}

double calculateAverage(agentCollection ac) {
    if (ac == NULL) return 0;
    int counter = 0;
    double sum = 0;
    while (ac != NULL) {
        sum += ac->earnings;
        counter++;
        ac = ac->next;
    }
    double average = sum / counter;
    return average;
}

void removeAgent(agentCollection &ac) {
    if (ac == NULL) cout << "Empty list";
    agent *temp = ac;
    ac = ac->next;
    cout << "DELETED: " << temp->name << "\n";
    delete temp;
    temp = NULL;
}

int main() {

    agentCollection ac = NULL;

    while (true) {
        int input;
        cout
                << " Press 1 to add agents\n Press 2 display agent list\n Press 3 to calculate average earnings\n Press 4 to delete most recently added Agent";
        cin >> input;

        switch (input) {
            case 1:
                addAgent(ac);
                break;
            case 2:
                displayList(ac);
                break;
            case 3:
                cout << "AVERAGE EARNINGS OF ALL AGENTS: " << calculateAverage(ac) << "\n";
                break;
            case 4:
                removeAgent(ac);
                break;
            default:
                cout << "Invalid number";
                break;
        }
    }
}


