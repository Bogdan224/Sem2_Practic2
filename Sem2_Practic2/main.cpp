#include<stdio.h>
#include<stdlib.h>
#include"TV.h"
#define _CRT_SECURE_NO_WARNINGS
/*
12) Написать тестирующую функцию (main), которая работает следующим образом:
- Создает 2 экземпляра структуры (автоматических, «на стеке»).
- Инициализирует их (вызов функции из п. 6).
- Печатает сведения об экземплярах структуры (п. 8).
- Инициализирует второй экземпляр как копию первого (п. 7).
- Изменяет значение поля в первом экземпляре (п. 9).
- Печатает сведения об экземплярах структуры (п. 8).
- Создает 2 экземпляра структуры в динамической памяти (п. 10).
- Выполняет с ними те же действия.
- Удаляет динамически созданные объекты (п. 12).
Важно: тестовые данные для функций не обязательно вводит пользователь. Их можно сразу задать в тексте программы.
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