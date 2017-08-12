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
	// �鿴Ա��ǰ����ķ�������
	List<Attend> findByEmpUnAttend(Employee emp, AttendType type);
}
