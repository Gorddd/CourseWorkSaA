#pragma once
//Подключение необходимых библиотек
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <iomanip>

struct SequenceNode { //Узел последовательности
	float data; 
	SequenceNode* next;//Указатель на следующий элемент
};

void isItClear(SequenceNode* head, SequenceNode* pointer) {//проверить пустая ли последовательнсоть
	system("cls");
	if (head)//Данные есть => не пустая
		printf("Структура НЕ пустая!\n");
	else
		printf("Структура пустая!\n");
	system("pause");
}

bool CheckStart(bool isStarted) {//Проверить начата ли работа
	if (!isStarted) {
		system("cls");
		printf("Выполнена недопустимая операция, сначала выполните [1]!\n");
		system("pause");
	}
	return isStarted;
}

void GetStartedSequence(bool& isStarted) {//Начать работу 
	if (isStarted) {//Если уже начали работу, то вывести это
		system("cls");
		printf("Вы уже работаете с последовательностью!\nЧтобы начать работу с новой, закончите с текущей [2]!\n");
		system("pause");
	}
	else//Иначе начать работу
		isStarted = true;
}

void FinishWorkSequence(SequenceNode*& head) {//Закончить работу с последовательностью
	system("cls");
	printf("Вы закончили работу с последовательностью\n");
	system("pause");
}

void CheckisAllocated(SequenceNode* node) {//Проверить выделилась ли память
	if (!node) {
		printf("Память не выделена, программа закроется!");
		Sleep(1000);
		exit(0);//Закрыть программу
	}
}

SequenceNode* InitializeSequenceElement() {//Инициализировать элемент последовательности
	SequenceNode* newNode = (SequenceNode*)malloc(sizeof(SequenceNode));//Выделить память
	CheckisAllocated(newNode);//Проверить выделилась ли память

	printf("Введите число: ");
	std::cin >> newNode->data;//Ввести данные

	newNode->next = NULL;

	return newNode;
}

void AddElement(SequenceNode*& head, SequenceNode*& pointer) {//Добавить элемент
	system("cls");
	if (!head) {//Если нет корня, то инициализировать корень
		head = InitializeSequenceElement();
		pointer = head;//Установить рабочий указатель на корень
		return;
	}

	SequenceNode* t = head;
	while (t->next) { //Получить последний элемент
		t = t->next;
	}

	t->next = InitializeSequenceElement();//Добавить новый элемент в конец 
	if (!pointer)//Если указатель уходил за пределы, присвоить ему новый элемент
		pointer = t->next;
}

