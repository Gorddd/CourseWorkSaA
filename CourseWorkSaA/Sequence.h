#pragma once

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

struct SequenceNode { //���� ������������������
	float data;
	SequenceNode* next;
};



void GetCommandofSequence(SequenceNode*& head, bool& isStarted) {
	printf("������� ~");

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
	printf("[13] - ��������� ������ ���������\n");
}

void SequenceMenu(SequenceNode*& head) {
	bool isStarted = false;

	while (true) {
		if (head) {

		}
		else
			if (isStarted)
				printf("��������� ������!\n\n");

		PrintSequenceMenu();
		GetCommandofSequence(head, isStarted);

		system("cls");
	}
}