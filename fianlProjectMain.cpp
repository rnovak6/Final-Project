#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>
#include <time.h>

//include all cpp files and csv data file
#include "priorityQueueLL.cpp"
#include "priorityQueueHeap.cpp"

using namespace std;

struct STLqueue{
	string name;
    int timeToDelivery;
    int treatmentTime;
    STLqueue(string inName, int inTimeToDelivery, int inTreatmentTime){
        name = inName;
        timeToDelivery = inTimeToDelivery;
        treatmentTime = inTreatmentTime;
    }
};

struct compare{
    bool operator()(const STLqueue &a, const STLqueue &b){
    	//if the time to delivery is equal then compare treatment time
    	if(a.timeToDelivery == b.timeToDelivery){
    		return a.treatmentTime > b.treatmentTime;
    	}
        return a.timeToDelivery > b.timeToDelivery;  //will return true or false
    }
};

void printMenu(){
	//display user menu
	cout<<endl;
	cout<<"1. Build LL Priority Queue"<<endl;
	cout<<"2. Build Heap Priority Queue"<<endl;
	cout<<"3. Build STL Priority Queue"<<endl;
	cout<<"4. Dequeue LL"<<endl;
	cout<<"5. Dequeue Entire LL"<<endl;
	cout<<"6. Dequeue Entire Heap"<<endl;
	cout<<"7. Dequeue Entire STL"<<endl;
	cout<<"8. Quit"<<endl;
}

int main(int argc, char *argv[]){
	//string filename = argv[1];	//command line argument is file name

	//initialize variables
	PriorityQueue list; //LL
	string newPatient;
	int sizeLL;
	priority_queue<STLqueue, vector<STLqueue>, compare> pq; //STL
	int spot;
	string line;
	string name;
	int delivery;
	int treatment;
	int count;
	MinHeap h(880); //MinHeap
	int sizeHeap = 880;

	//file to read in
	ifstream inFile;

	bool run = true;
	while(run){
		//initialize choice to 0
		int choice = 0;

		//print menu and read in users choice
		printMenu();
		cin>>choice; 

		if(choice != 0){ //if a valid menu option was chosen
			switch(choice){
				case 1: //build LL
					inFile.open("patientData2270.csv");
					if(inFile){
						sizeLL = 880;
						getline(inFile,newPatient, '\r');
						int i = 1;
						while(i <= 880){
							getline(inFile,newPatient, '\r');
							list.enqueuePatient(newPatient);
							i++;
						}
						inFile.close();
					}
					else{
						cout<<"ERROR: File not opened."<<endl;
					}
					break;

				case 2: //build heap
					inFile.open("patientData2270.csv");
					if(inFile){
						sizeHeap = 880;
						getline(inFile,newPatient, '\r');
						while(getline(inFile, newPatient, '\r')){
							h.insert(newPatient);
						}
						inFile.close();
					}
					else{
						cout<<"ERROR: File not opened."<<endl;
					}
					break;

				case 3: //Build STL
					inFile.open("patientData2270.csv");
					if(inFile){
						sizeLL = 880;
						getline(inFile,newPatient, '\r');
						int i = 1;
						while(i <= 880){
							getline(inFile,newPatient, '\r');
							stringstream sr(newPatient);
							spot = 1;
							while(getline(sr, line, ',')){
								if(spot == 1){
									name = line;
								}
								else if(spot == 2){
									delivery = stoi(line);
								}
								else if(spot == 3){
									treatment = stoi(line);
								}
								spot++;
							}
							STLqueue *ab = new STLqueue(name, delivery, treatment);
							pq.push(*ab);
							i++;
						}
						inFile.close();
					}
					else{
						cout<<"ERROR: File not opened."<<endl;
					}
					break;

				case 4: //dequeue LL
					sizeLL--;
					list.dequeuePatient();
					break;

				case 5: //dequeue entire LL
					cout<<"Rank	patient,  Priority,  Treatment"<<endl;
					list.dequeueList(sizeLL);
					break;

				case 6: //dequeue entire heap
					cout<<"Rank	patient,  Priority,  Treatment"<<endl;
					h.dequeueAll();
					break;

				case 7:	//dequeue entire STL
					count = 1;
					cout<<"Rank	patient,  Priority,  Treatment"<<endl;
					while(!pq.empty( )){
				        STLqueue t = pq.top();
				        cout<<count<<":	"<<t.name<<",  "<<t.timeToDelivery<<",  "<<t.treatmentTime<<endl;
				        pq.pop();
				        count++;
				    }
					break;

				case 8: //quit
					run = false;
					break;

				default:
					cout<<"Enter a valid menu option."<<endl;
			}
		}
		else{
			cout<<"Enter a valid menu option."<<endl;
		}
	}
}