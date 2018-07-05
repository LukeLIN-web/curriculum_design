#include "stdafx.h"

Classroom* importInfo(uint &n)
{
	fstream in("Data/ClassroomInfo.txt", ostream::in);
	in >> n;
	Classroom *rooms = new Classroom[n + 1];   //����һ��������

	for (uint i = 0; i < n; i++) {
		uint campusType, buildID, roomID, roomType;
		uint seats, orderCnt, classCnt;
		uint ordered;
		in >> campusType >> buildID >> roomID >> roomType
			>> seats >> ordered >> orderCnt;
		for (uint cnt = 0; cnt < orderCnt; cnt++) {  //����ԤԼ��Ϣ
			classTime time;
			string ID, name, phoneNum;
			in >> time.classWeek >> time.week >> time.section;

			in >> ID >> name >> phoneNum;
			OrderInfo info(time, ID, name, phoneNum);
	
			rooms[i].addOrderInfo(info);
		}

		in >> classCnt;
		for (uint j = 0; j < classCnt; j++) {   //����γ���Ϣ
			string name, ID;
			uint sumClassCnt;
			vector < classTime > vec;
			in >> name >> ID >> sumClassCnt;

			for (uint k = 0; k < sumClassCnt; k++) {
				classTime ctf;
				in >> ctf.classWeek >> ctf.week >> ctf.section;
				vec.push_back(ctf);
			}
			ClassInfo info(name, ID, sumClassCnt, vec);
			rooms[i].addClassInfo(info);
		}

		rooms[i].setCampusType(campusType);
		rooms[i].setBuildID(buildID);
		rooms[i].setRoomID(roomID);
		rooms[i].setRoomType(roomType);
		rooms[i].setOrderStatus(ordered);
		rooms[i].setSeats(seats);
		rooms[i].setOrderCnt(orderCnt);
		rooms[i].setClassCnt(classCnt);
	}

	in.close();
	return rooms;
}

int cmp(const Classroom &a, const Classroom &b)
{
	if (a.getBuildID() == b.getBuildID()) {
		if (a.getBuildID() == b.getBuildID())
			return a.getRoomID() < b.getRoomID();
	}
	else
		return a.getBuildID() < b.getBuildID();
}

void outputInfo(int n, Classroom *rooms, int delRoom)   //��������ص��ļ�
{
	ofstream out("Data/ClassroomInfo.txt", ios::out);
	sort(rooms, rooms + n, cmp);
	if (delRoom == -1)
		out << n;
	else
		out << n - 1;                            //ɾ������
	for (int i = 0; i < n; i++) {
		if (i == delRoom)
			continue;
		out << "\n";
		out << rooms[i].getCampusType() << " " << rooms[i].getBuildID() << " "
			<< rooms[i].getRoomID() << " " << rooms[i].getRoomType() << " "
			<< rooms[i].getSeats() << " " << rooms[i].getOrderStatus() << " "
			<< rooms[i].getOrderCnt();
		vector <OrderInfo> vec = rooms[i].getOrderInfo();
		for (auto &e : vec)
			out << e;
		out << " " << rooms[i].getClassCnt();
		vector <ClassInfo> vec2 = rooms[i].getClassInfo();
		for (auto &e : vec2)
			out << e;
	}
}

bool isAdmin(const string &account, const string &passward)
{
	string authorizedAccount, authorizedPassward;
	ifstream in("Data/AdminAccount.txt", ios::in);
	while (in >> authorizedAccount >> authorizedPassward) {
		if (account == authorizedAccount && authorizedPassward == passward) {
			in.close();
			return 1;
		}
	}
	in.close();
	return 0;
}

void addAdmin(const string &account, const string &passward)
{
	ofstream out("Data/AdminAccount.txt", ios::app);
	out << '\n' << account << " " << passward;
	out.close();
}

uint chooseCampus()
{
	system("cls");
	uint campus;
	cout << "����У�����                  " << endl;;
	cout << "1:������У�� 2:��ɽ·У�� 3:��ԭ·У��" << endl;;
	cout << "> ";
	cin >> campus;

	if (campus < 1 || campus > CAMPUSCNT)
		return -1;
	return campus;
}

uint chooseBuildID()
{
	uint buildID;
	cout << "����¥�� " << endl;
	cout << "> ";
	cin >> buildID;

	return buildID;
}

