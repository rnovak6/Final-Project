#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>
#include <time.h>
#include "priorityQueueLL.cpp"
#include "priorityQueueHeap.cpp"


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


int main(){
	ifstream inFile;

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

	//int sizeHeap = 180;
	//MinHeap h(sizeHeap); //MinHeap

	clock_t t1, t2;
	

	int capacity = 180;
	int x = 0;
	while(x < 500){ //insert the code from each implementaion to test runtimes (change the size 8 times)
		t1 = clock(); //starts clock

		/*
			//Heap
			inFile.open("patientData2270.csv");
					if(inFile){
						sizeHeap = 180;
						getline(inFile,newPatient, '\r');
						int i = 1;
						while(i <= 180){
							getline(inFile, newPatient, '\r');
							h.insert(newPatient);
							i++;
						}
						inFile.close();
					}
					cout<<"Rank	patient,  Priority,  Treatment"<<endl;
					h.dequeueAll();
*/

					//LL
		  /*
			inFile.open("patientData2270.csv");
					if(inFile){
						sizeLL = 180;
						getline(inFile,newPatient, '\r');
						int i = 1;
						while(i <= 180){
							getline(inFile,newPatient, '\r');
							list.enqueuePatient(newPatient);
							i++;
						}
						inFile.close();
					}
					else{
						cout<<"ERROR: File not opened."<<endl;
					}
					cout<<"Rank	patient,  Priority,  Treatment"<<endl;
					list.dequeueList(sizeLL);
	
		*/


					//STL
		/*
			inFile.open("patientData2270.csv");
					if(inFile){
						sizeLL = 180;
						getline(inFile,newPatient, '\r');
						int i = 1;
						while(i <= 180){
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
					count = 1;
					cout<<"Rank	patient,  Priority,  Treatment"<<endl;
					while(!pq.empty( )){
				        STLqueue t = pq.top();
				        cout<<count<<":	"<<t.name<<",  "<<t.timeToDelivery<<",  "<<t.treatmentTime<<endl;
				        pq.pop();
				        count++;
				    }
				    */


				    t2 = clock(); //stops clock
					float time = (float(t2) - float(t1)) / CLOCKS_PER_SEC;
					ofstream outFile;
					outFile.open("outputHeap.csv", fstream::app); //Heap
					//outFile.open("output.csv", fstream::app); //LL
					//outFile.open("outputSTL.csv", fstream::app); //STL
					outFile << time << endl;
					outFile.close();
					
					x++;
	}

}