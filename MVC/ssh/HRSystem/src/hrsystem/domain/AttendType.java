package hrsystem.domain;

import java.io.Serializable;

public class AttendType
	implements Serializable
{
	private static final long serialVersionUID = 48L;
	private Integer id;
	// 出勤类型的名称
	private String name;
	// 此类出勤对应的罚款
	private double amerce;
	
	public AttendType() {}

	public AttendType(Integer id, String name, double amerce)
	{
		this.id = id;
		this.name = name;
		this.amerce = amerce;
	}

	public void setId(Integer id)
	{
		this.id = id;
	}
	public Integer getId()
	{
		return this.id;
	}

	public void setName(String name)
	{
		this.name = name;
	}
	public String getName()
	{
		return this.name;
	}

	public void setAmerce(double amerce)
	{
		this.amerce = amerce;
	}
	public double getAmerce()
	{
		return this.amerce;
	}
}
