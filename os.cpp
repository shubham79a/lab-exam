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
// #include <iostream>
// #include <queue>
// #include <vector>
// #include <algorithm>
// using namespace std;
// struct Process {
//     int id;
//     int at;
//     int bt;
//     int rem_bt;
//     int tat;
//     int wt;
//     int completion_time;
// };
// struct GanttSegment {
//     int process_id;
//     int start_time;
//     int end_time;
// };
// void printGanttChart(vector<GanttSegment> &gantt) {
//     cout << "\n\n========== GANTT CHART ==========\n";
//     cout << " ";
//     for(size_t i = 0; i < gantt.size(); i++) {
//         cout << "--------";
//     }
//     cout << "\n|";
//     for(size_t i = 0; i < gantt.size(); i++) {
//         cout << "  P" << gantt[i].process_id << "   |";
//     }
//     cout << "\n ";
//     for(size_t i = 0; i < gantt.size(); i++) {
//         cout << "--------";
//     }
//     cout << "\n";
//     cout << gantt[0].start_time;
//     for(size_t i = 0; i < gantt.size(); i++) {
//         int time = gantt[i].end_time;
//         if(time < 10) cout << "       " << time;
//         else cout << "      " << time;
//     }
//     cout << "\n=================================\n";
// }
// void printOutput(Process p[], int n) {
//     cout << "\nID\tAT\tBT\tCT\tTAT\tWT\n";
//     cout << "--------------------------------------------------\n";
//     float totalTAT = 0, totalWT = 0;
//     for(int i = 0; i < n; i++) {
//         cout << p[i].id << "\t" 
//              << p[i].at << "\t" 
//              << p[i].bt << "\t" 
//              << p[i].completion_time << "\t"
//              << p[i].tat << "\t" 
//              << p[i].wt << endl;
//         totalTAT += p[i].tat;
//         totalWT += p[i].wt;
//     }
//     cout << "\nAvg TAT: " << totalTAT/n;
//     cout << "\nAvg WT: " << totalWT/n << endl;
// }
// int main() {
//     int n, tq;
//     cout << "Enter number of processes: ";
//     cin >> n;
//     Process p[10];
//     bool visited[10] = {false};
//     for(int i = 0; i < n; i++) {
//         p[i].id = i + 1;
//         cout << "Enter Arrival and Burst Time for P" << i+1 << ": ";
//         cin >> p[i].at >> p[i].bt;
//         p[i].rem_bt = p[i].bt;
//     }
//     sort(p, p + n, [](Process a, Process b) {
//         return a.at < b.at;
//     });
//     cout << "Enter Time Quantum: ";
//     cin >> tq;
//     queue<int> q;
//     vector<GanttSegment> gantt;
//     int current_time = 0;
//     int completed = 0;
//     for(int i=0; i<n; i++){
//         if(p[i].at <= current_time && !visited[i]){
//             q.push(i);
//             visited[i] = true;
//         }
//     }
//     while(completed < n) {
//         if(q.empty()) {
//             current_time++;
//             for(int i=0; i<n; i++){
//                 if(p[i].at <= current_time && !visited[i]){
//                     q.push(i);
//                     visited[i] = true;
//                 }
//             }
//             continue;
//         }
//         int idx = q.front();
//         q.pop();
//         int exec_time;
//         if(p[idx].rem_bt > tq) {
//             exec_time = tq;
//         } else {
//             exec_time = p[idx].rem_bt;
//         }
//         gantt.push_back({p[idx].id, current_time, current_time + exec_time});
//         p[idx].rem_bt -= exec_time;
//         current_time += exec_time;
//         for(int i = 0; i < n; i++) {
//             if(p[i].at <= current_time && p[i].rem_bt > 0 && !visited[i]) {
//                 q.push(i);
//                 visited[i] = true;
//             }
//         }
//         if(p[idx].rem_bt > 0) {
//             q.push(idx);
//         } else {
//             completed++;
//             p[idx].completion_time = current_time;
//             p[idx].tat = p[idx].completion_time - p[idx].at;
//             p[idx].wt = p[idx].tat - p[idx].bt;
//         }
//     }
//     printGanttChart(gantt);
//     printOutput(p, n);
//     return 0;
// }


