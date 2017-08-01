package hrsystem.dao.impl;

import java.util.List;

import org.springframework.orm.hibernate5.support.HibernateDaoSupport;

import hrsystem.dao.*;
import hrsystem.domain.*;

public class CheckBackDaoImpl
	extends HibernateDaoSupport implements CheckBackDao
{

	public CheckBack get(Integer id)
	{
		return getHibernateTemplate().get(CheckBack.class, id);
	}

	public Integer save(CheckBack checkBack)
	{
		return (Integer)getHibernateTemplate().save(checkBack);
	}
	
	public void update(CheckBack checkBack)
	{
		getHibernateTemplate().update(checkBack);
	}

	public void delete(CheckBack checkBack)
	{
		getHibernateTemplate().delete(checkBack);
	}

	public void delete(Integer id)
	{
		getHibernateTemplate().delete(get(id));
	}
	
	@SuppressWarnings("unchecked")
	public List<CheckBack> findAll()
	{
		return (List<CheckBack>)getHibernateTemplate().find("from CheckBack");
	}
}
