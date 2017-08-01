package hrsystem.dao.impl;

import java.util.List;

import org.springframework.orm.hibernate5.support.HibernateDaoSupport;

import hrsystem.dao.*;
import hrsystem.domain.*;

public class AttendTypeDaoImpl
	extends HibernateDaoSupport implements AttendTypeDao
{

	public AttendType get(Integer id)
	{
		return getHibernateTemplate().get(AttendType.class, id);
	}
	
	public Integer save(AttendType attendType)
	{
		return (Integer)getHibernateTemplate().save(attendType);
	}
	
	public void update(AttendType attendType)
	{
		getHibernateTemplate().update(attendType);
	}
	
	public void delete(AttendType attendType)
	{
		getHibernateTemplate().delete(attendType);
	}

	public void delete(Integer id)
	{
		getHibernateTemplate().delete(get(id));
	}
	
	@SuppressWarnings("unchecked")
	public List<AttendType> findAll()
	{
		return (List<AttendType>)getHibernateTemplate().find("from AttendType");
	}
}
