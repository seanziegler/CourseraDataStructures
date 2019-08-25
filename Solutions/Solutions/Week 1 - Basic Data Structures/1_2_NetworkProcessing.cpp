#include <vector>
#include <iostream>

using namespace std;


void processPackets(const int queueSize, int numberOfPackets, vector<int> &arrivalTime, vector<int> &processingTime) {

	int currentQueueSize = 0;
	int queueFinishTime = 0;
	vector<int> processingTimes;

	for (int i = 0; i < numberOfPackets; i++) {
		if (arrivalTime[i] >= queueFinishTime) {
			queueFinishTime = arrivalTime[i] + processingTime[i];
			currentQueueSize = 1;
			cout << arrivalTime[i] << endl;
		}
		else if (currentQueueSize < queueSize) {
			currentQueueSize++;
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