#include "stdafx.h"


//�ж��Ƿ�Ϊ����Ա�˻����޷����ļ�����-1���Ƿ���1���񷵻�0
int IsAdminAccount(char *account, char *password)
{
	FILE *fp = fopen("Data\\user.dat", "rb");

	if (fp == NULL)
		return -1;

	fseek(fp, 0, SEEK_END);
	int size = ftell(fp)/sizeof(UserAccount);
	fseek(fp, 0, SEEK_SET);

	UserAccount* user = (UserAccount*)malloc(size * sizeof(UserAccount));
	
	for (int i = 0; i < size; i++) {
		fread(user + i, sizeof(UserAccount), 1, fp);
		if (strcmp(account, user[i].account) == 0 && strcmp(password, user[i].password) == 0 
			&& user[i].permission_level == 1)
			return 1;
	}

	free(user);
	fclose(fp);

	return 0;
}

//�����˻���Ϣ���޷��򿪷���-1���ɹ�����1���˻��Ѵ��ڷ���0���������룩
int AddAccount(UserAccount *newInfo)
{
	FILE *fp = fopen("Data\\user.dat", "rb+");

	if (fp == NULL)
		return -1;

	fseek(fp, 0, SEEK_END);
	int size = ftell(fp) / sizeof(UserAccount);
	fseek(fp, 0, SEEK_SET);

	int index = -1;
	UserAccount *user = (UserAccount*)malloc((size + 1) * sizeof(UserAccount));
	for (int i = 0; i < size; i++) {
		fread(user + i, sizeof(UserAccount), 1, fp);
		if (strcmp(user[i].account, newInfo->account) == 0) {
			return 0;
		}
	}

	user[size] = *newInfo;
	fseek(fp, 0, SEEK_SET);

	for (int i = 0; i <= size; i++) {
		fwrite(user + i, sizeof(UserAccount), 1, fp);
	}

	free(user);
	fclose(fp);
	return 1;
	
}


//���������û������룬�ļ��޷��򿪷���-1��ɾ���ɹ�����1��ʧ�ܷ���0
int DeleteAccount(char *account)
{
	FILE *fp = fopen("Data\\user.dat", "rb+");

	if (fp == NULL)
		return -1;

	fseek(fp, 0, SEEK_END);
	int size = ftell(fp) / sizeof(UserAccount);
	fseek(fp, 0, SEEK_SET);

	UserAccount *user = (UserAccount*)malloc(size * sizeof(UserAccount));
	int index = -1;
	for (int i = 0; i < size; i++) {
		fread(user + i, sizeof(UserAccount), 1, fp);
		if (strcmp(user[i].account, account) == 0) {
			index = i;
		}
			
	}
	fclose(fp);
	
	if (index != -1) {
		fp = fopen("Data\\user.dat", "wb+");

		for (int i = 0; i < size; i++) {
			if (i == index) continue;
			//printf("look: %s %s %d\n", user[i].account, user[i].password, user[i].permission_level);
			fwrite(user + i, sizeof(UserAccount), 1, fp);
		}

		fclose(fp);
	}

	free(user);

	return index != -1 ? 1 : 0;
}


//��ʾϵͳ�������˻���Ϣ���޷��򿪷���-1
int DisplayAccountInfo()
{
	FILE *fp = fopen("Data\\user.dat", "rb");

	if (fp == NULL)
		return -1;

	fseek(fp, 0, SEEK_END);
	int size = ftell(fp) / sizeof(UserAccount);
	fseek(fp, 0, SEEK_SET);

	UserAccount* own = (UserAccount*)malloc(size * sizeof(UserAccount));
	printf("--------------------------------------\n");
	printf("%-10s %-10s  %-2s\n", "�˺�", "����", "Ȩ��");
	for (int i = 0; i < size; i++) {
		fread(own + i, sizeof(UserAccount), 1, fp);
		if (own[i].permission_level)
			printf("%-10s %-10s %-2s\n", own[i].account, own[i].password, "����Ա");
		else
			printf("%-10s %-10s %-2s\n", own[i].account, own[i].password, "�ۻ�Ա");
	}
	printf("--------------------------------------\n");

	free(own);
	fclose(fp);

	return 1;
}


