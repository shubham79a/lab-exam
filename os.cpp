// // // First Come First Serve (FCFS) Scheduling Algorithm Implementation
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// struct Process {
//     int id;
//     int at;
//     int bt;
//     int ct;
//     int tat;
//     int wt;
// };
// // External function to handle printing
// void printOutput(vector<Process>& p, int n) {
//     cout << "\nID\tAT\tBT\tCT\tTAT\tWT\n";
//     cout << "--------------------------------------------------\n";
//     float totalTAT = 0, totalWT = 0;
//     for(int i = 0; i < n; i++) {
//         cout << p[i].id << "\t" 
//              << p[i].at << "\t" 
//              << p[i].bt << "\t" 
//              << p[i].ct << "\t" 
//              << p[i].tat << "\t" 
//              << p[i].wt << endl;
//         totalTAT += p[i].tat;
//         totalWT += p[i].wt;
//     }
//     cout << "\nAvg TAT: " << totalTAT / n;
//     cout << "\nAvg WT: " << totalWT / n << endl;
// }
// bool compare(Process a, Process b) {
//     return a.at < b.at;
// }
// int main() {
//     int n;
//     cout << "Enter number of processes: ";
//     cin >> n;

//     vector<Process> p(n);
//     for(int i = 0; i < n; i++) {
//         p[i].id = i + 1;
//         cout << "Enter Arrival Time and Burst Time for P" << i + 1 << ": ";
//         cin >> p[i].at >> p[i].bt;
//     }
//     sort(p.begin(), p.end(), compare);

//     int currentTime = 0;
//     for(int i = 0; i < n; i++) {
//         if(currentTime < p[i].at) {
//             currentTime = p[i].at;
//         }
//         p[i].ct = currentTime + p[i].bt;
//         p[i].tat = p[i].ct - p[i].at;
//         p[i].wt = p[i].tat - p[i].bt;
//         currentTime = p[i].ct;
//     }
//     printOutput(p, n);
//     return 0;
// }

// 5
// 0 5
// 1 4
// 2 2
// 3 1
// 5 3
// Expected Output: 






// // // Shortest Job First (SJF) Scheduling Algorithm Implementation (Non-Preemptive)
// #include <iostream>
// using namespace std;

// struct Process {
//     int id;
//     int at;
//     int bt;
//     int ct;
//     int tat;
//     int wt;
// };
// // External function to handle printing
// void printOutput(Process p[], int n) {
//     cout << "\nID\tAT\tBT\tCT\tTAT\tWT\n";
//     cout << "--------------------------------------------------\n";
//     float totalTAT = 0, totalWT = 0;
//     for(int i = 0; i < n; i++) {
//         cout << p[i].id << "\t" 
//              << p[i].at << "\t" 
//              << p[i].bt << "\t" 
//              << p[i].ct << "\t" 
//              << p[i].tat << "\t" 
//              << p[i].wt << endl;
//         totalTAT += p[i].tat;
//         totalWT += p[i].wt;
//     }
//     cout << "\nAvg TAT: " << totalTAT/n;
//     cout << "\nAvg WT: " << totalWT/n << endl;
// }
// int main() {
//     int n;
//     cout << "Enter number of processes: ";
//     cin >> n;
//     Process p[10];
//     int completed[10] = {0};
//     for(int i = 0; i < n; i++) {
//         p[i].id = i + 1;
//         cout << "Enter Arrival and Burst Time for P" << i+1 << ": ";
//         cin >> p[i].at >> p[i].bt;
//     }
//     int currentTime = 0;
//     int count = 0;
//     while(count < n) {
//         int idx = -1;
//         int minBT = 9999;
//         for(int i = 0; i < n; i++) {
//             if(p[i].at <= currentTime && completed[i] == 0) {
//                 if(p[i].bt < minBT) {
//                     minBT = p[i].bt;
//                     idx = i;
//                 }
//             }
//         }
//         if(idx != -1) {
//             p[idx].ct = currentTime + p[idx].bt;
//             p[idx].tat = p[idx].ct - p[idx].at;
//             p[idx].wt = p[idx].tat - p[idx].bt;
//             completed[idx] = 1;
//             count++;
//             currentTime = p[idx].ct;
//         } else {
//             currentTime++;
//         }
//     }
//     printOutput(p, n);
//     return 0;
// }
// Sample Input:
// Enter number of processes: 4
// Enter Arrival and Burst Time for P1: 0 8
// Enter Arrival and Burst Time for P2: 1 4
// Enter Arrival and Burst Time for P3: 2 9
// Enter Arrival and Burst Time for P4: 3 5






