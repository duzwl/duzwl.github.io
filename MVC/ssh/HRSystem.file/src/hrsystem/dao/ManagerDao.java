package hrsystem.dao;

import java.util.*; 

import hrsystem.domain.*;

public interface ManagerDao
{

	Manager get(Integer id);
	String save(Manager manager);
	void update(Manager manager);
	void delete(Manager manager);
	void delete(Integer id);
	List<Manager> findAll();
	List<Manager> findByNameAndPass(Manager mgr);
	Manager findByName(String name);
}