void AdminInitMenu()
{
	system("cls");
	int op = -1;

	printf("1) ������\n");
	printf("2) �û�����\n");
	printf("3) ������Ʒ\n");
	printf("4) ����ͳ��\n");
	printf("0) �˳���½\n");

	printf(">> ");
	scanf("%d", &op);

	if (op == 1)
		StockManagement();
	else if (op == 2)
		UserManagement();
	else if (op == 3)
		SoldManagement();
	else if (op == 4)
		SoldStatistics();
	else
		LogIn();
}


void StockManagement()
{
	system("cls");
	int op = -1;

	printf("1) �����Ʒ\n");
	printf("2) �������\n");
	printf("3) �鿴���\n");
	printf("4) ��ѯ��Ʒ\n");
	printf("5) ������\n");
	printf("0) �����ϼ�\n");

	printf(">> ");
	scanf("%d", &op);

	GoodsList head = InitGoodsList();
	ImportGoodsFromFile(head, OpenGoodsFile("r"));

	if (op == 1)
		AddGoodsToStock(head);
	else if (op == 2)
		BatchedStock(head);
	else if (op == 3)
		LookOverStock(head);
	else if (op == 4)
		LookUpGoods(head);
	else if (op == 5)
		ClearStock(head);
	else {
		DeleteGoodsList(head);
		AdminInitMenu();
	}
		
}


void AddGoodsToStock(GoodsList head)
{
	system("cls");
	char id[20];

	printf("������Ʒid\n>> ");
	scanf("%s", id);

	GoodsList p = FindGoodsByID(head, atoi(id));
	if (p) {
		printf("����Ʒ�Ѵ���\n");
		DisplayGoodsInfo(p);
		printf("������������\n>> ");
		int add_cnt = 0;
		scanf("%d", &add_cnt);
		if (add_cnt < 0) add_cnt = 0;
		p->goods.quantity += add_cnt;

		TraverseGoodsList(head, DisplayGoodsInfo);

		ExportGoodsToFile(head, OpenGoodsFile("w"));
		printf("������\n");
	}
	else {
		Goods goods;
		goods.id = atoi(id);
		printf("������Ʒ����\n>> ");
		scanf("%s", goods.name);
		printf("������Ʒ����\n>> ");
		scanf("%lf", &goods.buying_price);
		printf("������Ʒ�ۼ�\n>> ");
		scanf("%lf", &goods.selling_price);
		printf("������Ʒ������\n>> ");
		scanf("%s", goods.manufacturer);
		printf("������Ʒ����\n>> ");
		scanf("%d", &goods.quantity);

		AddGoodsToList(head, goods);
		ExportGoodsToFile(head, OpenGoodsFile("w"));
		printf("������\n");
		DisplayGoodsInfo(&goods);
	}

	system("pause");
	StockManagement();
}

void BatchedStock(GoodsList head)
{
	FILE *fp = fopen("ExternalData\\added_goods.txt", "r");
	if (fp) {
		ImportGoodsFromFile(head, fp);
		ExportGoodsToFile(head, OpenGoodsFile("w"));
		fclose(fp);
		printf("����ɹ�\n");
	}
	else {
		printf("�򿪴������ļ�ʧ��\n");
	}
	system("pause");
	StockManagement();
}

void LookOverStock(GoodsList head)
{
	printf("-------------------------------------------------------\n");
	printf("%-5s %-12s %-6s %-6s %-15s %-5s\n", "ID", "����", "����", "�ۼ�", "��������", "����");
	TraverseGoodsList(head, DisplayGoodsInfo);
	printf("-------------------------------------------------------\n");
	system("pause");
	StockManagement();
}


void LookUpGoods(GoodsList head)
{
	system("cls");

	if (head->next == NULL) {
		printf("���Ϊ��\n");
		system("pause");
		StockManagement();
	}

	int op = -1;

	printf("1) ����Ʒ����ѯ\n");
	printf("2) ���������Ҳ�ѯ\n");
	printf("3) �ۺϲ�ѯ\n");
	printf("0) �����ϼ�\n");

	scanf("%d", &op);

	if (op == 1)
		LookUpGoodsByName(head);
	else if (op == 2)
		LookUpGoodsByManufacturer(head);
	else if (op == 3)
		LookUpGoodsByNameAndManufacturer(head);
	else {
		StockManagement();
	}
}


