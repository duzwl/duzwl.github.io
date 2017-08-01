package hrsystem.dao;

import java.util.*; 

import hrsystem.domain.*;

public interface AttendTypeDao
{

	AttendType get(Integer id);
	Integer save(AttendType attendType);
	void update(AttendType attendType);
	void delete(AttendType attendType);
	void delete(Integer id);
	List<AttendType> findAll();
}