// // 3 
// // 0 5
// // 1 4
// // 2 2
// // 2





// // // Banker's Algorithm Implementation
// #include <iostream>
// #include <vector>
// using namespace std;
// int n, m;
// vector<vector<int>> alloc;
// vector<vector<int>> max_res;
// vector<vector<int>> need;
// vector<int> avail;
// vector<int> safeSequence;
// vector<bool> visited;
// int totalSequences = 0;
// void findSafeSequences(vector<int>& currentAvail) {
//     if (safeSequence.size() == n) {
//         totalSequences++;
//         cout << "Safe Sequence " << totalSequences << ": ";
//         for (int i = 0; i < n; i++) {
//             cout << "P" << safeSequence[i] + 1;
//             if (i != n - 1) cout << " -> ";
//         }
//         cout << endl;
//         return;
//     }
//     for (int i = 0; i < n; i++) {
//         if (!visited[i]) {
//             bool canExecute = true;
//             for (int j = 0; j < m; j++) {
//                 if (need[i][j] > currentAvail[j]) {
//                     canExecute = false;
//                     break;
//                 }
//             }
//             if (canExecute) {
//                 visited[i] = true;
//                 safeSequence.push_back(i);
//                 for (int j = 0; j < m; j++) {
//                     currentAvail[j] += alloc[i][j];
//                 }
//                 findSafeSequences(currentAvail);
//                 for (int j = 0; j < m; j++) {
//                     currentAvail[j] -= alloc[i][j];
//                 }
//                 visited[i] = false;
//                 safeSequence.pop_back();
//             }
//         }
//     }
// }
// int main() {
//     cout << "Enter number of processes: ";
//     cin >> n;
//     cout << "Enter number of resource types: ";
//     cin >> m;
//     alloc.resize(n, vector<int>(m));
//     max_res.resize(n, vector<int>(m));
//     need.resize(n, vector<int>(m));
//     avail.resize(m);
//     visited.resize(n, false);
//     cout << "Enter Allocation Matrix:\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) cin >> alloc[i][j];
//     }
//     cout << "Enter Max Matrix:\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) cin >> max_res[i][j];
//     }
//     cout << "Enter Available Resources:\n";
//     for (int j = 0; j < m; j++) cin >> avail[j];
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             need[i][j] = max_res[i][j] - alloc[i][j];
//         }
//     }
//     cout << "\n--- All Possible Safe Sequences ---\n";
//     vector<int> currentAvail = avail;
//     findSafeSequences(currentAvail);
//     if (totalSequences == 0) {
//         cout << "No safe sequence found (Deadlock)." << endl;
//     }
//     return 0;
// }

// // // Process,Allocation (A B C),Max (A B C)
// // // 5 3
// // // P1, 0 1 0, 7 5 3
// // // P2, 2 0 0, 3 2 2
// // // P3, 3 0 2, 9 0 2
// // // P4, 2 1 1, 2 2 2
// // // P5, 0 0 2, 4 3 3
// // // 3 3 2