void chooseRoom(uint &campus, uint &buildID, uint &roomID)
{
	campus = chooseCampus();
	buildID = chooseBuildID();
	cout << "������Һ� " << endl;
	cin >> roomID;
}

void printLine()
{
	cout << "--------------------------------" << endl;
}

int cmpRoomID(Classroom &a, Classroom &b)
{
	return a.getRoomID() < b.getRoomID();
}

void back()
{
	cout << endl << ">�س�����" << endl;
	getchar();
	getchar();
}

void disOneBuildRoomsInfo(uint campus, uint buildID, uint n, Classroom *rooms)
{
	vector <Classroom> OneBuildRooms;
	int found = 0;

	for (uint i = 0; i < n; i++) {
		if (rooms[i].getCampusType() == campus && rooms[i].getBuildID() == buildID) {
			OneBuildRooms.push_back(rooms[i]);
			found = 1;
		}
	}

	if (found) {
		sort(OneBuildRooms.begin(), OneBuildRooms.end(), cmpRoomID);
		cout << left << setw(8) << "���Һ�" << setw(15) << "��������" << setw(10) << "��λ��" << setw(10) << "ԤԼ��" << setw(10) << "�γ���" << endl;
		for (auto &e : OneBuildRooms)
			cout << left << setw(8) << e.getRoomID() << setw(15) << CLASSROOMTYPE[e.getRoomType()] << setw(10)
			<< e.getSeats() << setw(10) << e.getOrderCnt() << setw(10) << e.getClassCnt() << endl;
	}
	else
		cout << "δ�ҵ������Ϣ" << endl;

	back();
}

void displayClassType()
{
	printLine();
	for (int i = 1; i <= CLASSROOMTYPECNT; i++)
		cout << setw(3) << left << i << ")  "  << setw(15) << CLASSROOMTYPE[i] << endl;
	printLine();
}

void addClassRooms(uint n, Classroom *rooms)
{
	uint campus, buildID, classRoomType, classRoomID, seats;
	campus = chooseCampus();
	buildID = chooseBuildID();
	cout << "����������Һ� �������� ��λ��" << endl;
	displayClassType();
	cout << "> ";
	cin >> classRoomID >> classRoomType >> seats;

	bool exit = 0;
	for (uint i = 0; i < n; i++) {
		if (rooms[i].getCampusType() == campus && rooms[i].getBuildID() == buildID && rooms[i].getRoomID() == classRoomID)
		{
			exit = 1;
			break;
		}
	}

	if (!exit) {
		rooms[n].setCampusType(campus);
		rooms[n].setBuildID(buildID);
		rooms[n].setRoomID(classRoomID);
		rooms[n].setRoomType(classRoomType);
		rooms[n].setSeats(seats);
		outputInfo(n + 1, rooms);
		cout << "����ɹ�" << endl;
	}
	else {
		cout << "�ý����Ѵ���" << endl;
	}
}

void addClassInfo(uint n, Classroom *rooms)
{
	uint campus, buildID, roomID;
	string name, ID;
	uint classCnt;
	vector<classTime> times;
	classTime time;

	chooseRoom(campus, buildID, roomID);
	int i = findRoomIndex(n, rooms, campus, buildID, roomID);

	if (i == -1) {
		cout << "δ��ѯ���ý���" << endl;
		return;
	}
	
	cout << "�����ʦ����" << endl;
	cout << "> ";
	cin >> name;
	cout << "�����ʦ��" << endl;
	cout << "> ";
	cin >> ID;
	cout << "�����Ͽδ���" << endl;
	cin >> classCnt;
	cout << "���������Ͽ�ʱ�� (��ʱ�� �� ��)" << endl;

	for (int j = 0; j < classCnt; j++) {
		cin >> time.classWeek >> time.week >> time.section;
		times.push_back(time);
	}

	ClassInfo info(name, ID, classCnt, times);
	rooms[i].addClassInfo(info);

	outputInfo(n, rooms);
	cout << "���ӳɹ�" << endl;
	
}


int findRoomIndex(uint n, Classroom *rooms, uint campus, uint buildID, uint roomID)
{
	int  index = -1;

	for (uint i = 0; i < n; i++) {
		if (rooms[i].getCampusType() == campus && rooms[i].getRoomID() == roomID
			&& rooms[i].getBuildID() == buildID) {
			index = i;
			break;
		}
	}
	return index;
}

