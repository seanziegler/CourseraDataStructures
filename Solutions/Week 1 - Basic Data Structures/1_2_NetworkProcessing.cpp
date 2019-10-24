#include <vector>
#include <iostream>

using namespace std;


void processPackets(const int queueSize, int numberOfPackets, vector<int> &arrivalTime, vector<int> &processingTime) {

	vector<int> packetQueue;			// stores finish times of each packet
	vector<int> processingTimes;

	for (int i = 0; i < numberOfPackets; i++) {
		if (packetQueue.size != 0 && arrivalTime[i] > packetQueue.front()) { 	// check if current packet has arrived after queue front has finished
			packetQueue.erase(packetQueue.begin()); 			// dequeue packets that are already finished
		}
		
		if (packetQueue.size() == 0) { 						// if nothing in queue
			cout << arrivalTime[i] << endl;					// start processing now
			packetQueue.push_back(arrivalTime[i] + processingTime[i]);	// add to queue until finished
			
		}
		else if (packetQueue.size() < queueSize) {				// if room left in queue
			cout << packetQueue.back();					// start processing when final item in queue finishes
			packetQueue.push_back(packetQueue.back() + processingTime[i])	// update finish time with additional time to process new packet
			
		}
		else {
			cout << "-1" << endl;						// no room left in queue, drop the packet
		}
	}
}

int main(int argv, int* argc) {

	int queueSize;
	cin >> queueSize;
	int numberOfPackets;
	cin >> numberOfPackets;

	vector<int> arrivalTime(numberOfPackets);
	vector<int> processingTime(numberOfPackets);

	for (int i = 0; i < numberOfPackets; i++) {
		cin >> arrivalTime[i];
		cin >> processingTime[i];
	}

	processPackets(queueSize,  numberOfPackets, arrivalTime, processingTime);

	return 0;
}
