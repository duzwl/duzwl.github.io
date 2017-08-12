package hrsystem.dao;

import java.util.*; 

import hrsystem.domain.*;

public interface EmployeeDao
{

	Employee get(Integer id);
	Integer save(Employee employee);
	void update(Employee employee);
	void delete(Employee employee);
	void delete(Integer id);
	List<Employee> findAll();
	List<Employee> findByNameAndPass(Employee emp);
	Employee findByName(String name);
	List<Employee> findByMgr(Manager mgr);
}