void modifyRoomType(uint n, Classroom *rooms)
{
	uint campus, buildID;
	uint roomID;
	chooseRoom(campus, buildID, roomID);

	uint index = findRoomIndex(n, rooms, campus, buildID, roomID);
	if (index == -1) {
		cout << "δ�ҵ��ý���" << endl;
		back();
		adminSystem();
	}
	else {
		int op;
		while (1) {
			cout << "����Ҫ�޸ĵ���Ϣ���" << endl;
			cout << "1) ��������  2)��λ��  ����)�˳�" << endl;
			cout << "> ";
			cin >> op;
			if (op == 1) {
				int type;
				displayClassType();
				cout << "> ";
				cin >> type;
				rooms[index].setRoomType(type);
			}
			else if (op == 2) {
				int seats;
				cout << "������λ��" << endl;
				cout << "> ";
				cin >> seats;
				rooms[index].setSeats(seats);
			}
			else
				break;
		}
	}

	outputInfo(n, rooms);
	cout << "�޸ĳɹ�" << endl;
	back();
	adminSystem();
}

void displyRoomDetailInfo(uint n, Classroom *rooms)
{
	uint campus, buildID, roomID;
	chooseRoom(campus, buildID, roomID);

	uint i = findRoomIndex(n, rooms, campus, buildID, roomID);
	if (i == -1)
		cout << "δ�ҵ��ý���" << endl;
	else {
		printLine();
		cout << "У��: " << CAMPUSTYPE[rooms[i].getCampusType()] << endl;
		cout << "��ѧ¥��" << rooms[i].getBuildID() << endl;
		cout << "���Һţ�" << rooms[i].getRoomID() << endl;
		cout << "�������ͣ�" << CLASSROOMTYPE[rooms[i].getRoomType()] << endl;
		cout << "��λ����" << rooms[i].getSeats() << endl;
		cout << "ԤԼ״̬��" << rooms[i].getOrderStatus() << endl;
		cout << endl;
		cout << "ԤԼ����" << rooms[i].getOrderCnt() << endl;
		for (uint j = 0; j < rooms[i].getOrderCnt(); j++) {
			cout << endl;
			cout << "ԤԼ" << j+1 << "��" << endl;
			cout << "ԤԼʱ�䣺" << rooms[i].getOrderInfo()[j].getClassTime() << endl;
			cout << "ѧ��/�̹��ţ�" << rooms[i].getOrderInfo()[j].getID() << endl;
			cout << "������" << rooms[i].getOrderInfo()[j].getName() << endl;
			cout << "�绰��" << rooms[i].getOrderInfo()[j].getPhoneNum() << endl;
		}
		cout << endl;
		cout << "�γ�����" << rooms[i].getClassCnt() << endl;
		for (uint j = 0; j < rooms[i].getClassCnt(); j++) {
			cout << endl;
			cout << "�γ�" << j+1 << "��" << endl;
			cout << "��ʦ������" << rooms[i].getClassInfo()[j].getName() << endl;
			cout << "�̹��ţ�" << rooms[i].getClassInfo()[j].getID() << endl;
			cout << "�ܿγ�����" << rooms[i].getClassInfo()[j].getSumClassCnt() << endl;
			cout << "�Ͽ�ʱ�䣺" << endl;
			
			for (auto &e : rooms[i].getClassInfo()[j].getClassTime()) {
				cout << e << " ";
					cout << endl;
			}
			cout << endl;
		}
		printLine();
	}
	back();
}

int isVancant(const Classroom &room, const classTime &time)
{
	int noOrdered = 1, noClass = 1;
	for (auto &e : room.getOrderInfo()) {
		if (e.getClassTime() == time) {
			noOrdered = 0;
			break;
		}
	}

	for (auto &e : room.getClassInfo())
		for (auto &t : e.getClassTime()) {
			if (t == time) {
				noClass = 0;
				break;
			}
		}
	if (noOrdered && noClass)
		return 1;
	else if (!noOrdered)
		return 0;
	else
		return -1;
	
}