void SetColor(int colorMode) {//Установить цвет символов в консоли
	switch (colorMode)//В зависимости от режима
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

void PrintSequence(SequenceNode* head, SequenceNode* pointer) {//Распечатать последовательность
	SequenceNode* t = head;
	int colorMode = 1;

	while (t) {//пока существует t
		if (t == pointer) {//Изменить цвет, если это рабочий указатель
			SetColor(2);
			std::cout << std::fixed << std::setprecision(3) << t->data << "  "; //Вывод числа с 3 знаками после запятой
			colorMode = 0;
		}
		else {
			SetColor(colorMode);
			std::cout << std::fixed << std::setprecision(3) << t->data << "  ";
		}

		t = t->next;
	}

	SetColor(0);
	printf("\n\n");
}

void ClearMemory(SequenceNode*& head, SequenceNode*& pointer) {//Очистить память от последовательности
	SequenceNode* t = head;

	while (t) {//Пока существует t
		SequenceNode* nodetoDelete = t;
		t = t->next;
		free(nodetoDelete);//Очистка памяти
	}

	pointer = head = NULL;
}

void ClearMemory(SequenceNode*& head) {//Очистка последовательности извне (например при очистке множества)
	SequenceNode* t = head;

	while (t) {
		SequenceNode* nodetoDelete = t;
		t = t->next;
		free(nodetoDelete);
	}

	head = NULL;
}

void PrintElement(SequenceNode* pointer) {//Распечатать элемент последовательности
	system("cls");
	if (pointer)//Если элемент существует распечатать его
		std::cout << std::fixed << std::setprecision(3) << "Очередной элемент: " << pointer->data << std::endl;
	else
		printf("Вы не можете посмотреть значение очередного элемента, т.к. непрочитанные элементы отстутствуют!\n");
	system("pause");
}

void SkipElement(SequenceNode*& pointer) {//Пропустить очередной элемент
	if (pointer) 
		pointer = pointer->next;//Сдвиг указателя
	else {
		system("cls");
		printf("Вы не можете пропустить очередной элемент, т.к. непрочитанные элементы отсутствуют\n");
		system("pause");
	}
}

void ReadElement(SequenceNode*& pointer, SequenceNode*& object) {//Прочитать очередной элемент
	system("cls");
	if (pointer) {//Если элемент существует
		object = pointer; //Присвоить объекту очередной элемент
		std::cout << std::fixed << std::setprecision(3) << "Прочитанный элемент: " << object->data << std::endl;
		pointer = pointer->next;//Сдвиг рабочего указателя
	}
	else 
		printf("Вы не можете прочитать очередной элемент, т.к. непрочитанные элементы отсутствуют\n");

	system("pause");
}

void ChangeElement(SequenceNode*& pointer) {//Изменить очередной элемент
	system("cls");
	if (pointer) {//Если очередной элемент существует
		printf("Введите новое значение: ");
		std::cin >> pointer->data;//Ввести новой значение
	}
	else {
		printf("Вы не можете изменить очередной элемент, т.к. все элементы прочитаны!\n");
		system("pause");
	}
}

bool CheckCommandifitisClear(int command) {//Проверить доступна ли команда, если последовательность пустая
	int allowedCommands[5] = { 1, 2, 3, 4, 9 };//Разрешенные команды
	for (int i = 0; i < 5; i++)
	{
		if (allowedCommands[i] == command)//Выйти если команда разрешена
			return false;
	}
	return true;
}

SequenceNode* isItClearandShowMsg(SequenceNode* head) {//Если последовательность пуста, вывести сообщение
	if (!head) {
		system("cls");
		printf("Структура пуста, вы не можете использовать эту операцию!\n");
		system("pause");
	}
	return head;
}

void SetPointerToHead(SequenceNode* head, SequenceNode*& pointer) {//Установить указатель на начало
	if (pointer == head) {//Если уже установлен
		system("cls");
		printf("Указатель уже установлен в начале!\n");
		system("pause");
	}
	else
		pointer = head;
}

void isThereUnread(SequenceNode* pointer) {//Есть ли непрочитанные элементы
	system("cls");
	if (pointer)//Если рабочий указатель не за пределами
		printf("Непрочитанные элементы есть!\n");
	else
		printf("Непрочитанных элементов нет!\n"); 
	system("pause");
}

int GetNumberofElements(SequenceNode* seqNode) {//Получить количество элементов (используется для сравнения последовательностей)
	int i = 0;
	while (seqNode) {
		i++;
		seqNode = seqNode->next;//Перейти к следующему элементу
	}
	return i;
}

bool areSeqstheSame(SequenceNode* firstSeq, SequenceNode* secondSeq) {//Сравнение последовательностей
	if (GetNumberofElements(firstSeq) != GetNumberofElements(secondSeq))//Если не равно количество элементов, то выйти
		return false;

	while (firstSeq && secondSeq) { //проверка по элементу
		if (firstSeq->data != secondSeq->data)//Если не равны, то выйти
			return false;

		firstSeq = firstSeq->next;//Переход к следующему элементу
		secondSeq = secondSeq->next;
	}

	return true;
}

int GetCommandofSequence(SequenceNode*& head, SequenceNode*& pointer, SequenceNode*& object, bool& isStarted) {//Обработать команду
	printf("Команда ~ ");

	int command = 0;
	std::cin >> command;//Получить команду

	if (command != 1 && !CheckStart(isStarted))//Проверить команду на допустимость, если работа не начата
		return 1;

	if (CheckCommandifitisClear(command) && !isItClearandShowMsg(head))//Проверить команду на допустимость, если 
		return 1;

	switch (command)
	{
	case 1:
		GetStartedSequence(isStarted);//Начать работу с последовательностью
		break;
	case 2:
		FinishWorkSequence(head);//Закончить работу с последовательностью
		return 0;
	case 3:
		system("cls");
		if (head) {
			ClearMemory(head, pointer);//Очистить память от последовательности
			printf("Вы сделали структуру пустой\n");
		}
		else
			printf("Структура уже пустая!\n");
		system("pause");
		break;
	case 4:
		isItClear(head, pointer);//Проверить пустая ли последовательность
		break;
	case 5:
		PrintElement(pointer);//Распечатать элемент
		break;
	case 6:
		SkipElement(pointer);//Пропустить элемент
		break;
	case 7:
		ReadElement(pointer, object);//Прочитать элемент
		break;
	case 8:
		ChangeElement(pointer);//Изменить элемент
		break;
	case 9:
		AddElement(head, pointer);//Добавить элемент
		break;
	case 10:
		SetPointerToHead(head, pointer);//Установить указатель в начало
		break;
	case 11:
		isThereUnread(pointer);//Проверить есть ли непрочитанные
		break;
	case 12:
		system("cls");
		PrintSequence(head, pointer);//Распечатать последовательность
		system("pause");
		break;
	default:
		system("cls");
		printf("Вы ввели неизвестную команду!\n");
		system("pause");
		break;
	}
	return 1;
}

void PrintSequenceMenu() {//Распечатать последовательность
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

void SequenceMenu(SequenceNode*& head) {//Меню обработчик 
	SequenceNode* pointer = head;//Указатель на начало последовательности
	SequenceNode* object = NULL;//Указатель на объект

	bool isStarted = false;

	while (true) {
		system("cls");

		if (head)//Если корень существует, распечатать последовательность
			PrintSequence(head, pointer);
		else//Иначе структура пустая
			if (isStarted)
				printf("Структура пустая!\n\n");

		PrintSequenceMenu();//Распечатать меню последовательности
		if (!GetCommandofSequence(head, pointer, object, isStarted))//Обработать команду пользователя
			return;													//Выход из меню последовательности
	}
}