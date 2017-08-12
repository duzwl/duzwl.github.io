package hrsystem.service;

import java.util.List;

import hrsystem.domain.*;
import hrsystem.vo.*;

public interface EmpManager
{
	//登录失败
	public static final int LOGIN_FAIL = 0;
	//以普通员工登录
	public static final int LOGIN_EMP = 1;
	//以经理登录
	public static final int LOGIN_MGR = 2;

	//不能打卡
	public static final int NO_PUNCH = 0;
	//只能上班打卡
	public static final int COME_PUNCH = 1;
	//只能下班打卡
	public static final int LEAVE_PUNCH = 2;
	//既可以上班，也可以下班打卡
	public static final int BOTH_PUNCH = 3;

	//打卡失败
	public static final int PUNCH_FAIL = 0;
	//已经打卡
	public static final int PUNCHED = 1;
	//打卡成功
	public static final int PUNCH_SUCC = 2;

	//以上午11点为上午时间
	public static final int AM_LIMIT = 11;

	//以上午9点之前为正常上班
	public static final int COME_LIMIT = 9;
	//以上午9~11点之间算迟到
	public static final int LATE_LIMIT = 11;
	//以下午18点之后算正常下班
	public static final int LEAVE_LIMIT = 18;
	//以上午16~18点之间算迟到
	public static final int EARLY_LIMIT = 16;

	// 以经理身份来验证登录：0为登录失败，1为登录emp 2为登录mgr
	int validLogin(Manager mgr);

	// 自动打卡，周一到周五，早上7：00为每个员工插入旷工记录
	void autoPunch();

	// 自动结算工资，每月1号，结算上个月工资
	void autoPay();

	// 验证某个员工是否可打卡，返回可打卡的类别
	int validPunch(String user , String dutyDay);

	// 打卡
	public int punch(String user , String dutyDay , boolean isCome);

	// 员工浏览自己的工资
	List<PaymentBean> empSalary(String empName);

	// 员工查看自己的最近三天非正常打卡
	List<AttendBean> unAttend(String empName);

	// 返回全部的出勤类别
	List<AttendType> getAllType();

	// 添加申请  attId:申请的出勤ID typeId:申请的类型ID
	boolean addApplication(int attId , int typeId , String reason);
}