void queryVancantRooms(uint n, Classroom *rooms, uint campus, uint buildID, const classTime &time, uint minSeats, uint roomType)
{
	printLine();
	int found = 0;
	for (uint i = 0; i < n; i++) {
		if (rooms[i].getCampusType() == campus && rooms[i].getBuildID() == buildID && rooms[i].getSeats() >= minSeats && rooms[i].getRoomType() == roomType) {
			if (isVancant(rooms[i], time)) {
				if (!found)
					cout << left << setw(8) << "���Һ�" << setw(15) << "��������" << setw(10) << "��λ��" << endl;
				cout << left << setw(8) << rooms[i].getRoomID() << setw(15) << CLASSROOMTYPE[rooms[i].getRoomType()] << setw(10)
					<< rooms[i].getSeats() << endl;
				found = 1;
			}

		}
	}
	if (!found)
		cout << "δ��ѯ�����������Ľ���" << endl;

	printLine();
	back();
	regularSystem();
}

void queryVancantRooms(uint n, Classroom *rooms, uint campus, uint buildID, const classTime &time, uint minSeats)
{
	printLine();
	int found = 0;
	for (uint i = 0; i < n; i++) {
		if (rooms[i].getCampusType() == campus && rooms[i].getBuildID() == buildID && rooms[i].getSeats() >= minSeats) {
			if (isVancant(rooms[i], time)) {
				if (!found)
					cout << left << setw(8) << "���Һ�" << setw(15) << "��������" << setw(10) << "��λ��" << endl;
				cout << left << setw(8) << rooms[i].getRoomID() << setw(15) << CLASSROOMTYPE[rooms[i].getRoomType()] << setw(10)
					<< rooms[i].getSeats() << endl;
				found = 1;
			}

		}
	}
	if (!found)
		cout << "δ��ѯ�����������Ľ���" << endl;

	printLine();
	back();
	regularSystem();
}

void orderVancantRooms(uint n, Classroom *rooms, uint campus, uint buildID, uint roomID, const classTime &time)
{
	int found = 0;
	for (uint i = 0; i < n; i++) {
		if (rooms[i].getCampusType() == campus && rooms[i].getBuildID() == buildID && rooms[i].getRoomID() == roomID)
		{
			found = 1;
			int ret = isVancant(rooms[i], time);
			if (ret == 1) {
				string ID, name, phoneNum;
				cout << "����ѧ��/�̹��ţ�" << endl << "> ";
				cin >> ID;
				cout << "����������" << endl << "> ";
				cin >> name;
				cout << "����绰��" << endl << "> ";
				cin >> phoneNum;

				OrderInfo info(time, ID, name, phoneNum);
				rooms[i].addOrderInfo(info);
				outputInfo(n, rooms);
				printLine();
				cout << "ԤԼ�ɹ�!" << endl;
				cout << time << " " << ID << " " << name << " " << phoneNum << endl;
			}
			else if (ret == 0) {
				cout << "��ʱ����ѱ�ԤԼ" << endl;
			}
			else {
				cout << "��ʱ����п��ý�ѧ" << endl;
			}
		}
	}
	if (!found)
		cout << "δ��ѯ���ý�����Ϣ" << endl;
}

//ͳ��ĳУ���������ͽ������Ͽ��ʡ���ԤԼ��
void statistics(uint n, Classroom *rooms, uint campus)
{
	printLine();
	uint weekClass[CLASSROOMTYPECNT+1][CLASSWEEKCNT+1][8];
	uint weekOrder[CLASSROOMTYPECNT+1][CLASSWEEKCNT+1][8];
	memset(weekClass, 0, sizeof(weekClass));
	memset(weekOrder, 0, sizeof(weekOrder));

	for (uint i = 0; i < n; i++)
	{
		
		for (uint roomtype = 1; roomtype <= CLASSROOMTYPECNT; roomtype++)
		{
			if (rooms[i].getCampusType() == campus && rooms[i].getRoomType() == roomtype)
			{
				for (auto &e : rooms[i].getOrderInfo()) {
					weekOrder[roomtype][e.getClassTime().classWeek][e.getClassTime().week]++;
				}
				for (auto &e : rooms[i].getClassInfo()) {
					for (auto &ee : e.getClassTime()) {
						weekClass[roomtype][ee.classWeek][ee.week]++;
					}
				}
			}
		}
	}
	
	for (uint roomtype = 1; roomtype <= CLASSROOMTYPECNT; roomtype++) {
		double sumWeekClass = 0, averWeekClass = 0;
		double sumWeekOrder = 0, averWeekOrder = 0;
		for (int i = 1; i <= CLASSWEEKCNT; i++) {
			for (int j = 1; j <= 7; j++) {
				sumWeekClass += weekClass[roomtype][i][j];
				sumWeekOrder += weekOrder[roomtype][i][j];
			}
		}
		averWeekClass = sumWeekClass / (CLASSWEEKCNT * 7 * ONEDAYCLASSCNT);
		averWeekOrder = sumWeekOrder / (CLASSWEEKCNT * 7 * ONEDAYCLASSCNT);

		cout << CLASSROOMTYPE[roomtype] << "ʹ�������" << endl;
		cout << "            ���Ͽ��ʣ�" << averWeekClass * 100 << "%" << endl;
		cout << "            ��ԤԼ�ʣ�" << averWeekOrder * 100 << "%" << endl;
		cout << endl;
	}
	printLine();

}

