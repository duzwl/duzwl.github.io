package hrsystem.domain;

import java.io.Serializable;
import java.util.Date;

public class Attend
	implements Serializable
{
	private static final long serialVersionUID = 48L;
	private Integer id;
	private String dutyDay;
	private Date punchTime;
	// 代表本次打卡是否为上班打卡
	private boolean isCome;
	private AttendType type;
	private Employee employee;

	public Attend() {}

	public Attend(Integer id, String dutyDay, Date punchTime, 
			boolean isCome, AttendType type, Employee employee)
	{
		this.id = id;
		this.dutyDay = dutyDay;
		this.punchTime = punchTime;
		this.isCome = isCome;
		this.type = type;
		this.employee = employee;
	}

	public void setId(Integer id)
	{
		this.id = id;
	}
	public Integer getId()
	{
		return this.id;
	}

	public void setDutyDay(String dutyDay)
	{
		this.dutyDay = dutyDay;
	}
	public String getDutyDay()
	{
		return this.dutyDay;
	}

	public void setPunchTime(Date punchTime)
	{
		this.punchTime = punchTime;
	}
	public Date getPunchTime()
	{
		return this.punchTime;
	}

	public void setIsCome(boolean isCome)
	{
		this.isCome = isCome;
	}
	public boolean getIsCome()
	{
		return this.isCome;
	}

	public void setType(AttendType type)
	{
		this.type = type;
	}
	public AttendType getType()
	{
		return this.type;
	}

	public void setEmployee(Employee employee)
	{
		this.employee = employee;
	}
	public Employee getEmployee()
	{
		return this.employee;
	}

	public boolean equals(Object obj)
	{
		if (this == obj)
		{
			return true;
		}
		if (obj != null && obj.getClass() == Attend.class)
		{
			Attend attend = (Attend)obj;
			return getEmployee().equals(attend.getEmployee())
				&& getDutyDay().equals(attend.getDutyDay())
				&& getIsCome() == attend.getIsCome();
		}
		return false;
	}

	public int hashCode ()
	{
		if (getIsCome())
		{
			return dutyDay.hashCode()+29*employee.hashCode()+1;
		}
		return dutyDay.hashCode()+29*employee.hashCode();
	}
}
