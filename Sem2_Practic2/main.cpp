#include<stdio.h>
#include<stdlib.h>
#include"TV.h"
#define _CRT_SECURE_NO_WARNINGS
/*
12) �������� ����������� ������� (main), ������� �������� ��������� �������:
- ������� 2 ���������� ��������� (��������������, ��� �����).
- �������������� �� (����� ������� �� �. 6).
- �������� �������� �� ����������� ��������� (�. 8).
- �������������� ������ ��������� ��� ����� ������� (�. 7).
- �������� �������� ���� � ������ ���������� (�. 9).
- �������� �������� �� ����������� ��������� (�. 8).
- ������� 2 ���������� ��������� � ������������ ������ (�. 10).
- ��������� � ���� �� �� ��������.
- ������� ����������� ��������� ������� (�. 12).
�����: �������� ������ ��� ������� �� ����������� ������ ������������. �� ����� ����� ������ � ������ ���������.
*/


int main() {
	TV original;
	TV tv;
	Init(&original, "LG", 30, false);
	Init(&tv, "Samsung", 45, true);
	Print(&original);
	Print(&tv);
	
	Init(&tv, &original);
	SetDisplaySize(25, &original);
	Print(&original);
	Print(&tv);

	TV* temp1 = NewTV();
	TV* temp2 = NewTV();
	Init(temp1, "LG", 30, false);
	Init(temp2, "Samsung", 45, true);
	Print(temp1);
	Print(temp2);

	Init(temp2, temp1);
	SetDisplaySize(25, temp1);
	Print(temp1);
	Print(temp2);
	DeleteTV(temp1);
	DeleteTV(temp2);

	return 0;
}