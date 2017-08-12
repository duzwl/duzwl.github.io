package hrsystem.dao;

import java.util.*; 

import hrsystem.domain.*;

public interface ApplicationDao
{

	Application get(Integer id);
	Integer save(Application application);
	void update(Application application);
	void delete(Application application);
	void delete(Integer id);
	List<Application> findAll();
	List<Application> findByEmp(Employee emp);
}