// // // FIFO Page Replacement Algorithm Implementation
// #include <iostream>
// #include <vector>
// using namespace std;
// bool isPagePresent(vector<int>& frames, int page) {
//     for(int i = 0; i < frames.size(); i++) {
//         if(frames[i] == page)
//             return true;
//     }
//     return false;
// }
// void printFrames(vector<int>& frames) {
//     for(int i = 0; i < frames.size(); i++) {
//         if(frames[i] == -1) 
//             cout << "- ";
//         else 
//             cout << frames[i] << " ";
//     }
//     cout << endl;
// }
// int main() {
//     int n, f_count;
//     cout << "Enter number of pages in reference string: ";
//     cin >> n;
//     cout << "Enter number of frames: ";
//     cin >> f_count;
//     vector<int> pages(n);
//     cout << "Enter the reference string (space separated): ";
//     for(int i = 0; i < n; i++) {
//         cin >> pages[i];
//     }
//     vector<int> frames(f_count, -1);
//     int pageFaults = 0;
//     int k = 0;
//     cout << "\nRef\tFrames Status\t\tStatus\n";
//     cout << "----------------------------------------\n";
//     for(int i = 0; i < n; i++) {
//         cout << pages[i] << "\t";
//         if(isPagePresent(frames, pages[i])) {
//             printFrames(frames);
//         } 
//         else {
//             frames[k] = pages[i];
//             k = (k + 1) % f_count;
//             pageFaults++;
//             printFrames(frames);
//         }
//     }
//     cout << "\n----------------------------------------\n";
//     cout << "Total Page Faults: " << pageFaults << endl;
//     cout << "Total Page Hits: " << n - pageFaults << endl;
//     return 0;
// }

// // 8
// // 3
// // 7 0 1 2 0 3 0 4 
 





// // // LRU Page Replacement Algorithm Implementation
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     int n, f_count;
//     cout << "Enter number of pages: ";
//     cin >> n;
//     cout << "Enter number of frames: ";
//     cin >> f_count;
//     vector<int> pages(n);
//     cout << "Enter reference string: ";
//     for(int i = 0; i < n; i++) {
//         cin >> pages[i];
//     }
//     vector<int> frames(f_count, -1);
//     vector<int> time(f_count, -1);
//     int pageFaults = 0;
//     cout << "\nRef\tFrames Status\t\tStatus\n";
//     cout << "----------------------------------------\n";
//     for(int i = 0; i < n; i++) {
//         bool hit = false;
//         for(int j = 0; j < f_count; j++) {
//             if(frames[j] == pages[i]) {
//                 hit = true;
//                 time[j] = i;
//                 break;
//             }
//         }
//         if(!hit) {
//             bool foundEmpty = false;
//             for(int j = 0; j < f_count; j++) {
//                 if(frames[j] == -1) {
//                     frames[j] = pages[i];
//                     time[j] = i;
//                     foundEmpty = true;
//                     pageFaults++;
//                     break;
//                 }
//             }
//             if(!foundEmpty) {
//                 int lru_idx = 0;
//                 int min_time = 99999;
//                 for(int j = 0; j < f_count; j++) {
//                     if(time[j] < min_time) {
//                         min_time = time[j];
//                         lru_idx = j;
//                     }
//                 }
//                 frames[lru_idx] = pages[i];
//                 time[lru_idx] = i;
//                 pageFaults++;
//             }
//         }
//         cout << pages[i] << "\t";
//         for(int j = 0; j < f_count; j++) {
//             if(frames[j] == -1) cout << "- ";
//             else cout << frames[j] << " ";
//         }
//         if(hit) cout << "\tHIT";
//         else cout << "\tMISS";
//         cout << endl;
//     }
//     cout << "\n----------------------------------------\n";
//     cout << "Total Page Faults: " << pageFaults << endl;
//     cout << "Total Page Hits: " << n - pageFaults << endl;
//     return 0;
// }

// // 8
// // 3
// // 7 0 1 2 0 3 0 4 






