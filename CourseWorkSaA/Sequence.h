#pragma once
//����������� ����������� ���������
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <iomanip>

struct SequenceNode { //���� ������������������
	float data; 
	SequenceNode* next;//��������� �� ��������� �������
};

void isItClear(SequenceNode* head, SequenceNode* pointer) {//��������� ������ �� ������������������
	system("cls");
	if (head)//������ ���� => �� ������
		printf("��������� �� ������!\n");
	else
		printf("��������� ������!\n");
	system("pause");
}

bool CheckStart(bool isStarted) {//��������� ������ �� ������
	if (!isStarted) {
		system("cls");
		printf("��������� ������������ ��������, ������� ��������� [1]!\n");
		system("pause");
	}
	return isStarted;
}

void GetStartedSequence(bool& isStarted) {//������ ������ 
	if (isStarted) {//���� ��� ������ ������, �� ������� ���
		system("cls");
		printf("�� ��� ��������� � �������������������!\n����� ������ ������ � �����, ��������� � ������� [2]!\n");
		system("pause");
	}
	else//����� ������ ������
		isStarted = true;
}

void FinishWorkSequence(SequenceNode*& head) {//��������� ������ � �������������������
	system("cls");
	printf("�� ��������� ������ � �������������������\n");
	system("pause");
}

void CheckisAllocated(SequenceNode* node) {//��������� ���������� �� ������
	if (!node) {
		printf("������ �� ��������, ��������� ���������!");
		Sleep(1000);
		exit(0);//������� ���������
	}
}

SequenceNode* InitializeSequenceElement() {//���������������� ������� ������������������
	SequenceNode* newNode = (SequenceNode*)malloc(sizeof(SequenceNode));//�������� ������
	CheckisAllocated(newNode);//��������� ���������� �� ������

	printf("������� �����: ");
	std::cin >> newNode->data;//������ ������

	newNode->next = NULL;

	return newNode;
}

void AddElement(SequenceNode*& head, SequenceNode*& pointer) {//�������� �������
	system("cls");
	if (!head) {//���� ��� �����, �� ���������������� ������
		head = InitializeSequenceElement();
		pointer = head;//���������� ������� ��������� �� ������
		return;
	}

	SequenceNode* t = head;
	while (t->next) { //�������� ��������� �������
		t = t->next;
	}

	t->next = InitializeSequenceElement();//�������� ����� ������� � ����� 
	if (!pointer)//���� ��������� ������ �� �������, ��������� ��� ����� �������
		pointer = t->next;
}

void SetColor(int colorMode) {//���������� ���� �������� � �������
	switch (colorMode)//� ����������� �� ������
	{
	case 0:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 7)); //�����������
		break;
	case 1:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN); 
		break;
	case 2:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 6)); //������
		break;
	default:
		break;
	}
}

