#include<iostream>
using namespace std;
#include<conio.h>



class Process{
	int arraival_time,Brust_time;
	int completion_time,tat;
	int waiting_time;
	int priority;
	
	public:
		static int time;
	void input(int,int);
	void static c_time(Process []);
	void  static output(Process []);
	void static p_time(Process []);
			 
};
