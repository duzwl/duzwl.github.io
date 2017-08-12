package hrsystem.dao;

import java.util.*; 

import hrsystem.domain.*;

public interface AttendDao
{

	Attend get(Integer id);
	Integer save(Attend attend);
	void update(Attend attend);
	void delete(Attend attend);
	void delete(Integer id);
	List<Attend> findAll();
	List<Attend> findByEmp(Employee emp);
	List<Attend> findByEmpAndDutyDay(Employee emp, String dutyDay);
	Attend findByEmpAndDutyDayAndCome(Employee emp, 
		String dutyDay, boolean isCome);
	// 查看员工前三天的非正常打卡
	List<Attend> findByEmpUnAttend(Employee emp, AttendType type);
}
