package hrsystem.dao.impl;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.List;

import org.springframework.orm.hibernate5.support.HibernateDaoSupport;

import hrsystem.dao.AttendDao;
import hrsystem.domain.Attend;
import hrsystem.domain.AttendType;
import hrsystem.domain.Employee;

public class AttendDaoImpl
	extends HibernateDaoSupport implements AttendDao
{

	public Attend get(Integer id)
	{
		return getHibernateTemplate().get(Attend.class , id);
	}
	
	public Integer save(Attend attend)
	{
		return (Integer)getHibernateTemplate().save(attend);
	}
	
	public void update(Attend attend)
	{
		getHibernateTemplate().update(attend);
	}
	
	public void delete(Attend attend)
	{
		getHibernateTemplate().delete(attend);
	}
	
	public void delete(Integer id)
	{
		getHibernateTemplate().delete(get(id));
	}
	
	@SuppressWarnings("unchecked")
	public List<Attend> findAll()
	{
		return (List<Attend>)getHibernateTemplate().find("from Attend");
	}
	
	@SuppressWarnings("unchecked")
	public List<Attend> findByEmp(Employee emp)
	{
		return (List<Attend>)getHibernateTemplate()
			.find("from Attend as a where a.employee=?" , emp);
	}
	
	@SuppressWarnings("unchecked")
	public List<Attend> findByEmpAndDutyDay(Employee emp, String dutyDay)
	{
		return (List<Attend>)getHibernateTemplate()
			.find("from Attend as a where a.employee=? and "
			+ "a.dutyDay=?" , new Object[]{emp , dutyDay});
	}
	
	@SuppressWarnings("null")
	public Attend findByEmpAndDutyDayAndCome(Employee emp, 
		String dutyDay, boolean isCome)
	{
		List<Attend> al = findByEmpAndDutyDay(emp, dutyDay);
		if (al != null || al.size() > 1)
		{
			for (Attend attend : al)
			{
				if (attend.getIsCome() == isCome)
				{
					return attend;
				}
			}
		}
		return null;
	}
	
	// 查看员工前三天的非正常打卡
	@SuppressWarnings("unchecked")
	public List<Attend> findByEmpUnAttend(Employee emp, AttendType type)
	{
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
		Calendar c = Calendar.getInstance();
		String end = sdf.format(c.getTime());
		c.add(Calendar.DAY_OF_MONTH, -3);
		String start = sdf.format(c.getTime());
	
		Object[] args = {emp , type , start , end};
		return (List<Attend>)getHibernateTemplate()
			.find("from Attend as a where a.employee=? and "
			+ "a.type != ? and a.dutyDay between ? and ?" , args);
	}
}
