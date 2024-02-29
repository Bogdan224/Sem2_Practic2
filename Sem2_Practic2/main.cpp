#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"TV.h"
#include<iostream>

int main() {
	TV original;
	TV tv;
	char model[200] = "LG";
	int displaySize = 34;
	bool wifi = true; 

	Init(&original, model, displaySize, wifi);
	Init(&tv, "Samsung", 45, false);
	Print(&original);
	Print(&tv);
	
	Init(&tv, &original);
	SetDisplaySize(25, &original);
	Print(&original);
	Print(&tv);

	TV* temp1 = NewTV();
	TV* temp2 = NewTV();

	strcpy(model, "Sony");
	displaySize = 30;
	wifi = false;

	Init(temp1, model, displaySize, wifi);
	Init(temp2, "Samsung", 45, true);
	Print(temp1);
	Print(temp2);

	Init(temp2, temp1);
	SetDisplaySize(21, temp1);
	Print(temp1);
	Print(temp2);
	DeleteTV(temp1);
	DeleteTV(temp2);

	return 0;
}