package hrsystem.dao.impl;

import java.util.List;

import org.springframework.orm.hibernate5.support.HibernateDaoSupport;

import hrsystem.dao.*;
import hrsystem.domain.*;

public class PaymentDaoImpl
	extends HibernateDaoSupport implements PaymentDao
{

	public Payment get(Integer id)
	{
		return getHibernateTemplate().get(Payment.class , id);
	}

	public Integer save(Payment payment)
	{
		return (Integer)getHibernateTemplate().save(payment);
	}
	
	public void update(Payment payment)
	{
		getHibernateTemplate().update(payment);
	}

	public void delete(Payment payment)
	{
		getHibernateTemplate().delete(payment);
	}

	public void delete(Integer id)
	{
		getHibernateTemplate().delete(get(id));
	}

	@SuppressWarnings("unchecked")
	public List<Payment> findAll()
	{
		return (List<Payment>)getHibernateTemplate().find("from Payment");
	}

	@SuppressWarnings("unchecked")
	public List<Payment> findByEmp(Employee emp)
	{
		return (List<Payment>)getHibernateTemplate().find("from Payment as p where p.employee=?" , emp);
	}

	@SuppressWarnings("unchecked")
	public Payment findByMonthAndEmp(String payMonth 
		 , Employee emp)
	{
		List<Payment> pays = (List<Payment>)getHibernateTemplate()
			.find("from Payment as p where p.employee=? and p.payMonth=?"
			, new Object[]{emp , payMonth});
		if (pays != null && pays.size() > 0)
		{
			return pays.get(0);
		}
		return null;
	}
}
