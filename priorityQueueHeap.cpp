#include "priorityQueueHeap.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

MinHeap::MinHeap(int inSize){
	currSize = 0;
	capacity = inSize;
	vector<Heap> heap;
	hp = heap;
}

void MinHeap::insert(string addPatient){
	Heap *p = new Heap();

	stringstream ss(addPatient);
	string line;
	int count = 1;

	while(getline(ss, line, ',')){
		if(count == 1){
			p->name = line;
		}
		else if(count == 2){
			p->timeToDelivery = stoi(line);
		}
		else if(count == 3){
			p->treatmentTime = stoi(line);
		}
		count++;
	}

	hp.push_back(*p); //inserts p at the front of vector
	currSize++;

	/*
	hp[currSize] = *p;
	MinHeapify(currSize);
	int index = currSize
	while(hp[index].timeToDelivery < hp[index / 2].timeToDelivery || hp[index].timeToDelivery == hp[index / 2].timeToDelivery){
		if(hp[index].timeToDelivery < hp[index / 2]){
			swap(hp[index],hp[index/2]);
		}
		else if(hp[index].timeToDelivery == hp[index / 2]){
			if(hp[index].treatmentTime < hp[index / 2].treatmentTime){
				swap(hp[index],hp[index/2]);
			}
		}
		index = index/2;
	}
	*/

	if(currSize == 880){
	 	make_heap(hp.begin(),hp.end(),lessThan()); //heapifys the vector
	}

}

void MinHeap::dequeueAll(){
	sort(hp.begin(),hp.end(),lessThan()); //sort the heap into order for printing
	for(int k = 0; k <= currSize - 1; k++){
		cout<<k+1<<":	"<<hp[k].name<<",  "<<hp[k].timeToDelivery<<",  "<<hp[k].treatmentTime<<endl;
	}
	currSize = 0;
	hp.clear();
}





/*
void MinHeap::MinHeapify(int index){
	int parent = index/2;
	int right = index * 2 + 1;
	int left = index * 2;
	int small = index;

		if(hp[small].timeToDelivery > hp[parent].timeToDelivery){
			small = parent;
		}
		else if(hp[right].timeToDelivery < hp[small].timeToDelivery){
			small = right;
		}
		else if(hp[left].timeToDelivery < hp[small].timeToDelivery){
			small = left;
		}
		
		if(small != index){
			swap(hp[small],hp[index])
		}
	}
}
*/