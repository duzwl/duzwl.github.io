package hrsystem.dao.impl;

import java.util.List;

import org.springframework.orm.hibernate5.support.HibernateDaoSupport;

import hrsystem.dao.*;
import hrsystem.domain.*;

public class ManagerDaoImpl
	extends HibernateDaoSupport implements ManagerDao
{

	public Manager get(Integer id)
	{
		return getHibernateTemplate().get(Manager.class , id);
	}

	public String save(Manager manager)
	{
		return (String)getHibernateTemplate().save(manager);
	}
	
	public void update(Manager manager)
	{
		getHibernateTemplate().update(manager);
	}
	
	public void delete(Manager manager)
	{
		getHibernateTemplate().delete(manager);
	}
	
	public void delete(Integer id)
	{
		getHibernateTemplate().delete(get(id));
	}
	
	@SuppressWarnings("unchecked")
	public List<Manager> findAll()
	{
		return (List<Manager>)getHibernateTemplate().find("from Manager");
	}
	
	@SuppressWarnings("unchecked")
	public List<Manager> findByNameAndPass(Manager mgr)
	{
		return (List<Manager>)getHibernateTemplate()
			.find("from Manager m where m.name = ? and m.pass=?"
			, mgr.getName(), mgr.getPass());
	}

	public Manager findByName(String name)
	{
		@SuppressWarnings("unchecked")
		List<Manager> ml = (List<Manager>)getHibernateTemplate()
			.find("from Manager m where m.name=?" , name);
		if (ml != null && ml.size() > 0)
		{
			return ml.get(0);
		}
		return null;
	}
}
