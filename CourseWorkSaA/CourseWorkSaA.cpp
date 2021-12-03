#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <iomanip>
#include "Sequence.h"

/*Множество последовательностей типа float*/ /*L1 список*/

struct SetNode { //Узел множества
	SequenceNode* data;
	SetNode* next;
};


void GetStartedSet(bool& isStarted) {
	if (isStarted) {
		system("cls");
		printf("Вы уже работаете с множеством!\nЧтобы начать работу с новым множеством, закончите с текущим [2]!\n");
		system("pause");
	}
	else
		isStarted = true;
}

void FinishWorkSet(SetNode*& head, bool& isStarted) {
	isStarted = false;

	system("cls");
	if (head)
		ClearSet(head);
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
	
	newNode->data = NULL;
	newNode->next = NULL;
	SequenceMenu(newNode->data);
	

	return newNode;
}

void AddtoSet(SetNode*& head) {
	if (!head) {
		head = InitializeSetElement();
		return;
	}

	SetNode* t = head;
	
	while (t->next) { //Получить последний элемент 
		t = t->next;
	}

	t->next = InitializeSetElement();
}

void PrintSet(SetNode* head) {
	SetNode* t = head;

	int i = 1;
	while (t) {
		SetColor(2);
		printf("Элемент %d{", i);
		SetColor(0);
		
		SequenceNode* seqt = t->data;
		if (seqt)
			while (seqt) {
				std::cout << std::fixed << std::setprecision(3) << seqt->data;
				seqt = seqt->next;

				if (seqt)
					printf(" ");
			}
		else
			printf("Пустая");

		SetColor(2);
		printf("} ");
		SetColor(0);

		t = t->next;
		i++;
	}
	printf("\n\n");
}

void ClearSet(SetNode*& head) {
	while (head) {
		SetNode* nodetoDelete = head;
		head = head->next;

		ClearMemory(nodetoDelete->data);
		free(nodetoDelete);
	}

	head = NULL;
}

void isSetClear(SetNode* head) {
	system("cls");
	if (head)
		printf("Структура не пустая!\n");
	else
		printf("Структура пустая!\n");
	system("pause");
}

bool CheckCommandifSetisClear(int command) {
	int allowedCommands[6] = { 1, 2, 3, 4, 7, 10 };
	for (int i = 0; i < 6; i++)
	{
		if (allowedCommands[i] == command)
			return false;
	}
	return true;
}

SetNode* isSetClearandShowMsg(SetNode* head) {
	if (!head) {
		system("cls");
		printf("Структура пуста, вы не можете использовать эту операцию!\n");
		system("pause");
	}
	return head;
}

void DeleteElement(SetNode*& head) {

}

void GetCommandofSet(SetNode*& head, bool& isStarted) {
	printf("Команда ~ ");

	int command = 0;
	std::cin >> command;

	if (command != 1 && command != 10 && !CheckStart(isStarted))
		return;
	if (CheckCommandifSetisClear(command) && !isSetClearandShowMsg(head))
		return;
	
	switch (command)
	{
	case 1:
		GetStartedSet(isStarted);
		break;
	case 2:
		FinishWorkSet(head, isStarted);
		break;
	case 3:
		system("cls");
		if (head) {
			ClearSet(head);
			printf("Вы сделали структуру пустой!\n");
		}
		else
			printf("Структура уже пустая!\n");
		system("pause");
		break;
	case 4:
		isSetClear(head);
		break;
	case 5:

		break;
	case 7:
		AddtoSet(head);
		break;
	default:
		system("cls");
		printf("Вы ввели неизвестную команду!\n");
		system("pause");
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
	printf("\n");
}

void SetMenu() {
	SetNode* head = NULL;
	bool isStarted = false;

	while (true) {
		if (head)
			PrintSet(head);
		else
			if (isStarted)
				printf("Структура пустая\n\n");

		PrintSetMenu();
		GetCommandofSet(head, isStarted);
		
		system("cls");
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	SetMenu();
}