void ShowQueriedGoodsListToAdmin(GoodsList queried_goods)
{
	printf("-------------------------------------------------------\n");
	printf("%-5s %-12s %-6s %-6s %-15s %-5s\n", "ID", "����", "����", "�ۼ�", "��������", "����");
	TraverseGoodsList(queried_goods, DisplayGoodsInfo);
	printf("-------------------------------------------------------\n");
}

void LookUpGoodsByName(GoodsList head)
{
	char goods_name_prefix[MAXGOODSNAME] = { 0 };
	//char manufacturer_prefix[MAXMANUFACTURERNAME] = { 0 };

	printf("������Ʒ���ƻ�����ǰ׺\n>> ");
	scanf("%s", goods_name_prefix);
	GoodsList queried_goods = QueryGoodsByName(head, goods_name_prefix);
	ShowQueriedGoodsListToAdmin(queried_goods);
	DeleteGoodsList(queried_goods);
	system("pause");
	LookUpGoods(head);
}

void LookUpGoodsByManufacturer(GoodsList head)
{
	char manufacturer_prefix[MAXMANUFACTURERNAME] = { 0 };

	printf("������Ʒ���������ƻ�����������ǰ׺\n>> ");
	scanf("%s", manufacturer_prefix);
	GoodsList queried_goods = QueryGoodsByManufacturer(head, manufacturer_prefix);
	ShowQueriedGoodsListToAdmin(queried_goods);
	DeleteGoodsList(queried_goods);
	system("pause");
	LookUpGoods(head);
}

void LookUpGoodsByNameAndManufacturer(GoodsList head)
{
	char goods_name_prefix[MAXGOODSNAME] = { 0 };
	char manufacturer_prefix[MAXMANUFACTURERNAME] = { 0 };

	printf("������Ʒ���ƻ�����ǰ׺\n>> ");
	scanf("%s", goods_name_prefix);
	printf("������Ʒ���������ƻ�����������ǰ׺\n>> ");
	scanf("%s", manufacturer_prefix);
	GoodsList queried_goods = QueryGoodsByNameAndManufacturer(head, goods_name_prefix, manufacturer_prefix);
	ShowQueriedGoodsListToAdmin(queried_goods);
	DeleteGoodsList(queried_goods);
	system("pause");
	LookUpGoods(head);
}


void ClearStock(GoodsList head)
{
	char op[10];
	printf("�Ƿ�ɾ�����������Ϊ0����Ʒ (Y �� N)\n");
	scanf("%s", op);

	if (op[0] == 'Y' || op[0] == 'y') {
		RemoveZeroQuantityGoods(head);
		ExportGoodsToFile(head, OpenGoodsFile("w"));
		printf("������ɹ�\n");
		system("pause");
	}
	
	StockManagement();
}

void UserManagement()
{
	system("cls");
	int op = -1;

	printf("1) ����û�\n");
	printf("2) ����û�\n");
	printf("3) ɾ���û�\n");
	printf("0) �����ϼ�\n");

	printf(">> ");
	scanf("%d", &op);

	if (op == 1)
		LookOverUser();
	else if (op == 2)
		AddUser();
	else if (op == 3)
		DeleteUser();
	else
		AdminInitMenu();
}


void LookOverUser()
{
	system("cls");
	DisplayAccountInfo();
	system("pause");
	UserManagement();
}


void AddUser()
{
	system("cls");
	UserAccount ua;
	printf("�˺�\n>> ");
	scanf("%s", ua.account);
	printf("����\n>> ");
	scanf("%s", ua.password);
	
	char level[15] = { 0 };
	while (strcmp(level, "0") && strcmp(level, "1")) {
		printf("�û�Ȩ��(0-�ۻ�Ա  1-����Ա)\n>> ");
scanf("%s", level);
	}

	ua.permission_level = atoi(level);
	int ret = AddAccount(&ua);

	if (ret == 1) {
		printf("\n����û��ɹ�\n");
		printf("--------------------------------------\n");
		printf("%-10s %-10s  %-2s\n", "�˺�", "����", "Ȩ��");
		if (ua.permission_level)
			printf("%-10s %-10s %-2s\n", ua.account, ua.password, "����Ա");
		else
			printf("%-10s %-10s %-2s\n", ua.account, ua.password, "�ۻ�Ա");
		printf("--------------------------------------\n");


	}
	else if (ret == 0) {
		printf("���û��Ѵ���\n");
	}
	else
		printf("���ʧ��\n");

	system("pause");
	UserManagement();
}


