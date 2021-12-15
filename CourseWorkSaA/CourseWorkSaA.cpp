#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <iomanip>
#include "Sequence.h"

struct SetNode { //Узел множества
	SequenceNode* data;
	SetNode* next;
};

void ClearSet(SetNode*& head) { //Удаление множества
	while (head) {
		SetNode* nodetoDelete = head;
		head = head->next;

		//Удаление последовательности
		ClearMemory(nodetoDelete->data); 
		//Очистка множества
		free(nodetoDelete);
	}

	head = NULL;
}

void GetStartedSet(bool& isStarted) {//Начать работу со множеством
	if (isStarted) { //Если работа уже начата
		system("cls");
		printf("Вы уже работаете с множеством!\nЧтобы начать работу с новым множеством, закончите с текущим [2]!\n");
		system("pause");
	}
	else
		isStarted = true;
}

void FinishWorkSet(SetNode*& head, bool& isStarted) {//Закончить работу со множеством
	isStarted = false;

	system("cls");
	if (head) //Если имеются данные, очистить их
		ClearSet(head);
	printf("Вы закончили работу со структурой\n");
	system("pause");
}

void isAllocated(SetNode* node) {//Проверить выделена ли память под новый элемент
	if (!node) { //Если нет, то завершить работу программы
		printf("Память не выделена, программа закроется!");
		Sleep(1000);
		exit(0);
	}
}

SetNode* InitializeSetElement() {//Инициализировать новый элемент
	SetNode* newNode = (SetNode*)malloc(sizeof(SetNode));//Выделить память под новый элемент
	isAllocated(newNode);//Проверить выделена ли память
	
	newNode->data = NULL;
	newNode->next = NULL;
	SequenceMenu(newNode->data);//Вызвать меню последовательности для данных нового элемента множества
	

	return newNode;
}

void AddtoSet(SetNode*& head) {//Добавить элемент во множество
	if (!head) {//Инициализировать корень, если он отсутствует
		head = InitializeSetElement();
		return;
	}

	SetNode* newNode = InitializeSetElement(); //Инициализировать новый элемент

	SetNode* t = head;
	SetNode* lastSeqNode = t;
	while (t) { //Получить последний элемент и узнать, есть ли уже такой

		if (areSeqstheSame(newNode->data, t->data)) {//Проверить имеется ли такой же элемент во множестве
			system("cls");
			printf("Такой элемент уже есть в множестве!\n");
			system("pause");
			ClearSet(newNode);//Удалить выделенный элемент, если такой уже имеется
			return;
		}

		if (!t->next) //Проверяет является ли элемент последним
			lastSeqNode = t;
		t = t->next;
	}
	
	lastSeqNode->next = newNode; //Присвоить новый элемент указателю на следующий элемент у последнего элемента
}

void PrintSet(SetNode* head, int printMode) {//Распечатать множество
	SetNode* t = head;

	int i = 1;
	while (t) {
		SetColor(2); //Установка необходимого цвета
		printf("Элемент %d{", i);
		SetColor(0);
		
		SequenceNode* seqt = t->data;
		if (seqt) //Если последовательность не пустая, вывести её данные
			while (seqt) {
				std::cout << std::fixed << std::setprecision(3) << seqt->data;
				seqt = seqt->next; //Перейти к следующему элементу в последовательности

				if (seqt)
					printf(" ");
			}
		else
			printf("Пустая");

		SetColor(2);
		printf("} ");
		if (printMode)
			printf("\n");
		SetColor(0);

		t = t->next; //Перейти к следующему элементу
		i++;
	}
	printf("\n\n");
}

void isSetClear(SetNode* head) {//Проверить пусто ли множество
	system("cls");
	if (head)//Данные имеются, значит множество не пусто
		printf("Структура не пустая!\n");
	else
		printf("Структура пустая!\n");
	system("pause");
}

bool CheckCommandifSetisClear(int command) {//Проверить допустимость выполнения команды, если множество пустое
	int allowedCommands[7] = { 1, 2, 3, 4, 7, 9, 10 };//Разрешенные команды
	for (int i = 0; i < 7; i++)
	{
		if (allowedCommands[i] == command)//Выход, если команда разрешена
			return false;
	}
	return true;
}

SetNode* isSetClearandShowMsg(SetNode* head) {//Вывести сообщение, если множество пустое
	if (!head) {
		system("cls");
		printf("Структура пуста, вы не можете использовать эту операцию!\n");
		system("pause");
	}
	return head;
}

void DeleteRoot(SetNode*& head) {//Удалить корень множества
	SetNode* nodetoDelete = head;
	head = head->next; //Получить новый корень

	nodetoDelete->next = NULL;
	ClearSet(nodetoDelete);//Удалить элемент множества
}