void PrintSequence(SequenceNode* head, SequenceNode* pointer) {//����������� ������������������
	SequenceNode* t = head;
	int colorMode = 1;

	while (t) {//���� ���������� t
		if (t == pointer) {//�������� ����, ���� ��� ������� ���������
			SetColor(2);
			std::cout << std::fixed << std::setprecision(3) << t->data << "  "; //����� ����� � 3 ������� ����� �������
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

void ClearMemory(SequenceNode*& head, SequenceNode*& pointer) {//�������� ������ �� ������������������
	SequenceNode* t = head;

	while (t) {//���� ���������� t
		SequenceNode* nodetoDelete = t;
		t = t->next;
		free(nodetoDelete);//������� ������
	}

	pointer = head = NULL;
}

void ClearMemory(SequenceNode*& head) {//������� ������������������ ����� (�������� ��� ������� ���������)
	SequenceNode* t = head;

	while (t) {
		SequenceNode* nodetoDelete = t;
		t = t->next;
		free(nodetoDelete);
	}

	head = NULL;
}

void PrintElement(SequenceNode* pointer) {//����������� ������� ������������������
	system("cls");
	if (pointer)//���� ������� ���������� ����������� ���
		std::cout << std::fixed << std::setprecision(3) << "��������� �������: " << pointer->data << std::endl;
	else
		printf("�� �� ������ ���������� �������� ���������� ��������, �.�. ������������� �������� ������������!\n");
	system("pause");
}

void SkipElement(SequenceNode*& pointer) {//���������� ��������� �������
	if (pointer) 
		pointer = pointer->next;//����� ���������
	else {
		system("cls");
		printf("�� �� ������ ���������� ��������� �������, �.�. ������������� �������� �����������\n");
		system("pause");
	}
}

void ReadElement(SequenceNode*& pointer, SequenceNode*& object) {//��������� ��������� �������
	system("cls");
	if (pointer) {//���� ������� ����������
		object = pointer; //��������� ������� ��������� �������
		std::cout << std::fixed << std::setprecision(3) << "����������� �������: " << object->data << std::endl;
		pointer = pointer->next;//����� �������� ���������
	}
	else 
		printf("�� �� ������ ��������� ��������� �������, �.�. ������������� �������� �����������\n");

	system("pause");
}

void ChangeElement(SequenceNode*& pointer) {//�������� ��������� �������
	system("cls");
	if (pointer) {//���� ��������� ������� ����������
		printf("������� ����� ��������: ");
		std::cin >> pointer->data;//������ ����� ��������
	}
	else {
		printf("�� �� ������ �������� ��������� �������, �.�. ��� �������� ���������!\n");
		system("pause");
	}
}

bool CheckCommandifitisClear(int command) {//��������� �������� �� �������, ���� ������������������ ������
	int allowedCommands[5] = { 1, 2, 3, 4, 9 };//����������� �������
	for (int i = 0; i < 5; i++)
	{
		if (allowedCommands[i] == command)//����� ���� ������� ���������
			return false;
	}
	return true;
}

SequenceNode* isItClearandShowMsg(SequenceNode* head) {//���� ������������������ �����, ������� ���������
	if (!head) {
		system("cls");
		printf("��������� �����, �� �� ������ ������������ ��� ��������!\n");
		system("pause");
	}
	return head;
}

void SetPointerToHead(SequenceNode* head, SequenceNode*& pointer) {//���������� ��������� �� ������
	if (pointer == head) {//���� ��� ����������
		system("cls");
		printf("��������� ��� ���������� � ������!\n");
		system("pause");
	}
	else
		pointer = head;
}

void isThereUnread(SequenceNode* pointer) {//���� �� ������������� ��������
	system("cls");
	if (pointer)//���� ������� ��������� �� �� ���������
		printf("������������� �������� ����!\n");
	else
		printf("������������� ��������� ���!\n"); 
	system("pause");
}

int GetNumberofElements(SequenceNode* seqNode) {//�������� ���������� ��������� (������������ ��� ��������� �������������������)
	int i = 0;
	while (seqNode) {
		i++;
		seqNode = seqNode->next;//������� � ���������� ��������
	}
	return i;
}

bool areSeqstheSame(SequenceNode* firstSeq, SequenceNode* secondSeq) {//��������� �������������������
	if (GetNumberofElements(firstSeq) != GetNumberofElements(secondSeq))//���� �� ����� ���������� ���������, �� �����
		return false;

	while (firstSeq && secondSeq) { //�������� �� ��������
		if (firstSeq->data != secondSeq->data)//���� �� �����, �� �����
			return false;

		firstSeq = firstSeq->next;//������� � ���������� ��������
		secondSeq = secondSeq->next;
	}

	return true;
}

int GetCommandofSequence(SequenceNode*& head, SequenceNode*& pointer, SequenceNode*& object, bool& isStarted) {//���������� �������
	printf("������� ~ ");

	int command = 0;
	std::cin >> command;//�������� �������

	if (command != 1 && !CheckStart(isStarted))//��������� ������� �� ������������, ���� ������ �� ������
		return 1;

	if (CheckCommandifitisClear(command) && !isItClearandShowMsg(head))//��������� ������� �� ������������, ���� 
		return 1;

	switch (command)
	{
	case 1:
		GetStartedSequence(isStarted);//������ ������ � �������������������
		break;
	case 2:
		FinishWorkSequence(head);//��������� ������ � �������������������
		return 0;
	case 3:
		system("cls");
		if (head) {
			ClearMemory(head, pointer);//�������� ������ �� ������������������
			printf("�� ������� ��������� ������\n");
		}
		else
			printf("��������� ��� ������!\n");
		system("pause");
		break;
	case 4:
		isItClear(head, pointer);//��������� ������ �� ������������������
		break;
	case 5:
		PrintElement(pointer);//����������� �������
		break;
	case 6:
		SkipElement(pointer);//���������� �������
		break;
	case 7:
		ReadElement(pointer, object);//��������� �������
		break;
	case 8:
		ChangeElement(pointer);//�������� �������
		break;
	case 9:
		AddElement(head, pointer);//�������� �������
		break;
	case 10:
		SetPointerToHead(head, pointer);//���������� ��������� � ������
		break;
	case 11:
		isThereUnread(pointer);//��������� ���� �� �������������
		break;
	case 12:
		system("cls");
		PrintSequence(head, pointer);//����������� ������������������
		system("pause");
		break;
	default:
		system("cls");
		printf("�� ����� ����������� �������!\n");
		system("pause");
		break;
	}
	return 1;
}

void PrintSequenceMenu() {//����������� ������������������
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

void SequenceMenu(SequenceNode*& head) {//���� ���������� 
	SequenceNode* pointer = head;//��������� �� ������ ������������������
	SequenceNode* object = NULL;//��������� �� ������

	bool isStarted = false;

	while (true) {
		system("cls");

		if (head)//���� ������ ����������, ����������� ������������������
			PrintSequence(head, pointer);
		else//����� ��������� ������
			if (isStarted)
				printf("��������� ������!\n\n");

		PrintSequenceMenu();//����������� ���� ������������������
		if (!GetCommandofSequence(head, pointer, object, isStarted))//���������� ������� ������������
			return;													//����� �� ���� ������������������
	}
}