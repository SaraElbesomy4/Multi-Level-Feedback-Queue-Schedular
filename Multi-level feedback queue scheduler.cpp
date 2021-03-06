// Multi-level feedback queue scheduler.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Assumptions:
// 1.The scheduler consists of two queues.
// 2.Processes in the first queue are scheduled using a round - robin scheduling algorithm.
// 3.Processes in the second queue are scheduled using a First - Come - First - Serve scheduling algorithm.
// 4.New Processes enter the scheduler at the first queue.If the process is not complete after 4 units, the process is demoted to the second queue.
// 5.No rules for promoting a process from second to first queue.
// 6.The execution of the second queue only begins when the first queue finish its execution.

#include "pch.h"
#include <iostream>
#include<stdio.h> 
using namespace std;



struct process
{
	int arrival_time = 0; 
	int burst_time_original = 0; 
	int burst_time = 0;
	int q_no = 0;
};




int main()
{
	int N = 0;   // total number of processes
	cout << "\nEnter the number of processes :";
	cin >> N;
	process P[10] = { 0 };
	for (int i = 0; i < N; i++)
	{
		cout << "\nImportant Note : The processes should be ascendingly sorted with the arrival time.";
		cout << "\nEnter the data of process (" << i + 1 << ") :";
		cout << "\nEnter the arrival time :";
		cin >> P[i].arrival_time;
		cout << "\nEnter the burst time :";
		cin >> P[i].burst_time_original;

		P[i].q_no = 1;
		P[i].burst_time = P[i].burst_time_original;   // to easily update

	}

	cout << "\n Solution : \n";
	cout << "\n Gantt Chart :";
	cout << " \nThe time index starts from 0";

	// Handling queue1 ( round-robin scheduling algorithm )
	int n = N;  // number of process ......> to easily update it
	int total_time = 0; // total time of execution
	int q = 2;  // time quantam
	int c = 0;  // flage to know that the process is executed
	int i = 0;   // interations index


	while (n != 0)
	{

		int completion[10] = { 0 };    // completion time for every unit

		if (P[i].burst_time <= ((P[i].burst_time_original) - (4 * q)))
		{
			P[i].q_no = 2;
			i++;
			n--;
		}
		else
		{
			if (P[i].q_no == 1)
			{
				if (P[i].burst_time <= q && P[i].burst_time > 0)
				{
					total_time = total_time + P[i].burst_time;
					P[i].burst_time = 0;
					c = 1;
					completion[i] = completion[i] + total_time;
					cout << " \nProcess (" << i + 1 << ")" << "--------> " << completion[i];
				}
				else if (P[i].burst_time > 0)
				{
					P[i].burst_time = P[i].burst_time - q;
					total_time = total_time + q;
					completion[i] = completion[i] + total_time;
					cout << " \nProcess (" << i + 1 << ")" << "--------> " << completion[i];
				}
				//.......
				if (P[i].burst_time == 0 && c == 1)  // Here the process is fully executed
				{
					n--;
					int wait_time = total_time - P[i].arrival_time - P[i].burst_time;
					c = 0;


				}
				//.....
				if (i == N - 1)  // the case of last process and return to the first one 
				{

					i = 0;


				}
				else if (P[i + 1].arrival_time <= total_time)    // the case in which it will forward to the next process   
				{
					i++;
				}
				else                     // return to the first process
				{
					i = 0;
				}
			}
		}
	}

	
	//........
	// Handeling FCFS
	//process  *temp[10] = { 0 };
	process *temp = P;
	
		if (n == 0)
		{
			for (int j = 0; j < N; j++)
			{
				int completion[10] = { 0 };    // completion time for every unit
				//cout << "\n............\n";
				//cout << "\n  " << temp[j].burst_time;
				//cout << "\n " << temp[j].q_no;
				if ( temp[j].q_no == 2)
				{ 
						total_time = total_time + temp[j].burst_time;
						completion[j] = completion[j] + total_time;
						cout << " \nProcess (" << j + 1 << ")" << "--------> " << completion[j];
				}

				
			}
		}



	
	
	
				
	

}

