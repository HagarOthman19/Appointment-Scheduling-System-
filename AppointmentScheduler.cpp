// final project edit.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

struct Appointment {
    int id;
    string date;
    string time;
    string description;
    int duration;
    string participants;
};

class AppointmentScheduler {
private:
    list<Appointment> appointments;
public:
    void addAppointment();
    void viewAppointmentsByDay();
    void editAppointment();
    void cancelAppointment();
    void searchAppointments();
    void generateReport();
    void loadAppointmentsFromFile(const string& filename);
    void saveAppointmentsToFile(const string& filename);
};

int main() {
    AppointmentScheduler scheduler;
    scheduler.loadAppointmentsFromFile("C:\\Users\\Sherif\\Desktop\\Computer Programming Final Project\\Programming Final Project Test Data.txt");

    // Example usage:
    int choice;
    do {
        cout << "\nAppointment Scheduler\n"
            << "1. Add appointment\n"
            << "2. View appointments by day\n"
            << "3. Edit appointment\n"
            << "4. Cancel appointment\n"
            << "5. Search appointments\n"
            << "6. Generate report\n"
            << "7. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            scheduler.addAppointment();
            break;
        case 2:
            scheduler.viewAppointmentsByDay();
            break;
        case 3:
            scheduler.editAppointment();
            break;
        case 4:
            scheduler.cancelAppointment();
            break;
        case 5:
            scheduler.searchAppointments();
            break;
        case 6:
            scheduler.generateReport();
            break;
        case 7:
            scheduler.saveAppointmentsToFile("C:\\Users\\Sherif\\Desktop\\Computer Programming Final Project\\Programming Final Project Test Data.txt");
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

void AppointmentScheduler::addAppointment() {
    Appointment appointment;
    cout << "Enter appointment ID: ";
    cin >> appointment.id;
    cout << "Enter appointment date (dd/mm/yyyy): ";
    cin >> appointment.date;
    cout << "Enter appointment time: ";
    cin >> appointment.time;
    cout << "Enter appointment description: ";
    cin.ignore();
    getline(cin, appointment.description);
    cout << "Enter appointment duration (in minutes): ";
    cin >> appointment.duration;
    cout << "Enter appointment participants (separated by commas): ";
    cin.ignore();
    getline(cin, appointment.participants);

    appointments.push_back(appointment);
}

void AppointmentScheduler::viewAppointmentsByDay() {
    string day;
    cout << "Enter the day to view appointments (dd/mm/yyyy): ";
    cin >> day;

    cout << "Appointments for " << day << ":\n";
    for (const Appointment& appointment : appointments) {
        if (appointment.date == day) {
            cout << "ID: " << appointment.id << ", Date: " << appointment.date << ", Time: " << appointment.time
                << ", Description: " << appointment.description << ", Duration: " << appointment.duration << " minutes, Participants: " << appointment.participants << "\n";
        }
    }
}

void AppointmentScheduler::editAppointment() {
    int id;
    cout << "Enter the ID of the appointment to edit: ";
    cin >> id;

    auto it = find_if(appointments.begin(), appointments.end(), [id](const Appointment& a) { return a.id == id; });
    if (it != appointments.end()) {
        cout << "Enter choice: 1 (Date), 2 (Time), 3 (Description), 4 (Duration), 5 (Participants): ";
        int choiceEdit;
        cin >> choiceEdit;

        switch (choiceEdit) {
        case 1:
            cout << "Enter new appointment date (dd/mm/yyyy): ";
            cin >> it->date;
            break;
        case 2:
            cout << "Enter new appointment time: ";
            cin >> it->time;
            break;
        case 3:
            cout << "Enter new appointment description: ";
            cin.ignore();
            getline(cin, it->description);
            break;
        case 4:
            cout << "Enter new appointment duration (in minutes): ";
            cin >> it->duration;
            break;
        case 5:
            cout << "Enter new appointment participants (separated by commas): ";
            cin.ignore();
            getline(cin, it->participants);
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
    else {
        cout << "Appointment with ID " << id << " not found.\n";
    }
}

void AppointmentScheduler::cancelAppointment() {
    int id;
    cout << "Enter the ID of the appointment to cancel: ";
    cin >> id;

    auto it = find_if(appointments.begin(), appointments.end(), [id](const Appointment& a) { return a.id == id; });
    if (it != appointments.end()) {
        appointments.erase(it);
        cout << "Appointment cancelled.\n";
    }
    else {
        cout << "Appointment with ID " << id << " not found.\n";
    }
}

void AppointmentScheduler::searchAppointments() {
    string date, participants, description;
    int choiceSearch;
    cout << "Enter either choice: 1 ( date (dd/mm/yyyy) ), 2 (name of participants) , or 3 (description of appointment): ";
    cin >> choiceSearch;
    switch (choiceSearch) {
    case 1:
        cout << "Enter date (dd/mm/yyyy): ";
        cin >> date;
        cout << "Appointments for " << date << ":\n";
        for (const Appointment& appointment : appointments) {
            if (appointment.date == date) {
                cout << "ID: " << appointment.id << ", Date: " << appointment.date << ", Time: " << appointment.time
                    << ", Description: " << appointment.description << ", Duration: " << appointment.duration << " minutes, Participants: " << appointment.participants << "\n";
            }
        }
        break;
    case 2:
        cout << "Enter particpants name: ";
        cin.ignore();
        getline(cin, participants);
        cout << "Appointments for " << participants << ":\n";
        for (const Appointment& appointment : appointments) {
            if (appointment.participants == participants) {
                cout << "ID: " << appointment.id << ", Date: " << appointment.date << ", Time: " << appointment.time
                    << ", Description: " << appointment.description << ", Duration: " << appointment.duration << " minutes, Participants: " << appointment.participants << "\n";
            }
        }
        break;
    case 3:
        cout << "Enter description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Appointments for " << description << ":\n";
        for (const Appointment& appointment : appointments) {
            if (appointment.description == description) {
                cout << "ID: " << appointment.id << ", Date: " << appointment.date << ", Time: " << appointment.time
                    << ", Description: " << appointment.description << ", Duration: " << appointment.duration << " minutes, Participants: " << appointment.participants << "\n";
            }
        }
        break;
    }
}

void AppointmentScheduler::generateReport() {
    // Implement report generation logic here
    cout << "All appointments IDs:" << endl;
    for (const Appointment& appointment : appointments) {
        cout << appointment.id << endl;
    }

    cout << "All appointments dates:" << endl;
    for (const Appointment& appointment : appointments) {
        cout << "Appointment ID " << appointment.id << ": " << appointment.date << endl;
    }

    cout << "All appointments times:" << endl;
    for (const Appointment& appointment : appointments) {
        cout << "Appointment ID " << appointment.id << ": " << appointment.time << endl;
    }

    cout << "All appointments descriptions:" << endl;
    for (const Appointment& appointment : appointments) {
        cout << "Appointment ID " << appointment.id << ": " << appointment.description << endl;
    }

    cout << "All appointments durations:" << endl;
    for (const Appointment& appointment : appointments) {
        cout << "Appointment ID "<< appointment.id << ": " << appointment.duration << endl;
    }

    cout << "All appointments participants:" << endl;
    for (const Appointment& appointment : appointments) {
        cout << "Appointment ID " << appointment.id << ": " << appointment.participants << endl;
    }
}

void AppointmentScheduler::loadAppointmentsFromFile(const string& filename) {
    ifstream input(filename);
    if (!input) {
        cerr << "Error opening file.\n";
        return;
    }

    Appointment appointment;
    while (input >> appointment.id >> appointment.date >> appointment.time >> appointment.duration) {
        input.ignore();
        getline(input, appointment.description);
        getline(input, appointment.participants);
        appointments.push_back(appointment);
    }
}

void AppointmentScheduler::saveAppointmentsToFile(const string& filename) {
    ofstream output(filename);
    if (!output) {
        cerr << "Error opening file.\n";
        return;
    }

    for (const auto& appointment : appointments) {
        output << "ID: " << appointment.id << ' ' << "Date: " << appointment.date << ' ' << "Time: " << appointment.time << ' '
            << "Duration: " << appointment.duration << '\n' << "Description: " << appointment.description << '\n' << "participants: " << appointment.participants << '\n';
    }
}