// // // MRU Page Replacement Algorithm Implementation
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n, f_count;
//     cout << "Enter number of pages: ";
//     cin >> n;
//     cout << "Enter number of frames: ";
//     cin >> f_count;
//     vector<int> pages(n);
//     cout << "Enter reference string: ";
//     for(int i = 0; i < n; i++) {
//         cin >> pages[i];
//     }
//     vector<int> frames(f_count, -1);
//     vector<int> time(f_count, -1);
//     int pageFaults = 0;
//     cout << "\nRef\tFrames Status\t\tStatus\n";
//     cout << "----------------------------------------\n";
//     for(int i = 0; i < n; i++) {
//         bool hit = false;
//         for(int j = 0; j < f_count; j++) {
//             if(frames[j] == pages[i]) {
//                 hit = true;
//                 time[j] = i;
//                 break;
//             }
//         }
//         if(!hit) {
//             bool foundEmpty = false;
//             for(int j = 0; j < f_count; j++) {
//                 if(frames[j] == -1) {
//                     frames[j] = pages[i];
//                     time[j] = i; 
//                     foundEmpty = true;
//                     pageFaults++;
//                     break;
//                 }
//             }
//             if(!foundEmpty) {
//                 int mru_idx = 0;
//                 int max_time = -1; 
//                 for(int j = 0; j < f_count; j++) {
//                     if(time[j] > max_time) {
//                         max_time = time[j];
//                         mru_idx = j;
//                     }
//                 }
//                 frames[mru_idx] = pages[i];
//                 time[mru_idx] = i;
//                 pageFaults++;
//             }
//         }
//         cout << pages[i] << "\t";
//         for(int j = 0; j < f_count; j++) {
//             if(frames[j] == -1) cout << "- ";
//             else cout << frames[j] << " ";
//         }
//         if(hit) cout << "\tHIT";
//         else cout << "\tMISS";
//         cout << endl;
//     }
//     cout << "\n----------------------------------------\n";
//     cout << "Total Page Faults: " << pageFaults << endl;
//     cout << "Total Page Hits: " << n - pageFaults << endl;
//     return 0;
// }


// // 8
// // 3
// // 7 0 1 2 0 3 0 4 






// // // Optimal Page Replacement Algorithm Implementation
// #include <iostream>
// #include <vector>
// using namespace std;
// bool search(int key, vector<int>& frames) {
//     for (int i = 0; i < frames.size(); i++)
//         if (frames[i] == key)
//             return true;
//     return false;
// }
// int predict(vector<int>& pages, vector<int>& frames, int n, int index) {
//     int res = -1, farthest = index;
//     for (int i = 0; i < frames.size(); i++) {
//         int j;
//         for (j = index; j < n; j++) {
//             if (frames[i] == pages[j]) {
//                 if (j > farthest) {
//                     farthest = j;
//                     res = i;
//                 }
//                 break;
//             }
//         }
//         if (j == n)
//             return i;
//     }
//     return (res == -1) ? 0 : res;
// }
// int main() {
//     int n, f_count;
//     cout << "Enter number of pages: ";
//     cin >> n;
//     cout << "Enter number of frames: ";
//     cin >> f_count;
//     vector<int> pages(n);
//     cout << "Enter reference string: ";
//     for(int i = 0; i < n; i++) {
//         cin >> pages[i];
//     }
//     vector<int> frames; 
//     int pageFaults = 0;
//     cout << "\nRef\tFrames Status\t\tStatus\n";
//     cout << "----------------------------------------\n";
//     for (int i = 0; i < n; i++) {
//         cout << pages[i] << "\t";
//         if (search(pages[i], frames)) {
//             for(int x : frames) cout << x << " ";
//             for(int k=frames.size(); k<f_count; k++) cout << "- ";
//             cout << "\tHIT" << endl;
//             continue;
//         }
//         pageFaults++;
//         if (frames.size() < f_count) {
//             frames.push_back(pages[i]);
//         }
//         else {
//             int j = predict(pages, frames, n, i + 1);
//             frames[j] = pages[i];
//         }
//         for(int x : frames) cout << x << " ";
//         for(int k=frames.size(); k<f_count; k++) cout << "- ";
//         cout << "\tMISS" << endl;
//     }
//     cout << "\n----------------------------------------\n";
//     cout << "Total Page Faults: " << pageFaults << endl;
//     cout << "Total Page Hits: " << n - pageFaults << endl;
//     return 0;
// }

// // 8
// // 3
// // 7 0 1 2 0 3 0 4 