void start()
{
	printLine();
	cout << endl;
	cout << "        ���ҹ���ϵͳV1.0             " << endl << endl;
	cout << "       Created By GaoTian        " << endl;
	cout << endl;
	printLine();
}

void choosePermission()
{
	system("cls");
	printLine();
	int op;
	cout << endl;
	cout << "        1)  ����Ա                " << endl;
	cout << "        2) ѧ��/��ʦ              " << endl;
	cout << "        3)   �˳�                 " << endl;
	cout << endl;
	printLine();
	cout << endl << "> ";
	cin >> op;

	if (op == 1)
		enterAdminSystem();
	else if (op == 2)
		regularSystem();
	else if (op == 3)
		exitSystem();
	else 
		choosePermission();

	
}

int adminWrangCope()
{
	int op;
	system("cls");
	cout << "�˻����������        " << endl << endl;
	cout << "1) ��������            " << endl;
	cout << "2) �����ϼ�            " << endl;
	cout << "3)  �˳�               " << endl;
	cout << "> ";
	cin >> op;
	return op;
}

void enterAdminSystem()
{
	system("cls");

	string account, passward;
	cout << "�����˻���" << endl;
	cout << "> ";
	cin >> account;
	cout << "�������룺" << endl;
	cout << "> ";
	cin >> passward;

	if (isAdmin(account, passward))
		adminSystem();
	else {
		int op = adminWrangCope();
		if (op == 1)
			enterAdminSystem();
		else if (op == 2)
			choosePermission();
		else if (op == 3)
			exitSystem();
		else
			enterAdminSystem();
	}

}

void adminLookUpInfo()
{
	system("cls");
	cout << "1) ͳ��ĳ¥������Ϣ" << endl;
	cout << "2) ��ϸ�鿴ĳ������Ϣ" << endl;
	cout << "����) �����ϼ�" << endl;
	cout << "> ";
	int op;

	cin >> op;
	if (op == 1) {
		uint n;
		Classroom *rooms = importInfo(n);
		uint campus = chooseCampus();
		uint buildID = chooseBuildID();
		disOneBuildRoomsInfo(campus, buildID, n, rooms);
		delete[] rooms;
		adminSystem();
	}
	else if (op == 2) {
		uint n;
		Classroom *rooms = importInfo(n);
		displyRoomDetailInfo(n, rooms);

		delete[] rooms;
		adminSystem();
	}
	else
		adminSystem();
}

void adminModifyInfo()
{
	uint n;
	Classroom *rooms = importInfo(n);
	modifyRoomType(n, rooms);
	delete[] rooms;
}

void adminAddInfo()
{
	uint n;
	Classroom *rooms = importInfo(n);
	addClassRooms(n, rooms);
	delete[] rooms;
	back();
	adminSystem();
}

void adminAddAccount()
{
	system("cls");

	string account, passward;
	cout << "����������˻���" << endl;
	cout << "> ";
	cin >> account;
	cout << "�������룺" << endl;
	cout << "> ";
	cin >> passward;
	addAdmin(account, passward);
	cout << endl << "����ɹ�" << endl;
	back();
	adminSystem();
}

void adminDeleteInfo()
{
	system("cls");
	uint n;
	Classroom *rooms = importInfo(n);

	uint campus, buildID, roomID;
	cout << "����ɾ����ɾ������У���� ��ѧ¥�� ���Һ�" << endl;
	chooseRoom(campus, buildID, roomID);

	int i = findRoomIndex(n, rooms, campus, buildID, roomID);
	if (i == -1) 
		cout << "δ��ѯ���ý���" << endl;
	else {
		outputInfo(n, rooms, i);
		cout << "ɾ���ɹ�" << endl;	
	}

	delete[] rooms;
	back();
	adminSystem();
}