void DeleteUser()
{
	system("cls");
	DisplayAccountInfo();
	char account[15];

	printf("\n�����ɾ���û����˺�\n>> ");
	scanf("%s", account);

	if (strcmp(account, "admin") == 0) {
		printf("�����û�, ����ɾ��\n");
	}
	else {
		int ret = DeleteAccount(account);
		if (ret == 1) {
			printf("ɾ���ɹ�\n");
		}
		else if (ret == -1) {
			printf("�޷�ɾ��\n");
		}
		else {
			printf("���û�������\n");
		}
	}

	system("pause");
	UserManagement();
	return;
}


void SoldManagement()
{
	GoodsList head = InitGoodsList();
	ImportGoodsFromFile(head, OpenGoodsFile("r"));
	SoldGoods(head);
	DeleteGoodsList(head);
	AdminInitMenu();
}


void SoldStatistics()
{
	system("cls");
	RecordsList head = InitRecordsList();
	ImportRecordsFromFile(head, OpenRecordsFile("r"));

	int op = -1;

	printf("1) �����¼\n");
	printf("2) �����¼\n");
	printf("3) ����ͳ��\n");
	printf("0) �����ϼ�\n");

	printf(">> ");
	scanf("%d", &op);

	if (op == 1)
		SingleDaySoldRecords(head);
	else if (op == 2)
		DaysSoldRecords(head);
	else if (op == 3)
		DaysSoldStatistics(head);
	else {
		AdminInitMenu();
		DeleteRecordsList(head);
	}
	
}


void SingleDaySoldRecords(RecordsList head)
{
	int year, month, day;

	printf("���������� �� ��\n>> ");

	scanf("%d %d %d", &year, &month, &day);

	if (year >= 1970 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
		SoldDate start = { year, month, day, 0, 0, 0 };
		SoldDate end = { year, month, day, 23, 59, 59 };

		QuerySoldRecordsByDate(head, start, end);
	}
	else {
		printf("��������\n");
	}
	system("pause");
	SoldStatistics();
}


void DaysSoldRecords(RecordsList head)
{
	int start_year, start_month, start_day;
	int end_year, end_month, end_day;

	printf("�����ѯ��ʼ���� �� �� ��\n>> ");
	scanf("%d %d %d", &start_year, &start_month, &start_day);

	printf("�����ѯ�������� �� �� ��\n>> ");
	scanf("%d %d %d", &end_year, &end_month, &end_day);

	if (start_year >= 1970 && end_year >= 1970 && start_year <= 9999 && end_year <= 9999 &&
		start_month >= 1 && end_month >= 1 && start_month <= 12 && end_month <= 12 &&
		start_day >= 1 && end_day >= 1 && start_day <= 31 && end_day <= 31) {
		SoldDate start = { start_year, start_month, start_day, 0, 0, 0 };
		SoldDate end = { end_year, end_month, end_day, 23, 59, 59 };

		QuerySoldRecordsByDate(head, start, end);
	}
	else {
		printf("��������\n");
	}
	system("pause");
	SoldStatistics();
}


void DaysSoldStatistics(RecordsList head)
{
	int start_year, start_month, start_day;
	int end_year, end_month, end_day;
	int min_sold_cnt = 0, min_earnings = 0;

	printf("�����ѯ��ʼ���� �� �� ��\n>> ");
	scanf("%d %d %d", &start_year, &start_month, &start_day);

	printf("�����ѯ�������� �� �� ��\n>> ");
	scanf("%d %d %d", &end_year, &end_month, &end_day);

	printf("������С����\n>> ");
	scanf("%d", &min_sold_cnt);

	printf("������С���۶�\n>> ");
	scanf("%d", &min_earnings);

	if (start_year >= 1970 && end_year >= 1970 && start_year <= 9999 && end_year <= 9999 &&
		start_month >= 1 && end_month >= 1 && start_month <= 12 && end_month <= 12 &&
		start_day >= 1 && end_day >= 1 && start_day <= 31 && end_day <= 31) {
		SoldDate start = { start_year, start_month, start_day, 0, 0, 0 };
		SoldDate end = { end_year, end_month, end_day, 23, 59, 59 };

		SoldStatisticsByDate(head, start, end, min_sold_cnt, min_earnings);
	}
	else {
		printf("��������\n");
	}
	system("pause");
	SoldStatistics();
}