// // //  Shortest Remaining Time First (SRTF) Scheduling Algorithm Implementation (Preemptive)
// #include <iostream>
// using namespace std;
// struct Process {
//     int id;
//     int at;
//     int bt;
//     int rt;
//     int ct;
//     int tat;
//     int wt;
// };
// void printOutput(Process p[], int n) {
//     cout << "\nID\tAT\tBT\tCT\tTAT\tWT\n";
//     cout << "--------------------------------------------------\n";
//     float totalTAT = 0, totalWT = 0;
//     for(int i = 0; i < n; i++) {
//         cout << p[i].id << "\t" 
//              << p[i].at << "\t" 
//              << p[i].bt << "\t" 
//              << p[i].ct << "\t" 
//              << p[i].tat << "\t" 
//              << p[i].wt << endl;
//         totalTAT += p[i].tat;
//         totalWT += p[i].wt;
//     }
//     cout << "\nAvg TAT: " << totalTAT/n;
//     cout << "\nAvg WT: " << totalWT/n << endl;
// }
// int main() {
//     int n;
//     cout << "Enter number of processes: ";
//     cin >> n;
//     Process p[10];
//     int completed = 0;
//     for(int i = 0; i < n; i++) {
//         p[i].id = i + 1;
//         cout << "Enter Arrival and Burst Time for P" << i+1 << ": ";
//         cin >> p[i].at >> p[i].bt;
//         p[i].rt = p[i].bt; 
//     }
//     int currentTime = 0;
//     int min_rt = 9999;
//     int shortest = -1;
//     bool check = false; 
//     while(completed != n) {
//         shortest = -1;
//         min_rt = 9999;
//         check = false;
//         for(int i = 0; i < n; i++) {
//             if(p[i].at <= currentTime && p[i].rt > 0) {
//                 if(p[i].rt < min_rt) {
//                     min_rt = p[i].rt;
//                     shortest = i;
//                     check = true;
//                 }
//             }
//         }
//         if(check == false) {
//             currentTime++;
//             continue;
//         }
//         p[shortest].rt--;
//         currentTime++;           
//         if(p[shortest].rt == 0) {
//             completed++;
//             p[shortest].ct = currentTime;
//             p[shortest].tat = p[shortest].ct - p[shortest].at;
//             p[shortest].wt = p[shortest].tat - p[shortest].bt;
//         }
//     }
//     printOutput(p, n);
//     return 0;
// }


// // Enter number of processes: 4
// // Enter Arrival and Burst Time for P1: 0 8
// // Enter Arrival and Burst Time for P2: 1 4
// // Enter Arrival and Burst Time for P3: 2 2
// // Enter Arrival and Burst Time for P4: 3 1
// //  ID	AT	BT	CT	TAT	WT
// // --------------------------------------------------





// // // Priority Scheduling Algorithm Implementation (Non-Preemptive)
// #include <iostream>
// using namespace std;

// struct Process {
//     int id;
//     int at; 
//     int bt; 
//     int pri;
//     int ct;
//     int tat; 
//     int wt;  
// };
// void printOutput(Process p[], int n) {
//     cout << "\nID\tAT\tBT\tPri\tCT\tTAT\tWT\n";
//     cout << "--------------------------------------------------------\n";
//     float totalTAT = 0, totalWT = 0;
//     for(int i = 0; i < n; i++) {
//         cout << p[i].id << "\t" 
//              << p[i].at << "\t" 
//              << p[i].bt << "\t" 
//              << p[i].pri << "\t" 
//              << p[i].ct << "\t" 
//              << p[i].tat << "\t" 
//              << p[i].wt << endl;
//         totalTAT += p[i].tat;
//         totalWT += p[i].wt;
//     }
//     cout << "\nAvg TAT: " << totalTAT/n;
//     cout << "\nAvg WT: " << totalWT/n << endl;
// }
// int main() {
//     int n;
//     cout << "Enter number of processes: ";
//     cin >> n;
//     Process p[10];
//     int completed[10] = {0}; 
//     for(int i = 0; i < n; i++) {
//         p[i].id = i + 1;
//         cout << "Enter Arrival, Burst, and Priority for P" << i+1 << ": ";
//         cin >> p[i].at >> p[i].bt >> p[i].pri;
//     }
//     int currentTime = 0;
//     int count = 0;
//     while(count < n) {
//         int idx = -1;
//         int bestPri = 9999; 
//         for(int i = 0; i < n; i++) {
//             if(p[i].at <= currentTime && completed[i] == 0) {
//                 if(p[i].pri < bestPri) { 
//                     bestPri = p[i].pri;
//                     idx = i;
//                 }
//                 else if(p[i].pri == bestPri) {
//                     if(p[i].at < p[idx].at) {
//                         idx = i;
//                     }
//                 }
//             }
//         }
//         if(idx != -1) {
//             p[idx].ct = currentTime + p[idx].bt;
//             p[idx].tat = p[idx].ct - p[idx].at;
//             p[idx].wt = p[idx].tat - p[idx].bt;
//             completed[idx] = 1;
//             count++;
//             currentTime = p[idx].ct;
//         } else {
//             currentTime++;
//         }
//     }
//     printOutput(p, n);
//     return 0;
// }

// // Enter number of processes: 4
// // Enter Arrival, Burst, and Priority for P1: 0 5 10
// // Enter Arrival, Burst, and Priority for P2: 1 4 20
// // Enter Arrival, Burst, and Priority for P3: 2 2 10
// // Enter Arrival, Burst, and Priority for P4: 3 1 5





// // // Round Robin (RR) Scheduling Algorithm Implementation