void adminStatistics()
{
	uint n;
	Classroom *rooms = importInfo(n);
	uint campus = chooseCampus();
	statistics(n, rooms, campus);

	delete[] rooms;
	back();
	adminSystem();
}

void adminAddClassInfo()
{
	system("cls");
	uint n;
	Classroom *rooms = importInfo(n);
	addClassInfo(n, rooms);

	delete[] rooms;
	back();
	adminSystem();
}

void adminSystem()
{
	system("cls");
	cout << "1) �鿴��Ϣ" << endl;
	cout << "2) �޸���Ϣ" << endl;
	cout << "3) ���ӽ���" << endl;
	cout << "4) ɾ������" << endl;
	cout << "5) ���ӹ���Ա" << endl;
	cout << "6) �����Ͽ���Ϣ" << endl;
	cout << "7) ͳ��ʹ�����" << endl;
	cout << "����) �˳�" << endl;
	cout << "> ";
	int op;
	cin >> op;

	if (op == 1)
		adminLookUpInfo();
	else if (op == 2)
		adminModifyInfo();
	else if (op == 3)
		adminAddInfo();
	else if (op == 4)
		adminDeleteInfo();
	else if (op == 5)
		adminAddAccount();
	else if (op == 6)
		adminAddClassInfo();
	else if (op == 7)
		adminStatistics();
	else
		exitSystem();
}

bool timeCorrect(const classTime &time)
{
	if (time.classWeek >= 1 && time.classWeek <= CLASSWEEKCNT && time.week >= 1 && time.week <= 7
		&& time.section >= 1 && time.section <= ONEDAYCLASSCNT)
		return 1;
	else
		return 0;
}

void regularQuery()
{
	system("cls");
	uint n;
	Classroom *rooms = importInfo(n);
	uint campus, buildID, minSeats, roomType;
	classTime time;

	campus = chooseCampus();
	buildID = chooseBuildID();
	cout << "����ʱ�� (��ʱ�� �� ��)" << endl;
	cout << "> ";
	cin >> time.classWeek >> time.week >> time.section;
	cout << "������С��λ�� (0Ϊȫ��)" << endl;
	cout << "> ";
	cin >> minSeats;
	cout << "����������� (0λȫ��)" << endl;
	displayClassType();
	cout << "> ";
	cin >> roomType;

	if (timeCorrect(time))
	{
		if (roomType == 0)
			queryVancantRooms(n, rooms, campus, buildID, time, minSeats);
		else if (roomType >= 1 && roomType <= CLASSROOMTYPECNT)
			queryVancantRooms(n, rooms, campus, buildID, time, minSeats, roomType);
		else {
			cout << "���������������" << endl;
			back();
			regularQuery();
		}
	}
	else {
		cout << "��ѯʱ�����" << endl;
		back();
		regularQuery();
	}

	delete[] rooms;

}

void regularOrder()
{
	system("cls");
	uint n;
	Classroom *rooms = importInfo(n);
	uint campus, buildID, roomID;
	classTime time;

	chooseRoom(campus, buildID, roomID);
	cout << "����ʱ�� (��ʱ�� �� ��)" << endl;
	cout << "> ";
	cin >> time.classWeek >> time.week >> time.section;

	if (timeCorrect(time)) {
		orderVancantRooms(n, rooms, campus, buildID, roomID, time);
		back();
		regularSystem();
	}
	else {
		cout << "ԤԼʱ�����" << endl;
		back();
		regularOrder();
	}

	delete[] rooms;
}


void regularSystem()
{
	system("cls");
	cout << "1) ��ѯ���н���" << endl;
	cout << "2) ԤԼ���н���" << endl;
	cout << "����) �˳�" << endl;
	cout << "> ";
	int op;
	cin >> op;

	if (op == 1)
		regularQuery();
	else if (op == 2)
		regularOrder();
	else
		exitSystem();
}

void exitSystem()
{
	system("cls");
	printLine();
	cout << endl;
	cout << "          �� ����               ";
	cout << endl << endl;
	printLine();
	getchar();
	getchar();
}