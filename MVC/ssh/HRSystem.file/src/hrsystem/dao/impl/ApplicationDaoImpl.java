package hrsystem.dao.impl;

import java.util.List;

import org.springframework.orm.hibernate5.support.HibernateDaoSupport;

import hrsystem.dao.ApplicationDao;
import hrsystem.domain.Application;
import hrsystem.domain.Employee;

public class ApplicationDaoImpl
	extends HibernateDaoSupport implements ApplicationDao
{

	public Application get(Integer id)
	{
		return getHibernateTemplate().get(Application.class, id);
	}

	public Integer save(Application application)
	{
		return (Integer)getHibernateTemplate().save(application);
	}

	public void update(Application application)
	{
		getHibernateTemplate().update(application);
	}

	public void delete(Application application)
	{
		getHibernateTemplate().delete(application);
	}

	public void delete(Integer id)
	{
		getHibernateTemplate().delete(get(id));
	}

	@SuppressWarnings("unchecked")
	public List<Application> findAll()
	{
		return (List<Application>)getHibernateTemplate().find("from Application");
	}

	@SuppressWarnings("unchecked")
	public List<Application> findByEmp(Employee emp)
	{
		return (List<Application>)getHibernateTemplate().find("from Application as a where "
			+ "a.attend.employee=?", emp);
	}
}
