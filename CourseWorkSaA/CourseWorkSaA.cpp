#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "Sequence.h"

/*Множество последовательностей типа float*/ /*L1 список*/

struct SetNode { //Узел множества
	SequenceNode* data;
	SetNode* next;
};


void GetStartedSet(bool& isStarted) {
	if (isStarted) {
		system("cls");
		printf("Вы уже работаете со множеством!\nЧтобы начать работу с новым множеством, закончите с текущим [2]!\n");
		system("pause");
	}
	else
		isStarted = true;
}

void FinishWorkSet(bool& isStarted) {
	isStarted = false;

	system("cls");
	printf("Вызвана функция чистки множества\n");
	printf("Вы закончили работу со структурой\n");
	system("pause");
}

void isAllocated(SetNode* node) {
	if (!node) {
		printf("Память не выделена, программа закроется!");
		Sleep(1000);
		exit(0);
	}
}

SetNode* InitializeSetElement() {
	SetNode* newNode = (SetNode*)malloc(sizeof(SetNode));
	isAllocated(newNode);

	//Переход в меню последовательности
	newNode->next = NULL;

	return newNode;
}

void AddtoSet(SetNode*& head) {
	SetNode* t = head;
	
	while (t) { //Получить последний элемент 
		t = t->next;
	}

	t = InitializeSetElement();
}

void GetCommandofSet(SetNode*& head, bool& isStarted) {
	printf("Команда ~ ");

	int command = 0;
	std::cin >> command;

	switch (command)
	{
	case 1:
		GetStartedSet(isStarted);
		break;
	case 2:
		FinishWorkSet(isStarted);
		break;
	case 7:
		AddtoSet(head);
		break;
	default:
		break;
	}
}

void PrintSetMenu() {
	printf("[1] - Начать работу с множеством\n");
	printf("[2] - Закончить работу с множеством\n");
	printf("[3] - Сделать пустой\n");
	printf("[4] - Структура пустая?\n");
	printf("[5] - Удалить элемент из множества\n");
	printf("[6] - Взять элемент из множества\n");
	printf("[7] - Добавить элемент в множество\n");
	printf("[8] - Проверить принадлежит ли элемент множеству\n");
	printf("[9] - Распечатать структуру\n");
	printf("[10] - Завершить работу программы\n");
}

void SetMenu() {
	SetNode* head = NULL;
	bool isStarted = false;

	while (true) {
		if (head) {

		}
		else
			if (isStarted)
				printf("Структура пустая\n\n");

		PrintSetMenu();

		
		system("cls");
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	SetMenu();
}