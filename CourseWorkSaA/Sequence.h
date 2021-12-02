#pragma once

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

struct SequenceNode { //Узел последовательности
	float data;
	SequenceNode* next;
};



void GetCommandofSequence(SequenceNode*& head, bool& isStarted) {
	printf("Команда ~");

	int command = 0;
	std::cin >> command;

	switch (command)
	{
	case1:

		break;
	default:
		break;
	}
}

void PrintSequenceMenu() {
	printf("[1] - Начать работу с последовательностью\n");
	printf("[2] - Закончить работу с последовательностью\n");
	printf("[3] - Сделать пустой\n");
	printf("[4] - Структура пустая?\n");
	printf("[5] - Показать значение очередного элемента\n");
	printf("[6] - Пропустить очередной элемент\n");
	printf("[7] - Прочесть очередной элемент\n");
	printf("[8] - Изменить значение очередного элемента\n");
	printf("[9] - Добавить элемент в конец\n");
	printf("[10] - Установить указатель очередного элемента в начало\n");
	printf("[11] - Есть ли непрочитанные элементы?\n");
	printf("[12] - Распечатать последовательность\n");
	printf("[13] - Закончить работу программы\n");
}

void SequenceMenu(SequenceNode*& head) {
	bool isStarted = false;

	while (true) {
		if (head) {

		}
		else
			if (isStarted)
				printf("Структура пустая!\n\n");

		PrintSequenceMenu();
		GetCommandofSequence(head, isStarted);

		system("cls");
	}
}