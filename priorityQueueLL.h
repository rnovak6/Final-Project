#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>

using namespace std;

struct Patient{
	
	Patient(string inName, int inTimeToDelivery, int inTreatmentTime){
		name = inName;
		timeToDelivery = inTimeToDelivery;
		treatmentTime = inTreatmentTime;
		next = NULL;
		previous = NULL;
	}

	Patient(){

	}
	string name;
	int timeToDelivery;
	int treatmentTime;
	
	Patient *next;
	Patient *previous;

};

class PriorityQueue{
public:
	PriorityQueue();
	PriorityQueue(string, int, int);
	~PriorityQueue();
	void enqueuePatient(string);
	void dequeuePatient();
	void dequeueList(int);
private:
	Patient *head;
	Patient *tail;
};

#endif //PRIORITYQUEUE