#include <iostream>
#include <sstream>

#include "priorityQueueLL.h"

using namespace std;

PriorityQueue::PriorityQueue(){

}

PriorityQueue::PriorityQueue(string inName, int inTimeToDelivery, int inTreatmentTime){
	Patient *newp = new Patient(inName, inTimeToDelivery, inTreatmentTime);
	head = newp;

}

PriorityQueue::~PriorityQueue(){

}

void PriorityQueue::enqueuePatient(string newPatient){

	Patient *p = new Patient();

	stringstream ss(newPatient);
	string line;
	string name;
	int timeToDelivery;
	int treatmentTime;
	int count = 1;

	while(getline(ss, line, ',')){
		if(count == 1){
			p->name = line;
			name = line;
		}
		else if(count == 2){
			p->timeToDelivery = stoi(line);
			timeToDelivery = stoi(line);
		}
		else if(count == 3){
			p->treatmentTime = stoi(line);
			treatmentTime = stoi(line);
		}
		count++;
	}

	p->next = NULL;
	p->previous = NULL;

	if(head ==  NULL){
		head = new Patient(name, timeToDelivery, treatmentTime);
	}
	else{
		Patient *tmp = new Patient();
		tmp = head;
		bool run = true;
		while(run){
			if(tmp->timeToDelivery < p->timeToDelivery){
				if(tmp->next != NULL){
					tmp = tmp->next;
				}
				else{
					tmp->next = p;
					p->previous = tmp;
					run = false;
				}
			}
			else if(tmp->timeToDelivery == p->timeToDelivery){
				if(tmp->treatmentTime < p->treatmentTime && tmp->next->timeToDelivery != p->timeToDelivery){
					p->next = tmp->next;
					p->previous = tmp;
					tmp->next->previous = p;
					tmp->next = p;
					run = false; //exit loop, patient added
				}
				else if(tmp->treatmentTime > p->treatmentTime){
					p->next = tmp;
					p->previous = tmp->previous;
					if(tmp!=head){
						tmp->previous->next = p;
					}
					else{
						head = p;
					}
					tmp->previous = p;
					run = false; //exit loop, patient added
				}
				else if(tmp->treatmentTime == p->treatmentTime){
					p->next = tmp;
					p->previous = tmp->previous;
					tmp->previous->next = p;
					tmp->previous = p;
					run = false;
				}
				else if(tmp->treatmentTime < p->treatmentTime && tmp->next->timeToDelivery == p->timeToDelivery){
					tmp = tmp->next;
				}
			}
			else{
				if(tmp == head && p->timeToDelivery < tmp->timeToDelivery){
					tmp->previous = p;
					p->next = tmp;
					head = p;
					run = false; //exit loop, patient added
				}
				else{
					tmp->previous->next = p;
					p->previous = tmp->previous;
					p->next = tmp;
					tmp->previous = p;
					run = false;
				}
			}
		}
	}
}


void PriorityQueue::dequeuePatient(){
	//dequeues a single patient, with the top priority
	Patient *tmp = new Patient();
	tmp = head;
	head = tmp->next;
	cout<<"Dequeued: "<<tmp->name<<", Priority: "<<tmp->timeToDelivery<<", Treatment: "<<tmp->treatmentTime<<endl;
	tmp->next = NULL;
	head->previous = NULL;
	delete tmp;
}


void PriorityQueue::dequeueList(int size){
	int counter = 1;
	Patient *tmp = new Patient;
	tmp = head;
	while(counter < size){
		tmp = head;
		cout<<counter<<":	"<<tmp->name<<",  "<<tmp->timeToDelivery<<",  "<<tmp->treatmentTime<<endl;
		head = head->next;
		head->previous = NULL;
		tmp->next = NULL;
		delete tmp;
		counter++;
	}
	cout<<counter<<":	"<<head->name<<",  "<<head->timeToDelivery<<",  "<<head->treatmentTime<<endl;
	delete head;
	head = NULL;
}
