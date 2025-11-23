#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int time_to_minutes(int h, int m) {
    if (h == 24 && m == 0) return 1440;
    return h * 60 + m;
}

struct Patient {
    string name;
    string doctor;
    int appointment_time;
    int booking_time;
    int registration_time;
    bool is_late;
};

string encode_name(const string &name) {
    if (name.length() <= 2) {
        return name;
    }
    string encoded = name.substr(0, 1);
    encoded += string(name.length() - 2, '*');
    encoded += name.back();
    return encoded;
}

void solve() {
    string event_type;
    int now_h, now_m;

    map<string, Patient> appointments;
    map<string, vector<Patient> > doctor_queues;
    set<string> registered_patients;

    int T;
    cin >> T;
    while (T--) {
        cin >> now_h >> now_m >> event_type;
        int now_time = time_to_minutes(now_h, now_m);

        if (event_type == "appointment") {
            string patient_name, doctor_name;
            int treat_h, treat_m;
            cin >> patient_name >> doctor_name >> treat_h >> treat_m;
            int treatment_time = time_to_minutes(treat_h, treat_m);
            appointments[patient_name] = {patient_name, doctor_name, treatment_time, now_time, 0, false};
        } else if (event_type == "register") {
            string patient_name;
            cin >> patient_name;

            if (registered_patients.count(patient_name)) {
                cout << "Fail" << endl;
                continue;
            }

            if (appointments.count(patient_name) == 0) {
                cout << "Fail" << endl;
                continue;
            }

            Patient p = appointments[patient_name];
            if (now_time < p.appointment_time - 60) {
                cout << "Fail" << endl;
                continue;
            }

            cout << "Success" << endl;
            p.registration_time = now_time;
            p.is_late = (now_time > p.appointment_time);

            doctor_queues[p.doctor].push_back(p);
            appointments.erase(patient_name);
            registered_patients.insert(patient_name);
        } else if (event_type == "query") {
            string doctor_name;
            cin >> doctor_name;

            if (doctor_queues.count(doctor_name) == 0 || doctor_queues[doctor_name].empty()) {
                cout << "No patient" << endl;
            } else {
                vector<Patient> not_late_queue;
                vector<Patient> late_queue;
                for (size_t i = 0; i < doctor_queues[doctor_name].size(); ++i) {
                    Patient p = doctor_queues[doctor_name][i];
                    if (p.is_late) {
                        late_queue.push_back(p);
                    } else {
                        not_late_queue.push_back(p);
                    }
                }

                sort(not_late_queue.begin(), not_late_queue.end(),
                     [](const Patient &a, const Patient &b) {
                         if (a.appointment_time != b.appointment_time) {
                             return a.appointment_time < b.appointment_time;
                         }
                         return a.booking_time < b.booking_time;
                     });

                sort(late_queue.begin(), late_queue.end(),
                     [](const Patient &a, const Patient &b) {
                         return a.registration_time < b.registration_time;
                     });

                doctor_queues[doctor_name].clear();
                for (size_t i = 0; i < not_late_queue.size(); ++i) {
                    doctor_queues[doctor_name].push_back(not_late_queue[i]);
                }
                for (size_t i = 0; i < late_queue.size(); ++i) {
                    doctor_queues[doctor_name].push_back(late_queue[i]);
                }

                Patient next_patient = doctor_queues[doctor_name][0];
                cout << encode_name(next_patient.name) << endl;

                vector<Patient> new_queue;
                for (size_t i = 1; i < doctor_queues[doctor_name].size(); ++i) {
                    new_queue.push_back(doctor_queues[doctor_name][i]);
                }
                doctor_queues[doctor_name] = new_queue;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}