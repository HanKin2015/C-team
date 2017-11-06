#pragma once
#include"SQLStruct.h"
#include"stdafx.h"
#include<vector>


class Operate {
public:
	Operate();

	string IntToString(int variable);
	int StringToInt(string variable);

	bool InsertIntoUserTable(userStruct User);
	bool InsertIntoEventTable(EventStruct Event);
	bool InsertIntoStationMessageable(StationMessageStruct StationMessage);
	bool UpdateUserTable(userStruct User);//�����޸�������޸��������
	bool UpdatePassword(string UserName, string Password);
	bool InsertIntoSecretSecurity(SecretSecurityStruct Security);
	bool joinEvent(int EventID, string username);
	bool setEventState(int Eventid, int State);//���û״̬
	string GetSecretSecurity(string UserName);

	bool DeleteDataParticipants(int EventID, string UserName);//ɾ��Participants���ض�����

	vector<userStruct> LikeUserName(string username);//ģ�������û���

	string GetPasswordFromUserTable(string username);
	userStruct GetUserDetails(string username);
	vector<EventStruct> GetEvent(string StartSite, string EndSite, string StartTime, string EventType);
	vector<EventStruct> GetEventByState(int State);//ͨ���״̬��ѯ�
	vector<EventStruct> GetEventByLike(string StartSite, string EndSite);//��ʼ�غͽ�����ģ����ѯ
	vector<string> GetParticipants(int EventId);
	
	vector<StationMessageStruct> GetMessageBySender(string SenderName);
	vector<StationMessageStruct> GetMessageByReceiver(string ReceiverName);
	EventStruct GetEventDetailById(int EventId);
public:
	MYSQL mydata;
};
