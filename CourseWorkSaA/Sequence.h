#pragma once

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <iomanip>

struct SequenceNode { //Узел последовательности
	float data;
	SequenceNode* next;
};

void isItClear(SequenceNode* head, SequenceNode* pointer) {
	system("cls");
	if (head && pointer)
		printf("Структура НЕ пустая!\n");
	else
		printf("Структура пустая!\n");
	system("pause");
}

bool CheckStart(bool isStarted) {
	if (!isStarted) {
		system("cls");
		printf("Выполнена недопустимая операция, сначала выполните [1]!\n");
		system("pause");
	}
	return isStarted;
}

void GetStartedSequence(bool& isStarted) {
	if (isStarted) {
		system("cls");
		printf("Вы уже работаете с последовательностью!\nЧтобы начать работу с новой, закончите с текущей [2]!\n");
		system("pause");
	}
	else
		isStarted = true;
}

void FinishWorkSequence(SequenceNode*& head) {
	system("cls");
	printf("Вы закончили работу с последовательностью\n");
	system("pause");
}

void CheckisAllocated(SequenceNode* node) {
	if (!node) {
		printf("Память не выделена, программа закроется!");
		Sleep(1000);
		exit(0);
	}
}

SequenceNode* InitializeSequenceElement() {
	SequenceNode* newNode = (SequenceNode*)malloc(sizeof(SequenceNode));
	CheckisAllocated(newNode);

	printf("Введите число: ");
	std::cin >> newNode->data;

	newNode->next = NULL;

	return newNode;
}

void AddElement(SequenceNode*& head, SequenceNode*& pointer) {
	system("cls");
	if (!head) {
		head = InitializeSequenceElement();
		pointer = head;
		return;
	}

	SequenceNode* t = head;

	while (t->next) { //Получить последний элемент
		t = t->next;
	}

	t->next = InitializeSequenceElement();
}

void SetColor(int colorMode) {
	switch (colorMode)
	{
	case 0:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 7)); //стандартный
		break;
	case 1:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN); 
		break;
	case 2:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 6)); //желтый
		break;
	default:
		break;
	}
}

void PrintSequence(SequenceNode* head, SequenceNode* pointer) {
	SequenceNode* t = head;
	int colorMode = 1;

	while (t) {
		if (t == pointer) {
			SetColor(2);
			std::cout << std::fixed << std::setprecision(3) << t->data << " "; //Вывод числа с 3 знаками после запятой
			colorMode = 0;
		}
		else {
			SetColor(colorMode);
			std::cout << std::fixed << std::setprecision(3) << t->data << " ";
		}

		t = t->next;
	}

	SetColor(0);
	printf("\n\n");
}

void ClearMemory(SequenceNode*& head, SequenceNode*& pointer) {
	SequenceNode* t = head;

	while (t) {
		SequenceNode* nodetoDelete = t;
		t = t->next;
		free(nodetoDelete);
	}

	pointer = head = NULL;
}

void PrintElement(SequenceNode* pointer) {
	system("cls");
	printf("Очередной элемент: %f", pointer->data);
	system("pause");
}

void SkipElement(SequenceNode*& pointer) {
	if (pointer) 
		pointer = pointer->next;
	else {
		system("cls");
		printf("Вы не можете пропустить очередной элемент, т.к. непрочитанные элементы отсутствуют\n");
		system("pause");
	}
}

int GetCommandofSequence(SequenceNode*& head, SequenceNode*& pointer, bool& isStarted) {
	printf("Команда ~ ");

	int command = 0;
	std::cin >> command;

	if (command != 1 && command != 2 && !CheckStart(isStarted))
		return 1;


	switch (command)
	{
	case 1:
		GetStartedSequence(isStarted);
		break;
	case 2:
		FinishWorkSequence(head);
		return 0;
	case 3:
		system("cls");
		if (head) {
			ClearMemory(head, pointer);
			printf("Вы сделали структуру пустой\n");
		}
		else
			printf("Структура уже пустая!\n");
		system("pause");
		break;
	case 4:
		isItClear(head, pointer);
		break;
	case 5:
		PrintElement(pointer);
		break;
	case 6:
		SkipElement(pointer);
		break;
	case 9:
		AddElement(head, pointer);
		break;
	case 12:
		system("cls");
		PrintSequence(head, pointer);
		system("pause");
		break;
	default:
		break;
	}
	return 1;
}

void PrintSequenceMenu() {
	printf("[1] - Начать работу с последовательностью\n");
	printf("[2] - Закончить работу с последовательностью (вернуться к множеству)\n");
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
	printf("\n");
}

void SequenceMenu(SequenceNode*& head) {
	SequenceNode* pointer = head;

	bool isStarted = false;

	while (true) {
		system("cls");

		if (head)
			PrintSequence(head, pointer);
		else
			if (isStarted)
				printf("Структура пустая!\n\n");

		PrintSequenceMenu();
		if (!GetCommandofSequence(head, pointer, isStarted))
			return; //Выход из меню последовательности
	}
}