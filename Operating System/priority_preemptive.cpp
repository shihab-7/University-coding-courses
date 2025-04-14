#include <bits/stdc++.h>
using namespace std;
struct Data
{
    string pid;
    int at, bt, priority, remaining, wt, tat, ct, rt;
};
struct GanttBlock
{
    string pid;
    int start, end;
};
void InputView(Data a[], int n)
{
    cout << "\nInputView : " << endl;
    cout << "----------------------------" << endl;
    cout << "| PID | AT | Priority | BT |\n";
    cout << "----------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << "| " << a[i].pid << "  | " << a[i].at << "  |   " << a[i].priority << "      | " << a[i].bt << "  |" << endl;
    }
    cout << "----------------------------\n";
}
void Calculate(Data a[], int n, vector<GanttBlock> &ganttChart)
{
    int time = 0, completed = 0;
    bool firstResponse[100] = {false};
    string lastExecuted = "";

    while (completed < n)
    {
        int shortest = -1;
        int minPriority = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (a[i].at <= time && a[i].remaining > 0 && a[i].priority < minPriority)
            {
                minPriority = a[i].priority;
                shortest = i;
            }
        }
        if (shortest == -1)
        {
            time++;
            continue;
        }
        if (!firstResponse[shortest])
        {
            a[shortest].rt = time - a[shortest].at;
            firstResponse[shortest] = true;
        }
        if (lastExecuted != a[shortest].pid)
            ganttChart.push_back({a[shortest].pid, time, time + 1});
        else
            ganttChart.back().end = time + 1;

        lastExecuted = a[shortest].pid;
        a[shortest].remaining--;
        time++;

        if (a[shortest].remaining == 0)
        {
            a[shortest].ct = time;
            a[shortest].tat = a[shortest].ct - a[shortest].at;
            a[shortest].wt = a[shortest].tat - a[shortest].bt;
            completed++;
        }
    }
}

void GanttChart(const vector<GanttBlock> &ganttChart)
{
    cout << "\nGantt Chart : \n";
    for (const auto &block : ganttChart)
    {
        cout << "| " << block.pid << " ";
    }
    cout << "|\n";
    for (const auto &block : ganttChart)
    {
        cout << block.start << "    ";
    }
    cout << ganttChart.back().end << endl;
}
void TablePrint(Data a[], int n)
{
    cout << "\n Preemptive Priority Scheduling Table view : \n";
    cout << "-------------------------------------------------------------------" << endl;
    cout << "| PID\t" << "| AT " << " | BT\t" << " | CT\t" << " | TAT\t" << " | WT\t" << " | RT\t| " << "Priority|" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    float total_wt = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "| " << a[i].pid << "    | " << a[i].at << "   | " << a[i].bt << "\t | " << a[i].ct
             << "\t | " << a[i].tat << "\t | " << a[i].wt << "\t | " << a[i].rt << "    | " << a[i].priority << " \t  |" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        total_wt += a[i].wt;
    }
    cout << fixed << setprecision(2) << "Average waiting time : " << (float)total_wt / n << " ms" << endl;
}

int main()
{
    int n;
    cout << "Enter number of processes : ";
    cin >> n;
    Data process[n];
    vector<GanttBlock> ganttChart;

    cout << "\nEnter process id(string), arrival time, priority, and burst time : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> process[i].pid >> process[i].at >> process[i].priority >> process[i].bt;
        process[i].remaining = process[i].bt;
    }

    InputView(process, n);
    Calculate(process, n, ganttChart);
    GanttChart(ganttChart);
    TablePrint(process, n);
    return 0;
}