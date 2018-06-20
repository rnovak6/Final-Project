#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <vector>

using namespace std;

struct Heap{
	Heap(string inName, int inTimeToDelivery, int inTreatmentTime){
		name = inName;
		timeToDelivery = inTimeToDelivery;
		treatmentTime = inTreatmentTime;
	}
	Heap(){

	}
	string name;
	int timeToDelivery;
	int treatmentTime;
};

struct lessThan{
	inline bool operator() (const Heap &a, const Heap &b){
		if(a.timeToDelivery < b.timeToDelivery){
			return true;
		}
		else if(a.timeToDelivery == b.timeToDelivery){
			if(a.treatmentTime < b.treatmentTime){
				return true;
			}
			else if(a.treatmentTime > b.treatmentTime){
				return false;
			}
			else if(a.treatmentTime == b.treatmentTime){
				return false;
			}
		}
		else if(a.timeToDelivery > b.timeToDelivery){
			return false;
		}
		return false;
	}
};

class MinHeap{
public:
	MinHeap(int capacity);
	void insert(string);
	void dequeueAll();
	void minHeapify(int);
private:
	int capacity;
	int currSize;
	vector<Heap> hp;
};

#endif //MinHeap