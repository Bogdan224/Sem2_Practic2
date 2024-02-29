#define _CRT_SECURE_NO_WARNINGS
#include "TV.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int CheckValues(TV* tv) {
	if (tv->_displaySize < 10) {
		return -1;
	}
	else {
		return 0;
	}
}

int Init(TV* res, char* model, int displaySize, bool connectToWifi) {
	char* m = (char*)malloc(sizeof(model));
	strncpy(m, model, sizeof(model));
	res->_model = m;
	res->_displaySize = displaySize;
	res->_connectToWiFi = connectToWifi;
	if (CheckValues(res) == 0) {
		return 0;
	}
	else {
		res = NULL;
		return -1;
	}
}

int Init(TV* res, const char* model, int displaySize, bool connectToWifi) {
	char* m = (char*)malloc(sizeof(model));
	strncpy(m, model, sizeof(model));
	res->_model = m;
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
	char* m = (char*)malloc(sizeof(original->_model));
	strncpy(m, original->_model, sizeof(original->_model));
	tv->_model = m;
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

int SetDisplaySize(int displaySize, TV* tv) {
	int size = tv->_displaySize;
	tv->_displaySize = displaySize;
	if (CheckValues(tv)==0) {
		return 0;
	}
	else {
		tv->_displaySize = size;
		return -1;
	}
}

TV* NewTV() {
	TV* tv = (TV*)malloc(sizeof(TV));
	Init(tv, "Samsung", 40, false);
	return tv;
}

void DeleteTV(TV* tv) {
	free(tv);
}