#pragma once

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

struct SequenceNode { //���� ������������������
	float data;
	SequenceNode* next;
};



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
		printf("������� ������� ������ ������������������\n"); /////���� ���������� head
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

	while (t->next) { //�������� ��������� �������
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
	printf("������� ~ ");

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
	printf("[1] - ������ ������ � �������������������\n");
	printf("[2] - ��������� ������ � �������������������\n");
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
	printf("[13] - ��������� �� ���������� �������\n");
	printf("[14] - ��������� ������ ���������\n");
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