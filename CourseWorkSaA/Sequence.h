#pragma once

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <iomanip>

struct SequenceNode { //���� ������������������
	float data;
	SequenceNode* next;
};

void isItClear(SequenceNode* head, SequenceNode* pointer) {
	system("cls");
	if (head && pointer)
		printf("��������� �� ������!\n");
	else
		printf("��������� ������!\n");
	system("pause");
}

bool CheckStart(bool isStarted) {
	if (!isStarted) {
		system("cls");
		printf("��������� ������������ ��������, ������� ��������� [1]!\n");
		system("pause");
	}
	return isStarted;
}

void GetStartedSequence(bool& isStarted) {
	if (isStarted) {
		system("cls");
		printf("�� ��� ��������� � �������������������!\n����� ������ ������ � �����, ��������� � ������� [2]!\n");
		system("pause");
	}
	else
		isStarted = true;
}

void FinishWorkSequence(SequenceNode*& head) {
	system("cls");
	printf("�� ��������� ������ � �������������������\n");
	system("pause");
}

void CheckisAllocated(SequenceNode* node) {
	if (!node) {
		printf("������ �� ��������, ��������� ���������!");
		Sleep(1000);
		exit(0);
	}
}

SequenceNode* InitializeSequenceElement() {
	SequenceNode* newNode = (SequenceNode*)malloc(sizeof(SequenceNode));
	CheckisAllocated(newNode);

	printf("������� �����: ");
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

	while (t->next) { //�������� ��������� �������
		t = t->next;
	}

	t->next = InitializeSequenceElement();
}

void PrintSequence(SequenceNode* head, SequenceNode* pointer) {
	SequenceNode* t = head;

	while (t) {
		std::cout << std::fixed << std::setprecision(3) << t->data << " "; //����� ����� � 3 ������� ����� �������
		t = t->next;
	}
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

int GetCommandofSequence(SequenceNode*& head, SequenceNode*& pointer, bool& isStarted) {
	printf("������� ~ ");

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
		if (head && pointer) {
			ClearMemory(head, pointer);
			printf("�� ������� ��������� ������\n");
		}
		else
			printf("��������� ��� ������!\n");
		system("pause");
		break;
	case 4:
		isItClear(head, pointer);
		break;
	case 5: 

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
	printf("==[������������������]==\n");
	printf("[1] - ������ ������ � �������������������\n");
	printf("[2] - ��������� ������ � ������������������� (��������� � ���������)\n");
	printf("[3] - ������� ������\n");
	printf("[4] - ��������� ������?\n");
	printf("[5] - �������� �������� ���������� ��������\n");
	printf("[6] - ���������� ��������� �������\n");
	printf("[7] - �������� ��������� �������\n");
	printf("[8] - �������� �������� ���������� ��������\n");
	printf("[9] - �������� ������� � �����\n");
	printf("[10] - ���������� ��������� ���������� �������� � ������\n");
	printf("[11] - ���� �� ������������� ��������?\n");
	printf("[12] - ����������� ������������������\n");
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
				printf("��������� ������!\n\n");

		PrintSequenceMenu();
		if (!GetCommandofSequence(head, pointer, isStarted))
			return; //����� �� ���� ������������������

		
	}
}