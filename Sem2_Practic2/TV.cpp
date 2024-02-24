#include "TV.h"
#include <stdlib.h>
#include <stdio.h>

int CheckValues(TV* tv) {
	if (tv == NULL) {
		return -1;
	}
	else if (tv->_displaySize < 10) {
		return -2;
	}
	else {
		return 0;
	}
}

int Init(TV* res, char* model, int displaySize, bool connectToWifi) {
	res->_model = model;
	res->_displaySize = displaySize;
	res->_connectToWiFi = connectToWifi;
	if (CheckValues(res) == 0) {
		return 0;
	}
	else {
		return -1;
	}
}

void Init(TV* tv, TV* original) {
	tv->_model = original->_model;
	tv->_displaySize = original->_displaySize;
	tv->_connectToWiFi = original->_connectToWiFi;
}

void Print(TV* tv) {
	printf("Model: %s\nDisplay size: %d''\n", tv->_model, tv->_displaySize);
	if (tv->_connectToWiFi) {
		printf("Connection to WiFi: Yes\n");
	}
	else {
		printf("Connect to WiFi: No\n");
	}
}