#include"stdafx.h"
#include"Operate.h"


Operate::Operate() {

	//��ʼ�����ݿ�  
	mysql_library_init(0, NULL, NULL);

	//��ʼ�����ݽṹ  
	mysql_init(&mydata);

	//���������ݿ�֮ǰ�����ö��������ѡ��  
	//�������õ�ѡ��ܶ࣬���������ַ����������޷���������  
	mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gbk");

	//�������ݿ�  
	mysql_real_connect(&mydata, "localhost", "root", "root", "root", 3306, NULL, 0);
}

string Operate::IntToString(int variable)
{
	stringstream ss;
	string str;
	ss << variable;
	ss >> str;
	return str;
}

int Operate::StringToInt(string variable)
{
	return atoi(variable.c_str());
}


bool Operate::InsertIntoUserTable(userStruct User) {
	string sqlstr;
	//����в�������  
	sqlstr =
		"INSERT INTO user VALUES(null,"+User.UserName+","+IntToString(User.StudentId)+","+User.Gender+","+User.PassWord+","+User.Image+","+User.UserQQ+", "+IntToString(User.Phone)+","+User.Email+","+User.University+","+User.LocateArea+","+User.SelfTag+","+IntToString(User.PlayTime)+");";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		return true;
	}
	else {
		return false;
	}
}

/*
bool Operate::InsertIntoEventNameTable(EventNameStruct Event)
{

}

bool Operate::InsertIntoEventDetailsTable(EventDetailsStruct Event)
{

}

bool Operate::InsertIntoStationMessageable(StationMessageStruct StationMessage)
{

}

string Operate::GetPasswordFromUserTable(string username)
{

}

vector<userStruct> Operate::GetUserDetails(string username)
{

}

vector<EventDetailsStruct> Operate::GetEvent(string StartSite, string EndSite, string StartTime)
{

}

vector<StationMessageStruct> Operate::GetMessageBySender(string SenderName)
{

}
vector<StationMessageStruct> Operate::GetMessageByReceiver(string ReceiverName)
{

}
*/