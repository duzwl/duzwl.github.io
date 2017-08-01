package hrsystem.dao.impl;

import java.util.List;

import org.springframework.orm.hibernate5.support.HibernateDaoSupport;

import hrsystem.dao.*;
import hrsystem.domain.*;

public class EmployeeDaoImpl
	extends HibernateDaoSupport
	implements EmployeeDao
{

	public Employee get(Integer id)
	{
		return getHibernateTemplate().get(Employee.class, id);
	}

	public Integer save(Employee employee)
	{
		return (Integer)getHibernateTemplate().save(employee);
	}
	
	public void update(Employee employee)
	{
		getHibernateTemplate().update(employee);
	}
	
	public void delete(Employee employee)
	{
		getHibernateTemplate().delete(employee);
	}

	public void delete(Integer id)
	{
		getHibernateTemplate().delete(get(id));
	}

	@SuppressWarnings("unchecked")
	public List<Employee> findAll()
	{
		return (List<Employee>)getHibernateTemplate().find("from Employee");
	}
	
	@SuppressWarnings("unchecked")
	public List<Employee> findByNameAndPass(Employee emp)
	{
		return (List<Employee>)getHibernateTemplate()
			.find("from Employee p where p.name = ? and p.pass=?"
			, emp.getName(), emp.getPass());
	}
	
	public Employee findByName(String name)
	{
		@SuppressWarnings("unchecked")
		List<Employee> emps = (List<Employee>)getHibernateTemplate()
			.find("from Employee where name = ? ", name);
		if (emps!= null && emps.size() >= 1)
		{
			return emps.get(0);
		}
		return null;
	}
	
	@SuppressWarnings("unchecked")
	public List<Employee> findByMgr(Manager mgr)
	{
		return (List<Employee>)getHibernateTemplate()
			.find("from Employee as e where "
			+ "e.manager = ?" , mgr);
	}
}
