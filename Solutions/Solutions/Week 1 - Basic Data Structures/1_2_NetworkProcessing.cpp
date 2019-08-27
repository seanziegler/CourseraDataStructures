#include <vector>
#include <iostream>

using namespace std;


void processPackets(const int queueSize, int numberOfPackets, vector<int> &arrivalTime, vector<int> &processingTime) {

	vector<int> packetQueue;
	vector<int> processingTimes;

	for (int i = 0; i < numberOfPackets; i++) {
		if (packetQueue.size != 0 && arrivalTime[i] > packetQueue.front()) {
			packetQueue.erase(packetQueue.begin());
		}
		
		if (packetQueue.size() == 0 || arrivalTime[i] >= packetQueue.back() ) {
			packetQueue.push_back(arrivalTime[i] + processingTime[i]);
			
			cout << arrivalTime[i] << endl;
		}
		else if (packetQueue.size() < queueSize) {
			packetQueue.push_back()
			cout << queueFinishTime << endl;
			queueFinishTime += processingTime[i];
		}
		else {
			cout << "-1" << endl;
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