void DeleteElement(SetNode*& head) {//Удалить элемент множества
	SetNode* newNode = InitializeSetElement();//Получить элемент, который хотим удалить во множестве
	SequenceNode* newSeqNode = newNode->data;

	if (areSeqstheSame(head->data, newSeqNode)) { //Если введённые данные совпадают с корнем, то удалить корень
		ClearSet(newNode); //Удалить введенный введенные даные
		DeleteRoot(head); //Удалить корень
		system("cls");
		printf("Элемент удалён!\n");
		system("pause");
		return;
	}

	SetNode* t = head;
	while (t->next) { //удаление элемента отличного от корня
		SequenceNode* seqt = t->next->data;
		
		if (areSeqstheSame(seqt, newSeqNode)) {//Поиск элемента, который нужно удалить
			SetNode* nodetoDelete = t->next;
			t->next = nodetoDelete->next;

			//Удаления множества
			ClearSet(newNode);
			nodetoDelete->next = NULL;
			ClearSet(nodetoDelete);
			system("cls");
			printf("Элемент удалён!\n");
			system("pause");
			return;
		}

		t = t->next;
	}
	//Удалить элемент, который ввели, чтобы найти элемент для удаления
	system("cls");
	printf("Такой элемент отсутствует!\n");
	system("pause");
	ClearSet(newNode);
}

void TakeElement(SetNode*& head, SetNode*& object) {//Взять элемент
	SetNode* t = head;

	system("cls");
	printf("Взятый элемент: ");

	if (!t->next) {//Если элемент является корнем
		ClearSet(object);
		object = head;
		head = NULL;
		if (object->data)
			PrintSequence(object->data, NULL);
		else
			printf("пустая последовательность!\n");
		system("pause");
		return;
	}

	while (t->next) {
		if (!t->next->next) {//Поиск последнего элемента
			ClearSet(object); //Удалит то что лежало до этого
			object = t->next; //Присвоить в объект взятый элемент
			t->next = NULL;
			if (object->data) 
				PrintSequence(object->data, NULL); //Вывести взятый объект
			else
				printf("пустая последовательность!\n");
			system("pause");
			return;
		}
		t = t->next;
	}
}

void isElementinSet(SetNode* head) {//Проверить принадлежит ли элемент множеству
	SetNode* newNode = InitializeSetElement();//Ввести элемент на проверку
	system("cls");

	SetNode* t = head;
	while (t) {//Проход по всем элементам множества
		if (areSeqstheSame(t->data, newNode->data)) {//Если последовательности одинаковые
			printf("Элемент принадлежит множеству!\n");
			system("pause");
			return;
		}

		t = t->next;
	}

	printf("Элемент не принадлежит множеству!\n");
	system("pause");
}

void GetCommandofSet(SetNode*& head, SetNode*& object, bool& isStarted) {//Обработка команды, полученной от пользователя
	printf("Команда ~ ");

	int command = 0;
	std::cin >> command;//Ввод команды пользователя

	if (command != 1 && command != 10 && !CheckStart(isStarted)) //Проверить начата ли работа, и допустимые при этом команды
		return;
	if (CheckCommandifSetisClear(command) && !isSetClearandShowMsg(head)) //Проверить допустима ли команда, если множество пустое
		return;
	
	switch (command)//Вызов нужной для пользователя функции
	{
	case 1:
		GetStartedSet(isStarted);//Начать работу
		break;
	case 2:
		FinishWorkSet(head, isStarted);//Закончить работу
		break;
	case 3:
		system("cls");
		if (head) {
			ClearSet(head);//Очистить структуру
			printf("Вы сделали структуру пустой!\n");
		}
		else
			printf("Структура уже пустая!\n");
		system("pause");
		break;
	case 4:
		isSetClear(head);//Проверить пуста ли структура
		break;
	case 5:
		DeleteElement(head);//Удалить элемент
		break;
	case 6:
		TakeElement(head, object);//Взять элемент
		break;
	case 7:
		AddtoSet(head);//Добавить элемент
		break;
	case 8:
		isElementinSet(head);//Проверить принадлежит ли элемент множеству
		break;
	case 9:
		system("cls");
		if (head)
			PrintSet(head, 1);
		else
			printf("Структура пустая!\n\n");
		system("pause");
		break;
	case 10:
		if (head)
			ClearSet(head);
		if (object)
			ClearSet(object);
		exit(0);
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
	SetNode* object = NULL;
	bool isStarted = false;

	while (true) {
		if (head)
			PrintSet(head, 0);
		else
			if (isStarted)
				printf("Структура пустая\n\n");

		PrintSetMenu();
		GetCommandofSet(head, object, isStarted);
		
		system("cls");
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	SetMenu();
}