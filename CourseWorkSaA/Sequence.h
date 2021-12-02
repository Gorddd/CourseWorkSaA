#pragma once

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

struct SequenceNode { //Узел последовательности
	float data;
	SequenceNode* next;
};



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
		printf("Вызвана функция чистки последовательности\n"); /////если существует head
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
	scanf("%f", &(newNode->data));

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

void PrintSequence(SequenceNode* head, SequenceNode* pointer) {
	SequenceNode* t = head;

	while (t) {
		printf("%f ", t->data);
		t = t->next;
	}
	printf("\n");
}

int GetCommandofSequence(SequenceNode*& head, SequenceNode*& pointer, bool& isStarted) {
	printf("Команда ~ ");

	int command = 0;
	std::cin >> command;

	switch (command)
	{
	case 1:
		GetStartedSequence(isStarted);
		break;
	case 2:
		FinishWorkSequence(head);
		isStarted = false;
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
	printf("[13] - Вернуться на предыдущий уровень\n");
	printf("[14] - Закончить работу программы\n");
	printf("\n");
}

void SequenceMenu(SequenceNode*& head) {
	SequenceNode* pointer = head;

	bool isStarted = false;

	while (true) {
		system("cls");

		if (head && pointer)
			PrintSequence(head, pointer);
		else
			if (isStarted)
				printf("Структура пустая!\n\n");

		PrintSequenceMenu();
		if (!GetCommandofSequence(head, pointer, isStarted))
			return; //Выход из меню последовательности

		
	}
}